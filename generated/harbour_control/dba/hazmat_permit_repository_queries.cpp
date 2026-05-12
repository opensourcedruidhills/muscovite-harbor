// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace harbour_control {

auto HazmatPermitRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<HazmatPermit> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return HazmatPermit::from_row(rows.front());
}

auto HazmatPermitRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<HazmatPermit> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<HazmatPermit>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(HazmatPermit::from_row(row));
    }
    return result;
}

auto HazmatPermitRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM hazmat_permits");
    return rows.front()[0].as<std::size_t>();
}

} // namespace harbour_control
