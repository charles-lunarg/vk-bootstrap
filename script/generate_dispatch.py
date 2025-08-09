
#
# generate_dispatch.py
#
# Copyright © 2021 Cody Goodson (contact@vibimanx.com)
# Copyright © 2022-2025 Charles Giessen (charles@lunarg.com)
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

# This script reqiores the vulkan_object package to be installed
# https://github.com/KhronosGroup/vulkan-object

import os
import codecs
from vulkan_object import get_vulkan_object

vk = get_vulkan_object()

# Command Exclusions
exclusions = [
    'vkGetDeviceProcAddr',
    'vkCreateDevice',
    'vkDestroyDevice'
]

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
    'vkCmdDispatchTileQCOM': '316', # Changed API parameters
}

# Functions that have types which have been promoted - workaround to allow users to use the non-promoted functions (ie, when the header is older)
DEPROMOTED_TYPES = {
    "vkReleaseSwapchainImagesEXT": [ "VkReleaseSwapchainImagesInfoKHR","VkReleaseSwapchainImagesInfoEXT"]
}

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


def get_command_guards(command):
    version_guard = f'defined({command.version.name})' if command.version is not None else ''
    ext_guard = ' || '.join([f'defined({e})' for e in command.extensions] )
    return f'{version_guard}{" || " if len(version_guard) > 0 and len(ext_guard) > 0 else ""}{ext_guard}'

def command_include_guard(command):
    guards = get_command_guards(command)
    if len(guards) == 0:
        return ''
    out = '#if (' + guards + ')'
    if command.name in HEADER_VERSION_WORKAROUNDS:
        out += f' && VK_HEADER_VERSION >= {HEADER_VERSION_WORKAROUNDS[command.name]}'
    out += '\n'
    return out

def command_end_include_guard(command):
    guards = get_command_guards(command)
    return '#endif\n' if len(guards) > 0 else ''

def command_end_include_guard_member_decl(command):
    guards = get_command_guards(command)
    if len(guards) == 0:
        return ''
    return f'#else\n    void * fp_{command.name}{{}};\n#endif\n'

def create_dispatch_table(dispatch_type):
    out = ''
    if dispatch_type == INSTANCE:
        commands = [x for x in vk.commands.values() if x.instance and x.name not in exclusions and x.params[0].type in ['VkInstance','VkPhysicalDevice']]
        out += 'struct InstanceDispatchTable {\n'
        out += '    InstanceDispatchTable() = default;\n'
        out += '    InstanceDispatchTable(VkInstance instance, PFN_vkGetInstanceProcAddr procAddr) : instance(instance), populated(true) {\n'
    else:
        commands = [x for x in vk.commands.values() if x.device and x.name not in exclusions]
        out += 'struct DispatchTable {\n'
        out += '    DispatchTable() = default;\n'
        out += '    DispatchTable(VkDevice device, PFN_vkGetDeviceProcAddr procAddr) : device(device), populated(true) {\n'

    commands = sorted(commands)

    for command in commands:
        out += command_include_guard(command)
        out += f'        fp_{command.name} = reinterpret_cast<PFN_{command.name}>(procAddr({dispatch_type}, "{command.name}"));\n'
        out += command_end_include_guard(command)
    out += '    }\n'

    for command in commands:
        out += command_include_guard(command)

        params = command.params
        if command.params[0].name == dispatch_type:
            params = params[1:]
        param_decl = [x.cDeclaration.strip() for x in params]
        param_names = [x.name for x in params]
        if command.name in DEPROMOTED_TYPES:
            replacement = DEPROMOTED_TYPES.get(command.name)
            param_decl = [x.replace(replacement[0], replacement[1]) for x in param_decl]
        if command.params[0].name == dispatch_type:
            param_names.insert(0, dispatch_type)
        out += f'    {command.returnType} {command.name[2].lower()}{command.name[3:]}({", ".join(param_decl)}) const noexcept {{\n        {"return " if command.returnType != "void" else ""}fp_{command.name}({", ".join(param_names)});\n    }}\n'
        out += command_end_include_guard(command)

    for command in commands:
        out += command_include_guard(command)
        out += f'    PFN_{command.name} fp_{command.name} = nullptr;\n'
        out += command_end_include_guard_member_decl(command)

    out += '    bool is_populated() const { return populated; }\n'
    out += f'    Vk{dispatch_type.capitalize()} {dispatch_type} = VK_NULL_HANDLE;\n'
    out += 'private:\n'
    out += '     bool populated = false;\n'
    out += '};\n\n'
    return out

tail = '} // namespace vkb'

# find the version used to generate the code
path_to_src = os.path.join('src')
if not os.path.exists(path_to_src):
    path_to_src = os.path.join('..', 'src')
if not os.path.exists(path_to_src):
    print('Could not find source folder. Is the current directory wrong?')
    exit(-1)

header_file = codecs.open(os.path.join(path_to_src,'VkBootstrapDispatch.h'), 'w', 'utf-8')
header_file.write(dispatch_license + info + head + create_dispatch_table('instance') + create_dispatch_table('device') + tail)
header_file.close()

path_to_gen = os.path.join('gen')
if not os.path.exists(path_to_gen):
    path_to_gen = os.path.join('..', 'gen')
if not os.path.exists(path_to_gen):
    print('Could not find gen folder. Is the current directory wrong?')
    exit(-1)

# Generate a CMake file that contains the header version used.
cmake_version_file = codecs.open(os.path.join(path_to_gen,'CurrentBuildVulkanVersion.cmake'), 'w', 'utf-8')
cmake_version_file.write(f'set(VK_BOOTSTRAP_SOURCE_HEADER_VERSION {vk.headerVersionComplete})\n')
cmake_version_file.write(f'set(VK_BOOTSTRAP_SOURCE_HEADER_VERSION_GIT_TAG v{vk.headerVersionComplete})\n')
cmake_version_file.close()

print('Generation finished.')
