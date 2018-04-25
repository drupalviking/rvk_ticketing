<?php
/**
 * Created by PhpStorm.
 * User: drupalviking
 * Date: 28/02/2018
 * Time: 11:23
 */
function rvk_ticketing_edit_indication_page() {
  $arg = (int)arg(2);
  $indication = node_load($arg);

  module_load_include('inc', 'node', 'node.pages');
  $build['form'] = array(
    'indication_edit_form' => drupal_get_form("indications_node_form", $indication),
  );

  return $build;
}