-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:9895a554ab7a2a80
--  context: security, entity: GroupMember, operation: select_by_id

SELECT id, group_id, user_id FROM security.group_member WHERE id = $1