-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:0de7fd4daf36f059
--  context: HarbourControl, entity: PortCall, operation: select_by_id

SELECT id, id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed FROM harbour_control.port_call WHERE id = $1