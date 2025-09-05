
#
# generate_features_chain.py
#
# Copyright © 2025 Charles Giessen (charles@lunarg.com)
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

# This script requires the vulkan_object package to be installed
# https://github.com/KhronosGroup/vulkan-object

import os
import codecs
from vulkan_object import get_vulkan_object

vk = get_vulkan_object()

header = '''/*
 * Copyright © 2025 Charles Giessen (charles@lunarg.com)
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

// This file is a part of VkBootstrap
// https://github.com/charles-lunarg/vk-bootstrap

#pragma once
#include <string>
#include <vector>
#include <vulkan/vulkan_core.h>
'''

namespace_decl = '''
namespace vkb::detail {

'''

def print_required_platform_defines():
    required_platforms = set()
    for feature in [x for x in vk.structs.values() if x.extends is not None and 'VkPhysicalDeviceFeatures2' in x.extends]:
        if feature.protect:
            required_platforms.add(feature.protect)

    out = ''
    for required_platform in required_platforms:
        out += f'#if defined({required_platform})\n'
        if required_platform == 'VK_ENABLE_BETA_EXTENSIONS':
            out += '#include <vulkan/vulkan_beta.h>\n'
        elif required_platform == 'VK_USE_PLATFORM_SCREEN_QNX':
            out += '#include <screen/screen.h>\n'
            out += '#include <vulkan/vulkan_screen.h>\n'
        elif required_platform == 'VK_USE_PLATFORM_ANDROID_KHR':
            out += '#include <vulkan/vulkan_android.h>\n'
        else:
            raise RuntimeError(f'Unhandled required platform {required_platform}!')
        out += f'#endif // defined({required_platform})\n'
    return out

def create_feature_chain_declarations():
    out = ''
    out += 'void compare_VkPhysicalDeviceFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceFeatures const& supported, VkPhysicalDeviceFeatures const& requested);\n'
    out += 'void merge_VkPhysicalDeviceFeatures(VkPhysicalDeviceFeatures & current, VkPhysicalDeviceFeatures const& merge_in);\n'

    for feature in [x for x in vk.structs.values() if x.extends is not None and 'VkPhysicalDeviceFeatures2' in x.extends]:
        if feature.protect:
            out += f'#if defined({feature.protect})\n'

        out += f'void compare_{feature.name}(std::vector<std::string> & error_list, {feature.name} const& supported, {feature.name} const& requested);\n'
        out += f'void merge_{feature.name}({feature.name} & current, {feature.name} const& merge_in);\n'
        if feature.protect:
            out += f'#endif // defined({feature.protect})\n'

    out += 'void compare_feature_struct(VkStructureType sType, std::vector<std::string> & error_list, const void* supported, const void* requested);\n'
    out += 'void merge_feature_struct(VkStructureType sType, void* current, const void* merge_in);\n'
    return out

def create_feature_chain_definitions():
    out = ''

    out += 'void compare_VkPhysicalDeviceFeatures(std::vector<std::string> & error_list, VkPhysicalDeviceFeatures const& supported, VkPhysicalDeviceFeatures const& requested) {\n'
    for member in vk.structs['VkPhysicalDeviceFeatures'].members:
        if member.name in ['sType', 'pNext']:
            continue
        out += f'    if (requested.{member.name} && !supported.{member.name}) {{\n        error_list.push_back("Missing feature VkPhysicalDeviceFeatures::{member.name}");\n    }}\n'
    out += '}\n'
    out += 'void merge_VkPhysicalDeviceFeatures(VkPhysicalDeviceFeatures & current, VkPhysicalDeviceFeatures const& merge_in) {\n'
    for member in vk.structs['VkPhysicalDeviceFeatures'].members:
        if member.name in ['sType', 'pNext']:
            continue
        out += f'    current.{member.name} = current.{member.name} || merge_in.{member.name};\n'
    out += '}\n'

    for feature in [x for x in vk.structs.values() if x.extends is not None and 'VkPhysicalDeviceFeatures2' in x.extends]:
        if feature.protect:
            out += f'#if defined({feature.protect})\n'

        out += f'void compare_{feature.name}(std::vector<std::string> & error_list, {feature.name} const& supported, {feature.name} const& requested) {{\n'
        for member in feature.members:
            if member.name in ['sType', 'pNext']:
                continue
            out += f'    if (requested.{member.name} && !supported.{member.name}) {{\n        error_list.push_back("Missing feature {feature.name}::{member.name}");\n    }}\n'

        out += '}\n'
        out += f'void merge_{feature.name}({feature.name} & current, {feature.name} const& merge_in) {{\n'
        for member in feature.members:
            if member.name in ['sType', 'pNext']:
                continue
            out += f'    current.{member.name} = current.{member.name} || merge_in.{member.name};\n'

        out += '}\n'
        if feature.protect:
            out += f'#endif // defined({feature.protect})\n'

    out += 'void compare_feature_struct(VkStructureType sType, std::vector<std::string> & error_list, const void* supported, const void* requested) {\n'
    out += '    switch (sType) {\n'
    for feature in [x for x in vk.structs.values() if x.extends is not None and 'VkPhysicalDeviceFeatures2' in x.extends]:
        if feature.protect:
            out += f'#if defined({feature.protect})\n'
        out += f'        case({feature.sType}):\n'
        out += f'            compare_{feature.name}(error_list, *reinterpret_cast<const {feature.name}*>(supported), *reinterpret_cast<const {feature.name}*>(requested));\n'
        out += '            break;\n'
        if feature.protect:
            out += f'#endif // defined({feature.protect})\n'
    out += '        default:\n'
    out += '            break;\n'
    out += '    }\n'
    out += '}\n'

    out += 'void merge_feature_struct(VkStructureType sType, void* current, const void* merge_in) {\n'
    out += '    switch (sType) {\n'
    for feature in [x for x in vk.structs.values() if x.extends is not None and 'VkPhysicalDeviceFeatures2' in x.extends]:
        if feature.protect:
            out += f'#if defined({feature.protect})\n'
        out += f'        case({feature.sType}):\n'
        out += f'            merge_{feature.name}(*reinterpret_cast<{feature.name}*>(current), *reinterpret_cast<const {feature.name}*>(merge_in));\n'
        out += '            break;\n'
        if feature.protect:
            out += f'#endif // defined({feature.protect})\n'
    out += '        default:\n'
    out += '            break;\n'
    out += '    }\n'
    out += '}\n'

    return out

tail = '} // namespace vkb'

# find the version used to generate the code
path_to_src = os.path.join('src')
if not os.path.exists(path_to_src):
    path_to_src = os.path.join('..', 'src')
if not os.path.exists(path_to_src):
    print('Could not find source folder. Is the current directory wrong?')
    exit(-1)

features_chain = codecs.open(os.path.join(path_to_src,'VkBootstrapFeatureChain.h'), 'w', 'utf-8')
features_chain.write(header + print_required_platform_defines() + namespace_decl + create_feature_chain_declarations() + tail)
features_chain.close()

features_chain_inl = codecs.open(os.path.join(path_to_src,'VkBootstrapFeatureChain.inl'), 'w', 'utf-8')
features_chain_inl.write(header + namespace_decl + create_feature_chain_definitions() + tail)
features_chain_inl.close()

path_to_gen = os.path.join('gen')
if not os.path.exists(path_to_gen):
    path_to_gen = os.path.join('..', 'gen')
if not os.path.exists(path_to_gen):
    print('Could not find gen folder. Is the current directory wrong?')
    exit(-1)

print('Generation finished.')
