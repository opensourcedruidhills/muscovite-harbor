# Glossary — IntermodalTransfer

> Ubiquitous language for the **IntermodalTransfer** bounded context.

## Entities

### TransferSlot

A time slot for container transfer to outbound transport

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `reference` | SlotReference |  | **required** **unique** |
| `container_id` | UUID |  | **required** |
| `transport_mode` | String |  | **required** |
| `scheduled_at` | DateTime |  | **required** |
| `status` | String |  | **required** |

### TruckVisit

A truck arriving for container pickup

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `truck_plate` | TruckPlate |  | **required** |
| `carrier_name` | String |  | **required** |
| `slot_id` | UUID |  | **required** |
| `arrived_at` | DateTime |  | |
| `departed_at` | DateTime |  | |

**Relationships:**

- **TruckVisit**: to-one → **TransferSlot** [required]

### RailWagon

A rail wagon for container transport

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `wagon_number` | String |  | **required** **unique** |
| `max_weight_kg` | Decimal |  | **required** |
| `slot_id` | UUID |  | |

### BargeBooking

Booking for barge transport of containers

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `barge_name` | String |  | **required** |
| `capacity_teu` | Integer |  | **required** |
| `departure_at` | DateTime |  | **required** |
| `status` | String |  | **required** |

### ChassisUnit

Chassis for container road transport

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `chassis_number` | String |  | **required** **unique** |
| `chassis_type` | String |  | **required** |
| `is_available` | Boolean |  | **required** |

## Domain Events

### YardExitReserved

Yard exit slot reserved for container

| Field | Type |
|-------|------|
| `slot_id` | UUID |
| `container_id` | UUID |

### GateCheckoutCompleted

Container cleared gate checkout

| Field | Type |
|-------|------|
| `slot_id` | UUID |
| `truck_plate` | String |

### TransportLoaded

Container loaded onto outbound transport

| Field | Type |
|-------|------|
| `slot_id` | UUID |
| `transport_mode` | String |

### DepartureConfirmed

Outbound transport has departed

| Field | Type |
|-------|------|
| `slot_id` | UUID |
| `departed_at` | DateTime |

### HandoffFailed

Handoff failed — requires compensation

| Field | Type |
|-------|------|
| `slot_id` | UUID |
| `reason` | String |

## Domain Services

### OptimalTransportSelector

Selects best transport mode based on urgency, destination, and availability

## Strong Types

### SlotReference

**Base type:** TEXT 

Transfer slot reference (e.g. TS-20260415-0001)

### TruckPlate

**Base type:** TEXT 

Truck licence plate number

