-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:f5f9e4112b899bf4
--  context: security, entity: Permission, operation: update

UPDATE security.permission SET name = $2, resource = $3, action = $4 WHERE id = $1