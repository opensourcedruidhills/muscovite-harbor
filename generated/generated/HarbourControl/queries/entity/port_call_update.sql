-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:e49b19ce334c4ebe
--  context: HarbourControl, entity: PortCall, operation: update

UPDATE harbour_control.port_call SET vessel_name = $2, imo_number = $3, berth_code = $4, arrival_time = $5, departure_time = $6, container_count = $7, hazmat_permits = $8, total_billed = $9 WHERE id = $1