-- Deploy: cargo_operations/indexes

BEGIN;

SET search_path TO cargo_operations, public;

CREATE INDEX IF NOT EXISTS idx_reefer_units_reefer_unit_id ON reefer_units (reefer_unit_id);
CREATE INDEX IF NOT EXISTS idx_discharge_sequences_discharge_sequence_id ON discharge_sequences (discharge_sequence_id);
CREATE INDEX IF NOT EXISTS idx_discharge_sequences_discharge_sequence_id ON discharge_sequences (discharge_sequence_id);
CREATE INDEX IF NOT EXISTS idx_discharge_sequences_discharge_sequence_id ON discharge_sequences (discharge_sequence_id);

COMMIT;
