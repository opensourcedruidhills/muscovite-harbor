-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:9563ed6e4d6a7e3e
--  context: PassengerTerminal, entity: Passenger, operation: select_by_id

SELECT id, booking_ref, passenger_type, voyage_id, status FROM passenger_terminal.passenger WHERE id = $1