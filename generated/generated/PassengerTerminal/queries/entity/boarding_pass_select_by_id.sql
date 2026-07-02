-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:6cc0d4824cadd9c0
--  context: PassengerTerminal, entity: BoardingPass, operation: select_by_id

SELECT id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at FROM passenger_terminal.boarding_pass WHERE id = $1