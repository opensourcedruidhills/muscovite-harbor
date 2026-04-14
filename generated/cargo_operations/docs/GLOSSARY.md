# Glossary — CargoOperations

> Ubiquitous language for the **CargoOperations** bounded context.

## Entities

### Container

A shipping container in terminal operations

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `container_number` | ContainerNumber |  | **required** **unique** |
| `size_category` | String |  | **required** |
| `hazmat_class` | String |  | |
| `voyage_id` | UUID |  | **required** |
| `yard_slot_id` | UUID |  | |
| `status` | String |  | **required** |

### YardSlot

A position in the container yard (bay-row-tier)

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `code` | YardSlotCode |  | **required** **unique** |
| `max_weight_kg` | Decimal |  | **required** |
| `max_tier` | Integer | Maximum stacking height | **required** |
| `has_power` | Boolean | Has reefer power connection | **required** |
| `is_occupied` | Boolean |  | **required** |

### Crane

A crane for container handling

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `name` | String |  | **required** |
| `crane_type` | String |  | **required** |
| `max_lift_kg` | Decimal |  | **required** |
| `is_active` | Boolean |  | **required** |

### ReeferUnit

Refrigeration monitoring unit for a reefer container

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `container_id` | UUID |  | **required** |
| `target_temp_c` | Decimal | Target temperature in Celsius | **required** |
| `current_temp_c` | Decimal |  | |
| `is_powered` | Boolean |  | **required** |

**Relationships:**

- **ReeferUnit**: to-one → **Container** [required]

### LoadPlan

Plan for loading/discharging containers for a voyage

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `voyage_id` | UUID |  | **required** |
| `created_at` | DateTime |  | **required** |
| `status` | String |  | **required** |

### DischargeSequence

Ordered sequence for container discharge

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `load_plan_id` | UUID |  | **required** |
| `container_id` | UUID |  | **required** |
| `sequence_order` | Integer |  | **required** |
| `crane_id` | UUID |  | |

**Relationships:**

- **DischargeSequence**: to-one → **LoadPlan** [required]
- **DischargeSequence**: to-one → **Container** [required]
- **DischargeSequence**: to-one → **Crane**

## Value Objects

### ContainerDimensions

**Storage mode:** inline

| Field | Type | Description |
|-------|------|-------------|
| `length_ft` | Integer | Container length: 20, 40, or 45 feet |
| `weight_kg` | Decimal | Gross weight in kilograms |
| `is_reefer` | Boolean |  |

## Strong Types

### ContainerNumber

**Base type:** TEXT 

ISO 6346 container number (4 letters + 7 digits)

### YardSlotCode

**Base type:** TEXT 

Yard slot address: bay-row-tier (e.g. A01-03-02)

## Lookup Tables

### ContainerSize

Standard container sizes

### HazmatClass

IMO hazardous materials classification

---

## Modules

### Module: YardManagement

Yard slot allocation and container positioning

### Module: CraneScheduling

Crane assignment and cycle optimisation

### Module: ReeferMonitoring

Temperature monitoring and alarm handling for reefer containers

