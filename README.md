# Muscovite Harbor

Port and maritime operations management system — fully managed by [Muscovite](https://github.com/opensourcedruidhills/muscovite) DSL.

## Overview

Muscovite Harbor models a harbor/port operations domain using Muscovite's DDD-first
code generation pipeline. The DSL model compiles to PostgreSQL, gRPC, C++, and Qt targets.

### Bounded Contexts

| Context | Domain | Team |
|---------|--------|------|
| **PortOperations** | Vessel scheduling, berth allocation, vessel visits | PortOpsTeam |
| **Cargo** | Cargo manifests, bill of lading, cargo tracking | CargoTeam |

### Key Domain Concepts

- **Vessel** — Ships visiting the port, identified by IMO number
- **Berth** — Physical docking positions with dimensional constraints
- **VesselVisit** — A port call with full lifecycle (announced → berthed → departed)
- **CargoManifest** — Bill of lading with associated cargo items
- **CargoItem** — Individual cargo units with hazmat tracking and customs status

## Prerequisites

- [Muscovite muscomp](https://github.com/opensourcedruidhills/muscovite) compiler
- PostgreSQL 15+
- C++23 compiler (GCC 13+ or Clang 17+)
- Qt 6.5+ (for UI targets)
- Conan 2.x + CMake 3.28+

## Quick Start

```bash
# Compile the domain model
muscomp --project project.mus --cpp-dba --cpp-dba-test --grpc --qt-frontend widgets --test

# Lint only (fast check)
muscomp --project project.mus --lint-only

# Dry run (preview generated files)
muscomp --project project.mus --dry-run
```

## Project Structure

```
muscovite-harbor/
├── project.mus              # Muscovite project definition
├── contexts/
│   ├── port-operations.ddd  # Core: vessel & berth management
│   └── cargo.ddd            # Supporting: cargo tracking
├── generated/               # muscomp output (gitignored)
├── doc/
│   └── adr/                 # Architecture Decision Records
└── README.md
```

## Architecture Decisions

See [doc/adr/](doc/adr/) for all ADRs. Key decisions:

- **ADR-001**: Muscovite DSL as single source of truth
- **ADR-002**: Harbor domain bounded context boundaries

## Versioning

This project follows semantic versioning. Releases are managed via GitHub Milestones
and the Muscovite iteration workflow.

## License

SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial

Dual-licensed under AGPL-3.0 and a commercial license.
Copyright (c) 2026 Johannes Lochmann.
