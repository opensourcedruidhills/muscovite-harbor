-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:d145b5d83b8897c4
--  context: security, entity: ContextPrivilege, operation: insert

INSERT INTO security.context_privilege (id, context_name, group_id, privilege) VALUES ($1, $2, $3, $4) RETURNING id