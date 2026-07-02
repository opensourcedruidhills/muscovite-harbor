-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:e37efe34bea542ac
--  context: CargoOperations, entity: ReeferUnit, operation: insert

INSERT INTO cargo_operations.reefer_unit (id, container_id, target_temp_c, current_temp_c, is_powered) VALUES ($1, $2, $3, $4, $5) RETURNING id