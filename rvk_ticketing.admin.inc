<?php
/**
 * ADMIN FILE
 */
/**
 * Implements hook_admin().
 */
function rvk_ticketing_admin() {
  $form['rvk_ticketing_config'] = [
    '#type' => 'fieldset',
    '#weight' => 20,
    '#title' => t('Reykjavik Ticketing API configuration'),
    '#description' => t('Application specific configuration for Reykjavik Ticketing Module'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['rvk_ticketing_mainmanager'] = [
    '#type' => 'fieldset',
    '#weight' => 25,
    '#title' => t('Reykjavik Ticketing Mainmanager Checkword configuration'),
    '#description' => t('Application specific configuration for Mainmanager API'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['rvk_ticketing_config']['rvk_ticketing_thank_you_page'] = [
    '#type' => 'textfield',
    '#weight' => 10,
    '#title' => t('URL to thank you page'),
    '#description' => t('Enter the URL you want users to be redirected to, after the submit their indication'),
    '#default_value' => variable_get('rvk_ticketing_thank_you_page', '/takk-fyrir-abendinguna'),
  ];

  $form['rvk_ticketing_config']['rvk_ticketing_thank_you_page'] = [
    '#type' => 'textarea',
    '#weight' => 10,
    '#title' => t('URL to thank you page'),
    '#description' => t('Enter the URL you want users to be redirected to, after the submit their indication'),
    '#default_value' => variable_get('rvk_ticketing_thank_you_page', '/takk-fyrir-abendinguna'),
  ];

  $form['rvk_ticketing_mainmanager']['mm_checkword_ids'] = [
    '#type' => 'textfield',
    '#weight' => 30,
    '#title' => t('Mainmanager Checkword IDs'),
    '#description' => t('Enter all Checkword IDs, that you want to fetch from Mainmanager, seperated by a comma (,)'),
    '#default_value' => variable_get('mm_checkword_ids', '6,132,135,134,133'),
  ];

  return system_settings_form($form);
}