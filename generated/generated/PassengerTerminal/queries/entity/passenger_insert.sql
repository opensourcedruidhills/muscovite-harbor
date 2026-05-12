-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:e6e5dc41109314d8
--  context: PassengerTerminal, entity: Passenger, operation: insert

INSERT INTO passenger_terminal.passenger (id, id, booking_ref, passenger_type, voyage_id, status) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id