-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:a1ddd65af6fd7785
--  context: CargoDecomposition, entity: Pallet, operation: insert

INSERT INTO cargo_decomposition.pallet (id, id, pallet_id, container_id, weight_kg, length_cm, width_cm, height_cm, hs_code) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9) RETURNING id