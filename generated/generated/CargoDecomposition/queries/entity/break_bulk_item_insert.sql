-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:0621e07b92a2f1ad
--  context: CargoDecomposition, entity: BreakBulkItem, operation: insert

INSERT INTO cargo_decomposition.break_bulk_item (id, container_id, item_type, weight_kg, requires_crane) VALUES ($1, $2, $3, $4, $5) RETURNING id