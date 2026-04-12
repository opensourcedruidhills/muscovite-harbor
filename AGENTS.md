# Muscovite Harbor — Agent Operations Guide

**Key distinction**: Generated artifacts are **checked in** (ADR-004).
muscomp is a dev-time tool, NOT a build dependency.

## Build (no muscomp needed)

```bash
conan install --profile conan_profiles/debug .
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
```

## Regenerate (after .ddd/.mus changes — requires muscomp)

```bash
tools/regenerate.sh
# Review diff, then:
git add generated/ && git commit -m "regen: update generated code"
```

## Iteration Workflow

1. Check milestone: `gh issue list --milestone vX.Y.Z --state open`
2. Edit `.ddd` contexts or `.mus` project file
3. Run `tools/regenerate.sh` to update generated code
4. Build and test: `cmake --build --preset debug && ctest --preset debug`
5. Commit both DSL changes AND generated output together
6. Release via milestone closure

## ADRs

New decisions go in `doc/adr/NNN-short-kebab-title.md`. Update `doc/adr/README.md` index.

## Bounded Contexts

| Context | File | Owner |
|---------|------|-------|
| PortOperations | `contexts/port-operations.ddd` | PortOpsTeam |
| Cargo | `contexts/cargo.ddd` | CargoTeam |

## Version Files

| File | Purpose |
|------|---------|
| `HARBOR_VERSION` | Project version (semver) |
| `MUSCOMP_VERSION` | muscomp version that produced `generated/` |

