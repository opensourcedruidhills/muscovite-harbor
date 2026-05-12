-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:9d3b00df7d83dd0b
--  context: security, entity: Role, operation: insert

INSERT INTO security.role (id, name, description, permissions) VALUES ($1, $2, $3, $4) RETURNING id