-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:b40a7e905720b325
--  context: CargoDecomposition, entity: Pallet, operation: insert

INSERT INTO cargo_decomposition.pallet (id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code) VALUES ($1, $2, $3, $4, $5, $6, $7, $8) RETURNING id