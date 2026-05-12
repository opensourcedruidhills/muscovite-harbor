-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:b780e8bfbd52b3a5
--  context: VesselTraffic, entity: PilotAssignment, operation: select_by_id

SELECT id, id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time FROM vessel_traffic.pilot_assignment WHERE id = $1