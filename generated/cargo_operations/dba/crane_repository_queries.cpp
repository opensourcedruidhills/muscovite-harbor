// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace cargo_operations {

auto CraneRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<Crane> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return Crane::from_row(rows.front());
}

auto CraneRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<Crane> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<Crane>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(Crane::from_row(row));
    }
    return result;
}

auto CraneRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM cranes");
    return rows.front()[0].as<std::size_t>();
}

} // namespace cargo_operations
