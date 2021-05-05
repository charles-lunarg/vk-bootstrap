
#https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/master/registry/vk.xml

import urllib.request
import xmltodict

with urllib.request.urlopen('https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/master/registry/vk.xml') as response:
   vk_xml_raw = response.read()

vk_xml = xmltodict.parse(vk_xml_raw,process_namespaces=True)

commands = vk_xml['registry']['commands']['command']

device_commands = [];
device_aliases = {};

def format_header_top(header: str):
	header += '\n#pragma once\n\n#include <vulkan/vulkan.h>\n\n'
	header += 'namespace vkb {\n\n'
	header += 'struct DispatchTable {\n'
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

for command in commands:
	keys = command.keys()
	if 'proto' in keys and 'param' in keys:
		type_device = False;
		for p in command['param']:
			if 'type' in p:
				for t in p:
					if t == 'type' and p[t] == 'VkDevice':
						#only check first type
						type_device = True;
						break;
		if type_device and command['proto']['name'] != 'vkGetDeviceProcAddr':
			device_commands += [command['proto']['name']]
	elif '@alias'in keys:
		device_aliases[(command['@alias'])] = command['@name'];

header = ''
header = format_header_top(header)
for command in device_commands:
	header = format_declaration(header, command);
header = format_header_bottom(header)

header_file = open("../src/VkDispatchTable.h", "w")
header_file.write(header)
header_file.close();