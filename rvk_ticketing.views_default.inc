<?php
/**
 * Implements hook_views_default_views().
 */
function rvk_ticketing_views_default_views() {
  $view = new view();
  $view->name = 'indications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ábendingar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'table-layout1';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'meira';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer ticketing content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Sækja';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Endursetja';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Raða eftir';
  $handler->display->display_options['pager']['type'] = 'show_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '125';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« fremsta';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ fyrri';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næsta ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'aftasta »';
  $handler->display->display_options['pager']['options']['show_more_text'] = 'Sjá allar';
  $handler->display->display_options['pager']['options']['initial'] = '3';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'scroll_fade';
  $handler->display->display_options['pager']['options']['effects']['speed_type'] = 'slow';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Haus: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2><span class="icon-status"></span>Óhreyfðar ábendingar <span class="total-rows"> (@total)</span></h2>';
  /* Reitur: Efni: Titill */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Reitur: Efni: Nafn sendanda */
  $handler->display->display_options['fields']['field_indication_reporter_name']['id'] = 'field_indication_reporter_name';
  $handler->display->display_options['fields']['field_indication_reporter_name']['table'] = 'field_data_field_indication_reporter_name';
  $handler->display->display_options['fields']['field_indication_reporter_name']['field'] = 'field_indication_reporter_name';
  /* Reitur: Efni: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Skráð þann';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Reitur: Efni: Ábendingategund */
  $handler->display->display_options['fields']['field_indication_type_ref']['id'] = 'field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['table'] = 'field_data_field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['field'] = 'field_indication_type_ref';
  /* Sort criterion: Efni: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Efni: Birt */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Efni: Gerð */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'indications' => 'indications',
  );
  /* Filter criterion: Efni: Staða (field_indication_status_ref) */
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['id'] = 'field_indication_status_ref_tid';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['table'] = 'field_data_field_indication_status_ref';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['field'] = 'field_indication_status_ref_tid';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['vocabulary'] = 'indication_status';

  /* Display: Nýjar ábendingar */
  $handler = $view->new_display('block', 'Nýjar ábendingar', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Haus: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2 class="table-layout1__item-count"><span class="icon-circle icon-circle--new"></span><span>Nýjar og óflokkaðar ábendingar </span><span class="total-rows"> (@total)</span></h2>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Reitur: Efni: Titill */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Reitur: Efni: Nafn sendanda */
  $handler->display->display_options['fields']['field_indication_reporter_name']['id'] = 'field_indication_reporter_name';
  $handler->display->display_options['fields']['field_indication_reporter_name']['table'] = 'field_data_field_indication_reporter_name';
  $handler->display->display_options['fields']['field_indication_reporter_name']['field'] = 'field_indication_reporter_name';
  /* Reitur: Efni: Ábendingategund */
  $handler->display->display_options['fields']['field_indication_type_ref']['id'] = 'field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['table'] = 'field_data_field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['field'] = 'field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['delta_offset'] = '0';
  /* Reitur: Efni: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Skráð þann';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Efni: Ábendingategund (field_indication_type_ref) */
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['id'] = 'field_indication_type_ref_tid';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['table'] = 'field_data_field_indication_type_ref';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['field'] = 'field_indication_type_ref_tid';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['validate_options']['vocabularies'] = array(
    'indication_types' => 'indication_types',
  );
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['validate_options']['type'] = 'convert';

  /* Display: Í vinnslu */
  $handler = $view->new_display('block', 'Í vinnslu', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Tengsl: Efni: Höfundur */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Efni: Birt */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Efni: Gerð */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'indications' => 'indications',
  );

  /* Display: Óhreyfðar ábendingar */
  $handler = $view->new_display('block', 'Óhreyfðar ábendingar', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Haus: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2 class="table-layout1__item-count"><span class="icon-circle icon-circle--alert"></span><span>Komnar framyfir svartíma </span><span class="total-rows"> (@total)</span></h2>';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Efni: Ábendingategund (field_indication_type_ref) */
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['id'] = 'field_indication_type_ref_tid';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['table'] = 'field_data_field_indication_type_ref';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['field'] = 'field_indication_type_ref_tid';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Efni: Birt */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Efni: Gerð */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'indications' => 'indications',
  );
  /* Filter criterion: Efni: Dags. uppfært */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '<=';
  $handler->display->display_options['filters']['changed']['value']['value'] = '-5 days';
  $handler->display->display_options['filters']['changed']['value']['type'] = 'offset';

  /* Display: Lokaðar ábendingar */
  $handler = $view->new_display('page', 'Lokaðar ábendingar', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Haus: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2><span class="icon-status"></span>Lokaðar ábendingar <span class="total-rows"> (@total)</span></h2>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Reitur: Efni: Titill */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Reitur: Efni: Nafn sendanda */
  $handler->display->display_options['fields']['field_indication_reporter_name']['id'] = 'field_indication_reporter_name';
  $handler->display->display_options['fields']['field_indication_reporter_name']['table'] = 'field_data_field_indication_reporter_name';
  $handler->display->display_options['fields']['field_indication_reporter_name']['field'] = 'field_indication_reporter_name';
  /* Reitur: Efni: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Skráð þann';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Reitur: Efni: Ábendingunni lokað þann */
  $handler->display->display_options['fields']['field_indication_closed_at']['id'] = 'field_indication_closed_at';
  $handler->display->display_options['fields']['field_indication_closed_at']['table'] = 'field_data_field_indication_closed_at';
  $handler->display->display_options['fields']['field_indication_closed_at']['field'] = 'field_indication_closed_at';
  $handler->display->display_options['fields']['field_indication_closed_at']['label'] = 'Lokað þann';
  $handler->display->display_options['fields']['field_indication_closed_at']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Reitur: Efni: Ábendingategund */
  $handler->display->display_options['fields']['field_indication_type_ref']['id'] = 'field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['table'] = 'field_data_field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['field'] = 'field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_indication_type_ref']['multi_type'] = 'ul';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Efni: Birt */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Efni: Gerð */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'indications' => 'indications',
  );
  /* Filter criterion: Efni: Staða (field_indication_status_ref) */
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['id'] = 'field_indication_status_ref_tid';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['table'] = 'field_data_field_indication_status_ref';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['field'] = 'field_indication_status_ref_tid';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['value'] = array(
    0 => '916',
  );
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['vocabulary'] = 'indication_status';
  /* Filter criterion: Dagsetning: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Dagsetning';
  $handler->display->display_options['filters']['date_filter']['expose']['description'] = 'Veldu dagsetningu til að sía eftir';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    4 => 0,
    12 => 0,
    10 => 0,
    5 => 0,
    7 => 0,
    9 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Efni: Nafn sendanda (field_indication_reporter_name) */
  $handler->display->display_options['filters']['field_indication_reporter_name_value']['id'] = 'field_indication_reporter_name_value';
  $handler->display->display_options['filters']['field_indication_reporter_name_value']['table'] = 'field_data_field_indication_reporter_name';
  $handler->display->display_options['filters']['field_indication_reporter_name_value']['field'] = 'field_indication_reporter_name_value';
  $handler->display->display_options['filters']['field_indication_reporter_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_indication_reporter_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_indication_reporter_name_value']['expose']['operator_id'] = 'field_indication_reporter_name_value_op';
  $handler->display->display_options['filters']['field_indication_reporter_name_value']['expose']['label'] = 'Nafn sendanda';
  $handler->display->display_options['filters']['field_indication_reporter_name_value']['expose']['operator'] = 'field_indication_reporter_name_value_op';
  $handler->display->display_options['filters']['field_indication_reporter_name_value']['expose']['identifier'] = 'field_indication_reporter_name_value';
  $handler->display->display_options['filters']['field_indication_reporter_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    4 => 0,
    12 => 0,
    10 => 0,
    5 => 0,
    7 => 0,
    9 => 0,
    13 => 0,
  );
  /* Filter criterion: Efni: Ábendingategund (field_indication_type_ref) */
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['id'] = 'field_indication_type_ref_tid';
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['table'] = 'field_data_field_indication_type_ref';
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['field'] = 'field_indication_type_ref_tid';
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['expose']['operator_id'] = 'field_indication_type_ref_tid_op';
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['expose']['label'] = 'Ábendingategund';
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['expose']['operator'] = 'field_indication_type_ref_tid_op';
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['expose']['identifier'] = 'field_indication_type_ref_tid';
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    4 => 0,
    12 => 0,
    10 => 0,
    5 => 0,
    7 => 0,
    9 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['vocabulary'] = 'indication_types';
  $handler->display->display_options['filters']['field_indication_type_ref_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'abendingar/lokadar-abendingar';

  /* Display: Yfirlit ábendinga */
  $handler = $view->new_display('page', 'Yfirlit ábendinga', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Yfirlit ábendinga';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Haus: Global: Block area */
  $handler->display->display_options['header']['block']['id'] = 'block';
  $handler->display->display_options['header']['block']['table'] = 'views';
  $handler->display->display_options['header']['block']['field'] = 'block';
  $handler->display->display_options['header']['block']['label'] = 'Svið';
  $handler->display->display_options['header']['block']['empty'] = TRUE;
  $handler->display->display_options['header']['block']['block_to_insert'] = 'menu:menu-abendingar';
  $handler->display->display_options['header']['block']['title'] = 'Svið';
  /* Haus: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2><span class="icon-status"></span>Ábendingar<span class="total-rows"> (@total)</span></h2>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Fótur: Global: Block area */
  $handler->display->display_options['footer']['block']['id'] = 'block';
  $handler->display->display_options['footer']['block']['table'] = 'views';
  $handler->display->display_options['footer']['block']['field'] = 'block';
  $handler->display->display_options['footer']['block']['block_to_insert'] = 'views:indications-block_2';
  $handler->display->display_options['footer']['block']['title'] = '<none>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Reitur: Efni: Titill */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Reitur: Efni: Nafn sendanda */
  $handler->display->display_options['fields']['field_indication_reporter_name']['id'] = 'field_indication_reporter_name';
  $handler->display->display_options['fields']['field_indication_reporter_name']['table'] = 'field_data_field_indication_reporter_name';
  $handler->display->display_options['fields']['field_indication_reporter_name']['field'] = 'field_indication_reporter_name';
  /* Reitur: Efni: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Skráð þann';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Reitur: Efni: Ábendingategund */
  $handler->display->display_options['fields']['field_indication_type_ref']['id'] = 'field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['table'] = 'field_data_field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['field'] = 'field_indication_type_ref';
  $handler->display->display_options['fields']['field_indication_type_ref']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_indication_type_ref']['multi_type'] = 'ul';
  /* Reitur: Efni: Staða */
  $handler->display->display_options['fields']['field_indication_status_ref']['id'] = 'field_indication_status_ref';
  $handler->display->display_options['fields']['field_indication_status_ref']['table'] = 'field_data_field_indication_status_ref';
  $handler->display->display_options['fields']['field_indication_status_ref']['field'] = 'field_indication_status_ref';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Efni: Ábendingategund (field_indication_type_ref) */
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['id'] = 'field_indication_type_ref_tid';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['table'] = 'field_data_field_indication_type_ref';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['field'] = 'field_indication_type_ref_tid';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_indication_type_ref_tid']['validate_options']['vocabularies'] = array(
    'indication_types' => 'indication_types',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Efni: Birt */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Efni: Gerð */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'indications' => 'indications',
  );
  /* Filter criterion: Efni: Staða (field_indication_status_ref) */
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['id'] = 'field_indication_status_ref_tid';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['table'] = 'field_data_field_indication_status_ref';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['field'] = 'field_indication_status_ref_tid';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['value'] = array(
    0 => '916',
  );
  $handler->display->display_options['filters']['field_indication_status_ref_tid']['vocabulary'] = 'indication_status';
  $handler->display->display_options['path'] = 'taxonomy/term/%';
  $translatables['indications'] = array(
    t('Master'),
    t('meira'),
    t('Sækja'),
    t('Endursetja'),
    t('Raða eftir'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« fremsta'),
    t('‹ fyrri'),
    t('næsta ›'),
    t('aftasta »'),
    t('Sjá allar'),
    t('<h2><span class="icon-status"></span>Óhreyfðar ábendingar <span class="total-rows"> (@total)</span></h2>'),
    t('Titill'),
    t('Nafn sendanda'),
    t('Skráð þann'),
    t('Ábendingategund'),
    t('Nýjar ábendingar'),
    t('<h2 class="table-layout1__item-count"><span class="icon-circle icon-circle--new"></span><span>Nýjar og óflokkaðar ábendingar </span><span class="total-rows"> (@total)</span></h2>'),
    t('All'),
    t('Í vinnslu'),
    t('höfundur'),
    t('Óhreyfðar ábendingar'),
    t('<h2 class="table-layout1__item-count"><span class="icon-circle icon-circle--alert"></span><span>Komnar framyfir svartíma </span><span class="total-rows"> (@total)</span></h2>'),
    t('Lokaðar ábendingar'),
    t('<h2><span class="icon-status"></span>Lokaðar ábendingar <span class="total-rows"> (@total)</span></h2>'),
    t('Lokað þann'),
    t('Dagsetning'),
    t('Veldu dagsetningu til að sía eftir'),
    t('Yfirlit ábendinga'),
    t('Svið'),
    t('<h2><span class="icon-status"></span>Ábendingar<span class="total-rows"> (@total)</span></h2>'),
    t('Staða'),
  );

  // Add view to list of views to provide.
  $views[$view->name] = $view;

  // Repeat all of the above for each view the module should provide. At the
  // end, return array of default views.
  return $views;
}