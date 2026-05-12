-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:cdbd09bdf26ffcee
--  context: PassengerTerminal, entity: Gate, operation: insert

INSERT INTO passenger_terminal.gate (id, id, code, name, capacity, status, voyage_id) VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id