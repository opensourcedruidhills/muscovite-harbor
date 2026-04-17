# DSL Quick Reference (.ddd files)

This is a condensed reference for the Muscovite domain DSL.
**For definitive syntax, read the PEG grammar** at the path shown by:
```bash
python3 -c "import conans; print(conans.__file__)"  # find Conan cache
# Grammar is at: <conan_cache>/share/muscomp/grammar/muscovite.peg
```

## Bounded Context

```ddd
CONTEXT MyContext @UUID("...") {
    OWNER "Team Name"
    VISION "What this context does"

    -- Entities, aggregates, events, etc. go here
}
```

## Entity

```ddd
ENTITY Patient @UUID("...") IDENTIFIED_BY id {
    id UUID @REQUIRED,
    name TEXT @REQUIRED,
    email Email,
    date_of_birth Date,
    active Boolean DEFAULT true

    DOC "A patient in the system."
}
```

Constraints: `@REQUIRED`, `@UNIQUE`, `NOT_NULL`, `DEFAULT value`
Annotations: `@UUID`, `@SEARCHABLE`, `@IMMUTABLE`, `@SPATIAL-QUERYABLE`

## Value Object

```ddd
VALUE_OBJECT Address {
    street TEXT @REQUIRED,
    city TEXT @REQUIRED,
    postal_code PostalCode,
    country CountryCode

    DOC "A postal address."
}
```

Value objects are immutable and identity-free. Default storage: `@storage inline`.

## Strong Type

```ddd
STRONG_TYPE PatientMRN : String
    DOC "Medical Record Number — unique patient identifier."
```

Generates a PostgreSQL `DOMAIN` with validation.

## Aggregate

```ddd
AGGREGATE PatientAggregate @UUID("...") ROOT Patient {
    DOC "Patient lifecycle aggregate."
}
```

## Command

```ddd
COMMAND AdmitPatient ON PatientAggregate {
    patient_id UUID @REQUIRED,
    ward_id UUID @REQUIRED,
    admitting_physician TEXT

    DECIDE {
        REQUIRES patient.active = true
            "Patient must be active for admission."
        ENSURES admission.status = "admitted"
            "Patient is admitted after command."
    }

    EMIT PatientAdmitted

    DOC "Admit a patient to a ward."
}
```

## Domain Event

```ddd
EVENT PatientAdmitted @UUID("...") {
    patient_id UUID @REQUIRED,
    ward_id UUID @REQUIRED,
    admitted_at TIMESTAMPTZ @REQUIRED

    DOC "Raised when a patient is admitted."
}
```

## Sourced Event (Event Sourcing)

```ddd
SOURCED_EVENT PatientRegistered @UUID("...") {
    patient_id UUID @REQUIRED,
    name TEXT @REQUIRED

    UPCAST FROM v1 {
        SET name = COALESCE(first_name || ' ' || last_name, "Unknown")
    }

    DOC "Event-sourced patient registration with schema evolution."
}
```

## Policy

```ddd
POLICY NotifyOnAdmission WHEN PatientAdmitted {
    ASYNC ON_FAILURE_AFTER 3

    DOC "Send notification when patient is admitted."
}
```

## Saga

```ddd
SAGA TransferPatient @UUID("...") CORRELATE_BY transfer_id {
    STEP reserve_bed {
        ACTION ReserveBed
        COMPENSATES_WITH ReleaseBed
    }
    STEP transfer {
        ACTION MovePatient
        COMPENSATES_WITH RollbackTransfer
    }

    ON_SUCCESS TransferCompleted
    ON_FAILURE TransferFailed

    DOC "Multi-step patient transfer between wards."
}
```

## State Machine

```ddd
STATE_MACHINE PatientLifecycle @UUID("...") FOR Patient {
    STATE registered
    STATE admitted
    STATE discharged
    STATE deceased

    INITIAL registered

    TRANSITION admit FROM registered TO admitted {
        GUARD patient.active = true
        ACTION AdmitPatient
    }
    TRANSITION discharge FROM admitted TO discharged {
        ACTION DischargePatient
    }

    TERMINAL discharged
    TERMINAL deceased

    DOC "Patient lifecycle state transitions."
}
```

## Lookup Table

```ddd
LOOKUP_TABLE BloodType {
    "A_positive"  @UUID("...") DOC "A+",
    "A_negative"  @UUID("...") DOC "A-",
    "B_positive"  @UUID("...") DOC "B+",
    "O_positive"  @UUID("...") DOC "O+",
    "O_negative"  @UUID("...") DOC "O-",
    "AB_positive" @UUID("...") DOC "AB+",
    "AB_negative" @UUID("...") DOC "AB-"

    DOC "Blood type classification."
}
```

Generates: reference table with UUIDv5 keys + C++ `constexpr` lookup. Never use
PostgreSQL `CHECK` or `ENUM` for this.

## Relationships

```ddd
RELATIONSHIPS {
    patient -> PatientContext.Patient REQUIRED ONE
        VIA patient_id
        DOC "The patient for this encounter.";
    ward -> WardContext.Ward REQUIRED ONE
        VIA ward_id;
}
```

**Critical**: Foreign keys are NEVER inferred from `_id` naming. Every FK requires
an explicit `RELATIONSHIPS {}` declaration.

Cardinality: `ONE`, `MANY`. Optionality: `REQUIRED`, `OPTIONAL`.

## Projection (CQRS Read Model)

```ddd
PROJECTION PatientSummary @UUID("...") {
    patient_id UUID,
    name TEXT,
    total_encounters Integer

    FROM PatientRegistered, PatientAdmitted
    GROUP_BY patient_id
    COMPUTE total_encounters = COUNT(PatientAdmitted)

    DOC "Read model summarizing patient encounters."
}
```

## Specification

```ddd
SPECIFICATION ActivePatient FOR Patient {
    PREDICATE patient.active = true AND patient.discharged_at IS NULL

    DOC "Patients who are currently active."
}
```

## Repository

```ddd
REPOSITORY PatientRepository FOR Patient {
    find_by_mrn(mrn: PatientMRN) -> Patient
    find_active() -> Patient[]
    search_by_name(query: String) -> Patient[]

    DOC "Custom query methods for patients."
}
```

## Domain Service

```ddd
SERVICE TransferService {
    transfer_patient(patient_id: UUID, from_ward: UUID, to_ward: UUID) -> TransferResult

    DOC "Stateless patient transfer orchestration."
}
```

## Extension Point

```ddd
EXTENSION_POINT CustomValidation {
    validate(entity: Patient) -> ValidationResult

    DOC "Plugin extension for custom validation logic."
}
```

## Comments

```ddd
-- Single-line comment
/* Multi-line
   comment */
```

## Annotations Reference

| Annotation | Applies To | Effect |
|------------|-----------|--------|
| `@UUID("...")` | Entity, Event, Aggregate, etc. | Stable identifier for rename tracking |
| `@REQUIRED` | Field | NOT NULL constraint |
| `@UNIQUE` | Field | UNIQUE constraint |
| `@SEARCHABLE` | Field | OpenSearch indexing |
| `@IMMUTABLE` | Field | Cannot be updated after creation |
| `@SPATIAL-QUERYABLE` | Spatial field | PostGIS spatial index |
| `@SOURCE("...")` | Field | Source mapping for projections |
| `@compliance(scheme.tag)` | Field | Compliance annotation (HIPAA, GDPR, etc.) |
| `@quality(scheme.tag)` | Field | Data quality annotation |
| `@unit(name)` | Numeric field | Unit of measure |
| `@ORDER(n)` | Field | Display ordering |
| `@BUILTIN` | Context | Built-in context (not user-defined) |
| `@CASCADE` | Relationship | Cascade delete |
| `@OWNED` | Relationship | Ownership semantics |
| `@SHARED` | Relationship | Shared reference |
| `@EMBEDDED` | Value Object | Embedded storage |
| `@INLINE` | Value Object | Inline storage |
