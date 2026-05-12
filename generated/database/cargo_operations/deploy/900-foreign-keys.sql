-- Deploy: cargo_operations/foreign-keys

BEGIN;

SET search_path TO cargo_operations, public;

ALTER TABLE reefer_units ADD CONSTRAINT fk_reefer_units_container_id FOREIGN KEY (container_id) REFERENCES cargo_operations.containers (id);
ALTER TABLE discharge_sequences ADD CONSTRAINT fk_discharge_sequences_load_plan_id FOREIGN KEY (load_plan_id) REFERENCES cargo_operations.load_plans (id);
ALTER TABLE discharge_sequences ADD CONSTRAINT fk_discharge_sequences_container_id FOREIGN KEY (container_id) REFERENCES cargo_operations.containers (id);
ALTER TABLE discharge_sequences ADD CONSTRAINT fk_discharge_sequences_crane_id FOREIGN KEY (crane_id) REFERENCES cargo_operations.cranes (id);

COMMIT;
