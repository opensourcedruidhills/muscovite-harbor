-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8e19c37fe9f8acb9
--  context: HarbourControl, entity: PortCall, operation: insert

INSERT INTO harbour_control.port_call (id, id, vessel_name, imo_number, berth_code, arrival_time, departure_time, container_count, hazmat_permits, total_billed) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10) RETURNING id