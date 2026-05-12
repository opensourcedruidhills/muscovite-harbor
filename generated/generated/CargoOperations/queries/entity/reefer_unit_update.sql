-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:be9ecf9bec8c70ff
--  context: CargoOperations, entity: ReeferUnit, operation: update

UPDATE cargo_operations.reefer_unit SET id = $2, container_id = $3, target_temp_c = $4, current_temp_c = $5, is_powered = $6 WHERE id = $1