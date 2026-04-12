# ADR-003: Iteration and Release Governance

**Status:** Accepted
**Date:** 2026-04-12
**Context:** Establishing autonomous project governance

## Decision

Muscovite Harbor follows the Muscovite iteration workflow:

- **GitHub Milestones** are the sole source of truth for iteration scope (no MoSCoW)
- **GitHub Issues** track all features (FTR), bugs (BUG), and ideas (IDEA)
- **Bi-weekly releases** with semantic versioning
- **Quality gates** enforced by scripts, not documentation

## Release Process

1. All milestone issues must be `status:complete` and closed
2. DSL lint must pass (`muscomp --lint-only`)
3. Full regeneration must succeed
4. C++ build and test gates must pass
5. Tag and release

## Consequences

- No local planning files (PLAN.md, ITERATION.md) — GitHub is the system of record
- Every planned item gets done — items are not removed from milestones to unblock releases
- Retrospectives are mandatory and must produce improvement FTRs
