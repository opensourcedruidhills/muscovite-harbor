#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <optional>
#include <string>

namespace cargo_decomposition {

/// Unified DBA struct for DeliveryUnit.
struct DeliveryUnit {
    boost::uuids::uuid id{};
    TrackingNumber tracking_number{};
    std::string destination{};
    std::string carrier{};
    muscovite::dba::Timestamp dispatched_at{};

    /// Construct from a database row.
    static auto from_row(const pqxx::row& row) -> DeliveryUnit {
        return DeliveryUnit{
            .id = row[0].as<std::string>(),
            .tracking_number = row[1].as<std::string>(),
            .destination = row[2].as<std::string>(),
            .carrier = row[3].as<std::string>(),
            .dispatched_at = row[4].as<std::string>(),
        };
    }

    /// Try to construct; returns nullopt on missing required field.
    static auto try_from(const pqxx::row& row) -> std::optional<DeliveryUnit> {
        if (row[0].is_null()) return std::nullopt;
        if (row[1].is_null()) return std::nullopt;
        if (row[2].is_null()) return std::nullopt;
        if (row[3].is_null()) return std::nullopt;
        return from_row(row);
    }
};

} // namespace cargo_decomposition
