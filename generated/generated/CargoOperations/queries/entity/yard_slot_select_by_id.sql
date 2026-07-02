-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:7ae93ff286b253b1
--  context: CargoOperations, entity: YardSlot, operation: select_by_id

SELECT id, code, max_weight_kg, max_tier, has_power, is_occupied FROM cargo_operations.yard_slot WHERE id = $1