-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:222d2f4a64035a27
--  context: CargoDecomposition, entity: BreakBulkItem, operation: select_by_id

SELECT id, id, container_id, item_type, weight_kg, requires_crane FROM cargo_decomposition.break_bulk_item WHERE id = $1