# ADR-005: Architecture Reset — 6-Context Harbour Operations Platform

**Status:** Accepted
**Date:** 2026-04-14
**Supersedes:** ADR-002

## Context

The initial 2-context model (PortOperations + Cargo) was a quick scaffold to bootstrap
the repository. The project's purpose is to serve as a comprehensive Muscovite sample
exercising ~48/50 DSL constructs across all context-level features. The simple model
exercises only ~15 constructs and lacks the domain richness to demonstrate sagas,
event sourcing, bitemporal data, foreign contexts, brownfield mapping, or UI targets.

## Decision

Replace the 2-context model with a 6-context harbour operations platform:

| Context | Classification | Core Responsibility |
|---------|---------------|---------------------|
| **VesselTraffic** | Core | Vessel registry, voyage scheduling, berth allocation, pilot/tug coordination, tide windows |
| **CargoOperations** | Core | Container lifecycle, load plans, crane sequencing, yard storage, reefer monitoring |
| **PassengerTerminal** | Supporting | Embarkation/disembarkation, gate management, manifests, departure displays |
| **IntermodalTransfer** | Supporting | Container↔truck/rail/barge handoff, booking slots, chassis pool |
| **CargoDecomposition** | Supporting | Container→pallet→parcel breakdown, legacy equivalence, last-mile dispatch |
| **HarbourControl** | Generic | Port authority oversight, safety zones, hazmat clearance, billing, compliance |

### Boundary Rules
- **CargoDecomposition** is strictly downstream of CargoOperations — it owns decomposition
  workflow and legacy equivalence, never canonical container lifecycle state.
- **HarbourControl** is regulations/authority-facing only — no operational state copies.
- **PassengerTerminal** consumes VesselTraffic projections, does not modify voyage state.

### Backlog Impact
All 51 issues (#1–#51) from the prior design are superseded by this reset.
New milestones and issues will be created to match the 6-context architecture.

## Rationale

- Physical constraints (berth capacity, 3D yard grid, tide windows, hazmat segregation)
  drive real invariants that exercise DSL constructs naturally
- Six contexts create genuine integration tensions (sagas, ACLs, event choreography)
- The decomposition chain (vessel→bay→container→pallet→parcel) exercises deep relationships
- Brownfield constructs (Mapping, LegacyView, LegacyProcedure) need a realistic legacy
  migration scenario — CargoDecomposition provides this
- Target: DSL construct coverage (~48/50), not full generator integration

## Consequences

- Old port-operations.ddd and cargo.ddd are deleted
- project.mus is rewritten with 6 context includes, expanded schemes, teams, capabilities
- Context MAP exercises all 7 DDD stereotypes
- Future milestones track implementation of individual contexts
