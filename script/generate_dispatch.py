
#https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/master/registry/vk.xml

#exclusions
exclusions = [
	'vkGetDeviceProcAddr',
	'vkCreateDevice',
	'vkDestroyDevice'
]

#formatting functions
def format_header_top(header: str):
	header += '\n#pragma once\n\n#include <vulkan/vulkan.h>\n\n'
	header += 'namespace vkb {\n\n'
	header += 'struct DispatchTable {\n'
	header += '\tDispatchTable() = default;\n'
	header += '\tDispatchTable(VkDevice const& device, PFN_vkGetDeviceProcAddr const& procAddr) {\n'
	return header;

def format_header_mid(header: str):
	header += '\t}\n'
	return header;

def format_header_bottom(header: str):
	header += '}\n\n'
	header += '} // namespace vkb'
	return header;

def format_declaration(header: str, name):
	fptr_name = 'PFN_' + name
	member_name = name[2].lower() + name[3:]
	header += '\t' + fptr_name + ' ' + member_name + ' = nullptr;\n'
	if name in device_aliases:
		header = format_declaration(header, device_aliases[name])
	return header;

def format_load(header: str, name):
	fptr_name = 'PFN_' + name
	member_name = name[2].lower() + name[3:]
	header += '\t\t' + member_name + ' = (' + fptr_name + ')procAddr(device, "' + name + '");\n'
	return header;

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

commands = vk_xml['registry']['commands']['command']
extensions = vk_xml['registry']['extensions']['extension']

device_commands = {};

extension_commands = {};

for extension in extensions:
	extension_name = extension['@name']
	for key in extension.keys():
		if key == 'require':
			requires = [extension[key]]
			for required in requires:
				if type(required) is list:
					for nested_required in required:
						if '@feature' in nested_required and 'command' in nested_required:
							extension_commands[(extension_name, nested_required['@feature'])] = []
							commands = [nested_required['command']]
							for command in commands:
								if type(command) is list:
									for nested_command in command:
										extension_commands[(extension_name, nested_required['@feature'])] += [nested_command['@name']]
								else:
									extension_commands[(extension_name, nested_required['@feature'])] += [command['@name']]
				elif 'command' in required:
					commands = [required['command']]

print(extension_commands)

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