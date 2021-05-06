
#https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/master/registry/vk.xml

#exclusions
exclusions = [
	'vkGetDeviceProcAddr',
	'vkCreateDevice',
	'vkDestroyDevice'
]

#install xmltodict
import sys
import subprocess
import json

subprocess.check_call([sys.executable, '-m', 'pip', 'install', 'xmltodict'])

#fetch fresh vk.xml from Khronos repo
import urllib.request
import xmltodict

with urllib.request.urlopen('https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/master/registry/vk.xml') as response:
   vk_xml_raw = response.read()

vk_xml = xmltodict.parse(vk_xml_raw,process_namespaces=True)

device_commands = {}
core_commands = {}
extension_commands = {}

#Gather all device functions/aliases for filtering core/extension function fetching
commands = vk_xml['registry']['commands']['command']
aliases = {}
for command in commands:
	if 'proto' in command:
		name = command['proto']['name']
		return_type = command['proto']['type']
		types = []
		if type(command['param']) is list:
			types = command['param']
		else:
			types = [command['param']]
		if not name in exclusions:
			if types[0]['type'] == 'VkDevice' or types[0]['type'] == 'VkCommandBuffer' or types[0]['type'] == 'VkQueue':
				device_commands[name] = [types, return_type]
	elif '@alias' in command:
		aliases[command['@alias']] = command['@name'];

#Push the alias name as a device function if the alias exists in device commands
for alias in aliases:
	if alias in device_commands:
		device_commands[aliases[alias]] = device_commands[alias]

#Gather all core feature levels and functions
levels = vk_xml['registry']['feature']
for level in levels:
	core_commands[level['@name']] = []
	for require in level['require']:
		params = require.keys()
		for param in params:
			if param == 'command':
				if type(require[param]) is list:
					for n_param in require[param]:
						if n_param['@name'] in device_commands:
							core_commands[level['@name']] += [n_param['@name']]
				else:
					if require[param]['@name'] in device_commands:
							core_commands[level['@name']] += [require[param]['@name']]

#Gather extension functions
extensions = vk_xml['registry']['extensions']['extension']
for extension in extensions:
	extension_name = extension['@name']
	extension_commands[(extension_name, 'VK_VERSION_1_0')] = []
	for key in extension.keys():
		if key == 'require':
			requires = [extension[key]]
			for required in requires:
				if type(required) is list:
					for n_required in required:
						if '@feature' in n_required and 'command' in n_required:
							extension_commands[(extension_name, n_required['@feature'])] = []
							commands = [n_required['command']]
							for command in commands:
								if type(command) is list:
									for n_command in command:
										if n_command['@name'] in device_commands:
											extension_commands[(extension_name, n_required['@feature'])] += [n_command['@name']]
								elif command['@name'] in device_commands:
									extension_commands[(extension_name, n_required['@feature'])] += [command['@name']]
						elif 'command' in n_required:
							commands = [n_required['command']]
							for command in commands:
								if type(command) is list:
									for n_command in command:
										if n_command['@name'] in device_commands:
											extension_commands[(extension_name, 'VK_VERSION_1_0')] += [n_command['@name']]
								elif command['@name'] in device_commands:
									extension_commands[(extension_name, 'VK_VERSION_1_0')] += [command['@name']]
				elif 'command' in required:
					commands = [required['command']]
					for command in commands:
						if type(command) is list:
							for n_command in command:
								if n_command['@name'] in device_commands:
									extension_commands[(extension_name, 'VK_VERSION_1_0')] += [n_command['@name']]
						elif command['@name'] in device_commands:
							extension_commands[(extension_name, 'VK_VERSION_1_0')] += [command['@name']]

header = '\n#pragma once\n\n#include <vulkan/vulkan.h>\n\n'
header += 'namespace vkb {\n\n'
header += 'struct DispatchTable {\n'
header += '\tDispatchTable() = default;\n'
header += '\tDispatchTable(VkDevice const& device, PFN_vkGetDeviceProcAddr const& procAddr) {\n'
header += '\t\t_device = device;\n'

proxy_definition = ''
pfn_declaration = ''
pfn_loading = ''

for level in core_commands:
	pfn_declaration += '#ifdef ' + level + '\n';
	pfn_loading += '#ifdef ' + level + '\n';
	for command in core_commands[level]:
		fptr_name = 'PFN_' + command
		member_name = 'fp_' + command
		proxy_name = command[2].lower() + command[3:]

		types = device_commands[command][0]
		names = [];
		i = 0
		length = len(types) - 1
		takes_device = False;
		proxy_definition += '\t'
		return_type = device_commands[command][1];
		proxy_definition += return_type
		proxy_definition += ' '
		proxy_definition += proxy_name
		proxy_definition += '('
		for t in types:
			if i == 0 and t['type'] == 'VkDevice':
				takes_device = True
			else:
				if '#text' in t:
					text = t['#text']
					if 'const' in text:
						proxy_definition += 'const '
					proxy_definition += t['type']
					if '*' in text and not '**' in text:
						proxy_definition += '* '
						proxy_definition += t['name']
					elif '**' in text:
						proxy_definition += '** '
						proxy_definition += t['name']
					else:
						proxy_definition += ' '
						proxy_definition += t['name']
					if '[' in text and ']' in text:
						start = text.find('[')
						end = text.find(']')
						proxy_definition += text[start:end+1]
				else:
					proxy_definition += t['type']
					proxy_definition += ' '
					proxy_definition += t['name']
				names += [t['name']]
				if i < length:
					proxy_definition += ', '
			i += 1
		proxy_definition += ') {\n'
		proxy_definition += '\t\t'
		if return_type != 'void':
			proxy_definition += 'return '
		proxy_definition += member_name
		proxy_definition += '('

		if takes_device:
			proxy_definition +='_device'
			if(len(names) > 0):
				proxy_definition += ', '
		i = 0
		length = len(names) - 1
		for name in names:
			proxy_definition += name
			if i < length:
				proxy_definition += ', '
			i += 1
		proxy_definition += ');\n'

		proxy_definition += '\t}\n'
		#print(proxy_name)
		#print(names)
		#print(proxy_definition)

		pfn_declaration += '\t' + fptr_name + ' ' + member_name + ' = nullptr;\n'
		pfn_loading += '\t\t' + member_name + ' = (' + fptr_name + ')procAddr(device, "' + command + '");\n'
	pfn_declaration += '#endif\n'
	pfn_loading += '#endif\n'

for extension in extension_commands:
	if len(extension_commands[extension]) > 0:
		pfn_declaration += '#if defined(' + extension[0] + ') && defined(' + extension[1] + ')\n';
		pfn_loading += '#if defined(' + extension[0] + ') && defined(' + extension[1] + ')\n';
		for command in extension_commands[extension]:
			fptr_name = 'PFN_' + command
			member_name = 'fp_' + command
			proxy_name = command[2].lower() + command[3:]
			#Duplication guards
			pfn_declaration += '#ifndef ' + fptr_name + '_DECLARE\n'
			pfn_declaration += '#define ' + fptr_name + '_DECLARE\n'
			pfn_declaration += '\t' + fptr_name + ' ' + member_name + ' = nullptr;\n'
			pfn_declaration += '#endif\n'
			#Duplication guards
			pfn_loading += '#ifndef ' + fptr_name + '_LOAD\n'
			pfn_loading += '#define ' + fptr_name + '_LOAD\n'
			pfn_loading += '\t\t' + member_name + ' = (' + fptr_name + ')procAddr(device, "' + command + '");\n'
			pfn_loading += '#endif\n'
		pfn_declaration += '#endif\n'
		pfn_loading += '#endif\n'

header += pfn_loading
header += '\t}\n'
header += proxy_definition
header += 'private:\n\nVkDevice _device = VK_NULL_HANDLE;\n\n'
header += pfn_declaration
header += '};\n\n'
header += '} // namespace vkb'

header_file = open("../src/VkDispatchTable.h", "w")
header_file.write(header)
header_file.close();
	#print(test)

#print(core_commands)
#print(core_feature_levels)
#print(extension_commands)
#print(device_commands)

#header = ''
#header = format_header_top(header)
#for command in device_commands:
#	header = format_load(header, command);
#header = format_header_mid(header)
#for command in device_commands:
#	header = format_declaration(header, command);
#header = format_header_bottom(header)

#header_file = open("../src/VkDispatchTable.h", "w")
#header_file.write(header)
#header_file.close();