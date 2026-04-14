-- Deploy: cargo_operations/foreign-keys

BEGIN;

SET search_path TO cargo_operations, public;

ALTER TABLE reefer_units ADD CONSTRAINT fk_reefer_units_reefer_unit_id FOREIGN KEY (reefer_unit_id) REFERENCES cargo_operations.containers (id);
ALTER TABLE discharge_sequences ADD CONSTRAINT fk_discharge_sequences_discharge_sequence_id FOREIGN KEY (discharge_sequence_id) REFERENCES cargo_operations.load_plans (id);
ALTER TABLE discharge_sequences ADD CONSTRAINT fk_discharge_sequences_discharge_sequence_id FOREIGN KEY (discharge_sequence_id) REFERENCES cargo_operations.containers (id);
ALTER TABLE discharge_sequences ADD CONSTRAINT fk_discharge_sequences_discharge_sequence_id FOREIGN KEY (discharge_sequence_id) REFERENCES cargo_operations.cranes (id);

COMMIT;
