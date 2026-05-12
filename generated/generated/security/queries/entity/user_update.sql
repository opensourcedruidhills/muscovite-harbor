-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:1933cc22a4cce85a
--  context: security, entity: User, operation: update

UPDATE security.user SET username = $2, email = $3, password_hash = $4, is_active = $5 WHERE id = $1