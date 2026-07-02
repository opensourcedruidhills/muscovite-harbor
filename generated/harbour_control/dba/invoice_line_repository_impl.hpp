#pragma once
// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "invoice_line.hpp"
#include "harbour_control_queries.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>

namespace harbour_control {

class DbaOperationSpan {
public:
    explicit DbaOperationSpan(std::string_view operation) : operation_{operation} {}
    auto set_status_ok() noexcept -> void {}
    auto set_error(std::string_view /*message*/) noexcept -> void {}
private:
    std::string_view operation_;
};

/// Concrete CRTP repository implementation for InvoiceLine.
/// Satisfies RepositoryBase<InvoiceLineRepositoryImpl<C>, InvoiceLine> contract.
/// Uses embedded SQL constants from harbour_control_queries.hpp (FTR-1507).
/// No stored procedures (ADR 20260120).
template<typename Connection>
class InvoiceLineRepositoryImpl {
public:
    explicit InvoiceLineRepositoryImpl(Connection& conn) : conn_{conn} {}

    auto save(const InvoiceLine& entity) -> void {
        DbaOperationSpan span("InvoiceLineRepositoryImpl::save");
        auto tx = conn_.begin();
        tx.exec_params(queries::InvoiceLineInsert, entity.id, entity.vessel_id, entity.service_type, entity.amount, entity.currency, entity.issued_at);
        tx.commit();
        span.set_status_ok();
    }

    auto update(const InvoiceLine& entity) -> void {
        DbaOperationSpan span("InvoiceLineRepositoryImpl::update");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::InvoiceLineUpdate, entity.id, entity.vessel_id, entity.service_type, entity.amount, entity.currency, entity.issued_at);
        if (result.affected_rows() == 0) {
            span.set_error("not found");
            throw std::runtime_error("InvoiceLine not found: " + entity.id);
        }
        tx.commit();
        span.set_status_ok();
    }

    auto remove(const std::string& id) -> void {
        DbaOperationSpan span("InvoiceLineRepositoryImpl::remove");
        auto tx = conn_.begin();
        tx.exec_params(queries::InvoiceLineDelete, id);
        tx.commit();
        span.set_status_ok();
    }

    [[nodiscard]] auto find_by_id(const std::string& id) -> std::optional<InvoiceLine> {
        DbaOperationSpan span("InvoiceLineRepositoryImpl::find_by_id");
        auto tx = conn_.begin();
        auto result = tx.exec_params(queries::InvoiceLineSelectById, id);
        tx.commit();
        if (result.empty()) {
            span.set_status_ok();
            return std::nullopt;
        }
        auto mapped = map_row(result[0]);
        span.set_status_ok();
        return mapped;
    }

    [[nodiscard]] auto find_all() -> std::vector<InvoiceLine> {
        DbaOperationSpan span("InvoiceLineRepositoryImpl::find_all");
        auto tx = conn_.begin();
        auto result = tx.exec(queries::InvoiceLineSelectAll);
        tx.commit();
        auto out = std::vector<InvoiceLine>{ };
        out.reserve(result.size());
        for (const auto& row : result) { out.push_back(map_row(row)); }
        span.set_status_ok();
        return out;
    }

    /// Filter all entities by a domain specification (in-memory).
    template<typename Spec>
    [[nodiscard]] auto filter_by_spec(const Spec& spec) const -> std::vector<InvoiceLine> {
        auto all = find_all();
        auto result = std::vector<InvoiceLine>{};
        std::copy_if(all.begin(), all.end(), std::back_inserter(result),
                     [&spec](const InvoiceLine& e) { return spec.is_satisfied_by(e); });
        return result;
    }

    [[nodiscard]] auto map_row(const pqxx::row& row) const -> InvoiceLine {
        return InvoiceLine{
            .id = row[0].as<std::string>(),
            .vessel_id = row[1].as<boost::uuids::uuid>(),
            .service_type = row[2].as<std::string>(),
            .amount = row[3].as<muscovite::dba::Decimal>(),
            .currency = row[4].as<std::string>(),
            .issued_at = row[5].as<muscovite::dba::Timestamp>(),
        };
    }

private:
    Connection& conn_;
;

} // namespace harbour_control
