<?php
/**
 * DRUSH FILE
 */
function rvk_ticketing_drush_command() {
  $items['rvk-ticketing-debug'] = [
    'description' => 'Debug function',
  ];

  return $items;
}

function drush_rvk_ticketing_debug() {
  $info = node_type_load('page');
  print_r($info);

}