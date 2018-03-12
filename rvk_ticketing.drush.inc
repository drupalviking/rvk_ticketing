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
  $date_array = [];

  $date_array[]['before'] = new DateTime('2018-08-01 07:19');
  $date_array[]['before'] = new DateTime('2018-08-01 09:19');
  $date_array[]['before'] = new DateTime('2018-08-01 17:19');

  $date_array[]['before'] = new DateTime('2018-08-02 07:19');
  $date_array[]['before'] = new DateTime('2018-08-02 09:19');
  $date_array[]['before'] = new DateTime('2018-08-02 17:19');

  $date_array[]['before'] = new DateTime('2018-08-03 07:19');
  $date_array[]['before'] = new DateTime('2018-08-03 09:19');
  $date_array[]['before'] = new DateTime('2018-08-03 17:19');

  $date_array[]['before'] = new DateTime('2018-08-04 07:19');
  $date_array[]['before'] = new DateTime('2018-08-04 09:19');
  $date_array[]['before'] = new DateTime('2018-08-04 17:19');

  $date_array[]['before'] = new DateTime('2018-08-05 07:19');
  $date_array[]['before'] = new DateTime('2018-08-05 09:19');
  $date_array[]['before'] = new DateTime('2018-08-05 17:19');

  $date_array[]['before'] = new DateTime('2018-08-06 07:19');
  $date_array[]['before'] = new DateTime('2018-08-06 09:19');
  $date_array[]['before'] = new DateTime('2018-08-06 17:19');

  $date_array[]['before'] = new DateTime('2018-08-07 07:19');
  $date_array[]['before'] = new DateTime('2018-08-07 09:19');
  $date_array[]['before'] = new DateTime('2018-08-07 17:19');

  foreach($date_array as $row => $date) {
    $last_response_date = new DateTime($date['before']->format('Y-m-d H:i'));
    $last_response_date = rvk_ticketing_get_last_response_date($last_response_date);
    $date_array[$row]['after'] = $last_response_date;
  }

  print_r($date_array);
}

function drush_rvk_ticketing_import_checkword_items() {
  rvk_ticketing_populate_checkword_items_parents_taxonomy_vocabulary();
  rvk_ticketing_populate_checkword_items_taxonomy_vocabulary();

  drush_print("Checkword items imported");
}