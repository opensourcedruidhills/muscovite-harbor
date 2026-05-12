-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:3edeb401d2a35782
--  context: VesselTraffic, entity: TugBooking, operation: insert

INSERT INTO vessel_traffic.tug_booking (id, id, voyage_id, tug_name, bollard_pull_t, is_confirmed) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id