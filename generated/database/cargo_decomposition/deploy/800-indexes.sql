-- Deploy: cargo_decomposition/indexes

BEGIN;

SET search_path TO cargo_decomposition, public;

CREATE INDEX IF NOT EXISTS idx_parcels_parcel_id ON parcels (parcel_id);
CREATE INDEX IF NOT EXISTS idx_delivery_units_delivery_unit_id ON delivery_units (delivery_unit_id);

COMMIT;
