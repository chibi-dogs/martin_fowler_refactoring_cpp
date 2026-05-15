from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps, cmake_layout

class TeeworldsDeps(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("nlohmann_json/[>=3.12.0]")
        self.requires("gtest/1.17.0")
    def layout(self):
        cmake_layout(self)
