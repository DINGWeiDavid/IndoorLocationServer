/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS `WifiMap_wifi_vec`;

DROP TABLE IF EXISTS `WifiMap`;

CREATE TABLE `WifiMap` (
  `id` BIGINT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT)
 ENGINE=InnoDB;

CREATE TABLE `WifiMap_wifi_vec` (
  `object_id` BIGINT UNSIGNED NOT NULL,
  `key` TEXT NOT NULL,
  `value` INT NOT NULL,
  CONSTRAINT `WifiMap_wifi_vec_object_id_fk`
    FOREIGN KEY (`object_id`)
    REFERENCES `WifiMap` (`id`)
    ON DELETE CASCADE)
 ENGINE=InnoDB;

CREATE INDEX `object_id_i`
  ON `WifiMap_wifi_vec` (`object_id`);

