#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "invoice_line.hpp"
#include "harbour_control_queries.hpp"
#include <optional>
#include <stdexcept>
#include <string>

namespace harbour_control {

/// Concrete CRTP repository implementation for InvoiceLine.
/// Satisfies RepositoryBase<InvoiceLineRepositoryImpl<C>, InvoiceLine> contract.
/// Uses embedded SQL constants from harbour_control_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class InvoiceLineRepositoryImpl {
public:
    explicit InvoiceLineRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const InvoiceLine& entity) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::InvoiceLineInsert, entity.id, entity.id, entity.vessel_id, entity.service_type, entity.amount, entity.currency, entity.issued_at);
        tx.commit();
    }

    auto update(const InvoiceLine& entity) -> void {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::InvoiceLineUpdate, entity.id, entity.id, entity.vessel_id, entity.service_type, entity.amount, entity.currency, entity.issued_at);
        if (result.affected_rows() == 0) {
            throw std::runtime_error(InvoiceLine not found:  + entity.id);
        }
        tx.commit();
    }

    auto remove(const std::string& id) -> void {
        auto tx = conn_.begin();
        tx.exec_params(queries::InvoiceLineDelete, id);
        tx.commit();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<InvoiceLine> {
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::InvoiceLineSelectById, id);
        tx.commit();
        if (result.empty()) { return std::nullopt; }
        return map_row(result[0]);
    }

    [[nodiscard]] auto find_all() -> std::vector<InvoiceLine> {
        auto tx = conn_.begin();
        auto result = tx.exec(queries::InvoiceLineSelectAll);
        tx.commit();
        auto out = std::vector<InvoiceLine>{};
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        return out;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> InvoiceLine {
        return InvoiceLine{
            .id = row[0].as<std::string>(),
            .id = row[1].as<std::string>(),
            .vessel_id = row[2].as<std::string>(),
            .service_type = row[3].as<std::string>(),
            .amount = row[4].as<std::string>(),
            .currency = row[5].as<std::string>(),
            .issued_at = row[6].as<std::string>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace harbour_control
