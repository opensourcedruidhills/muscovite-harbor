-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:b7db4eba55897987
--  context: security, entity: Role, operation: update

UPDATE security.role SET name = $2, description = $3, permissions = $4 WHERE id = $1