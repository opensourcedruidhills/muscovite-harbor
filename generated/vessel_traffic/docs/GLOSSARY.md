# Glossary — VesselTraffic

> Ubiquitous language for the **VesselTraffic** bounded context.

## Entities

### Vessel

A registered vessel in the harbour traffic system

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `imo_number` | IMONumber |  | **required** **unique** |
| `mmsi` | MMSI |  | **required** **unique** |
| `call_sign` | CallSign |  | **required** |
| `name` | String |  | **required** |
| `vessel_type` | String |  | **required** |
| `flag_state` | String |  | **required** |
| `is_active` | Boolean |  | **required** |

### Berth

A physical berth where vessels moor

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `code` | BerthCode |  | **required** **unique** |
| `name` | String |  | **required** |
| `max_loa_metres` | Decimal | Maximum vessel LOA this berth can accommodate | **required** |
| `max_draft_metres` | Decimal | Maximum draft at lowest astronomical tide | **required** |
| `max_beam_metres` | Decimal |  | **required** |
| `has_crane_access` | Boolean |  | **required** |
| `has_reefer_plugs` | Boolean |  | **required** |
| `is_active` | Boolean |  | **required** |

### Voyage

A single vessel call at the harbour

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `vessel_id` | UUID |  | **required** |
| `berth_id` | UUID |  | |
| `voyage_number` | String |  | **required** **unique** |
| `eta` | DateTime |  | **required** |
| `ata` | DateTime |  | |
| `etd` | DateTime |  | |
| `atd` | DateTime |  | |
| `cargo_category` | String |  | **required** |
| `status` | String |  | **required** |

**Relationships:**

- **Voyage**: to-one → **Vessel** [required]
- **Voyage**: to-one → **Berth**

### PilotAssignment

Assignment of a pilot to a voyage

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `voyage_id` | UUID |  | **required** |
| `pilot_name` | String |  | **required** |
| `pilot_zone` | String |  | **required** |
| `boarding_time` | DateTime |  | |
| `disembark_time` | DateTime |  | |

**Relationships:**

- **PilotAssignment**: to-one → **Voyage** [required]

### TugBooking

Booking of a tug for vessel manoeuvring

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `voyage_id` | UUID |  | **required** |
| `tug_name` | String |  | **required** |
| `bollard_pull_t` | Decimal | Bollard pull in tonnes | **required** |
| `is_confirmed` | Boolean |  | **required** |

**Relationships:**

- **TugBooking**: to-one → **Voyage** [required]

### TideWindow

A tidal window with navigable draft at a specific berth

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `berth_id` | UUID |  | **required** |
| `tide_height_metres` | Decimal | Predicted tide height above chart datum | **required** |
| `available_draft` | Decimal | Effective navigable draft = berth depth + tide height | **required** |

**Relationships:**

- **TideWindow**: to-one → **Berth** [required]

## Value Objects

### Dimensions

**Storage mode:** inline

| Field | Type | Description |
|-------|------|-------------|
| `loa_metres` | Decimal | Length overall in metres |
| `beam_metres` | Decimal | Beam (width) in metres |
| `draft_metres` | Decimal | Current draft in metres |

**Invariants:**

- **valid_proportions**

### GeoPosition

**Storage mode:** inline

| Field | Type | Description |
|-------|------|-------------|
| `latitude` | Decimal |  |
| `longitude` | Decimal |  |

### TimeWindow

**Storage mode:** inline

| Field | Type | Description |
|-------|------|-------------|
| `window_start` | DateTime |  |
| `window_end` | DateTime |  |

**Invariants:**

- **valid_range**

## Domain Events

### VesselAnnounced

A vessel has announced its arrival

| Field | Type |
|-------|------|
| `voyage_id` | UUID |
| `vessel_id` | UUID |
| `eta` | DateTime |

### BerthAllocated

A berth has been allocated to a voyage

| Field | Type |
|-------|------|
| `voyage_id` | UUID |
| `berth_id` | UUID |

### PilotDispatched

Pilot dispatched to meet inbound vessel

| Field | Type |
|-------|------|
| `voyage_id` | UUID |
| `pilot_name` | String |

### VesselMooredEvent

Vessel has been moored at berth

| Field | Type |
|-------|------|
| `voyage_id` | UUID |
| `berth_id` | UUID |
| `moored_at` | DateTime |

### VesselDepartedEvent

Vessel has departed harbour

| Field | Type |
|-------|------|
| `voyage_id` | UUID |
| `departed_at` | DateTime |

## Specifications

### AvailableBerths

### VesselsByETA

## Strong Types

### IMONumber

**Base type:** TEXT 

IMO vessel identification number (7 digits)

### MMSI

**Base type:** TEXT 

Maritime Mobile Service Identity (9 digits)

### CallSign

**Base type:** TEXT 

International radio call sign

### BerthCode

**Base type:** TEXT 

Berth identifier (e.g. NQ-12, SC-3)

## Lookup Tables

### VesselType

Classification of vessel types

### CargoCategory

High-level cargo classification

### PilotZone

Pilotage zones within harbour limits

