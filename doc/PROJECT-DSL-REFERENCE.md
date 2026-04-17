# Project DSL Reference (.mus files)

The `.mus` file is the project configuration. It defines databases, frontends,
generation targets, capabilities, and infrastructure settings.

**For definitive syntax, read the PEG grammar** shipped with muscomp.

## Project Block

```mus
PROJECT my_project {
    VERSION "1.0.0"
    DESCRIPTION "My Muscovite consumer project"
    OUTPUT "generated"

    -- All configuration sections go here
}
```

## Context Files

Reference `.ddd` domain model files:

```mus
CONTEXT_FILES {
    "contexts/patient.ddd"
    "contexts/encounter.ddd"
    "contexts/billing.ddd"
}
```

Or for domain-level files:

```mus
DOMAIN_FILES {
    "domain/shared-types.ddd"
}
```

## Database Configuration

```mus
DATABASE "primary" {
    URI "postgresql://user:pass@localhost:5432/mydb"
    POOL_MIN 5
    POOL_MAX 20
    RETRY {
        MAX_RETRIES 3
        BACKOFF_ALGORITHM "Exponential"  -- or "Linear", "Fixed"
        BACKOFF_BASE "100ms"
        BACKOFF_MAX "5s"
        RETRY_ON_CONNECTION_ERROR true
        RETRY_ON_SERIALIZATION true
    }
}
```

## Frontend Configuration

```mus
FRONTEND "qt_widgets" {
    ENABLED true
    APP_NAME "My Application"
    STYLE "Fusion"
    THEME "Light"       -- or "Dark"
    MDI true            -- Multiple Document Interface
    STARTUP_CONTEXT "main"
}
```

## Generation Targets

```mus
GENERATE {
    CPP_DBA true
    CPP_DBA_TEST true
    GRPC true
    QT_WIDGETS true
    QT true
}
```

## Capabilities

Enable optional features:

```mus
CAPABILITIES {
    "security"
    "event_sourcing"
    "telemetry"
    "search"
    "messaging"
}
```

| Capability | What it enables |
|------------|----------------|
| `security` | OAuth2, RBAC, JWT authentication |
| `event_sourcing` | Event store, sourced events, projections |
| `telemetry` | OpenTelemetry tracing and metrics |
| `search` | OpenSearch full-text search for `@searchable` fields |
| `messaging` | NATS JetStream outbox pattern |

## OAuth2

```mus
OAUTH2 {
    ENABLED true
    MODE "builtin"          -- or "external"
    PROVIDER "Keycloak"
    CLIENT_ID "my-app"
    CLIENT_SECRET "secret"
    SCOPES { "openid" "profile" "email" }
    AUTH_ENDPOINT "https://auth.example.com/authorize"
    TOKEN_ENDPOINT "https://auth.example.com/token"
    JWKS_URI "https://auth.example.com/.well-known/jwks.json"
}
```

## Plugin System

```mus
PLUGIN "ExternalValidator" {
    IMPLEMENTS "PatientContext.Patient"
    TRANSPORT "LocalGRPC"       -- or "SyncVirtual", "QtRemoteObjects"
    CIRCUIT_BREAKER {
        FAILURE_THRESHOLD 5
        TIMEOUT "30s"
        BACKOFF_ALGORITHM "Exponential"
        JITTER_PCT 10
        ON_OPEN "Block"         -- or "Emit", "Probe"
        ON_HALF_OPEN "Probe"
        ON_TRIP "Emit"
    }
}
```

## Server Configuration

```mus
SERVER {
    GRPC_DEFAULT_DEADLINE "5s"
    GRPC_MAX_DEADLINE "30s"
}
```

## Telemetry (OpenTelemetry)

```mus
TELEMETRY {
    OTLP_ENDPOINT "http://collector:4317"
    SERVICE_NAME "my-service"
    SAMPLING_RATE 0.1
}
```

## Outbox Pattern (NATS)

```mus
OUTBOX {
    ENABLED true
    NATS_URL "nats://localhost:4222"
    POLL_INTERVAL "100ms"
    BATCH_SIZE 100
}
```

## Search (OpenSearch)

```mus
SEARCH {
    HOST "localhost"
    PORT 9200
    INDEX_PREFIX "myapp"
}
```

## Messaging (NATS)

```mus
MESSAGING {
    HOST "localhost"
    PORT 4222
    SUBJECTS {
        "events.>"
        "commands.>"
    }
    JETSTREAM_ENABLED true
}
```

## TLA+ Verification

```mus
TLAPLUS {
    SPEC_PATHS {
        "specs/saga.tla"
    }
    INVARIANTS {
        "TypeOK"
        "NoDeadlock"
    }
    MAX_DEPTH 20
    WORKERS 4
}
```

## Presentation Profiles

```mus
PRESENTATION_PROFILES {
    "layouts/desktop.lay"
    "layouts/tablet.lay"
}
```
