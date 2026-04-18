-- Deploy: passenger_terminal/indexes

BEGIN;

SET search_path TO passenger_terminal, public;

CREATE INDEX IF NOT EXISTS idx_boarding_passes_boarding_pass_id ON boarding_passes (passenger_id);

COMMIT;
