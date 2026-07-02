-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:fab7e1cad929f417
--  context: PassengerTerminal, entity: Gate, operation: select_by_id

SELECT id, code, name, capacity, status, voyage_id FROM passenger_terminal.gate WHERE id = $1