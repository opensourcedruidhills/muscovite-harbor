#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container.hpp"
#include "container_event_repository.hpp"
#include "container_query_service.hpp"
#include "muscovite/dba/unit_of_work.hpp"
#include "policy/policies.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace cargo_operations {

struct PlaceContainerDecision {
    std::vector<ContainerPlaced> events;
    std::vector<EffectIntent> effects;
    bool ok{true};
};

struct PickContainerDecision {
    std::vector<ContainerPicked> events;
    std::vector<EffectIntent> effects;
    bool ok{true};
};

/// Domain service for Container aggregate.
/// Orchestrates three-tier validation pipeline and delegates to
/// CommandService (writes) and QueryService (reads).
class ContainerDomainService {
public:
    explicit ContainerDomainService(ContainerEventRepository& event_repository, ContainerQueryService& query_service, UnitOfWork& unit_of_work
    )
        : event_repository_{event_repository}
        , query_service_{query_service}
        , unit_of_work_{unit_of_work}
        {}

    // Command operations (write side)
    auto create(const Container& entity) -> void;
    auto update(const Container& entity) -> void;
    auto remove(const Container::Id& id) -> void;
    auto place_container(const Container::Id& id, const boost::uuids::uuid& slot_id, const std::int32_t& tier) -> void;
    [[nodiscard]] auto decide_place_container(const Container& entity) const -> PlaceContainerDecision;
    auto pick_container(const Container::Id& id, const boost::uuids::uuid& picked_by) -> void;
    [[nodiscard]] auto decide_pick_container(const Container& entity) const -> PickContainerDecision;

    // Query operations (read side — pass-through)
    [[nodiscard]] auto find_by_id(const Container::Id& id) -> std::optional<Container>;
    [[nodiscard]] auto find_all() -> std::vector<Container>;

private:
    ContainerEventRepository& event_repository_;
    ContainerQueryService& query_service_;
    UnitOfWork& unit_of_work_;
    PolicyRegistry policy_registry_;
};

} // namespace cargo_operations
