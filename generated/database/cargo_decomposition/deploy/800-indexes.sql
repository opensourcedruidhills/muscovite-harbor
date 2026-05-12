-- Deploy: cargo_decomposition/indexes

BEGIN;

SET search_path TO cargo_decomposition, public;

CREATE INDEX IF NOT EXISTS idx_parcels_pallet_id ON parcels (pallet_id);
CREATE INDEX IF NOT EXISTS idx_delivery_units_tracking_number ON delivery_units (tracking_number);
CREATE INDEX IF NOT EXISTS idx_outbox_unprocessed ON outbox (created_at);

COMMIT;
