<?php
/**
 * DRUSH FILE
 */
function rvk_ticketing_drush_command() {
  $items['rvk-ticketing-debug'] = [
    'description' => 'Debug function',
  ];

  $items['rvk-ticketing-import-checkword-items'] = [
    'description' => 'Imports checkword items from MainManager',
  ];

  return $items;
}

function drush_rvk_ticketing_debug() {
  $obj = new stdClass();
  $obj->MainId = 0;
  $obj->Name = "Veggjakrot í Eyjabakka";
  $obj->Description = "Það er búið að krota á hús í Eyjabakka. Vinsamlegast lagið strax";
  $obj->Contact = "Hilmar Kári Hallbjörnsson";
  $obj->ContactNumber = "8477653";
  $obj->ContactEmail = "zormoni@gmail.com";
  $obj->CheckWordID = 6;
  $obj->CheckWordItemID = 10067;
  $obj->Latidue = "360080.1816103632";
  $obj->Longitude = "406608.21893388574";

  $return = mainmanager_create_incident($obj);

  print_r($return);
}

function drush_rvk_ticketing_import_checkword_items() {
  rvk_ticketing_populate_checkword_items_parents_taxonomy_vocabulary();
  rvk_ticketing_populate_checkword_items_taxonomy_vocabulary();

  drush_print("Checkword items imported");
}