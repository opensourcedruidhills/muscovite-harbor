-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:202ae334e91a8c95
--  context: CargoDecomposition, entity: Parcel, operation: update

UPDATE cargo_decomposition.parcel SET tracking_number = $2, pallet_id = $3, weight_kg = $4, hs_code = $5, description = $6 WHERE id = $1