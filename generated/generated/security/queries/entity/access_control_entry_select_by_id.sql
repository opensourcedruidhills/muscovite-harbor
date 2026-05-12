-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:5fb26c55328e853b
--  context: security, entity: AccessControlEntry, operation: select_by_id

SELECT id, principal, resource, permission, effect FROM security.access_control_entry WHERE id = $1