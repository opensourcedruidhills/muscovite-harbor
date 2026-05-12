#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace security {

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
        {"User", 0, 4, false},
        {"UserRole", 0, 2, false},
        {"Role", 0, 3, false},
        {"Permission", 0, 3, false},
        {"AccessControlEntry", 0, 4, false},
        {"AuditLogEntry", 0, 5, false},
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

} // namespace security
