// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace harbour_control {

auto InvoiceLineRepositoryImpl::insert(pqxx::work& tx, const InvoiceLine& entity) -> void {
    tx.exec_params(kInsert,
        entity.id,
        entity.id,
        entity.vessel_id,
        entity.service_type,
        entity.amount,
        entity.currency,
        entity.issued_at,
    );
}

auto InvoiceLineRepositoryImpl::update(pqxx::work& tx, const InvoiceLine& entity) -> void {
    // field params reuse same order as kUpdate (SET ... WHERE id = $N+1)
    auto params = pqxx::params{};
    params.append(entity.id);
    params.append(entity.id);
    params.append(entity.vessel_id);
    params.append(entity.service_type);
    params.append(entity.amount);
    params.append(entity.currency);
    params.append(entity.issued_at);
    tx.exec_params(kUpdate, params);
}

auto InvoiceLineRepositoryImpl::remove(pqxx::work& tx, const std::string& id) -> void {
    tx.exec_params(kDelete, id);
}

} // namespace harbour_control
