-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d41d6d1dc9bdf6fe
--  context: VesselTraffic, entity: PilotAssignment, operation: update

UPDATE vessel_traffic.pilot_assignment SET id = $2, voyage_id = $3, pilot_name = $4, pilot_zone = $5, boarding_time = $6, disembark_time = $7 WHERE id = $1