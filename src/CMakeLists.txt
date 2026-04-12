# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2026 Johannes Lochmann

# Hand-written application sources.
# Generated sources live in generated/src/ and are added by the top-level CMakeLists.txt.

add_executable(harbor-server
    main.cpp
)

target_link_libraries(harbor-server PRIVATE
    spdlog::spdlog
    nlohmann_json::nlohmann_json
)

# Link muscovite framework when available
if(TARGET muscovite::dba)
    target_link_libraries(harbor-server PRIVATE muscovite::dba)
endif()
if(TARGET muscovite::server)
    target_link_libraries(harbor-server PRIVATE muscovite::server)
endif()
if(TARGET muscovite::grpc)
    target_link_libraries(harbor-server PRIVATE muscovite::grpc)
endif()

target_include_directories(harbor-server PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/../generated
    ${CMAKE_CURRENT_SOURCE_DIR}/../generated/src
)
