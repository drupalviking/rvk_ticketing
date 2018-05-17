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

  $form['rvk_ticketing_config']['rvk_ticketing_delicate_info'] = array(
    '#type' => 'textarea',
    '#weight' => 10,
    '#title' => t('Text to display when indication has been marked delicate'),
    '#description' => t('Enter the text to display when the indication has been marked delicate. This will replace
     the text displayed, so that the delicate info is not shown.'),
    '#default_value' => variable_get(
      'rvk_ticketing_delicate_info',
      'Ábendingin inniheldur viðkvæmar upplýsingar og eru þær ekki birtar hér'
    ),
  );

  $form['rvk_ticketing_config']['rvk_ticketing_main_headline'] = array(
    '#type' => 'textfield',
    '#weight' => 10,
    '#title' => t('Main headline'),
    '#description' => t('Enter the main headline.'),
    '#default_value' => variable_get(
      'rvk_ticketing_main_headline',
      'Senda ábendingu'
    ),
  );

  $form['rvk_ticketing_config']['rvk_ticketing_main_message'] = array(
    '#type' => 'textarea',
    '#weight' => 10,
    '#title' => t('Main text for the Indication'),
    '#description' => t('Enter the main text for the indication'),
    '#default_value' => variable_get(
      'rvk_ticketing_main_message',
      'Hér geturðu sent ábendingu um hvað sem er. Ábendingin mun berast þjónustuverinu okkar sem svarar strax 
      eða kemur áfram á réttan stað.'
    ),
  );

  $form['rvk_ticketing_config']['rvk_ticketing_user_headline'] = array(
    '#type' => 'textfield',
    '#weight' => 10,
    '#title' => t('User headline'),
    '#description' => t('Enter the user headline.'),
    '#default_value' => variable_get(
      'rvk_ticketing_user_headline',
      'Viltu fylgjast með ábendingunni?'
    ),
  );

  $form['rvk_ticketing_config']['rvk_ticketing_user_message'] = array(
    '#type' => 'textarea',
    '#weight' => 10,
    '#title' => t('Main text for the Indication'),
    '#description' => t('Enter the main text for the indication'),
    '#default_value' => variable_get(
      'rvk_ticketing_user_message',
      'Ef þú vilt vita hvað verður um ábendinguna þína er nauðsynlegt að fylla þessa reiti út. Ef ekki geturðu 
      smellt á senda hnappinn hér að neðan.'
    ),
  );

  $form['rvk_ticketing_config']['rvk_ticketing_child_services_message'] = array(
    '#type' => 'textarea',
    '#weight' => 10,
    '#title' => t('Main text for child services notice'),
    '#description' => t('Enter the main text for child services notice. The text will be displayed at the top of 
    indication form, to direct people to correct form.'),
    '#default_value' => variable_get(
      'rvk_ticketing_child_services_message',
      'Allar tilkynningar sem snúa að barnavernd er nauðsynlegt að senda í gegnum . 
      <a href="/tilkynningar-til-barnaverndar">rafræna tilkynningagátt barnaverndar</a>'
    ),
  );

  $form['rvk_ticketing_config']['rvk_ticketing_map_location_headline'] = array(
    '#type' => 'textfield',
    '#weight' => 10,
    '#title' => t('Location headline'),
    '#description' => t('Enter the location headline.'),
    '#default_value' => variable_get(
      'rvk_ticketing_map_location_headline',
      'Veldu staðsetningu á korti (ef á við)'
    ),
  );

  $form['rvk_ticketing_config']['rvk_ticketing_map_location_message'] = array(
    '#type' => 'textarea',
    '#weight' => 10,
    '#title' => t('Main text map location.'),
    '#description' => t('Enter the main text for the map location'),
    '#default_value' => variable_get(
      'rvk_ticketing_map_location_message',
      'Þú getur slegið inn heimilisfang eða sett punkt á kortið með því að smella á þann stað á kortinu sem 
      tengist ábendingunni. Ef þú ert í snjallsíma geturðu virkjað staðsetninguna þína með því að ýta á 
      <span class="locate-icon"></span> hnappinn á kortinu.'
    ),
  );

  $form['rvk_ticketing_config']['rvk_ticketing_image_headline'] = array(
    '#type' => 'textfield',
    '#weight' => 10,
    '#title' => t('Image headline'),
    '#description' => t('Enter the image headline.'),
    '#default_value' => variable_get(
      'rvk_ticketing_image_headline',
      'Senda mynd'
    ),
  );

  $form['rvk_ticketing_config']['rvk_ticketing_image_message'] = array(
    '#type' => 'textarea',
    '#weight' => 10,
    '#title' => t('Image message'),
    '#description' => t('Enter the image message.'),
    '#default_value' => variable_get(
      'rvk_ticketing_image_message',
      'Sendu inn mynd með tilkynningunni, til að gera betri grein fyrir henni.'
    ),
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