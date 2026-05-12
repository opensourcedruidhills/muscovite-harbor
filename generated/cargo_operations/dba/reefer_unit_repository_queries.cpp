// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace cargo_operations {

auto ReeferUnitRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<ReeferUnit> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return ReeferUnit::from_row(rows.front());
}

auto ReeferUnitRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<ReeferUnit> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<ReeferUnit>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(ReeferUnit::from_row(row));
    }
    return result;
}

auto ReeferUnitRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM reefer_units");
    return rows.front()[0].as<std::size_t>();
}

} // namespace cargo_operations
