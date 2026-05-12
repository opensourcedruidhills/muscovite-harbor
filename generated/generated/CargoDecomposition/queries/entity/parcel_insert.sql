-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:c9a2a16a36414a67
--  context: CargoDecomposition, entity: Parcel, operation: insert

INSERT INTO cargo_decomposition.parcel (id, id, tracking_number, pallet_id, weight_kg, hs_code, description) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id