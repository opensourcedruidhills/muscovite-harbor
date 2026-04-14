// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann
// GENERATED FILE — DO NOT EDIT

#include "container_handoff_processor.hpp"

namespace intermodal_transfer {

auto ContainerHandoffProcessor::start(const ContainerHandoffData& data) -> std::string {
    auto saga_id = cmd_repo_.start(data);
    cmd_repo_.advance(saga_id, "ReserveYardExit");
    return saga_id;
}

auto ContainerHandoffProcessor::execute_step(const std::string& saga_id) -> bool {
    auto instance_opt = query_repo_.find_by_id(saga_id);
    if (!instance_opt) { return false; }
    const auto& instance = *instance_opt;

    if (instance.current_step == "ReserveYardExit") {
        auto ok = handle_reserve_yard_exit(instance);
        if (ok) {
            cmd_repo_.advance(saga_id, "CheckoutGate");
        } else {
            cmd_repo_.fail(saga_id, "Step ReserveYardExit failed");
            run_compensation(saga_id);
        }
        return ok;
    } else if (instance.current_step == "CheckoutGate") {
        auto ok = handle_checkout_gate(instance);
        if (ok) {
            cmd_repo_.advance(saga_id, "LoadTransport");
        } else {
            cmd_repo_.fail(saga_id, "Step CheckoutGate failed");
            run_compensation(saga_id);
        }
        return ok;
    } else if (instance.current_step == "LoadTransport") {
        auto ok = handle_load_transport(instance);
        if (ok) {
            cmd_repo_.advance(saga_id, "ConfirmDeparture");
        } else {
            cmd_repo_.fail(saga_id, "Step LoadTransport failed");
            run_compensation(saga_id);
        }
        return ok;
    } else if (instance.current_step == "ConfirmDeparture") {
        auto ok = handle_confirm_departure(instance);
        if (ok) {
            cmd_repo_.complete(saga_id);
        } else {
            cmd_repo_.fail(saga_id, "Step ConfirmDeparture failed");
            run_compensation(saga_id);
        }
        return ok;
    }

    return false; // Unknown step
}

auto ContainerHandoffProcessor::run_compensation(const std::string& saga_id) -> void {
    auto instance_opt = query_repo_.find_by_id(saga_id);
    if (!instance_opt) { return; }
    const auto& instance = *instance_opt;

}

auto ContainerHandoffProcessor::check_timeouts(std::chrono::seconds threshold) -> void {
    auto timed_out = query_repo_.find_timed_out(threshold);
    for (const auto& instance : timed_out) {
        cmd_repo_.fail(instance.id, "Timeout");
        run_compensation(instance.id);
    }
}

} // namespace intermodal_transfer
