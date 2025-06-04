from conans import ConanFile


class VkBootstrapConan(ConanFile):
    name = "vk-bootstrap"
    version = "1.3.283"
    url = "https://github.com/Esri/vk-bootstrap/blob/runtimecore/"
    license = "https://github.com/Esri/vk-bootstrap/blob/runtimecore/LICENSE.md"
    description = "A utility library that jump starts initialization of Vulkan"

    # RTC specific triple
    settings = "platform_architecture_target"

    def package(self):
        base = self.source_folder + "/"
        relative = "3rdparty/vk-bootstrap/"

        # headers
        self.copy("*.h*", src=base, dst=relative)

        # libraries
        output = "output/" + str(self.settings.platform_architecture_target) + "/staticlib"
        self.copy("*" + self.name + "*", src=base + "../../" + output, dst=output)
