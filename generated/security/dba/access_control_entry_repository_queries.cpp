// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace security {

auto AccessControlEntryRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<AccessControlEntry> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return AccessControlEntry::from_row(rows.front());
}

auto AccessControlEntryRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<AccessControlEntry> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<AccessControlEntry>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(AccessControlEntry::from_row(row));
    }
    return result;
}

auto AccessControlEntryRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM access_control_entrys");
    return rows.front()[0].as<std::size_t>();
}

} // namespace security
