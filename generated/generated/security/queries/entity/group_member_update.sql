-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:ae7529e8e202f41b
--  context: security, entity: GroupMember, operation: update

UPDATE security.group_member SET group_id = $2, user_id = $3 WHERE id = $1