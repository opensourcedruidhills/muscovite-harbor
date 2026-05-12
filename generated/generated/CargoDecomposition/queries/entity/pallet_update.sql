-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d443151ee81e0d66
--  context: CargoDecomposition, entity: Pallet, operation: update

UPDATE cargo_decomposition.pallet SET id = $2, pallet_id = $3, container_id = $4, weight_kg = $5, length_cm = $6, width_cm = $7, height_cm = $8, hs_code = $9 WHERE id = $1