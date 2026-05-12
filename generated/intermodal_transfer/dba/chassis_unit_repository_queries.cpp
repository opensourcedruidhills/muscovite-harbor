// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace intermodal_transfer {

auto ChassisUnitRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<ChassisUnit> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return ChassisUnit::from_row(rows.front());
}

auto ChassisUnitRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<ChassisUnit> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<ChassisUnit>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(ChassisUnit::from_row(row));
    }
    return result;
}

auto ChassisUnitRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM chassis_units");
    return rows.front()[0].as<std::size_t>();
}

} // namespace intermodal_transfer
