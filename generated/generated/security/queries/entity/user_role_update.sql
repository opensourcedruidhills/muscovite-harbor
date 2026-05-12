-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:62ac934d73280c2a
--  context: security, entity: UserRole, operation: update

UPDATE security.user_role SET user_id = $2, role_id = $3 WHERE id = $1