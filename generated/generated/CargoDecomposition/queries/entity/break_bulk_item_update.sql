-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:350672eafa9d1afa
--  context: CargoDecomposition, entity: BreakBulkItem, operation: update

UPDATE cargo_decomposition.break_bulk_item SET container_id = $2, item_type = $3, weight_kg = $4, requires_crane = $5 WHERE id = $1