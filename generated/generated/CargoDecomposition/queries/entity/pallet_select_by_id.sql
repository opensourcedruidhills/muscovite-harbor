-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8d6a92a44587893e
--  context: CargoDecomposition, entity: Pallet, operation: select_by_id

SELECT id, id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code FROM cargo_decomposition.pallet WHERE id = $1