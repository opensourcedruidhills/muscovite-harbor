-- Deploy: cargo_decomposition/foreign-keys

BEGIN;

SET search_path TO cargo_decomposition, public;

ALTER TABLE parcels ADD CONSTRAINT fk_parcels_parcel_id FOREIGN KEY (pallet_id) REFERENCES cargo_decomposition.pallets (id);
ALTER TABLE delivery_units ADD CONSTRAINT fk_delivery_units_delivery_unit_id FOREIGN KEY (parcel_id) REFERENCES cargo_decomposition.parcels (id);

COMMIT;
