-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:3926e71678708f8e
--  context: CargoOperations, entity: ReeferUnit, operation: select_by_id

SELECT id, id, container_id, target_temp_c, current_temp_c, is_powered FROM cargo_operations.reefer_unit WHERE id = $1