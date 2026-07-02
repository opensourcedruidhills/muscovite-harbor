-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:eda8d694e448d84c
--  context: PassengerTerminal, entity: Gate, operation: update

UPDATE passenger_terminal.gate SET code = $2, name = $3, capacity = $4, status = $5, voyage_id = $6 WHERE id = $1