-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:82e16b4b44e079bf
--  context: VesselTraffic, entity: TugBooking, operation: insert

INSERT INTO vessel_traffic.tug_booking (id, voyage_id, tug_name, bollard_pull_t, is_confirmed) VALUES ($1, $2, $3, $4, $5) RETURNING id