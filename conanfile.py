# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2026 Johannes Lochmann
#
# This software is dual-licensed:
#  - GNU Affero General Public License v3 (AGPL-3.0), see LICENSE-AGPL
#  - Commercial license, contact muscovite-licensing@johanneslochmann.net

from conan import ConanFile
from conan.tools.cmake import cmake_layout


class MuscoviteHarborConan(ConanFile):
    """Muscovite Harbor — Port & Maritime Operations Management.

    Pure consumer of the Muscovite framework. Domain model is defined
    in .mus/.ddd files and compiled by muscomp into generated C++, SQL,
    Proto, and QML artifacts.
    """

    name = "muscovite_harbor"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        # Muscovite framework (C++ runtime libraries)
        self.requires("muscovite/2.23.0")

        # Direct dependencies (also pulled transitively by muscovite,
        # but declared explicitly for version pinning)
        self.requires("spdlog/1.15.0")
        self.requires("nlohmann_json/3.11.3")
        self.requires("libpqxx/8.0.0")
        self.requires("libpq/17.7")

        # gRPC stack
        self.requires("grpc/1.70.0")
        self.requires("protobuf/5.29.3")

        # Testing
        self.requires("doctest/2.4.11")

    def layout(self):
        cmake_layout(self)
