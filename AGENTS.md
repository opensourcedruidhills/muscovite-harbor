# Muscovite Harbor — Agent Operations Guide

## Quick Start

```bash
# Lint DSL
muscomp --project project.mus --lint-only

# Full generation
muscomp --project project.mus --cpp-dba --cpp-dba-test --grpc --qt-frontend widgets --test

# Dry run
muscomp --project project.mus --dry-run
```

## Iteration Workflow

1. Check milestone: `gh issue list --milestone vX.Y.Z --state open`
2. Implement FTRs by editing `.ddd` contexts
3. Lint: `muscomp --project project.mus --lint-only`
4. Regenerate and build
5. Release via milestone closure

## ADRs

New decisions go in `doc/adr/NNN-short-kebab-title.md`. Update `doc/adr/README.md` index.

## Bounded Contexts

| Context | File | Owner |
|---------|------|-------|
| PortOperations | `contexts/port-operations.ddd` | PortOpsTeam |
| Cargo | `contexts/cargo.ddd` | CargoTeam |
