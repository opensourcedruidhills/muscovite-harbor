-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:5777b8b41c34ca51
--  context: VesselTraffic, entity: PilotAssignment, operation: insert

INSERT INTO vessel_traffic.pilot_assignment (id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id