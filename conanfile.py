import os
 
from conans import ConanFile, CMake, tools

def get_verion_tag():
    git = tools.Git("stonex-cms-amqp-test-cases")
    try:
        return "%s" % (git.get_tag())
    except Exception as e:
        return e
        
class StonexCMSAMQPTestCases(ConanFile):
    name = "stonex-cms-amqp-test-cases"
    version = get_verion_tag()
    license = "<Put the package license here>"
    author = "krzysztof.obrebski@stonex.com"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "cms client core test"
    topics = ("cms","amqp")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    generators = "cmake"
    

    def build_requirements(self):
        self.build_requires("stonex-cms-amqp-test-engine/2.0.0@enterprise_messaging/test")
        self.build_requires("protobuf/3.20.1@enterprise_messaging/test")
        self.build_requires("fmt/9.1.0@enterprise_messaging/test")
        self.build_requires("boost/1.78.0@enterprise_messaging/stable")
        self.build_requires("stonex-logger-wrapper/0.0.2@enterprise_messaging/test")
        self.build_requires("stonex-cms-amqp-lib/0.2.3@enterprise_messaging/test")

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC
        if self.settings.arch == "x86":
            self.options["protobuf"].use_32_time_t = True

    def source(self):
         self.run("git clone https://github.com/StoneXLabs/stonex-cms-amqp-test-cases.git")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()


    def package(self):
        self.copy("*.h", dst="include",src="CoreTests\include")
        self.copy("*.lib", dst="lib",src="lib", keep_path=False)
        self.copy("*.pdb", dst="lib",src="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = self.collect_libs()

    
