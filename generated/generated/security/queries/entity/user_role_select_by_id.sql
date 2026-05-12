-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:0e0fae35b5902613
--  context: security, entity: UserRole, operation: select_by_id

SELECT id, user_id, role_id FROM security.user_role WHERE id = $1