-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:54583b55e4412c5c
--  context: security, entity: Permission, operation: select_by_id

SELECT id, name, resource, action FROM security.permission WHERE id = $1