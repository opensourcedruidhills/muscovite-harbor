-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:36d445b2ecae0e04
--  context: security, entity: Permission, operation: insert

INSERT INTO security.permission (id, name, resource, action) VALUES ($1, $2, $3, $4) RETURNING id