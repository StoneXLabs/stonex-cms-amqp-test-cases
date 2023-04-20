import os
 
from conans import ConanFile, CMake, tools

class StonexCMSAMQPTestCases(ConanFile):
    name = "stonex-cms-amqp-test-cases"
    version = "0.0.1"
    license = "<Put the package license here>"
    author = "krzysztof.obrebski@stonex.com"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "cms client core test"
    topics = ("cms","amqp")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    requires = ["stonex-cms-amqp-test-framework/0.0.1@enterprise_messaging/test"]
    generators = "cmake"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def source(self):
        pass

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()


    def package(self):
        self.copy("*.h", dst="include",src="include")
        self.copy("*.lib", dst="lib",src="lib", keep_path=False)
        self.copy("*.pdb", dst="lib",src="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = self.collect_libs()
        pass

    
