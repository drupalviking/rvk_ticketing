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
  $results = mainmanager_get_checkword_items(6);

  $vocabulary = taxonomy_vocabulary_machine_name_load('checkword_items');
  $term_tree = taxonomy_get_tree($vocabulary->vid);
  $tids = [];
  foreach ($term_tree as $term) {
    $tids[] = $term->tid;
  }

  $terms = taxonomy_term_load_multiple($tids);
  $leftovers = [];

  foreach($results as $result) {
    $found = FALSE;
    foreach($terms as $term) {
      if($term->name == $result['Name']) {
        $term->field_cwi_record_id[LANGUAGE_NONE][0]['value'] = $result['RecordID'];
        $term->field_cwi_number[LANGUAGE_NONE][0]['value'] = $result['Nr'];
        $term->field_cwi_incident_mode[LANGUAGE_NONE][0]['value'] = $result['IncidentMode'][0];
        taxonomy_term_save($term);
        $found = true;
        break;
      }
    }

    if($found == FALSE) {
      $leftovers[] = $result;
    }
  }

  foreach($leftovers as $leftover) {
    $term = new stdClass();
    $term->name = $leftover['Name'];
    $term->vid = $vocabulary->vid;
    $term->field_cwi_record_id[LANGUAGE_NONE][0]['value'] = $leftover['RecordID'];
    $term->field_cwi_number[LANGUAGE_NONE][0]['value'] = $leftover['Nr'];
    $term->field_cwi_incident_mode[LANGUAGE_NONE][0]['value'] = $leftover['IncidentMode'][0];
    taxonomy_term_save($term);
  }

  drush_print("Checkword items imported");
}