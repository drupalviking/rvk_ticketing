<?php
/**
 * DRUSH FILE
 */
function rvk_ticketing_drush_command() {
  $items['rvk-ticketing-debug'] = array(
    'description' => 'Debug function',
  );

  return $items;
}

function drush_rvk_ticketing_debug() {

}

function drush_rvk_ticketing_import_checkword_items() {

}