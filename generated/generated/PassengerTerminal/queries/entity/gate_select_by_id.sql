-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:1a44861c699b5b3e
--  context: PassengerTerminal, entity: Gate, operation: select_by_id

SELECT id, id, code, name, capacity, status, voyage_id FROM passenger_terminal.gate WHERE id = $1