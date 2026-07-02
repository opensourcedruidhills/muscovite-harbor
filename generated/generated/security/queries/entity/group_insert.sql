-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:82cbf9e6f0647d42
--  context: security, entity: Group, operation: insert

INSERT INTO security.group (id, name, description) VALUES ($1, $2, $3) RETURNING id