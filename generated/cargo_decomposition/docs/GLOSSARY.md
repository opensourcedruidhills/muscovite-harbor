# Glossary — CargoDecomposition

> Ubiquitous language for the **CargoDecomposition** bounded context.

## Entities

### Pallet

A pallet extracted from a container

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `pallet_id` | PalletId |  | **required** **unique** |
| `container_id` | UUID |  | **required** |
| `weight_kg` | Decimal |  | **required** |
| `length_cm` | Decimal |  | **required** |
| `width_cm` | Decimal |  | **required** |
| `height_cm` | Decimal |  | **required** |
| `hs_code` | HSCode |  | **required** |

### Parcel

An individual parcel within a pallet

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `tracking_number` | TrackingNumber |  | **required** **unique** |
| `pallet_id` | UUID |  | **required** |
| `weight_kg` | Decimal |  | **required** |
| `hs_code` | HSCode |  | **required** |
| `description` | String |  | **required** |

**Relationships:**

- **Parcel**: to-one → **Pallet** [required]

### DeliveryUnit

Last-mile delivery unit dispatched from terminal

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `tracking_number` | TrackingNumber |  | **required** |
| `destination` | String |  | **required** |
| `carrier` | String |  | **required** |
| `dispatched_at` | DateTime |  | |

**Relationships:**

- **DeliveryUnit**: to-one → **Parcel** [required]

### BreakBulkItem

Non-containerised cargo item requiring special handling

| Field | Type | Description | Flags |
|-------|------|-------------|-------|
| `id` | UUID |  | **required** |
| `container_id` | UUID |  | **required** |
| `item_type` | String |  | **required** |
| `weight_kg` | Decimal |  | **required** |
| `requires_crane` | Boolean |  | **required** |

## Value Objects

### Dimensions

**Storage mode:** inline

| Field | Type | Description |
|-------|------|-------------|
| `length_cm` | Decimal |  |
| `width_cm` | Decimal |  |
| `height_cm` | Decimal |  |

### Weight

**Storage mode:** shared

| Field | Type | Description |
|-------|------|-------------|
| `value_kg` | Decimal |  |

## Domain Events

### ContainerUnpacked

Container has been fully unpacked into pallets

| Field | Type |
|-------|------|
| `container_id` | UUID |
| `pallet_count` | Integer |

### PalletWeightVerified

Pallet weight verified against manifest

| Field | Type |
|-------|------|
| `pallet_id` | UUID |
| `verified_kg` | Decimal |

### ParcelDispatched

Parcel dispatched for last-mile delivery

| Field | Type |
|-------|------|
| `tracking_number` | String |
| `carrier` | String |

## Strong Types

### PalletId

**Base type:** TEXT 

Pallet identifier (e.g. PLT-ABC12345)

### TrackingNumber

**Base type:** TEXT 

Parcel tracking number

### HSCode

**Base type:** TEXT 

Harmonised System tariff classification code

