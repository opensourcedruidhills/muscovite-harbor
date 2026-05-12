#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>
#include <vector>

namespace passenger_terminal {

/// Repository interface for Gate.
class GateRepository {
public:
    virtual ~GateRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const std::string& id) const
        -> std::optional<Gate> = 0;

    [[nodiscard]] virtual auto find_all() const
        -> std::vector<Gate> = 0;

    virtual auto save(const Gate& entity) -> void = 0;

    virtual auto remove(const std::string& id) -> void = 0;

    [[nodiscard]] virtual auto find_by_code(const std::string& code) const
        -> std::optional<Gate> = 0;
};

} // namespace passenger_terminal
