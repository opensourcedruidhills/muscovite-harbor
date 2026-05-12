-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:2b44df1234eb299e
--  context: CargoDecomposition, entity: BreakBulkItem, operation: insert

INSERT INTO cargo_decomposition.break_bulk_item (id, id, container_id, item_type, weight_kg, requires_crane) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id