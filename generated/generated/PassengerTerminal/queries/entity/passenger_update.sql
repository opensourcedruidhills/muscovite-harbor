-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:62e6cb11615dec6a
--  context: PassengerTerminal, entity: Passenger, operation: update

UPDATE passenger_terminal.passenger SET booking_ref = $2, passenger_type = $3, voyage_id = $4, status = $5 WHERE id = $1