# Skill: Add Entity / Domain Construct

Use this skill when adding new entities, value objects, aggregates, commands,
events, sagas, or other domain constructs to a `.ddd` file.

## Before you start

1. **Read the PEG grammar** to verify exact syntax for the construct you're adding.
   The grammar is at the path in your Conan cache: `share/muscomp/grammar/muscovite.peg`
2. **Read `doc/DSL-QUICK-REFERENCE.md`** for examples of each construct.
3. **Read `doc/TYPE-MAPPINGS.md`** to verify field types are valid.

## Adding an Entity

### Step 1: Choose the right bounded context

Entities belong in the `.ddd` file for their bounded context.
Check `project.mus` `CONTEXT_FILES` to find the right file.

### Step 2: Define the entity

```ddd
ENTITY MyEntity @UUID("generate-a-uuidv4-here") IDENTIFIED_BY id {
    id UUID @REQUIRED,
    name TEXT @REQUIRED,
    description TEXT,
    created_at TIMESTAMPTZ,
    active Boolean DEFAULT true

    DOC "Describe what this entity represents."
}
```

**Rules**:
- Every entity MUST have `IDENTIFIED_BY id` with a `UUID` primary key named `id`
- Generate a fresh UUIDv4 for the `@UUID` annotation (used for rename tracking)
- Use types from `doc/TYPE-MAPPINGS.md` only — unknown types cause FAIL
- Use `TEXT` not `VARCHAR`, `TIMESTAMPTZ` not `TIMESTAMP`
- End the entity with a `DOC` clause

### Step 3: Add relationships (if needed)

If this entity references other entities, add explicit relationships:

```ddd
RELATIONSHIPS {
    other_entity -> OtherContext.OtherEntity REQUIRED ONE
        VIA other_entity_id
        DOC "Describes the relationship.";
}
```

**Never rely on `_id` field naming for foreign keys.** Every FK needs an
explicit `RELATIONSHIPS` declaration.

### Step 4: Add to an aggregate (if needed)

```ddd
AGGREGATE MyAggregate @UUID("...") ROOT MyEntity {
    DOC "Lifecycle boundary for MyEntity."
}
```

### Step 5: Lint and regenerate

```bash
muscomp --project project.mus --lint-only
muscomp --project project.mus --full --output generated/
```

## Adding a Value Object

```ddd
VALUE_OBJECT Address {
    street TEXT @REQUIRED,
    city TEXT @REQUIRED,
    postal_code PostalCode,
    country CountryCode

    DOC "Immutable postal address."
}
```

Value objects have no identity (`id` field). They are immutable.

## Adding a Command

```ddd
COMMAND DoSomething ON MyAggregate {
    entity_id UUID @REQUIRED,
    parameter TEXT @REQUIRED

    DECIDE {
        REQUIRES entity.active = true
            "Entity must be active."
    }

    EMIT SomethingHappened

    DOC "Describe what this command does."
}
```

## Adding a Domain Event

```ddd
EVENT SomethingHappened @UUID("...") {
    entity_id UUID @REQUIRED,
    happened_at TIMESTAMPTZ @REQUIRED

    DOC "Raised when something happens."
}
```

## Adding a Lookup Table

Use for fixed sets of values (never PostgreSQL ENUM or CHECK constraints):

```ddd
LOOKUP_TABLE Status {
    "active"    @UUID("...") DOC "Currently active",
    "inactive"  @UUID("...") DOC "Deactivated",
    "archived"  @UUID("...") DOC "Archived and read-only"

    DOC "Entity status classification."
}
```

## Checklist

- [ ] Used valid types from `doc/TYPE-MAPPINGS.md`
- [ ] Generated fresh UUIDv4 for `@UUID` annotations
- [ ] Entity has `IDENTIFIED_BY id` with `id UUID @REQUIRED`
- [ ] All foreign keys have explicit `RELATIONSHIPS {}` entries
- [ ] Added `DOC` clause
- [ ] Ran `muscomp --lint-only` successfully
- [ ] Regenerated and built successfully
