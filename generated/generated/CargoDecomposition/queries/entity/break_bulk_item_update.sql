-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:46673ff5157a4e50
--  context: CargoDecomposition, entity: BreakBulkItem, operation: update

UPDATE cargo_decomposition.break_bulk_item SET id = $2, container_id = $3, item_type = $4, weight_kg = $5, requires_crane = $6 WHERE id = $1