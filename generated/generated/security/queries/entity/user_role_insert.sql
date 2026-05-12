-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ed9c0d3cc7e7ff39
--  context: security, entity: UserRole, operation: insert

INSERT INTO security.user_role (id, user_id, role_id) VALUES ($1, $2, $3) RETURNING id