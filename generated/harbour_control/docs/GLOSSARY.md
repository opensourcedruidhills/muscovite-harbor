# Glossary — HarbourControl

> Ubiquitous language for the **HarbourControl** bounded context.

## Entities

### SafetyZone

Designated safety zone within the port area

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `zone_code` | ZoneCode |  | **required** **unique** |
| `zone_name` | String |  | **required** |
| `security_level` | String |  | **required** |
| `max_hazmat_class` | Integer |  | **required** |
| `is_restricted` | Boolean |  | **required** |

### HazmatPermit

Hazmat handling permit issued by port authority

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `permit_number` | PermitNumber |  | **required** **unique** |
| `vessel_id` | UUID |  | **required** |
| `imo_class` | Integer |  | **required** |
| `quantity_kg` | Decimal |  | **required** |
| `approved` | Boolean |  | **required** |
| `valid_from` | DateTime |  | **required** |
| `valid_until` | DateTime |  | **required** |

### InvoiceLine

Port services invoice line item

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `vessel_id` | UUID |  | **required** |
| `service_type` | String |  | **required** |
| `amount` | Decimal |  | **required** |
| `currency` | String |  | **required** |
| `issued_at` | DateTime |  | **required** |

### PortCall

Read-only aggregation across VesselTraffic, CargoOps, and billing

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `vessel_name` | String |  | **required** |
| `imo_number` | String |  | **required** |
| `berth_code` | String |  | |
| `arrival_time` | DateTime |  | |
| `departure_time` | DateTime |  | |
| `container_count` | Integer |  | **required** |
| `hazmat_permits` | Integer |  | **required** |
| `total_billed` | Decimal |  | **required** |

## Domain Events

### VesselPositionUpdated

Vessel position update from radar translation

| Field | Type |
|-------|------|
| `mmsi` | String |
| `latitude` | Decimal |
| `longitude` | Decimal |

### HazmatPermitApproved

Hazmat permit approved by port authority

| Field | Type |
|-------|------|
| `permit_number` | String |
| `vessel_id` | UUID |

## Strong Types

### PermitNumber

**Base type:** TEXT 

Hazmat permit number (e.g. HP-2026-000123)

### ZoneCode

**Base type:** TEXT 

Safety zone code (e.g. SZ-NQ01)

