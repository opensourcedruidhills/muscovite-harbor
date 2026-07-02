-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:7b63094c2d1fef7e
--  context: security, entity: ContextPrivilege, operation: select_by_id

SELECT id, context_name, group_id, privilege FROM security.context_privilege WHERE id = $1