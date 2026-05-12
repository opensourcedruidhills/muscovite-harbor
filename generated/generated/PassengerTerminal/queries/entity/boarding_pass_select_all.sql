-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:6cc697179de7ae2b
--  context: PassengerTerminal, entity: BoardingPass, operation: select_all

SELECT id, id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at FROM passenger_terminal.boarding_pass ORDER BY id