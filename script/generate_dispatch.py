
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

command_params = {'return_type': '', 'args': [], 'requirements': [], 'macro_template': Template('')}

device_commands = {}

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
            if new_command_params['args'][0]['type'] in ['VkDevice', 'VkCommandBuffer', 'VkQueue']:
                device_commands[command_name] = new_command_params
                device_commands[command_name]['is_alias'] = False
    elif '@alias' in command_node:
        aliases[command_node['@alias']] = command_node['@name']

# Push the alias name as a device function if the alias exists in device commands
for alias_name, alias in aliases.items():
    if alias in device_commands:
        device_commands[alias] = copy.deepcopy(device_commands[alias_name])
        device_commands[alias]['is_alias'] = True

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
                        if param['@name'] in device_commands:
                            device_commands[param['@name']]['requirements'] += [[feature_node['@name']]]


# Add requirements for extension PFN's
extensions_node = vk_xml['registry']['extensions']['extension']
for extension_node in extensions_node:
    extension_name = extension_node['@name']
    if 'require' in extension_node.keys():
        require_nodes = extension_node['require']
        for require_node in require_nodes:
            requirements = [extension_name]
            if not isinstance(require_node, str):
                if 'command' in require_node.keys():
                    if '@feature' in require_node.keys():
                        requirements.append(require_node['@feature'])
                    if '@extension' in require_node.keys():
                        requirements.extend(require_node['@extension'].split(','))
                    if not isinstance(require_node['command'], list):
                        require_node['command'] = [require_node['command']]
                    for command_node in require_node['command']:
                        if command_node['@name'] in device_commands:
                            if '@author' in extension_node and extension_node['@author'] in excluded_extension_authors:
                                device_commands.pop(command_node['@name'])
                            else:
                                device_commands[command_node['@name']]['requirements'] += [requirements]
            elif require_node == 'command':
                if not isinstance(require_nodes['command'], list):
                    require_nodes['command'] = [require_nodes['command']]
                for command_node in require_nodes['command']:
                    if command_node['@name'] in device_commands:
                        if '@author' in extension_node and extension_node['@author'] in excluded_extension_authors:
                            device_commands.pop(command_node['@name'])
                        else:
                            device_commands[command_node['@name']]['requirements'] += [requirements]

# Generate macro templates
for command_name, command in device_commands.items():
    macro = ''
    requirements_collection = device_commands[command_name]['requirements']
    collection_count = len(requirements_collection)
    if collection_count > 0:
        macro = '#if '
        while collection_count > 0:
            for requirements in requirements_collection:
                requirements_count = len(requirements)
                macro += '('
                for requirement in requirements:
                    macro += f'defined({requirement})'
                    requirements_count -= 1
                    if requirements_count > 0:
                        macro += ' && '
                macro += ')'
                if collection_count > 0:
                    collection_count -= 1
                    if collection_count > 0:
                        macro += ' || '
        macro += '\n$body#endif\n'
    else:
        macro = '$body'
    device_commands[command_name]['macro_template'] = Template(macro)

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
body = '\n#pragma once\n\n#include <vulkan/vulkan.h>\n\n'
body += 'namespace vkb {\n\n'
body += 'struct DispatchTable {\n'
body += '\tDispatchTable() = default;\n'
body += '\tDispatchTable(VkDevice device, PFN_vkGetDeviceProcAddr procAddr) : device(device), populated(true) {\n'

proxy_section = ''
fp_decl_section = ''
pfn_load_section = ''

proxy_template = Template('\t$return_type $proxy_name($args_full) const noexcept {\n\t\t$opt_return$fp_name($args_names);\n\t}\n')
fp_decl_template = Template('\t$pfn_name $fp_name = nullptr;\n')
pfn_load_template = Template('\t\t$fp_name = reinterpret_cast<$pfn_name>(procAddr(device, "$command_name"));\n')

for command_name, command in device_commands.items():
    params = device_commands[command]
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
            elif text == 'struct**':
                front_mods = 'struct '
                back_mods = '** '
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
        if i == args_count and arg_type == 'VkDevice':
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
    pfn_load_body = pfn_load_template.substitute(fp_name = fp_name, pfn_name = pfn_name, command_name = command)

    macro_template = params['macro_template']
    proxy_section += macro_template.substitute(body=proxy_body)
    fp_decl_section += macro_template.substitute(body=fp_decl_body)
    pfn_load_section +=macro_template.substitute(body=pfn_load_body)

body += pfn_load_section
body += '\t}\n'
body += proxy_section
body += fp_decl_section
body += '\tbool is_populated() const { return populated; }\n'
body += '\tVkDevice device = VK_NULL_HANDLE;\n'
body += 'private:\n'
body += '\t bool populated = false;\n'
body += '};\n\n'
body += '} // namespace vkb'

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

header = dispatch_license + info + body

path_to_src = os.path.join('src')
if not os.path.exists(path_to_src):
    path_to_src = os.path.join('..', 'src')
if not os.path.exists(path_to_src):
    print('Could not find source folder. Is the current directory wrong?')
    sys.exit()

header_file = codecs.open(os.path.join(path_to_src,'VkBootstrapDispatch.h'), 'w', 'utf-8')
header_file.write(header)
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
