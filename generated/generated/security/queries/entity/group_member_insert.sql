-- MUSCOVITE:SIDECAR:UNMODIFIED
-- MUSCOVITE:QUERY-HASH:5993fa788913f52c
--  context: security, entity: GroupMember, operation: insert

INSERT INTO security.group_member (id, group_id, user_id) VALUES ($1, $2, $3) RETURNING id