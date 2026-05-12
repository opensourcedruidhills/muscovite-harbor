-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:12704867556d6a29
--  context: CargoDecomposition, entity: Parcel, operation: select_by_id

SELECT id, id, tracking_number, pallet_id, weight_kg, hs_code, description FROM cargo_decomposition.parcel WHERE id = $1