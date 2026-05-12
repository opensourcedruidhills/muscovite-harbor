// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace security {

auto AuditLogEntryRepositoryImpl::insert(pqxx::work& tx, const AuditLogEntry& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.timestamp,
        entity.actor,
        entity.action,
        entity.resource,
        entity.details,
    );
}

auto AuditLogEntryRepositoryImpl::update(pqxx::work& tx, const AuditLogEntry& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.timestamp);
    params.append(entity.actor);
    params.append(entity.action);
    params.append(entity.resource);
    params.append(entity.details);
    tx.exec_params(kUpdate, params);
}

auto AuditLogEntryRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace security
