-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:2a0d8899ede1549d
--  context: CargoDecomposition, entity: Pallet, operation: select_all

SELECT id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code FROM cargo_decomposition.pallet ORDER BY id