-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:2ce8ad20e75ca80f
--  context: PassengerTerminal, entity: Passenger, operation: insert

INSERT INTO passenger_terminal.passenger (id, booking_ref, passenger_type, voyage_id, status) VALUES ($1, $2, $3, $4, $5) RETURNING id