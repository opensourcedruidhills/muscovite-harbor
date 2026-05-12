// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT


namespace harbour_control {

auto InvoiceLineRepositoryImpl::find_by_id(pqxx::work& tx, const std::string& id)
    -> std::optional<InvoiceLine> {
    auto rows = tx.exec_params(kSelectById, id);
    if (rows.empty()) { return std::nullopt; }
    return InvoiceLine::from_row(rows.front());
}

auto InvoiceLineRepositoryImpl::find_all(pqxx::work& tx) -> std::vector<InvoiceLine> {
    auto rows = tx.exec(kSelectAll);
    auto result = std::vector<InvoiceLine>{};
    result.reserve(rows.size());
    for (const auto& row : rows) {
        result.push_back(InvoiceLine::from_row(row));
    }
    return result;
}

auto InvoiceLineRepositoryImpl::count(pqxx::work& tx) -> std::size_t {
    auto rows = tx.exec("SELECT count(*) FROM invoice_lines");
    return rows.front()[0].as<std::size_t>();
}

} // namespace harbour_control
