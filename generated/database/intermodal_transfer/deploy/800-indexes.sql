-- Deploy: intermodal_transfer/indexes

BEGIN;

SET search_path TO intermodal_transfer, public;

CREATE INDEX IF NOT EXISTS idx_truck_visits_slot_id ON truck_visits (slot_id);
CREATE INDEX IF NOT EXISTS idx_outbox_created_at ON outbox (created_at);
CREATE INDEX IF NOT EXISTS idx_dead_letter_queue_created_at ON dead_letter_queue (created_at);
CREATE INDEX IF NOT EXISTS idx_idempotency_keys_expires_at ON idempotency_keys (expires_at);
CREATE INDEX IF NOT EXISTS idx_outbox_unprocessed ON outbox (occurred_at);

COMMIT;
