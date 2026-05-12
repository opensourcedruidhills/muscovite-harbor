// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace security {

auto RoleRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<Role> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return Role::from_row(rows.front());
}

auto RoleRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<Role> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<Role>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(Role::from_row(row));
    }
    return result;
}

auto RoleRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM roles");
    return rows.front()[0].as<std::size_t>();
}

} // namespace security
