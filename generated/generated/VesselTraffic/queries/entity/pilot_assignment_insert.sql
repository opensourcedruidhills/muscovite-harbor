-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ef900f5a06256659
--  context: VesselTraffic, entity: PilotAssignment, operation: insert

INSERT INTO vessel_traffic.pilot_assignment (id, id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id