-- Deploy: intermodal_transfer/foreign-keys

BEGIN;

SET search_path TO intermodal_transfer, public;

ALTER TABLE truck_visits ADD CONSTRAINT fk_truck_visits_slot_id FOREIGN KEY (slot_id) REFERENCES intermodal_transfer.transfer_slots (id);

COMMIT;
