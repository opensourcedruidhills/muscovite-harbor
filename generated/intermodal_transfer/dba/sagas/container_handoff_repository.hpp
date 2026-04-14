#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_handoff_structs.hpp"
#include <optional>
#include <string>
#include <vector>

namespace intermodal_transfer {

/// Command repository for ContainerHandoff saga lifecycle operations.
class ContainerHandoffCommandRepository {
public:
    virtual ~ContainerHandoffCommandRepository() = default;

    virtual auto start(const ContainerHandoffData& data) -> std::string = 0;
    virtual auto advance(const std::string& saga_id, const std::string& step) -> void = 0;
    virtual auto complete(const std::string& saga_id) -> void = 0;
    virtual auto fail(const std::string& saga_id, const std::string& reason) -> void = 0;
    virtual auto log_step(const ContainerHandoffStepLogEntry& entry) -> void = 0;
    virtual auto log_compensation(const ContainerHandoffStepLogEntry& entry) -> void = 0;
};

/// Query repository for ContainerHandoff saga state retrieval.
class ContainerHandoffQueryRepository {
public:
    virtual ~ContainerHandoffQueryRepository() = default;

    [[nodiscard]] virtual auto find_by_id(const std::string& saga_id) -> std::optional<ContainerHandoffInstance> = 0;
    [[nodiscard]] virtual auto find_by_correlation(const std::string& correlation_id) -> std::vector<ContainerHandoffInstance> = 0;
    [[nodiscard]] virtual auto find_timed_out(std::chrono::seconds threshold) -> std::vector<ContainerHandoffInstance> = 0;
    [[nodiscard]] virtual auto get_step_log(const std::string& saga_id) -> std::vector<ContainerHandoffStepLogEntry> = 0;
};

} // namespace intermodal_transfer
