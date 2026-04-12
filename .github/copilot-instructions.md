# Muscovite Harbor — Copilot Instructions

Muscovite Harbor is a **fully DSL-managed** port operations project.
All domain modeling is done in `.mus` and `.ddd` files, compiled by `muscomp`.

## Rules

1. **DSL is the source of truth** — never hand-edit generated code (ADR-001)
2. **Fix the generator, not the output** — if generated code is wrong, fix the DSL or muscomp
3. **Lint before commit** — run `muscomp --project project.mus --lint-only` for any DSL change
4. **GitHub Milestones for iterations** — no local planning files
5. **SPDX headers** — all source files need dual-license header
6. **ADRs for decisions** — document in `doc/adr/NNN-title.md`

## Domain

- **PortOperations** (Core): Vessels, Berths, VesselVisits with state machine lifecycle
- **Cargo** (Supporting): CargoManifests, CargoItems with customs/hazmat tracking

## Build

```bash
muscomp --project project.mus --cpp-dba --cpp-dba-test --grpc --qt-frontend widgets --test
```
