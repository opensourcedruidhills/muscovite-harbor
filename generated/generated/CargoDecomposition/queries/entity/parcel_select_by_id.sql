-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d9384c09de1b3ee2
--  context: CargoDecomposition, entity: Parcel, operation: select_by_id

SELECT id, tracking_number, pallet_id, weight_kg, hs_code, description FROM cargo_decomposition.parcel WHERE id = $1