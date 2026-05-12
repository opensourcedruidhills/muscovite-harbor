-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:a72c0dd6db791b8b
--  context: PassengerTerminal, entity: BoardingPass, operation: update

UPDATE passenger_terminal.boarding_pass SET id = $2, passenger_id = $3, gate_id = $4, boarding_group = $5, seat_number = $6, issued_at = $7, scanned_at = $8 WHERE id = $1