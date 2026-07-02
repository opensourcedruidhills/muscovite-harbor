-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:0fb7c804685d5142
--  context: CargoDecomposition, entity: Parcel, operation: select_all

SELECT id, tracking_number, pallet_id, weight_kg, hs_code, description FROM cargo_decomposition.parcel ORDER BY id