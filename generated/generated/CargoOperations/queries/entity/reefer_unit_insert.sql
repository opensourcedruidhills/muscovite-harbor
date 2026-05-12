-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:af2f58ed8d0e8c11
--  context: CargoOperations, entity: ReeferUnit, operation: insert

INSERT INTO cargo_operations.reefer_unit (id, id, container_id, target_temp_c, current_temp_c, is_powered) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id