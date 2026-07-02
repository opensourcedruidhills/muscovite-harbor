-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:1351d23ad778eea1
--  context: CargoDecomposition, entity: Pallet, operation: update

UPDATE cargo_decomposition.pallet SET pallet_id = $2, container_id = $3, weight_kg = $4, length_cm = $5, width_cm = $6, height_cm = $7, hs_code = $8 WHERE id = $1