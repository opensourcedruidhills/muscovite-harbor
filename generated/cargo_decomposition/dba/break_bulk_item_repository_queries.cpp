// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace cargo_decomposition {

auto BreakBulkItemRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<BreakBulkItem> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return BreakBulkItem::from_row(rows.front());
}

auto BreakBulkItemRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<BreakBulkItem> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<BreakBulkItem>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(BreakBulkItem::from_row(row));
    }
    return result;
}

auto BreakBulkItemRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM break_bulk_items");
    return rows.front()[0].as<std::size_t>();
}

} // namespace cargo_decomposition
