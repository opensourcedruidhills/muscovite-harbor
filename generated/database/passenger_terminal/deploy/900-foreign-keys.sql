-- Deploy: passenger_terminal/foreign-keys

BEGIN;

SET search_path TO passenger_terminal, public;

ALTER TABLE boarding_passes ADD CONSTRAINT fk_boarding_passes_boarding_pass_id FOREIGN KEY (passenger_id) REFERENCES passenger_terminal.passengers (id);
ALTER TABLE gates ADD CONSTRAINT fk_gates_status_id FOREIGN KEY (status_id) REFERENCES passenger_terminal.gate_status_states (id);
ALTER TABLE passengers ADD CONSTRAINT fk_passengers_status_id FOREIGN KEY (status_id) REFERENCES passenger_terminal.passenger_status_states (id);

COMMIT;
