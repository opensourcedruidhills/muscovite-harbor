#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <array>
#include <cstdint>
#include <iostream>
#include <string>

namespace spatial {

/// Branch count constants per entity (DECIDE block analysis).

/// Tracks branch coverage for DECIDE block testing.
template<int BranchCount>
class BranchTracker {
public:
    /// Mark a branch as exercised.
    auto mark(int branch_id) -> void {
        if (branch_id >= 0 && branch_id < BranchCount) {
            branches_[static_cast<std::size_t>(branch_id)] = true;
        }
    }

    /// Calculate coverage percentage.
    [[nodiscard]] auto coverage_pct() const -> double {
        if constexpr (BranchCount == 0) { return 100.0; }
        auto covered = 0;
        for (auto b : branches_) { if (b) { ++covered; } }
        return 100.0 * static_cast<double>(covered) / BranchCount;
    }

    /// Print a human-readable coverage report.
    auto report(const std::string& entity_name) const -> void {
        std::cout << entity_name << " coverage: "
                  << coverage_pct() << "% ("
                  << covered_count() << "/" << BranchCount << ")\n";
    }

    /// Number of exercised branches.
    [[nodiscard]] auto covered_count() const -> int {
        auto count = 0;
        for (auto b : branches_) { if (b) { ++count; } }
        return count;
    }

private:
    std::array<bool, BranchCount> branches_{};
};

} // namespace spatial
