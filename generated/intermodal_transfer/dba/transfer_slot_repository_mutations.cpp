// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "transfer_slot_repository_mutations.hpp"
#include <pqxx/pqxx>
#include <stdexcept>

namespace intermodal_transfer {

auto TransferSlotRepositoryImpl::insert(pqxx::work& tx, const TransferSlot& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.reference,
        entity.container_id,
        entity.transport_mode,
        entity.scheduled_at,
        entity.status);
}

auto TransferSlotRepositoryImpl::update(pqxx::work& tx, const TransferSlot& entity) -> void {
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.reference);
    params.append(entity.container_id);
    params.append(entity.transport_mode);
    params.append(entity.scheduled_at);
    params.append(entity.status);
    tx.exec_params(kUpdate, params);
}

auto TransferSlotRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace intermodal_transfer
