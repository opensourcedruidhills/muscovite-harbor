// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

# gcov coverage targets for MuscoviteHarbor / VesselTraffic

# Aggregate coverage target: collects gcov data for all entities
add_custom_target(coverage-gcov-vessel_traffic
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/coverage
    COMMAND gcov -b -c ${CMAKE_BINARY_DIR}/CMakeFiles/*.dir/**/*.gcno
    COMMAND ${CMAKE_COMMAND} -E echo "gcov coverage collected for VesselTraffic"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
    COMMENT "Collecting gcov coverage for context VesselTraffic"
)

# Coverage target for entity: TideWindow
add_custom_target(coverage-gcov-tide_window
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/coverage/tide_window
    COMMAND gcov -b -c ${CMAKE_BINARY_DIR}/CMakeFiles/*.dir/**/*.gcno
    COMMAND ${CMAKE_COMMAND} -E echo "gcov coverage collected for TideWindow"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage/tide_window
    COMMENT "Collecting gcov coverage for TideWindow"
)

# Compiler flags required for gcov instrumentation
# target_compile_options(<target> PRIVATE --coverage)
# target_link_options(<target> PRIVATE --coverage)
