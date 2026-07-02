-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:7f4a56d907877f4d
--  context: security, entity: Group, operation: update

UPDATE security.group SET name = $2, description = $3 WHERE id = $1