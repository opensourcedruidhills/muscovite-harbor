-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:e35897857791399f
--  context: CargoOperations, entity: ReeferUnit, operation: update

UPDATE cargo_operations.reefer_unit SET container_id = $2, target_temp_c = $3, current_temp_c = $4, is_powered = $5 WHERE id = $1