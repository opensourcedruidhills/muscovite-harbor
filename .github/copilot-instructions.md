# Muscovite Harbor — Copilot Instructions

Muscovite Harbor is a **fully DSL-managed** port operations project.
All domain modeling is done in `.mus` and `.ddd` files, compiled by `muscomp`.

**Key distinction**: Generated artifacts are **checked in** (ADR-004).
muscomp is a dev-time tool only — the project builds without it.

## Rules

1. **DSL is the source of truth** — never hand-edit generated code (ADR-001)
2. **Fix the generator, not the output** — if generated code is wrong, fix the DSL or muscomp
3. **Generated code is committed** — PRs that change .ddd/.mus MUST include regenerated output (ADR-004)
4. **Build without muscomp** — CI only needs C++ toolchain + Conan
5. **GitHub Milestones for iterations** — no local planning files
6. **SPDX headers** — all source files need dual-license header
7. **ADRs for decisions** — document in `doc/adr/NNN-title.md`

## Domain

- **PortOperations** (Core): Vessels, Berths, VesselVisits with state machine lifecycle
- **Cargo** (Supporting): CargoManifests, CargoItems with customs/hazmat tracking

## Build

```bash
conan install --profile conan_profiles/debug .
cmake --preset debug && cmake --build --preset debug
```

## Regenerate (dev-time only, requires muscomp)

```bash
tools/regenerate.sh
```
