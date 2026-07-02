-- Deploy: security/indexes

BEGIN;

SET search_path TO security, public;

CREATE INDEX IF NOT EXISTS idx_group_members_group_id ON group_members (group_id);
CREATE INDEX IF NOT EXISTS idx_group_members_user_id ON group_members (user_id);
CREATE INDEX IF NOT EXISTS idx_context_privileges_group_id ON context_privileges (group_id);

COMMIT;
