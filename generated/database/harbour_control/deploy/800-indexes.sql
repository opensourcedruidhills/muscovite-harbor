-- Deploy: harbour_control/indexes

BEGIN;

SET search_path TO harbour_control, public;

CREATE INDEX IF NOT EXISTS idx_outbox_unprocessed ON outbox (created_at);

COMMIT;
