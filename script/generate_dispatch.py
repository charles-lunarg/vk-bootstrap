
#https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/master/registry/vk.xml

import urllib.request
import xmltodict

with urllib.request.urlopen('https://raw.githubusercontent.com/KhronosGroup/Vulkan-Headers/master/registry/vk.xml') as response:
   vk_xml_raw = response.read()

vk_xml = xmltodict.parse(vk_xml_raw)

commands = vk_xml['registry']['commands']

device_commands = []

for command in commands:
	if(command['command']['proto'])
	print(command['command']['proto']['name'])