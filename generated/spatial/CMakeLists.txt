# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2025-2026 Johannes Lochmann
# GENERATED FILE -- DO NOT EDIT

add_library(muscovite_harbor_spatial_dba INTERFACE)
target_include_directories(muscovite_harbor_spatial_dba INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Header-only library: list headers for IDE integration
set(muscovite_harbor_spatial_dba_HEADERS
    dba/coordinate.hpp
    dba/coordinate_repository.hpp
    dba/region.hpp
    dba/region_repository.hpp
    dba/spatial_projection.hpp
    dba/spatial_projection_repository.hpp
    dba/vo/bounding_box.hpp
    dba/vo/geo_point.hpp
    dba/lookup/coordinate_system.hpp
)

target_sources(muscovite_harbor_spatial_dba INTERFACE
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/..
    FILES ${muscovite_harbor_spatial_dba_HEADERS}
)
