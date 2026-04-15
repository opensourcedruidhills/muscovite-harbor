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

    Pure consumer of the Muscovite framework via Conan. Domain model is
    defined in .mus/.ddd files and compiled by muscomp into generated C++,
    SQL, Proto, and QML artifacts.

    All transitive dependencies (spdlog, grpc, protobuf, libpqxx, etc.)
    are pulled automatically through the muscovite package. Only declare
    direct dependencies here that are NOT part of muscovite.
    """

    name = "muscovite_harbor"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        # Muscovite framework — ships C++ runtime libraries, PEG grammar,
        # reference docs, and relocatable lint tool.
        # All transitive deps (spdlog, grpc, protobuf, libpqxx, etc.)
        # are resolved automatically by Conan.
        self.requires("muscovite/2.24.0")

        # Testing (not shipped by muscovite)
        self.requires("doctest/2.4.11")

    def layout(self):
        cmake_layout(self)
