-- Deploy: intermodal_transfer/foreign-keys

BEGIN;

SET search_path TO intermodal_transfer, public;

ALTER TABLE truck_visits ADD CONSTRAINT fk_truck_visits_truck_visit_id FOREIGN KEY (truck_visit_id) REFERENCES intermodal_transfer.transfer_slots (id);

COMMIT;
