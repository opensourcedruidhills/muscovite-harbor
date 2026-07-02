-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:2c631081592d30a8
--  context: PassengerTerminal, entity: BoardingPass, operation: select_all

SELECT id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at FROM passenger_terminal.boarding_pass ORDER BY id