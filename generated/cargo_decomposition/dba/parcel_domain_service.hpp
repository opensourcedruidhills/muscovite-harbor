#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "parcel.hpp"
#include "parcel_command_service.hpp"
#include "parcel_query_service.hpp"
#include "muscovite/dba/unit_of_work.hpp"
#include "policy/policies.hpp"
#include "delivery_unit.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace cargo_decomposition {

/// Domain service for Parcel aggregate.
/// Orchestrates three-tier validation pipeline and delegates to
/// CommandService (writes) and QueryService (reads).
class ParcelDomainService {
public:
    explicit ParcelDomainService(ParcelCommandService& command_service, ParcelQueryService& query_service, UnitOfWork& unit_of_work
    , EventPublisher* publisher = nullptr
    , CommandDispatcher* cmd_disp = nullptr
    , NotificationSender* notifier = nullptr
    , ServiceCaller* caller = nullptr
    )
        : command_service_{command_service}
        , query_service_{query_service}
        , unit_of_work_{unit_of_work}
    , policy_registry_{publisher, cmd_disp, notifier, caller}
        {}

    // Command operations (write side)
    auto create(const Parcel& entity) -> void;
    auto update(const Parcel& entity) -> void;
    auto remove(const Parcel::Id& id) -> void;

    // Query operations (read side — pass-through)
    [[nodiscard]] auto find_by_id(const Parcel::Id& id) -> std::optional<Parcel>;
    [[nodiscard]] auto find_all() -> std::vector<Parcel>;

    // DeliveryUnit child entity operations
    auto add_delivery_unit(const Parcel::Id& parent_id, const DeliveryUnit& child) -> void;
    auto remove_delivery_unit(const Parcel::Id& parent_id, const DeliveryUnit::Id& child_id) -> void;

private:
    ParcelCommandService& command_service_;
    ParcelQueryService& query_service_;
    UnitOfWork& unit_of_work_;
    PolicyRegistry policy_registry_;
};

} // namespace cargo_decomposition
