
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

device_commands = []
core_commands = {}
extension_commands = {}

#Gather all device functions/aliases for filtering core/extension function fetching
commands = vk_xml['registry']['commands']['command']
aliases = {}
for command in commands:
	#Not worrying about aliases as all extension functions are fetched regardless
	if 'proto' in command:
		#print(command['proto']['name'])
		name = command['proto']['name']
		if type(command['param']) is list:
			t = command['param'][0]['type']
		else:
			t = command['param']['type']
		if not name in exclusions:
			if t == 'VkDevice' or t == 'VkCommandBuffer' or t == 'VkQueue':
				device_commands += [name]
	elif '@alias' in command:
		aliases[command['@alias']] = command['@name'];

#Push the alias name as a device function if the alias exists in device commands
for alias in aliases:
	if alias in device_commands:
		device_commands += [aliases[alias]]

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

declaration = ''
loading = ''

for level in core_commands:
	declaration += '#ifdef ' + level + '\n';
	loading += '#ifdef ' + level + '\n';
	for command in core_commands[level]:
		fptr_name = 'PFN_' + command
		member_name = command[2].lower() + command[3:]
		declaration += '\t' + fptr_name + ' ' + member_name + ' = nullptr;\n'
		loading += '\t\t' + member_name + ' = (' + fptr_name + ')procAddr(device, "' + command + '");\n'
	declaration += '#endif\n'
	loading += '#endif\n'

for extension in extension_commands:
	if len(extension_commands[extension]) > 0:
		declaration += '#if defined(' + extension[0] + ') && defined(' + extension[1] + ')\n';
		loading += '#if defined(' + extension[0] + ') && defined(' + extension[1] + ')\n';
		for command in extension_commands[extension]:
			fptr_name = 'PFN_' + command
			member_name = command[2].lower() + command[3:]
			#Duplication guards
			declaration += '#ifndef ' + fptr_name + '_DECLARE\n'
			declaration += '#define ' + fptr_name + '_DECLARE\n'
			declaration += '\t' + fptr_name + ' ' + member_name + ' = nullptr;\n'
			declaration += '#endif\n'
			#Duplication guards
			loading += '#ifndef ' + fptr_name + '_LOAD\n'
			loading += '#define ' + fptr_name + '_LOAD\n'
			loading += '\t\t' + member_name + ' = (' + fptr_name + ')procAddr(device, "' + command + '");\n'
			loading += '#endif\n'
		declaration += '#endif\n'
		loading += '#endif\n'

header += loading
header += '\t}\n'
header += declaration
header += '};\n\n'
header += '} // namespace vkb'

header_file = open("../src/VkDispatchTable.h", "w")
header_file.write(header)
header_file.close();

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