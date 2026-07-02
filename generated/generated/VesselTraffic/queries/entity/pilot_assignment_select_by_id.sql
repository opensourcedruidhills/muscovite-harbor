-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:4c4419b23c3ff476
--  context: VesselTraffic, entity: PilotAssignment, operation: select_by_id

SELECT id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time FROM vessel_traffic.pilot_assignment WHERE id = $1