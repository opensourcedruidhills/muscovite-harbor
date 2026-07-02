-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:90ab10b7f08c8332
--  context: HarbourControl, entity: PortCall, operation: select_by_id

SELECT id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed FROM harbour_control.port_call WHERE id = $1