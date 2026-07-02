-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:9daa6392219e47ad
--  context: CargoOperations, entity: ReeferUnit, operation: select_by_id

SELECT id, container_id, target_temp_c, current_temp_c, is_powered FROM cargo_operations.reefer_unit WHERE id = $1