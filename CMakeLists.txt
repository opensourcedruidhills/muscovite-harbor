# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2026 Johannes Lochmann
#
# This software is dual-licensed:
#  - GNU Affero General Public License v3 (AGPL-3.0), see LICENSE-AGPL
#  - Commercial license, contact muscovite-licensing@johanneslochmann.net

cmake_minimum_required(VERSION 3.28)
project(harbor VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ── Hardened stdlib (FTR-687) ──────────────────────────────────────
add_compile_definitions(_GLIBCXX_ASSERTIONS)

# ── Version provenance ────────────────────────────────────────────
include(cmake/Version.cmake)

# ── Framework resolution ─────────────────────────────────────────
# Muscovite comes from Conan. After find_package, these CMake variables
# are available:
#   MUSCOVITE_GRAMMAR_DIR  — directory containing muscovite.peg
#   MUSCOVITE_DOC_DIR      — GROUND-TRUTH.md, IR-CHEATSHEET.md
#   MUSCOVITE_TOOLS_DIR    — relocatable lint-ddd.sh
#   MUSCOVITE_MUSCOMP_DIR  — muscomp binary (if installed)
find_package(muscovite REQUIRED)

# ── Dependencies ────────────────────────────────────────────────
# spdlog, nlohmann_json, libpqxx, etc. are pulled transitively by
# muscovite via Conan. Only declare non-transitive deps here.
find_package(doctest REQUIRED)

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
