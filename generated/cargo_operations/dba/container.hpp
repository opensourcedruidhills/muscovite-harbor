#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include <boost/uuid/uuid.hpp>
#include <string>
#include <string>

namespace cargo_operations {

/// A shipping container in terminal operations
struct Container {
    using Id = boost::uuids::uuid;

    Id id{};
    ContainerNumber container_number{};
    std::string size_category{};
    std::string hazmat_class{};
    boost::uuids::uuid voyage_id{};
    boost::uuids::uuid yard_slot_id{};
    std::string status{};

    [[nodiscard]] auto get_id() const noexcept -> const Id& { return id; }
    [[nodiscard]] auto get_container_number() const noexcept -> const ContainerNumber& { return container_number; }
    [[nodiscard]] auto get_size_category() const noexcept -> const std::string& { return size_category; }
    [[nodiscard]] auto get_hazmat_class() const noexcept -> const std::string& { return hazmat_class; }
    [[nodiscard]] auto get_voyage_id() const noexcept -> const boost::uuids::uuid& { return voyage_id; }
    [[nodiscard]] auto get_yard_slot_id() const noexcept -> const boost::uuids::uuid& { return yard_slot_id; }
    [[nodiscard]] auto get_status() const noexcept -> const std::string& { return status; }
};

} // namespace cargo_operations
