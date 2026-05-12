-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:aacbde24134ed516
--  context: CargoOperations, entity: YardSlot, operation: select_by_id

SELECT id, id, code, max_weight_kg, max_tier, has_power, is_occupied FROM cargo_operations.yard_slot WHERE id = $1