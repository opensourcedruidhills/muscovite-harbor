# Glossary — PassengerTerminal

> Ubiquitous language for the **PassengerTerminal** bounded context.

## Entities

### Passenger

A passenger travelling on a voyage

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `booking_ref` | BookingReference |  | **required** **unique** |
| `passenger_type` | String |  | **required** |
| `voyage_id` | UUID |  | **required** |
| `status` | String |  | **required** |

### Gate

A physical gate in the passenger terminal

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `code` | GateCode |  | **required** **unique** |
| `name` | String |  | **required** |
| `capacity` | Integer | Maximum passengers in gate area | **required** |
| `status` | String |  | **required** |
| `voyage_id` | UUID |  | |

### BoardingPass

Issued boarding pass for a passenger

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `passenger_id` | UUID |  | **required** |
| `gate_id` | UUID |  | |
| `boarding_group` | String |  | **required** |
| `seat_number` | String |  | |
| `issued_at` | DateTime |  | **required** |
| `scanned_at` | DateTime |  | |

**Relationships:**

- **BoardingPass**: to-one → **Passenger** [required]
- **BoardingPass**: to-one → **Gate**

## Value Objects

### PassengerName

**Storage mode:** inline

| Field | Type | Description |
|-------|------|-------------|
| `given_name` | String |  |
| `family_name` | String |  |

## Domain Events

### PassengerCheckedIn

Passenger completed check-in

| Field | Type |
|-------|------|
| `passenger_id` | UUID |
| `voyage_id` | UUID |
| `checked_in_at` | DateTime |

### BoardingPassIssued

Boarding pass issued to passenger

| Field | Type |
|-------|------|
| `boarding_pass_id` | UUID |
| `passenger_id` | UUID |
| `gate_id` | UUID |

### GateStatusChanged

Gate status transition

| Field | Type |
|-------|------|
| `gate_id` | UUID |
| `new_status` | String |

## Strong Types

### BookingReference

**Base type:** TEXT 

Passenger booking reference (e.g. AB123456)

### GateCode

**Base type:** TEXT 

Terminal gate identifier (e.g. G1, G12)

## Lookup Tables

### PassengerType

Passenger classification

