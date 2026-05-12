// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace harbour_control {

auto SafetyZoneRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<SafetyZone> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return SafetyZone::from_row(rows.front());
}

auto SafetyZoneRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<SafetyZone> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<SafetyZone>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(SafetyZone::from_row(row));
    }
    return result;
}

auto SafetyZoneRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM safety_zones");
    return rows.front()[0].as<std::size_t>();
}

} // namespace harbour_control
