-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ea3ff5abe85c80bc
--  context: CargoOperations, entity: YardSlot, operation: update

UPDATE cargo_operations.yard_slot SET code = $2, max_weight_kg = $3, max_tier = $4, has_power = $5, is_occupied = $6 WHERE id = $1