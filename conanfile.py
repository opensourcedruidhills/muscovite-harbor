# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
from conan import ConanFile
from conan.tools.cmake import cmake_layout


class MuscoviteHarborConan(ConanFile):
    name = "muscovite_harbor"
    version = "0.2.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("muscovite/2.25.9")

    def build_requirements(self):
        self.tool_requires("muscomp/2.25.9")

    def layout(self):
        cmake_layout(self)
