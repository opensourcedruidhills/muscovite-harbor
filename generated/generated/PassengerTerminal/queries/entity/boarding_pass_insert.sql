-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:b4de9e9be89d1899
--  context: PassengerTerminal, entity: BoardingPass, operation: insert

INSERT INTO passenger_terminal.boarding_pass (id, id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at) VALUES ($1, $2, $3, $4, $5, $6, $7, $8) RETURNING id