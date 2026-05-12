-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:6bc137c510918d30
--  context: CargoDecomposition, entity: Parcel, operation: update

UPDATE cargo_decomposition.parcel SET id = $2, tracking_number = $3, pallet_id = $4, weight_kg = $5, hs_code = $6, description = $7 WHERE id = $1