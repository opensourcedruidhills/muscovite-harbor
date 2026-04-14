# Muscovite Harbor — Copilot Instructions

Muscovite Harbor is a **consumer project** of the Muscovite DSL toolchain.
All domain modeling is done in `.mus` and `.ddd` files, compiled by `muscomp`.

## Muscovite Toolchain

The Muscovite compiler and framework live in a **separate repository**.
Set `MUSCOVITE_ROOT` to locate it (default: `$HOME/muscovite`).

| Resource | Path |
|----------|------|
| PEG grammar (DSL syntax reference) | `$MUSCOVITE_ROOT/grammar/muscovite.peg` |
| DSL linter | `$MUSCOVITE_ROOT/tools/lint-ddd.sh` |
| muscomp binary | `$MUSCOVITE_ROOT/build/Debug/toolchain/muscomp/muscomp` |
| Ground truth (IR/naming/types) | `$MUSCOVITE_ROOT/doc/GROUND-TRUTH.md` |
| Example projects | `$MUSCOVITE_ROOT/examples/` |

**Before editing `.ddd` files**, read the PEG grammar for the construct you're modifying.
The grammar is the authoritative syntax reference — not documentation, not examples.

### Lint (after any .ddd/.mus change)

```bash
MUSCOVITE_ROOT="${MUSCOVITE_ROOT:-$HOME/muscovite}"
"$MUSCOVITE_ROOT/tools/lint-ddd.sh" project.mus
```

### Regenerate (requires muscomp on PATH or MUSCOMP_BIN set)

```bash
tools/regenerate.sh
```

## Rules

1. **DSL is the source of truth** — never hand-edit generated code (ADR-001)
2. **Fix the generator, not the output** — if generated code is wrong, fix the DSL or muscomp
3. **Generated code is committed** — PRs that change .ddd/.mus MUST include regenerated output (ADR-004)
4. **Build without muscomp** — CI only needs C++ toolchain + Conan
5. **GitHub Milestones for iterations** — no local planning files
6. **SPDX headers** — all source files need dual-license header
7. **ADRs for decisions** — document in `doc/adr/NNN-title.md`

## Bounded Contexts (6)

| Context | File | Key Constructs |
|---------|------|----------------|
| VesselTraffic | `contexts/vessel-traffic.ddd` | StateMachine, Bitemporal, Projections, Concurrency, Seed |
| CargoOperations | `contexts/cargo-operations.ddd` | EVENT_SOURCED, SourcedEvents, DECIDE/EMIT, Policy, Modules |
| PassengerTerminal | `contexts/passenger-terminal.ddd` | UseCase, UserStory, StoryMap, Qt widgets+QML |
| IntermodalTransfer | `contexts/intermodal-transfer.ddd` | Saga, Flow, FeatureFlag, LifecycleScheme, WorkStream |
| CargoDecomposition | `contexts/cargo-decomposition.ddd` | Mapping, LegacyView, LegacyProcedure, Instruct |
| HarbourControl | `contexts/harbour-control.ddd` | ForeignContext+ACL, ViewEntity, Fishbone, Deployment |

## Build

```bash
conan install --profile conan_profiles/debug .
cmake --preset debug && cmake --build --preset debug
ctest --preset debug
```

## Common DSL Grammar Pitfalls

These are patterns that frequently cause parse errors:

- **SEED** is an EntityClause (inside entity), not a ContextItem. Syntax: `SEED "label" { (val, ...) }`
- **INSTRUCT** is an EntityClause — must be inside an entity body
- **RELATIONSHIPS** / **BITEMPORAL** — EntityClause only, not context-level
- **State machine GUARD** takes a STRING: `GUARD "condition"`
- **EMIT in DECIDE** uses `:` — `EMIT Name(key: value)`
- **INVOKE in Policy/Saga** uses `=` with STRING — `INVOKE Name(key = "value")`
- **Repository method params** use space: `name TYPE` (not `name: TYPE`)
- **Wardley stages**: only GENESIS, CUSTOM, PRODUCT, COMMODITY
- **ALERT WHEN** (not CONDITION): `WHEN "expression";`
- **Saga ON COMPLETED/FAILED** go after the `}` closing the steps block
