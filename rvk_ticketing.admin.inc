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
    '#weight' => 25,
    '#title' => t('Reykjavik Ticketing API configuration'),
    '#description' => t('Application specific configuration for Reykjavik Ticketing Module'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['rvk_ticketing_config']['first_email'] = [
    '#type' => 'textarea',
    '#weight' => 10,
    '#title' => 'Fyrsti tölvupóstur',
    '#default_value' => variable_get('first_email', ''),
    '#description' => t('Email that is sent out when a user submits the initial ticket'),
  ];

  $form['rvk_ticketing_config']['closing_email'] = [
    '#type' => 'textarea',
    '#weight' => 20,
    '#title' => 'Loka tölvupóstur',
    '#default_value' => variable_get('closing_email', ''),
    '#description' => t('Email that is sent out when the issue has been closed'),
  ];

  $form['rvk_ticketing_mainmanager'] = [
    '#type' => 'fieldset',
    '#weight' => 25,
    '#title' => t('Reykjavik Ticketing Mainmanager Checkword configuration'),
    '#description' => t('Application specific configuration for Mainmanager API'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['rvk_ticketing_mainmanager']['mm_checkword_ids'] = [
    '#type' => 'textfield',
    '#weight' => 30,
    '#title' => t('Mainmanager Checkword IDs'),
    '#description' => t('Enter all Checkword IDs, that you want to fetch from Mainmanager, seperated by a comma (,)'),
    '#default_value' => variable_get('mm_checkword_ids', ''),
  ];

  return system_settings_form($form);
}