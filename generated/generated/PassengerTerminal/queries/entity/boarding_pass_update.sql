-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:92599e83e84ca1ad
--  context: PassengerTerminal, entity: BoardingPass, operation: update

UPDATE passenger_terminal.boarding_pass SET passenger_id = $2, gate_id = $3, boarding_group = $4, seat_number = $5, issued_at = $6, scanned_at = $7 WHERE id = $1