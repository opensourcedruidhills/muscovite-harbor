# SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
# Copyright (c) 2025-2026 Johannes Lochmann
# GENERATED FILE -- DO NOT EDIT

add_library(muscovite_harbor_security_dba INTERFACE)
target_include_directories(muscovite_harbor_security_dba INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Header-only library: list headers for IDE integration
set(muscovite_harbor_security_dba_HEADERS
    dba/user.hpp
    dba/user_repository.hpp
    dba/user_role.hpp
    dba/user_role_repository.hpp
    dba/role.hpp
    dba/role_repository.hpp
    dba/permission.hpp
    dba/permission_repository.hpp
    dba/access_control_entry.hpp
    dba/access_control_entry_repository.hpp
    dba/audit_log_entry.hpp
    dba/audit_log_entry_repository.hpp
    dba/vo/principal.hpp
    dba/vo/resource_identifier.hpp
    dba/lookup/effect.hpp
    dba/lookup/audit_action.hpp
)

target_sources(muscovite_harbor_security_dba INTERFACE
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/..
    FILES ${muscovite_harbor_security_dba_HEADERS}
)
