#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace cargo_operations {

/// Per-entity coverage tracking record.
struct EntityCoverageEntry {
    std::string_view entity_name;
    int branch_count = 0;
    int field_count = 0;
    bool has_commands = false;
    double covered_pct = 0.0;
};

/// Minimum coverage threshold (configurable per module).
inline constexpr double COVERAGE_THRESHOLD_PCT = 80.0;
inline constexpr bool FAIL_ON_BELOW_THRESHOLD = true;

/// Static entity registry for coverage tracking.
[[nodiscard]] inline auto entity_coverage_registry()
    -> std::vector<EntityCoverageEntry> {
    return {
        {"Container", 0, 7, false},
        {"YardSlot", 0, 6, false},
        {"Crane", 0, 5, false},
        {"ReeferUnit", 0, 5, false},
        {"LoadPlan", 0, 4, false},
        {"DischargeSequence", 0, 5, true},
    };
}

/// Check if all entities meet the coverage threshold.
[[nodiscard]] inline auto check_coverage_threshold(
    const std::vector<EntityCoverageEntry>& entries) -> bool {
    auto all_pass = true;
    for (const auto& e : entries) {
        if (e.covered_pct < COVERAGE_THRESHOLD_PCT) {
            std::cout << "BELOW THRESHOLD: " << e.entity_name
                      << " (" << e.covered_pct << "% < "
                      << COVERAGE_THRESHOLD_PCT << "%)\n";
            all_pass = false;
        }
    }
    return all_pass;
}

} // namespace cargo_operations
