-- Deploy: cargo_operations/indexes

BEGIN;

SET search_path TO cargo_operations, public;

CREATE INDEX IF NOT EXISTS idx_reefer_units_reefer_unit_id ON reefer_units (reefer_unit_id);
CREATE INDEX IF NOT EXISTS idx_discharge_sequences_discharge_sequence_id ON discharge_sequences (discharge_sequence_id);
CREATE UNIQUE INDEX IF NOT EXISTS ux_container_stack_events_agg_seq ON container_stack_events (aggregate_id, sequence_number);
CREATE INDEX IF NOT EXISTS idx_container_stack_events_aggregate_id ON container_stack_events (aggregate_id);

COMMIT;
