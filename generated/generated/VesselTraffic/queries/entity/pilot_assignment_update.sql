-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ba188bf06931a677
--  context: VesselTraffic, entity: PilotAssignment, operation: update

UPDATE vessel_traffic.pilot_assignment SET voyage_id = $2, pilot_name = $3, pilot_zone = $4, boarding_time = $5, disembark_time = $6 WHERE id = $1