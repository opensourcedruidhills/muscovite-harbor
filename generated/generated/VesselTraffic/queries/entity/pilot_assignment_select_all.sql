-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:0655e66c18bb49e6
--  context: VesselTraffic, entity: PilotAssignment, operation: select_all

SELECT id, voyage_id, pilot_name, pilot_zone, boarding_time, disembark_time FROM vessel_traffic.pilot_assignment ORDER BY id