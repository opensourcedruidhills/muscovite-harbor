# Muscovite Harbor — Agent Operations Guide

## Environment

| Variable | Default | Purpose |
|----------|---------|---------|
| `MUSCOVITE_ROOT` | `$HOME/muscovite` | Path to muscovite toolchain repo |
| `MUSCOMP_BIN` | `muscomp` (on PATH) | Path to muscomp binary |

**Key distinction**: Generated artifacts are **checked in** (ADR-004).
muscomp is a dev-time tool, NOT a build dependency.

## Quick Reference

```bash
MUSCOVITE_ROOT="${MUSCOVITE_ROOT:-$HOME/muscovite}"
```

| Task | Command |
|------|---------|
| Lint DSL | `"$MUSCOVITE_ROOT/tools/lint-ddd.sh" project.mus` |
| Regenerate | `tools/regenerate.sh` |
| Build | `cmake --build --preset debug` |
| Test | `ctest --preset debug` |
| PEG grammar | `$MUSCOVITE_ROOT/grammar/muscovite.peg` |

## Build (no muscomp needed)

```bash
conan install --profile conan_profiles/debug .
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
```

## DSL Editing Workflow

1. **Read the grammar first**: `$MUSCOVITE_ROOT/grammar/muscovite.peg`
2. Edit `.ddd` or `.mus` files
3. Lint: `"$MUSCOVITE_ROOT/tools/lint-ddd.sh" project.mus`
4. Fix parse errors (see pitfalls in `.github/copilot-instructions.md`)
5. Regenerate: `tools/regenerate.sh`
6. Build and test
7. Commit DSL changes AND generated output together

## Regenerate (after .ddd/.mus changes — requires muscomp)

```bash
tools/regenerate.sh
# Review diff, then:
git add generated/ && git commit -m "regen: update generated code"
```

## Bounded Contexts

| Context | File | Owner |
|---------|------|-------|
| VesselTraffic | `contexts/vessel-traffic.ddd` | VesselOpsTeam |
| CargoOperations | `contexts/cargo-operations.ddd` | CargoOpsTeam |
| PassengerTerminal | `contexts/passenger-terminal.ddd` | PassengerServicesTeam |
| IntermodalTransfer | `contexts/intermodal-transfer.ddd` | LogisticsTeam |
| CargoDecomposition | `contexts/cargo-decomposition.ddd` | LogisticsTeam |
| HarbourControl | `contexts/harbour-control.ddd` | HarbourAuthorityTeam |

## Iteration Workflow

1. Check milestone: `gh issue list --milestone vX.Y.Z --state open`
2. Edit `.ddd` contexts or `.mus` project file
3. Lint → Regenerate → Build → Test
4. Commit both DSL changes AND generated output together
5. Release via milestone closure

## ADRs

New decisions go in `doc/adr/NNN-short-kebab-title.md`. Update `doc/adr/README.md` index.

## Version Files

| File | Purpose |
|------|---------|
| `HARBOR_VERSION` | Project version (semver) |
| `MUSCOMP_VERSION` | muscomp version that produced `generated/` |

