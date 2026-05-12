-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:99a9defe1dd75dc7
--  context: PassengerTerminal, entity: Gate, operation: update

UPDATE passenger_terminal.gate SET id = $2, code = $3, name = $4, capacity = $5, status = $6, voyage_id = $7 WHERE id = $1