-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:af2cefa1339c76bc
--  context: security, entity: User, operation: select_by_id

SELECT id, username, email, password_hash, is_active FROM security.user WHERE id = $1