-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:c6d9c56bd0eacb48
--  context: PassengerTerminal, entity: Gate, operation: insert

INSERT INTO passenger_terminal.gate (id, code, name, capacity, status, voyage_id) VALUES ($1, $2, $3, $4, $5, $6) RETURNING id