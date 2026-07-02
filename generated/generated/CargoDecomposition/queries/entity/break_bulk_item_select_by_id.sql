-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:7dbfab720a13499c
--  context: CargoDecomposition, entity: BreakBulkItem, operation: select_by_id

SELECT id, container_id, item_type, weight_kg, requires_crane FROM cargo_decomposition.break_bulk_item WHERE id = $1