# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2026 Johannes Lochmann
#
# This software is dual-licensed:
#  - GNU Affero General Public License v3 (AGPL-3.0), see LICENSE-AGPL
#  - Commercial license, contact muscovite-licensing@johanneslochmann.net

# Version.cmake
# Version header generation from Git

# Get Git SHA
execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_SHA
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)
if(NOT GIT_SHA)
    set(GIT_SHA "unknown")
endif()

# Build timestamp (ISO 8601 UTC)
string(TIMESTAMP BUILD_TIMESTAMP "%Y-%m-%dT%H:%M:%SZ" UTC)

# Derive a safe namespace and header subdirectory from project name
if(NOT DEFINED VERSION_NAMESPACE)
    set(_version_namespace "${PROJECT_NAME}")
    string(REPLACE "-" "_" _version_namespace "${_version_namespace}")
    string(REPLACE " " "_" _version_namespace "${_version_namespace}")
    set(VERSION_NAMESPACE "${_version_namespace}" CACHE INTERNAL "")
endif()

set(VERSION_HEADER_SUBDIR "${VERSION_NAMESPACE}" CACHE INTERNAL "")
set(PROJECT_VERSION_HEADER_DIR "${CMAKE_BINARY_DIR}/generated/${VERSION_HEADER_SUBDIR}" CACHE INTERNAL "")
set(PROJECT_VERSION_HEADER "${PROJECT_VERSION_HEADER_DIR}/version.hpp" CACHE INTERNAL "")

# Generate version header
configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/version.hpp.in
    ${PROJECT_VERSION_HEADER}
    @ONLY
)

# Make generated headers available
set(PROJECT_GENERATED_INCLUDE_DIR ${CMAKE_BINARY_DIR}/generated CACHE INTERNAL "")
