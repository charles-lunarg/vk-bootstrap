
#
# generate_dispatch.py
# 
# Copyright © 2021 Cody Goodson (contact@vibimanx.com)
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

# On run, vk.xml is pulled from the master of Khronos's Vulkan-Headers repo and a VkDispatchTable type 
# is generated and placed in VkBoostrap's source directory
# https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/master/registry/vk.xml

# This script makes use of xmltodict
# https://github.com/martinblech/xmltodict
# The module will be auto-installed if not detected

# Exclusions
exclusions = [
	'vkGetDeviceProcAddr',
	'vkCreateDevice',
	'vkDestroyDevice'
]

# Check for/install xmltodict
import sys
import subprocess
import pkg_resources

installed = {pkg.key for pkg in pkg_resources.working_set}
xmltodict_missing = {'xmltodict'} - installed

if xmltodict_missing:
	subprocess.check_call([sys.executable, '-m', 'pip', 'install', 'xmltodict'])

# Fetch fresh vk.xml from Khronos repo
import urllib.request
import xmltodict

with urllib.request.urlopen('https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/master/registry/vk.xml') as response:
   vk_xml_raw = response.read()

vk_xml = xmltodict.parse(vk_xml_raw,process_namespaces=True)

criteria = { 'extension': '', 'feature': 'VK_VERSION_1_0' }
command_params = {'return_type': '', 'args': [], 'criterias': []}

device_commands = {}
core_commands = {}
extension_commands = {}

# Gather all device functions/aliases for filtering core/extension function fetching
commands_node = vk_xml['registry']['commands']['command']
aliases = {}
for command_node in commands_node:
	if 'proto' in command_node:
		command_name = command_node['proto']['name']
		new_command_params = command_params.copy()
		new_command_params['return_type'] = command_node['proto']['type']
		if type(command_node['param']) is list:
			new_command_params['args'] = command_node['param']
		else:
			new_command_params['args'] = [command_node['param']]
		if not command_name in exclusions:
			if new_command_params['args'][0]['type'] == 'VkDevice' or new_command_params['args'][0]['type'] == 'VkCommandBuffer' or new_command_params['args'][0]['type'] == 'VkQueue':
				device_commands[command_name] = new_command_params
	elif '@alias' in command_node:
		aliases[command_node['@alias']] = command_node['@name'];

# Push the alias name as a device function if the alias exists in device commands
for alias in aliases:
	if alias in device_commands:
		aliased_command_params = device_commands[alias].copy()
		device_commands[aliases[alias]] = aliased_command_params;

# Add criterias for core device pfns
features_node = vk_xml['registry']['feature']
for feature_node in features_node:
	for require_node in feature_node['require']:
		for param_node in require_node:
			if param_node == 'command':
				if type(require_node[param_node]) is list:
					for param in require_node[param_node]:
						if param['@name'] in device_commands:
							new_criteria = criteria.copy()
							new_criteria['feature'] = feature_node['@name']
							device_commands[param['@name']]['criterias'] += [new_criteria]

extensions_node = vk_xml['registry']['extensions']['extension']
for extension_node in extensions_node:
	extension_name = extension_node['@name']
	new_criteria = criteria.copy()
	new_criteria['extension'] = extension_name
	new_criteria['feature'] = 'VK_VERSION_1_0'
	if 'require' in extension_node:
		for require_node in extension_node['require']: 
			if '@feature' in extension_node['require']:
				print('aye')
				new_criteria['feature'] = extension_node['require']['@feature']
			#print(extension_node['require']['command'])
		# for command_node in extension_node['require']['command']:
		# 	for command_name in command_node['name']:
		# 		print(command_name)

# Gather extension functions
#extensions = vk_xml['registry']['extensions']['extension']
#for extension in extensions:
#	extension_name = extension['@name']
#	extension_commands[(extension_name, 'VK_VERSION_1_0')] = []
#	for key in extension.keys():
#		if key == 'require':
#			requires = [extension[key]]
#			for required in requires:
#				if type(required) is list:
#					for n_required in required:
#						if '@feature' in n_required and 'command' in n_required:
#							extension_commands[(extension_name, n_required['@feature'])] = []
#							commands = [n_required['command']]
#							for command in commands:
#								if type(command) is list:
#									for n_command in command:
#										if n_command['@name'] in device_commands:
#											extension_commands[(extension_name, n_required['@feature'])] += [n_command['@name']]
#								elif command['@name'] in device_commands:
#									extension_commands[(extension_name, n_required['@feature'])] += [command['@name']]
#						elif 'command' in n_required:
#							commands = [n_required['command']]
#							for command in commands:
#								if type(command) is list:
#									for n_command in command:
#										if n_command['@name'] in device_commands:
#											extension_commands[(extension_name, 'VK_VERSION_1_0')] += [n_command['@name']]
#								elif command['@name'] in device_commands:
#									extension_commands[(extension_name, 'VK_VERSION_1_0')] += [command['@name']]
#				elif 'command' in required:
#					commands = [required['command']]
#					for command in commands:
#						if type(command) is list:
#							for n_command in command:
#								if n_command['@name'] in device_commands:
#									extension_commands[(extension_name, 'VK_VERSION_1_0')] += [n_command['@name']]
#						elif command['@name'] in device_commands:
#							extension_commands[(extension_name, 'VK_VERSION_1_0')] += [command['@name']]
#
# Build header

# License
# header = '/* \n'
# header += ' * Copyright © 2021 Cody Goodson (contact@vibimanx.com)\n'
# header += ' * \n'
# header += ' * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated\n'
# header += ' * documentation files (the “Software”), to deal in the Software without restriction, including without\n'
# header += ' * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies\n'
# header += ' * of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\n'
# header += ' * \n'
# header += ' * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\n'
# header += ' * \n'
# header += ' * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT\n'
# header += ' * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.\n'
# header += ' * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,\n'
# header += ' * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n'
# header += ' * \n'
# header += ' */\n\n'

# # Info
# header += '// This file is a part of VkBootstrap\n'
# header += '// https://github.com/charles-lunarg/vk-bootstrap\n\n'

# # Content
# header += '\n#pragma once\n\n#include <vulkan/vulkan.h>\n\n'
# header += 'namespace vkb {\n\n'
# header += 'struct DispatchTable {\n'
# header += '\tDispatchTable() = default;\n'
# header += '\tDispatchTable(VkDevice const& device, PFN_vkGetDeviceProcAddr const& procAddr) : device(device) {\n'

# proxy_definition = ''
# pfn_declaration = ''
# pfn_loading = ''

# for level in core_commands:
# 	pfn_declaration += '#ifdef ' + level + '\n';
# 	pfn_loading += '#ifdef ' + level + '\n';
# 	for command in core_commands[level]:
# 		fptr_name = 'PFN_' + command
# 		member_name = 'fp_' + command
# 		proxy_name = command[2].lower() + command[3:]

# 		types = device_commands[command][0]
# 		names = [];
# 		i = 0
# 		length = len(types) - 1
# 		takes_device = False;
# 		proxy_definition += '\t'
# 		return_type = device_commands[command][1];
# 		proxy_definition += return_type
# 		proxy_definition += ' '
# 		proxy_definition += proxy_name
# 		proxy_definition += '('
# 		for t in types:
# 			if i == 0 and t['type'] == 'VkDevice':
# 				takes_device = True
# 			else:
# 				if '#text' in t:
# 					text = t['#text']
# 					text = text.replace(' ', '')
# 					array = '';
# 					array_index = text.find('[')
# 					if array_index != -1:
# 						array = text[array_index:]
# 						text = text[0:array_index]
# 					if text == '*':
# 						proxy_definition += t['type']
# 						proxy_definition += '* '
# 						proxy_definition += t['name']
# 					elif text == '**':
# 						proxy_definition += t['type']
# 						proxy_definition += '** '
# 						proxy_definition += t['name']
# 					elif text == 'const*':
# 						proxy_definition += 'const '
# 						proxy_definition += t['type']
# 						proxy_definition += '* '
# 						proxy_definition += t['name']
# 					elif text == 'const**':
# 						proxy_definition += 'const '
# 						proxy_definition += t['type']
# 						proxy_definition += '** '
# 						proxy_definition += t['name']
# 					elif text == 'const*const*':
# 						proxy_definition += 'const '
# 						proxy_definition += t['type']
# 						proxy_definition += '* const* '
# 						proxy_definition += t['name']
# 					else:
# 						proxy_definition += t['type']
# 						proxy_definition += ' '
# 						proxy_definition += t['name']
# 					if array != '':
# 						proxy_definition += array
# 				else:
# 					proxy_definition += t['type']
# 					proxy_definition += ' '
# 					proxy_definition += t['name']
# 				names += [t['name']]
# 				if i < length:
# 					proxy_definition += ', '
# 			i += 1
# 		proxy_definition += ') const {\n'
# 		proxy_definition += '\t\t'
# 		if return_type != 'void':
# 			proxy_definition += 'return '
# 		proxy_definition += member_name
# 		proxy_definition += '('

# 		if takes_device:
# 			proxy_definition +='device'
# 			if(len(names) > 0):
# 				proxy_definition += ', '
# 		i = 0
# 		length = len(names) - 1
# 		for name in names:
# 			proxy_definition += name
# 			if i < length:
# 				proxy_definition += ', '
# 			i += 1
# 		proxy_definition += ');\n'
# 		proxy_definition += '\t}\n'

# 		pfn_declaration += '\t' + fptr_name + ' ' + member_name + ' = nullptr;\n'
# 		pfn_loading += '\t\t' + member_name + ' = (' + fptr_name + ')procAddr(device, "' + command + '");\n'
# 	pfn_declaration += '#endif\n'
# 	pfn_loading += '#endif\n'

# for extension in extension_commands:
# 	if len(extension_commands[extension]) > 0:
# 		pfn_declaration += '#if defined(' + extension[0] + ') && defined(' + extension[1] + ')\n';
# 		pfn_loading += '#if defined(' + extension[0] + ') && defined(' + extension[1] + ')\n';
# 		proxy_definition += '#if defined(' + extension[0] + ') && defined(' + extension[1] + ')\n';
# 		for command in extension_commands[extension]:
# 			fptr_name = 'PFN_' + command
# 			member_name = 'fp_' + command
# 			proxy_name = command[2].lower() + command[3:]
# 			#Duplication guards
# 			pfn_declaration += '#ifndef ' + fptr_name + '_DECLARE\n'
# 			pfn_declaration += '#define ' + fptr_name + '_DECLARE\n'
# 			pfn_declaration += '\t' + fptr_name + ' ' + member_name + ' = nullptr;\n'
# 			pfn_declaration += '#endif\n'
# 			#Duplication guards
# 			pfn_loading += '#ifndef ' + fptr_name + '_LOAD\n'
# 			pfn_loading += '#define ' + fptr_name + '_LOAD\n'
# 			pfn_loading += '\t\t' + member_name + ' = (' + fptr_name + ')procAddr(device, "' + command + '");\n'
# 			pfn_loading += '#endif\n'
# 			#Duplication guards
# 			proxy_definition += '#ifndef ' + fptr_name + '_PROXY\n'
# 			proxy_definition += '#define ' + fptr_name + '_PROXY\n'
# 			#proxy_definition += '\t\tTEST '+ proxy_name +'\n'
# 			types = device_commands[command][0]
# 			names = [];
# 			i = 0
# 			length = len(types) - 1
# 			takes_device = False;
# 			proxy_definition += '\t'
# 			return_type = device_commands[command][1];
# 			proxy_definition += return_type
# 			proxy_definition += ' '
# 			proxy_definition += proxy_name
# 			proxy_definition += '('
# 			for t in types:
# 				if i == 0 and t['type'] == 'VkDevice':
# 					takes_device = True
# 				else:
# 					if '#text' in t:
# 						text = t['#text']
# 						text = text.replace(' ', '')
# 						array = '';
# 						array_index = text.find('[')
# 						if array_index != -1:
# 							array = text[array_index:]
# 							text = text[0:array_index]
# 						if text == '*':
# 							proxy_definition += t['type']
# 							proxy_definition += '* '
# 							proxy_definition += t['name']
# 						elif text == '**':
# 							proxy_definition += t['type']
# 							proxy_definition += '** '
# 							proxy_definition += t['name']
# 						elif text == 'const*':
# 							proxy_definition += 'const '
# 							proxy_definition += t['type']
# 							proxy_definition += '* '
# 							proxy_definition += t['name']
# 						elif text == 'const**':
# 							proxy_definition += 'const '
# 							proxy_definition += t['type']
# 							proxy_definition += '** '
# 							proxy_definition += t['name']
# 						elif text == 'const*const*':
# 							proxy_definition += 'const '
# 							proxy_definition += t['type']
# 							proxy_definition += '* const* '
# 							proxy_definition += t['name']
# 						else:
# 							proxy_definition += t['type']
# 							proxy_definition += ' '
# 							proxy_definition += t['name']
# 						if array != '':
# 							proxy_definition += array
# 					else:
# 						proxy_definition += t['type']
# 						proxy_definition += ' '
# 						proxy_definition += t['name']
# 					names += [t['name']]
# 					if i < length:
# 						proxy_definition += ', '
# 				i += 1
# 			proxy_definition += ') const {\n'
# 			proxy_definition += '\t\t'
# 			if return_type != 'void':
# 				proxy_definition += 'return '
# 			proxy_definition += member_name
# 			proxy_definition += '('

# 			if takes_device:
# 				proxy_definition +='device'
# 				if(len(names) > 0):
# 					proxy_definition += ', '
# 			i = 0
# 			length = len(names) - 1
# 			for name in names:
# 				proxy_definition += name
# 				if i < length:
# 					proxy_definition += ', '
# 				i += 1
# 			proxy_definition += ');\n'
# 			proxy_definition += '\t}\n'
# 			proxy_definition += '#endif\n'
# 		pfn_declaration += '#endif\n'
# 		pfn_loading += '#endif\n'
# 		proxy_definition += '#endif\n'

# header += pfn_loading
# header += '\t}\n'
# header += proxy_definition
# header += pfn_declaration
# header += '\tVkDevice device = VK_NULL_HANDLE;\n'
# header += '};\n\n'
# header += '} // namespace vkb'

# header_file = open("../src/VkDispatchTable.h", "w")
# header_file.write(header)
# header_file.close();