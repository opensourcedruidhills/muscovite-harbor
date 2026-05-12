-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:49447d8aa90b80fb
--  context: CargoOperations, entity: YardSlot, operation: update

UPDATE cargo_operations.yard_slot SET id = $2, code = $3, max_weight_kg = $4, max_tier = $5, has_power = $6, is_occupied = $7 WHERE id = $1