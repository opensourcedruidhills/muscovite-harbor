-- Deploy: passenger_terminal/indexes

BEGIN;

SET search_path TO passenger_terminal, public;

CREATE INDEX IF NOT EXISTS idx_boarding_passes_passenger_id ON boarding_passes (passenger_id);
CREATE INDEX IF NOT EXISTS idx_boarding_passes_gate_id ON boarding_passes (gate_id);
CREATE INDEX IF NOT EXISTS idx_outbox_created_at ON outbox (created_at);
CREATE INDEX IF NOT EXISTS idx_dead_letter_queue_created_at ON dead_letter_queue (created_at);
CREATE INDEX IF NOT EXISTS idx_idempotency_keys_expires_at ON idempotency_keys (expires_at);
CREATE INDEX IF NOT EXISTS idx_outbox_unprocessed ON outbox (occurred_at);

COMMIT;
