-- Deploy: security/foreign-keys

BEGIN;

SET search_path TO security, public;

ALTER TABLE group_members ADD CONSTRAINT fk_group_members_group_id FOREIGN KEY (group_id) REFERENCES security.groups (id);
ALTER TABLE group_members ADD CONSTRAINT fk_group_members_user_id FOREIGN KEY (user_id) REFERENCES security.users (id);
ALTER TABLE context_privileges ADD CONSTRAINT fk_context_privileges_group_id FOREIGN KEY (group_id) REFERENCES security.groups (id);

COMMIT;
