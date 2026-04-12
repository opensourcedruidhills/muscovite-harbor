# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2026 Johannes Lochmann

add_executable(harbor-tests
    harbor_smoke_test.cpp
)

target_link_libraries(harbor-tests PRIVATE
    doctest::doctest
    spdlog::spdlog
)

target_include_directories(harbor-tests PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/../generated
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/src
)

include(doctest)
doctest_discover_tests(harbor-tests)
