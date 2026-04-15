# Muscovite Harbor

Port and maritime operations management system — built with [Muscovite](https://github.com/opensourcedruidhills/muscovite) DSL.

## Overview

Muscovite Harbor models a harbor/port operations domain using Muscovite's DDD-first
code generation pipeline. The DSL model compiles to PostgreSQL, gRPC, C++, and Qt targets.

This is a **standalone consumer project** — it depends on Muscovite exclusively through
Conan. No access to the muscovite source repository is required to build or work on it.

### Bounded Contexts

| Context | Domain | File |
|---------|--------|------|
| **VesselTraffic** | Vessel scheduling, AIS tracking, berth allocation | `contexts/vessel-traffic.ddd` |
| **CargoOperations** | Event-sourced cargo manifests, bill of lading | `contexts/cargo-operations.ddd` |
| **PassengerTerminal** | Check-in, boarding, passenger management | `contexts/passenger-terminal.ddd` |
| **IntermodalTransfer** | Modal transfers, sagas, feature flags | `contexts/intermodal-transfer.ddd` |
| **CargoDecomposition** | Legacy integration, cargo breakdown | `contexts/cargo-decomposition.ddd` |
| **HarbourControl** | Port authority, foreign context ACL | `contexts/harbour-control.ddd` |

## Prerequisites

**To build** (CI/production — no muscomp needed):
- C++23 compiler (GCC 13+ or Clang 17+)
- Conan 2.x + CMake 3.28+ + Ninja
- PostgreSQL 15+ (libpqxx, pulled transitively by muscovite)
- Qt 6.5+ (for UI targets, pulled transitively by muscovite)

**To modify the domain model** (dev workstation):
- All of the above, plus:
- [muscomp](https://github.com/opensourcedruidhills/muscovite) compiler on PATH

### Conan Remote Setup

Muscovite is distributed via a private Conan remote:

```bash
conan remote add muscovite-origin <URL>   # Ask your team lead for the URL
conan remote login muscovite-origin <user>
```

## Quick Start

```bash
# Build (generated code is already checked in)
conan install --profile conan_profiles/debug .
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
```

### Accessing Muscovite Resources

The Conan package ships the PEG grammar, reference docs, and lint tool.
After `cmake --preset debug`, CMake cache variables point to them:

```bash
# Read the PEG grammar (authoritative DSL syntax reference)
GRAMMAR_DIR=$(cmake --preset debug -N -L 2>/dev/null | grep MUSCOVITE_GRAMMAR_DIR | cut -d= -f2)
cat "$GRAMMAR_DIR/muscovite.peg"

# Read the IR reference docs
DOC_DIR=$(cmake --preset debug -N -L 2>/dev/null | grep MUSCOVITE_DOC_DIR | cut -d= -f2)
cat "$DOC_DIR/GROUND-TRUTH.md"
```

### Regenerating from DSL (after .ddd/.mus changes)

```bash
# Requires muscomp on PATH (or set MUSCOMP_BIN)
tools/lint.sh project.mus
tools/regenerate.sh

# Review the generated diff, then commit
git add generated/ && git commit -m "regen: update generated code"
```

## Project Structure

```
muscovite-harbor/
├── project.mus              # Muscovite project definition (.mus)
├── contexts/
│   ├── vessel-traffic.ddd   # Vessel scheduling, AIS, berth allocation
│   ├── cargo-operations.ddd # Event-sourced cargo manifests
│   ├── passenger-terminal.ddd # Passenger check-in, boarding
│   ├── intermodal-transfer.ddd # Sagas, feature flags, modal transfers
│   ├── cargo-decomposition.ddd # Legacy integration
│   └── harbour-control.ddd  # Port authority, ACL
├── generated/               # muscomp output — CHECKED IN (ADR-004)
│   ├── src/                 # Generated C++ sources
│   ├── proto/               # Generated .proto files
│   ├── sql/                 # Generated SQL / Sqitch migrations
│   └── qml/                 # Generated QML files
├── src/                     # Hand-written application code
├── tests/                   # Hand-written tests
├── CMakeLists.txt           # Build system (Conan consumer of muscovite)
├── conanfile.py             # Conan dependencies
├── CMakePresets.json        # Build presets (debug, release)
├── conan_profiles/          # Conan profiles
├── MUSCOMP_VERSION          # Which muscomp version generated the output
├── HARBOR_VERSION           # Project version
├── tools/
│   ├── lint.sh              # DSL lint (wraps muscomp --lint-only)
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

This project follows semantic versioning. Releases are managed via GitHub Milestones.

## License

SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial

Dual-licensed under AGPL-3.0 and a commercial license.
Copyright (c) 2026 Johannes Lochmann.
