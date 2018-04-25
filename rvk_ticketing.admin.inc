<?php
/**
 * ADMIN FILE
 */
/**
 * Implements hook_admin().
 */
function rvk_ticketing_admin() {
  $form['rvk_ticketing_config'] = array(
    '#type' => 'fieldset',
    '#weight' => 20,
    '#title' => t('Reykjavik Ticketing API configuration'),
    '#description' => t('Application specific configuration for Reykjavik Ticketing Module'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['rvk_service_desk_config'] = array(
    '#type' => 'fieldset',
    '#weight' => 20,
    '#title' => t('Reykjavik Ticketing Service desk configuration'),
    '#description' => t('Application specific configuration for the service desk'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['rvk_ticketing_config']['rvk_ticketing_thank_you_page'] = array(
    '#type' => 'textfield',
    '#weight' => 10,
    '#title' => t('URL to thank you page'),
    '#description' => t('Enter the URL you want users to be redirected to, after the submit their indication'),
    '#default_value' => variable_get('rvk_ticketing_thank_you_page', '/abendingar/takk-fyrir-abendinguna'),
  );

  $form['rvk_ticketing_config']['rvk_ticketing_expired_indication_text'] = array(
    '#type' => 'textarea',
    '#weight' => 10,
    '#title' => t('Text to display when response time for indication has expired'),
    '#description' => t('Enter the text to display when response time for indication has expired'),
    '#default_value' => variable_get('rvk_ticketing_expired_indication_text', 'Ábendingin er komin framyfir svar/framkvæmdartíma'),
  );

  $form['rvk_service_desk_config']['rvk_ticketing_service_desk_opening_hours'] = array(
    '#type' => 'textfield',
    '#weight' => 20,
    '#title' => t('Service desk opening hours.'),
    '#description' => t('Enter the Service desk opening hours, in the format hh:mm (Like 08:20).'),
    '#default_value' => variable_get('rvk_ticketing_service_desk_opening_hours', '08:20'),
  );

  $form['rvk_service_desk_config']['rvk_ticketing_service_desk_opening_hour'] = array(
    '#type' => 'textfield',
    '#weight' => 20,
    '#title' => t('Service desk opening hour.'),
    '#description' => t('Enter the Service desk opening hour, as in what hour excactly (e.g. 8).'),
    '#default_value' => variable_get('rvk_ticketing_service_desk_opening_hour', 8),
  );

  $form['rvk_service_desk_config']['rvk_ticketing_service_desk_opening_minute'] = array(
    '#type' => 'textfield',
    '#weight' => 20,
    '#title' => t('Service desk opening minute.'),
    '#description' => t('Enter the Service desk opening minute, as in what hour excactly (e.g. 20).'),
    '#default_value' => variable_get('rvk_ticketing_service_desk_opening_minute', 20),
  );

  $form['rvk_service_desk_config']['rvk_ticketing_service_desk_opening_duration'] = array(
    '#type' => 'textfield',
    '#weight' => 20,
    '#title' => t('Service desk opening duration (in hours).'),
    '#description' => t('Enter the Service desk opening duration, as in how many hours (e.g. 8).'),
    '#default_value' => variable_get('rvk_ticketing_service_desk_duration', 8),
  );

  $form['rvk_service_desk_config']['rvk_ticketing_service_desk_days_to_respond'] = array(
    '#type' => 'textfield',
    '#weight' => 20,
    '#title' => t('Number of days to respond.'),
    '#description' => t('How many days does the service desk have to respond to the ticket.'),
    '#default_value' => variable_get('rvk_ticketing_service_desk_days_to_respond', 2),
  );

  return system_settings_form($form);
}