-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ccecebf3e383b1ed
--  context: HarbourControl, entity: PortCall, operation: update

UPDATE harbour_control.port_call SET id = $2, vessel_name = $3, imo_number = $4, berth_code = $5, arrival_time = $6, departure_time = $7, container_count = $8, hazmat_permits = $9, total_billed = $10 WHERE id = $1