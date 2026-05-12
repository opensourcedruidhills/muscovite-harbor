-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:8273cb32dfd458eb
--  context: security, entity: Role, operation: select_by_id

SELECT id, name, description, permissions FROM security.role WHERE id = $1