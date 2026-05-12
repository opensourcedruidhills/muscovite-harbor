-- Deploy: cargo_operations/indexes

BEGIN;

SET search_path TO cargo_operations, public;

CREATE INDEX IF NOT EXISTS idx_reefer_units_container_id ON reefer_units (container_id);
CREATE INDEX IF NOT EXISTS idx_discharge_sequences_load_plan_id ON discharge_sequences (load_plan_id);
CREATE INDEX IF NOT EXISTS idx_discharge_sequences_container_id ON discharge_sequences (container_id);
CREATE INDEX IF NOT EXISTS idx_discharge_sequences_crane_id ON discharge_sequences (crane_id);
CREATE UNIQUE INDEX IF NOT EXISTS ux_container_stack_events_agg_seq ON container_stack_events (aggregate_id, sequence_number);
CREATE INDEX IF NOT EXISTS idx_container_stack_events_aggregate_id ON container_stack_events (aggregate_id);

COMMIT;
