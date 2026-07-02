-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ee29dd46220750d9
--  context: CargoOperations, entity: YardSlot, operation: select_all

SELECT id, code, max_weight_kg, max_tier, has_power, is_occupied FROM cargo_operations.yard_slot ORDER BY id