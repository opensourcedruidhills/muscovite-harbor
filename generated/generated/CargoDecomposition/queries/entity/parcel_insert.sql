-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d5a81e820ba7d845
--  context: CargoDecomposition, entity: Parcel, operation: insert

INSERT INTO cargo_decomposition.parcel (id, tracking_number, pallet_id, weight_kg, hs_code, description) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id