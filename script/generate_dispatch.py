
#
# generate_dispatch.py
#
# Copyright © 2021 Cody Goodson (contact@vibimanx.com)
# Copyright © 2022 Charles Giessen (charles@lunarg.com)
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
# documentation files (the “Software”), to deal in the Software without restriction, including without
# limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
# of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
# LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
# WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# This file is a part of VkBootstrap
# https://github.com/charles-lunarg/vk-bootstrap

# On run, vk.xml is pulled from the master of Khronos's Vulkan-Headers repo and a VkBoostrapDispatch header
# is generated and placed in VkBoostrap's source directory
# https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/master/registry/vk.xml

# This script makes use of xmltodict
# https://github.com/martinblech/xmltodict
# User will be prompted to install if not detected

# Command Line Arguments
# [--auto] Don't ask for input from the command line


import sys
import os
import subprocess
import copy
import codecs
import re
from string import Template
import urllib.request
import pkg_resources

# Exclusions
exclusions = [
    'vkGetDeviceProcAddr',
    'vkCreateDevice',
    'vkDestroyDevice'
]

# Excluded extension authors - don't generate anything for these types of extensions
excluded_extension_authors = [
    'NVX'
]

excluded_alias_types = [
    'VkPipelineInfoKHR'
]

# Check for/install xmltodict
installed = {pkg.key for pkg in pkg_resources.working_set}
xmltodict_missing = {'xmltodict'} - installed

# Install xmltodict
if xmltodict_missing:
    if '--auto' not in sys.argv:
        val = input('xmltodict is required to run this script. Would you like to install? (y/n): ')
    else:
        val = 'y'
    if val.lower() == 'y':
        try:
            subprocess.check_call([sys.executable, '-m', 'pip', 'install', 'xmltodict'])
        except subprocess.CalledProcessError as error:
            print('Failed to install xmltodict due to error:')
            print(error)
            if '--auto' not in sys.argv:
                input('Press Enter to continue...')
            sys.exit()
    else:
        sys.exit()

# Fetch fresh vk.xml from Khronos repo
import xmltodict

try:
    response = urllib.request.urlopen('https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/main/registry/vk.xml')
except urllib.error.URLError as error:
    print('Failed to download vk.xml due to error:')
    print(error.reason)
    if '-q' not in sys.argv:
        input('Press Enter to continue...')
    sys.exit()
vk_xml_raw = response.read()

vk_xml = xmltodict.parse(vk_xml_raw,process_namespaces=True)

command_params = {'return_type': '', 'args': [], 'dispatch_type': '', 'requirements': [], 'macro_template': Template('')}

commands = {}

INSTANCE = 'instance'
DEVICE = 'device'

# No good way to detect incompatibilities with the macro defines and the actual functions. Just keep a list here
HEADER_VERSION_WORKAROUNDS = {
    'vkGetLatencyTimingsNV': '271', # Changed API parameters
    'vkCmdSetDiscardRectangleEnableEXT': '241', # new function in older extension
    'vkCmdSetDiscardRectangleModeEXT': '241', # new function in older extension
    'vkCmdSetExclusiveScissorEnableNV': '241', # Changed API parameters
    'vkCmdInitializeGraphScratchMemoryAMDX': '298', # Changed API parameters
    'vkCmdDispatchGraphAMDX': '298', # Changed API parameters
    'vkCmdDispatchGraphIndirectAMDX': '298', # Changed API parameters
    'vkCmdDispatchGraphIndirectCountAMDX': '298', # Changed API parameters
}

def get_macro_guard(reqs_collection, command_name):
    unique_guards = []
    for reqs in reqs_collection:
        is_unique = True
        for unique_guard in unique_guards:
            if set(unique_guard) == set(reqs):
                is_unique = False
        if is_unique:
            if (isinstance(reqs, str)):
                unique_guards.append([reqs])
            else:
                unique_guards.append(reqs)
    guards = []
    for reqs in unique_guards:
        guards.append(' && '.join(map('defined({0})'.format, reqs)))

    guard = ' || '.join(map('({0})'.format, guards))
    # API breaking change causes this function to fail compilation, so guard it to not work before the known good version
    if command_name in HEADER_VERSION_WORKAROUNDS:
        guard = f'({guard}) && VK_HEADER_VERSION >= {HEADER_VERSION_WORKAROUNDS[command_name]}'

    return guard


aliased_types = {}
types_node = vk_xml['registry']['types']['type']
for type_node in  types_node:
    if '@alias' in type_node:
        aliased_types[type_node['@alias']] = type_node['@name']

# Gather all device functions/aliases for filtering core/extension function fetching
commands_node = vk_xml['registry']['commands']['command']
aliases = {}
for command_node in commands_node:
    if 'proto' in command_node:
        command_name = command_node['proto']['name']
        new_command_params = copy.deepcopy(command_params)
        new_command_params['return_type'] = command_node['proto']['type']
        if isinstance(command_node['param'], list):
            params = command_node['param']
        else:
            params = [command_node['param']]
        new_command_params['args'] = []
        for param in params:
            # if the api attribute does exist, make sure it is for vulkan
            if not '@api' in param or param['@api'] == 'vulkan':
                new_command_params['args'].append(param)
        if not command_name in exclusions:
            commands[command_name] = new_command_params
            commands[command_name]['is_alias'] = False
            if new_command_params['args'][0]['type'] in ['VkDevice', 'VkCommandBuffer', 'VkQueue']:
                commands[command_name]['dispatch_type'] = DEVICE
            elif new_command_params['args'][0]['type'] in ['VkInstance', 'VkPhysicalDevice']:
                commands[command_name]['dispatch_type'] = INSTANCE
    elif '@alias' in command_node:
        aliases[command_node['@alias']] = command_node['@name']

# Push the alias name as a device function if the alias exists in device commands
for aliased_type, alias in aliases.items():
    if aliased_type in commands:
        commands[alias] = copy.deepcopy(commands[aliased_type])
        commands[alias]['is_alias'] = True

# Add requirements for core PFN's
features_node = vk_xml['registry']['feature']
for feature_node in features_node:
    if feature_node['@name'] != 'VK_VERSION_1_0':
        for require_node in feature_node['require']:
            for param_node in require_node:
                if param_node == 'command':
                    if not isinstance(require_node[param_node], list):
                        require_node[param_node] = [require_node[param_node]]
                    for param in require_node[param_node]:
                        if param['@name'] in commands:
                            commands[param['@name']]['requirements'] += [[feature_node['@name']]]


# Add requirements for extension PFN's
for extension_node in vk_xml['registry']['extensions']['extension']:
    extension_name = extension_node['@name']
    if 'require' not in extension_node.keys():
        continue
    requires_list = [extension_node['require']] if isinstance(extension_node['require'], dict) else extension_node['require']
    for requires_dict in requires_list:
        requirements = []
        if 'command' not in requires_dict.keys():
            continue
        if '@depends' in requires_dict:
            for dep in requires_dict['@depends'].split(','):
                requirements.append([extension_name, dep])
        command_list = [requires_dict['command']] if isinstance(requires_dict['command'], dict) else requires_dict['command']
        for command_node in command_list:
            if command_node['@name'] in commands:
                if '@author' in extension_node and extension_node['@author'] in excluded_extension_authors:
                    commands.pop(command_node['@name'])
                else:
                    if not requirements:
                        requirements = [extension_name]
                    commands[command_node['@name']]['requirements'].extend(requirements)

# Generate macro templates
for command_name, command in commands.items():
    if len(commands[command_name]['requirements']) > 0:
        macro_guard = get_macro_guard(commands[command_name]['requirements'], command_name)
        macro = f'#if {macro_guard}\n$body#endif\n'
    else:
        macro = '$body'
    commands[command_name]['macro_template'] = Template(macro)

for command_name, command in commands.items():
    if len(commands[command_name]['requirements']) > 0:
        macro_guard = get_macro_guard(commands[command_name]['requirements'], command_name)
        pfn_decl_macro = f'#if {macro_guard}\n$body#else\n    void * fp_{command_name}{{}};\n#endif\n'
    else:
        pfn_decl_macro = '$body'
    commands[command_name]['pfn_decl_macro_template'] = Template(pfn_decl_macro)

# License
dispatch_license = '''/*
 * Copyright © 2021 Cody Goodson (contact@vibimanx.com)
 * Copyright © 2022 Charles Giessen (charles@lunarg.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the “Software”), to deal in the Software without restriction, including without
 * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
'''

# Info
info = '// This file is a part of VkBootstrap\n'
info += '// https://github.com/charles-lunarg/vk-bootstrap\n\n'

# # Content
head = '\n#pragma once\n\n#include <vulkan/vulkan_core.h>\n\n'
head += 'namespace vkb {\n\n'

def create_dispatch_table(dispatch_type):
    out = ''
    if dispatch_type == INSTANCE:
        out += 'struct InstanceDispatchTable {\n'
        out += '    InstanceDispatchTable() = default;\n'
        out += '    InstanceDispatchTable(VkInstance instance, PFN_vkGetInstanceProcAddr procAddr) : instance(instance), populated(true) {\n'
    else:
        out += 'struct DispatchTable {\n'
        out += '    DispatchTable() = default;\n'
        out += '    DispatchTable(VkDevice device, PFN_vkGetDeviceProcAddr procAddr) : device(device), populated(true) {\n'

    proxy_section = ''
    fp_decl_section = ''
    pfn_load_section = ''

    proxy_template = Template('    $return_type $proxy_name($args_full) const noexcept {\n        $opt_return$fp_name($args_names);\n    }\n')
    fp_decl_template = Template('    $pfn_name $fp_name = nullptr;\n')
    if dispatch_type == INSTANCE:
        pfn_load_template = Template('        $fp_name = reinterpret_cast<$pfn_name>(procAddr(instance, "$command_name"));\n')
    else:
        pfn_load_template = Template('        $fp_name = reinterpret_cast<$pfn_name>(procAddr(device, "$command_name"));\n')

    for command_name, command in commands.items():
        if command['dispatch_type'] != dispatch_type:
            continue
        params = commands[command_name]
        # easy stuff out of the way
        return_type = params['return_type']
        if return_type != 'void':
            opt_return = 'return '
        else:
            opt_return = ''
        proxy_name = command_name[2].lower() + command_name[3:]
        fp_name = 'fp_' + command_name
        pfn_name = 'PFN_' + command_name

        # Now for args
        arg_template = Template('$front_mods$arg_type$back_mods$arg_name$array')
        args_full = ''
        args_names = ''
        args_count = len(params['args'])
        i = args_count
        for arg in params['args']:
            front_mods = ''
            back_mods = ' '
            array = ''
            arg_type = arg['type']
            arg_name = arg['name']
            if '#text' in arg:
                text = arg['#text']
                text = text.replace(' ', '')
                array_index = text.find('[')
                if array_index != -1:
                    array = text[array_index:]
                    text = text[0:array_index]
                if text == '*':
                    front_mods = ''
                    back_mods = '* '
                elif text == '**':
                    front_mods = ''
                    back_mods = '** '
                elif text == 'struct*':
                    front_mods = 'struct '
                    back_mods = '* '
                elif text == 'struct**':
                    front_mods = 'struct '
                    back_mods = '** '
                elif text == 'const':
                    front_mods = 'const '
                    back_mods = ' '
                elif text == 'const*':
                    front_mods = 'const '
                    back_mods = '* '
                elif text == 'const**':
                    front_mods = 'const '
                    back_mods = '** '
                elif text == 'const*const*':
                    front_mods = 'const '
                    back_mods = '* const* '
                elif text == 'conststruct*':
                    front_mods = 'const struct '
                    back_mods = '* '
                else:
                    print("Unhandled Text Case!")
                    assert(False)
            if i == args_count and (dispatch_type == INSTANCE and arg_type == 'VkInstance') or (dispatch_type == DEVICE and arg_type == 'VkDevice'):
                args_names += arg_name
                if i > 0:
                    i -= 1
                    if i > 0:
                        args_names += ', '
            else:
                if arg_type in aliased_types and  arg_type not in excluded_alias_types:
                    arg_type = aliased_types[arg_type]
                args_full += arg_template.substitute(front_mods = front_mods, arg_type = arg_type, back_mods = back_mods, arg_name = arg_name, array = array)
                args_names += arg_name
                if i > 0:
                    i -= 1
                    if i > 0:
                        args_full += ', '
                        args_names += ', '

        proxy_body = proxy_template.substitute(return_type = return_type, proxy_name = proxy_name, args_full = args_full, opt_return = opt_return, fp_name = fp_name, args_names = args_names)
        fp_decl_body = fp_decl_template.substitute(pfn_name = pfn_name, fp_name = fp_name)
        pfn_load_body = pfn_load_template.substitute(fp_name = fp_name, pfn_name = pfn_name, command_name = command_name)

        macro_template = params['macro_template']
        pfn_decl_macro_template = params['pfn_decl_macro_template']
        proxy_section += macro_template.substitute(body=proxy_body)
        fp_decl_section += pfn_decl_macro_template.substitute(body=fp_decl_body)
        pfn_load_section += macro_template.substitute(body=pfn_load_body)

    out += pfn_load_section
    out += '    }\n'
    out += proxy_section
    out += fp_decl_section
    out += '    bool is_populated() const { return populated; }\n'
    if dispatch_type == INSTANCE:
        out += '    VkInstance instance = VK_NULL_HANDLE;\n'
    else:
        out += '    VkDevice device = VK_NULL_HANDLE;\n'
    out += 'private:\n'
    out += '     bool populated = false;\n'
    out += '};\n\n'
    return out

tail = '} // namespace vkb'

# find the version used to generate the code
for type_node in  types_node:
    if '@api' in type_node and type_node['@api'] == 'vulkan' and 'name' in type_node and type_node['name'] == 'VK_HEADER_VERSION_COMPLETE':
        complete_header_version = type_node['#text']
    if '@api' in type_node and type_node['@api'] == 'vulkan' and 'name' in type_node and type_node['name'] == 'VK_HEADER_VERSION':
        vk_header_version = type_node['#text']
find_number_fields = re.compile('[0-9]+')
version_fields = find_number_fields.findall(complete_header_version)
header_version_field = find_number_fields.findall(vk_header_version)[0]
version_tag = f'{version_fields[1]}.{version_fields[2]}.{header_version_field}'

path_to_src = os.path.join('src')
if not os.path.exists(path_to_src):
    path_to_src = os.path.join('..', 'src')
if not os.path.exists(path_to_src):
    print('Could not find source folder. Is the current directory wrong?')
    sys.exit()

header_file = codecs.open(os.path.join(path_to_src,'VkBootstrapDispatch.h'), 'w', 'utf-8')
header_file.write(dispatch_license + info + head + create_dispatch_table('instance') + create_dispatch_table('device') + tail)
header_file.close()

path_to_gen = os.path.join('gen')
if not os.path.exists(path_to_gen):
    path_to_gen = os.path.join('..', 'gen')
if not os.path.exists(path_to_gen):
    print('Could not find gen folder. Is the current directory wrong?')
    sys.exit()

# Generate a CMake file that contains the header version used.
cmake_version_file = codecs.open(os.path.join(path_to_gen,'CurrentBuildVulkanVersion.cmake'), 'w', 'utf-8')
cmake_version_file.write(f'set(VK_BOOTSTRAP_SOURCE_HEADER_VERSION {version_tag})\n')
cmake_version_file.write(f'set(VK_BOOTSTRAP_SOURCE_HEADER_VERSION_GIT_TAG v{version_tag})\n')
cmake_version_file.close()

print('Generation finished.')
