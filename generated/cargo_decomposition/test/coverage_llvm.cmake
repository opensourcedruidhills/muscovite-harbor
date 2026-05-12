// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

# llvm-cov coverage targets for MuscoviteHarbor / CargoDecomposition

# Aggregate: merge all profraw data and produce summary report
add_custom_target(coverage-llvm-cargo_decomposition
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/profiles
    COMMAND llvm-profdata merge -sparse ${CMAKE_BINARY_DIR}/profiles/*.profraw
            -o ${CMAKE_BINARY_DIR}/profiles/merged.profdata
    COMMAND llvm-cov report ${CMAKE_BINARY_DIR}/$<TARGET_FILE_NAME:${PROJECT_NAME}_tests>
            -instr-profile=${CMAKE_BINARY_DIR}/profiles/merged.profdata
    COMMAND llvm-cov show ${CMAKE_BINARY_DIR}/$<TARGET_FILE_NAME:${PROJECT_NAME}_tests>
            -instr-profile=${CMAKE_BINARY_DIR}/profiles/merged.profdata
            -format=html -output-dir=${CMAKE_BINARY_DIR}/coverage-html/cargo_decomposition
    COMMENT "Generating llvm-cov report for context CargoDecomposition"
)

# Compiler flags required for LLVM source-based coverage
# target_compile_options(<target> PRIVATE -fprofile-instr-generate -fcoverage-mapping)
# target_link_options(<target> PRIVATE -fprofile-instr-generate)
