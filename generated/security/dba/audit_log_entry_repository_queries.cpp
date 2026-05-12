// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace security {

auto AuditLogEntryRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<AuditLogEntry> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return AuditLogEntry::from_row(rows.front());
}

auto AuditLogEntryRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<AuditLogEntry> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<AuditLogEntry>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(AuditLogEntry::from_row(row));
    }
    return result;
}

auto AuditLogEntryRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM audit_log_entrys");
    return rows.front()[0].as<std::size_t>();
}

} // namespace security
