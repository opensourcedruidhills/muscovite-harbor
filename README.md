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

**To build** (CI/production — no muscomp needed):
- C++23 compiler (GCC 13+ or Clang 17+)
- Conan 2.x + CMake 3.28+ + Ninja
- PostgreSQL 15+ (libpqxx)
- Qt 6.5+ (for UI targets)

**To modify the domain model** (dev workstation):
- All of the above, plus:
- [Muscovite muscomp](https://github.com/opensourcedruidhills/muscovite) compiler

## Quick Start

```bash
# Build (generated code is already checked in)
conan install --profile conan_profiles/debug .
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
```

### Regenerating from DSL (after .ddd/.mus changes)

```bash
# Requires muscomp on PATH (or set MUSCOMP_BIN)
tools/regenerate.sh

# Review the generated diff, then commit
git add generated/ && git commit -m "regen: update generated code"
```

## Project Structure

```
muscovite-harbor/
├── project.mus              # Muscovite project definition (.mus)
├── contexts/
│   ├── port-operations.ddd  # Core: vessel & berth management (.ddd)
│   └── cargo.ddd            # Supporting: cargo tracking (.ddd)
├── generated/               # muscomp output — CHECKED IN (ADR-004)
│   ├── src/                 # Generated C++ sources
│   ├── proto/               # Generated .proto files
│   ├── sql/                 # Generated SQL / Sqitch migrations
│   └── qml/                 # Generated QML files
├── src/                     # Hand-written application code
├── tests/                   # Hand-written tests
├── CMakeLists.txt           # Build system (pure consumer of muscovite)
├── conanfile.py             # Conan dependencies (muscovite as package)
├── CMakePresets.json         # Build presets (debug, release)
├── conan_profiles/          # Conan profiles
├── MUSCOMP_VERSION          # Which muscomp version generated the output
├── HARBOR_VERSION           # Project version
├── tools/
│   ├── regenerate.sh        # Re-run muscomp (dev-time only)
│   └── verify-generated.sh  # CI: check generated code is fresh
├── doc/
│   └── adr/                 # Architecture Decision Records
└── README.md
```

## Architecture Decisions

See [doc/adr/](doc/adr/) for all ADRs. Key decisions:

- **ADR-001**: Muscovite DSL as single source of truth
- **ADR-002**: Harbor domain bounded context boundaries
- **ADR-003**: Iteration and release governance
- **ADR-004**: Generated artifacts are checked in (key distinction)

## Versioning

This project follows semantic versioning. Releases are managed via GitHub Milestones
and the Muscovite iteration workflow.

## License

SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial

Dual-licensed under AGPL-3.0 and a commercial license.
Copyright (c) 2026 Johannes Lochmann.
