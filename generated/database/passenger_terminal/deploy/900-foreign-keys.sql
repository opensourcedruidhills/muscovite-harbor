-- Deploy: passenger_terminal/foreign-keys

BEGIN;

SET search_path TO passenger_terminal, public;

ALTER TABLE boarding_passes ADD CONSTRAINT fk_boarding_passes_boarding_pass_id FOREIGN KEY (boarding_pass_id) REFERENCES passenger_terminal.passengers (id);

COMMIT;
