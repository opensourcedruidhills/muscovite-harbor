-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d33c939099c4d532
--  context: security, entity: ContextPrivilege, operation: update

UPDATE security.context_privilege SET context_name = $2, group_id = $3, privilege = $4 WHERE id = $1