-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:f149c7277bcff720
--  context: PassengerTerminal, entity: Passenger, operation: update

UPDATE passenger_terminal.passenger SET id = $2, booking_ref = $3, passenger_type = $4, voyage_id = $5, status = $6 WHERE id = $1