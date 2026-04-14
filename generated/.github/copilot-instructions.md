# Copilot Instructions for MuscoviteHarbor

MuscoviteHarbor is a domain-driven application with 6 bounded context(s) and 28 entity(ies).

## Generated Code

This project uses Muscovite for code generation. **Never edit generated files directly** — fix the generator or the `.ddd` model instead.

Generated directories include `generated/`, database migrations, and proto files.

## Database Conventions

- Use `TEXT` for strings — no `VARCHAR`
- Use `TIMESTAMPTZ` for timestamps — no `TIMESTAMP`
- Every table has an `id` UUID primary key
- Migrations via muscdb (`muscdb deploy`/`muscdb revert`)
- No `JSONB` columns for structured data — use proper tables
- No `CHECK` constraints for enum enforcement — use lookup tables

## C++23 Patterns

- Use range-based algorithms (`std::ranges::*`) — no raw loops
- Use structured bindings where applicable
- No C-style casts — use `static_cast`, `dynamic_cast`, etc.
- Prefer `std::optional` and `std::variant` over nullable pointers
- Return types use trailing return syntax: `auto foo() -> int`

## gRPC Conventions

- All gRPC calls are asynchronous — no synchronous stubs in production code
- Use deadline propagation on every RPC
- Proto files are generated — do not edit `.proto` files directly
- Error mapping follows gRPC status code conventions

## Qt Patterns

- No synchronous gRPC calls from the UI thread
- QML imports use versioned module paths
- Widget code follows model/view separation
- All UI strings are translatable (`tr()`)

## Compile-Time Lookups

- Lookup tables are compile-time constants — no runtime `SELECT` for static data
- Use `constexpr` arrays or `std::array` for fixed lookup sets

## Licensing

- Dual-licensed: AGPL-3.0-or-later + Commercial
- Copyright: Johannes Lochmann
- Every source file must have an SPDX header:
  `// SPDX-License-Identifier: AGPL-3.0-or-later OR LicenseRef-Muscovite-Commercial`

## Testing

- Test-first development — write tests before implementation
- Use **doctest** BDD style (`SCENARIO`/`GIVEN`/`WHEN`/`THEN`), not Catch2
- All test gates are blocking — never `warn`, always `fail`

## Build Commands

```bash
conan install --profile conan_profiles/debug .
cmake --preset debug
cmake --build --preset debug
ctest --preset unit --output-on-failure
```

## Workflow

- Feature branches: `feature/ftr-NNN-short-description`
- No direct commits to `main` — merge through `develop`
- Run lint before committing `.ddd`/`.mus` changes
- Document changes alongside code — no "will document later"

## Bounded Contexts

- **VesselTraffic**: 6 entity(ies)
- **CargoOperations**: 6 entity(ies)
- **PassengerTerminal**: 3 entity(ies)
- **IntermodalTransfer**: 5 entity(ies)
- **CargoDecomposition**: 4 entity(ies)
- **HarbourControl**: 4 entity(ies)

