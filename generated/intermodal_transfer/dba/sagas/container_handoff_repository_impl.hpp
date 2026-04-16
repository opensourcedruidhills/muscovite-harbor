#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_handoff_repository.hpp"
#include <stdexcept>
#include <string>

namespace intermodal_transfer {

/// pqxx-based command repository for ContainerHandoff saga.
/// Uses direct SQL — no stored procedures (ADR 20260120).
template<typename Connection>
class ContainerHandoffCommandRepositoryImpl : public ContainerHandoffCommandRepository {
public:
    explicit ContainerHandoffCommandRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto start(const ContainerHandoffData& data) -> std::string override {
        auto tx = conn_.begin();
        tx.exec_params(
            "INSERT INTO intermodal_transfer.container_handoff_saga "
            "(id, status, current_step, payload, created_at, updated_at) "
            "VALUES ($1, 'pending', $2, $3, NOW(), NOW())",
            data.saga_id, "ReserveYardExit", data.payload);
        tx.commit();
        return data.saga_id;
    }

    auto advance(const std::string& saga_id, const std::string& step) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(
            "UPDATE intermodal_transfer.container_handoff_saga "
            "SET current_step = $2, status = 'in_progress', updated_at = NOW() WHERE id = $1",
            saga_id, step);
        tx.commit();
    }

    auto complete(const std::string& saga_id) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(
            "UPDATE intermodal_transfer.container_handoff_saga "
            "SET status = 'completed', updated_at = NOW() WHERE id = $1",
            saga_id);
        tx.commit();
    }

    auto fail(const std::string& saga_id, const std::string& reason) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(
            "UPDATE intermodal_transfer.container_handoff_saga "
            "SET status = 'failed', updated_at = NOW() WHERE id = $1",
            saga_id);
        tx.commit();
    }

    auto log_step(const ContainerHandoffStepLogEntry& entry) -> void override {
        auto tx = conn_.begin();
        tx.exec_params(
            "INSERT INTO intermodal_transfer.container_handoff_step_log "
            "(saga_id, step_name, status, result, started_at, completed_at) "
            "VALUES ($1, $2, $3, $4, NOW(), NOW())",
            entry.saga_id, entry.step_name, entry.status,
            entry.result.value_or(""));
        tx.commit();
    }

    auto log_compensation(const ContainerHandoffStepLogEntry& entry) -> void override {
        log_step(entry); // Compensation logged as regular step entry
    }

private:
    Connection& conn_;
};

/// pqxx-based query repository for ContainerHandoff saga.
template<typename Connection>
class ContainerHandoffQueryRepositoryImpl : public ContainerHandoffQueryRepository {
public:
    explicit ContainerHandoffQueryRepositoryImpl(Connection& conn) : conn_{conn} {}

    [[nodiscard]] auto find_by_id(const std::string& saga_id) -> std::optional<ContainerHandoffInstance> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params(
            "SELECT id, status, current_step, payload, created_at, updated_at "
            "FROM intermodal_transfer.container_handoff_saga WHERE id = $1",
            saga_id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        // TODO: map result row to ContainerHandoffInstance
        return ContainerHandoffInstance{.id = saga_id};
    }

    [[nodiscard]] auto find_timed_out(std::chrono::seconds threshold) -> std::vector<ContainerHandoffInstance> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params(
            "SELECT id FROM intermodal_transfer.container_handoff_saga "
            "WHERE status = 'in_progress' AND created_at < NOW() - $1 * interval '1 second'",
            threshold.count());
        tx.commit();
        auto instances = std::vector<ContainerHandoffInstance>{};
        for (const auto& row : result) {
            instances.push_back(ContainerHandoffInstance{.id = row[0].as<std::string>()});
        }
        return instances;
    }

    [[nodiscard]] auto get_step_log(const std::string& saga_id) -> std::vector<ContainerHandoffStepLogEntry> override {
        auto tx = conn_.begin();
        auto result = tx.exec_params(
            "SELECT saga_id, step_name, status, result, started_at, completed_at "
            "FROM intermodal_transfer.container_handoff_step_log WHERE saga_id = $1 ORDER BY started_at",
            saga_id);
        tx.commit();
        auto entries = std::vector<ContainerHandoffStepLogEntry>{};
        // TODO: map result rows to StepLogEntry
        return entries;
    }

private:
    Connection& conn_;
};

} // namespace intermodal_transfer
