-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:841f88f72021e95b
--  context: PassengerTerminal, entity: BoardingPass, operation: select_by_id

SELECT id, id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at FROM passenger_terminal.boarding_pass WHERE id = $1