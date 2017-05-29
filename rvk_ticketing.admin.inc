<?php
/**
 * ADMIN FILE
 */
/**
 * Implements hook_admin().
 */
function rvk_ticketing_admin() {
  $form['rvk_ticketing_street_lookup_config'] = [
    '#type' => 'fieldset',
    '#weight' => 20,
    '#title' => t('Street Lookup API configuration'),
    '#description' => t('Application specific configuration of Client keys.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];

  $form['rvk_ticketing_street_lookup_config']['rvk_ticketing_street_lookup_api'] = [
    '#type' => 'textfield',
    '#weight' => 5,
    '#title' =>  t('Street Lookup API'),
    '#default_value' => variable_get('rvk_ticketing_street_lookup_api',
      'http://borgarvefsja.reykjavik.is/bvsAddressFindUTF8/'),
    '#description' => t('Path to Street Lookup API.')
  ];

  $form['rvk_ticketing_street_lookup_config']['rvk_ticketing_street_lookup_max_hits'] = [
    '#type' => 'textfield',
    '#weight' => 10,
    '#title' => t('Max hits'),
    '#default_value' => variable_get('rvk_ticketing_street_lookup_max_hits', 20),
    '#description' => t('Number of values to be returned with any result.'),
  ];

  return system_settings_form($form);
}