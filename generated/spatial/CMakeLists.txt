# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2025-2026 Johannes Lochmann
# GENERATED FILE -- DO NOT EDIT

add_library(muscovite_harbor_spatial_dba STATIC)
target_include_directories(muscovite_harbor_spatial_dba PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(muscovite_harbor_spatial_dba PUBLIC
    muscovite::dba
)

set(muscovite_harbor_spatial_dba_HEADERS
    dba/vo/geo_point.hpp
    dba/vo/geo_polygon.hpp
    dba/vo/geo_line_string.hpp
    dba/vo/geo_region.hpp
    dba/vo/geo_crs.hpp
)

target_sources(muscovite_harbor_spatial_dba PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/..
    FILES ${muscovite_harbor_spatial_dba_HEADERS}
)
