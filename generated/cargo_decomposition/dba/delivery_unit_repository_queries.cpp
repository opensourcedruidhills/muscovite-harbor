// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace cargo_decomposition {

auto DeliveryUnitRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<DeliveryUnit> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return DeliveryUnit::from_row(rows.front());
}

auto DeliveryUnitRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<DeliveryUnit> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<DeliveryUnit>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(DeliveryUnit::from_row(row));
    }
    return result;
}

auto DeliveryUnitRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM delivery_units");
    return rows.front()[0].as<std::size_t>();
}

} // namespace cargo_decomposition
