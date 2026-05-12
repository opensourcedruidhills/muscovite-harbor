// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

# gcov coverage targets for MuscoviteHarbor / spatial

# Aggregate coverage target: collects gcov data for all entities
add_custom_target(coverage-gcov-spatial
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/coverage
    COMMAND gcov -b -c ${CMAKE_BINARY_DIR}/CMakeFiles/*.dir/**/*.gcno
    COMMAND ${CMAKE_COMMAND} -E echo "gcov coverage collected for spatial"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
    COMMENT "Collecting gcov coverage for context spatial"
)

# Compiler flags required for gcov instrumentation
# target_compile_options(<target> PRIVATE --coverage)
# target_link_options(<target> PRIVATE --coverage)
