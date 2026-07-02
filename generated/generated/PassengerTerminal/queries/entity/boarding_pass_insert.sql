-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:9a8f9207f8ecf7ae
--  context: PassengerTerminal, entity: BoardingPass, operation: insert

INSERT INTO passenger_terminal.boarding_pass (id, passenger_id, gate_id, boarding_group, seat_number, issued_at, scanned_at) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id