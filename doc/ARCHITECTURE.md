# Architecture — Consumer Project Guide

These principles govern all Muscovite consumer projects. They are derived from
220+ ADRs and 74+ releases of the Muscovite code generation platform.

## Core Principles

### 1. The Model Is the System

The `.ddd` domain model is the canonical specification. All generated code —
database schemas, gRPC services, C++ backends, Qt frontends — is a **projection**
of this model. If the generated output diverges from the model, the generator is wrong.

**Consequence**: Never hand-edit files in `generated/`. Fix the `.ddd`/`.mus` source
and regenerate.

### 2. Explicit Over Implicit

Every relationship, type, constraint, and capability must be declared in the DSL.
Nothing is inferred from naming conventions. A field named `patient_id UUID` is
NOT an implicit foreign key — it requires an explicit `RELATIONSHIPS {}` declaration.

The sole exception: `created_at` and `updated_at` timestamps are auto-generated.

### 3. Type Safety Spans the Entire Stack

A type defined in the DSL is semantically preserved across every target:
DSL → PostgreSQL → C++ → Proto → Qt. `Decimal` stays `Decimal` (not `double`).
`UUID` stays `UUID` (not `string`). Unknown types cause generation to **FAIL**.

See `doc/TYPE-MAPPINGS.md` for the complete mapping table.

### 4. Layers Must Never Collapse

Three layers are strictly separated:

| Layer | Contains | Editable? |
|-------|----------|-----------|
| **0 — Generator** | muscomp compiler, PEG grammar | Only in muscovite repo |
| **1 — Framework** | muscovite::dba, muscovite::grpc, etc. | Only in muscovite repo |
| **2 — Generated** | Your `generated/` directory | **Never** — regenerate from DSL |

Sidecar files (hand-written code that extends generated code) are the designated
extension point. The generator creates stub sidecars on first run; you fill in
the implementation.

### 5. Uniformity Is How You Scale

Naming, patterns, and structures are identical across all targets:
- `TEXT` not `VARCHAR`
- `TIMESTAMPTZ` not ambiguous local time
- `id` for all primary keys
- Every entity gets the same structure

Language idioms differ (`snake_case` SQL, `PascalCase` Proto, `camelCase` Qt),
but the mapping between them is deterministic.

### 6. Database Checks Invariants; Backend Checks Logic

The database enforces what fits in a single transaction on a single table:
`CHECK` constraints, `UNIQUE`, `NOT NULL`, foreign keys. Cross-table, cross-context,
or domain-specific logic belongs in the C++ backend.

### 7. Every Change Is Versioned

Schema changes are Sqitch migrations with deploy/verify/revert triplets.
Every semantic element carries a stable UUID for rename tracking.
Migrations are immutable once released.

### 8. Quality Is Binary

Pass or fail. Never warn. A signal that can be ignored will be ignored.
Test gates, linting, and governance checks are blocking.

## Priority Hierarchy

When principles conflict, resolve by this order:

1. **Correctness** — wrong output is worse than no output
2. **Predictability** — you must be able to reason from `.ddd` to generated output
3. **Model authority** — the DSL is always right
4. **Type safety** — types must be preserved across stack
5. **Explicitness** — nothing inferred
6. **Layer separation** — generators don't read each other
7. **Uniformity** — same patterns everywhere
8. **Performance** — C++23, no runtime cost for compile-time data
9. **Velocity** — fast iteration within the above constraints

## Red Lines (Inviolable)

1. Never edit generated code — fix the DSL source
2. Never deploy DB changes outside Sqitch
3. Never use JSONB for domain entity fields
4. Never use PostgreSQL ENUM or CHECK for enums — use `LOOKUP_TABLE`
5. Never hand-write `ALTER TABLE` — use semantic diff pipeline
6. Never skip quality gates
7. SPDX license header on every hand-written file
8. Never async gRPC in Qt UI thread (use async workers)
9. Queries never modify data (CQRS separation)
