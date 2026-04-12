# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2026 Johannes Lochmann
#
# This software is dual-licensed:
#  - GNU Affero General Public License v3 (AGPL-3.0), see LICENSE-AGPL
#  - Commercial license, contact muscovite-licensing@johanneslochmann.net

cmake_minimum_required(VERSION 3.28)
project(harbor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ── Hardened stdlib (FTR-687) ──────────────────────────────────────
add_compile_definitions(_GLIBCXX_ASSERTIONS)

# ── Version provenance ────────────────────────────────────────────
include(cmake/Version.cmake)

# ── Framework resolution ─────────────────────────────────────────
# Four-tier discovery:
#   1. In-tree target (monorepo subproject)
#   2. find_package(muscovite) — installed package
#   3. MUSCOVITE_DIR env var override
#   4. FetchContent fallback from GitHub
find_package(muscovite QUIET)
if(NOT muscovite_FOUND)
    if(DEFINED ENV{MUSCOVITE_DIR})
        list(PREPEND CMAKE_PREFIX_PATH $ENV{MUSCOVITE_DIR})
    endif()
    find_package(muscovite-cpp QUIET)
    if(NOT muscovite-cpp_FOUND)
        include(FetchContent)
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/MUSCOVITE_CPP_VERSION")
            file(READ "${CMAKE_CURRENT_SOURCE_DIR}/MUSCOVITE_CPP_VERSION" _mcpp_version)
            string(STRIP "${_mcpp_version}" _mcpp_version)
        else()
            message(WARNING "MUSCOVITE_CPP_VERSION not found, using main branch")
            set(_mcpp_version "main")
        endif()
        FetchContent_Declare(muscovite-cpp
            GIT_REPOSITORY https://github.com/opensourcedruidhills/muscovite.git
            GIT_TAG ${_mcpp_version}
            GIT_SHALLOW TRUE)
        FetchContent_MakeAvailable(muscovite-cpp)
    endif()
endif()

# ── Dependencies ────────────────────────────────────────────────
find_package(spdlog REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(doctest REQUIRED)
find_package(libpqxx REQUIRED)

# ── Proto / gRPC (if generated) ──────────────────────────────────
find_package(gRPC QUIET)
find_package(protobuf QUIET)

# ── Qt (if generated) ────────────────────────────────────────────
find_package(Qt6 QUIET COMPONENTS Core Widgets)

# ── Generated sources (checked in — ADR-004) ────────────────────
# muscomp output is committed to the repo. muscomp is NOT a build
# dependency — it is only needed when changing .ddd/.mus files.
# See tools/regenerate.sh for the dev-time workflow.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/generated/src/CMakeLists.txt")
    add_subdirectory(generated/src)
endif()

# ── Application sources ──────────────────────────────────────────
add_subdirectory(src)

# ── Tests ─────────────────────────────────────────────────────────
enable_testing()
add_subdirectory(tests)
