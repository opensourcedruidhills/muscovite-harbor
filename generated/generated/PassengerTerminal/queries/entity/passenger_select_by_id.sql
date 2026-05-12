-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:667f62a0c196ade3
--  context: PassengerTerminal, entity: Passenger, operation: select_by_id

SELECT id, id, booking_ref, passenger_type, voyage_id, status FROM passenger_terminal.passenger WHERE id = $1