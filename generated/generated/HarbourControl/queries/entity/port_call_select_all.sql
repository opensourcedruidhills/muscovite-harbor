-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:c039533d98259121
--  context: HarbourControl, entity: PortCall, operation: select_all

SELECT id, id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed FROM harbour_control.port_call ORDER BY id