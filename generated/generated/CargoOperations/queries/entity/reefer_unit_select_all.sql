-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:6d3888c6d9930015
--  context: CargoOperations, entity: ReeferUnit, operation: select_all

SELECT id, container_id, target_temp_c, current_temp_c, is_powered FROM cargo_operations.reefer_unit ORDER BY id