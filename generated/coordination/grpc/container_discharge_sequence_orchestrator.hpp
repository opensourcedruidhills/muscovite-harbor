// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial
// Copyright (c) 2025-2026 Johannes Lochmann

#pragma once

#include <string>
#include <functional>

namespace coordination::container_discharge_sequence {

/// Orchestrator for ContainerDischargeSequence (FTR-870)
class ContainerDischargeSequenceOrchestrator {
public:
    /// Step: CranePick (context: CargoOperations)
    void execute_crane_pick(const std::string& correlation_id);

    /// Step: YardPlacement (context: CargoOperations)
    void execute_yard_placement(const std::string& correlation_id);

    /// Step: CustomsCheck (context: HarbourControl)
    void execute_customs_check(const std::string& correlation_id);

    /// Step: HandoffDispatch (context: IntermodalTransfer)
    void execute_handoff_dispatch(const std::string& correlation_id);

    /// Execute full coordination
    void run(const std::string& correlation_id);
};

} // namespace coordination::container_discharge_sequence
