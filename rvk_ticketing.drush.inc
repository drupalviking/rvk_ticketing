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
  $departments = [
    [
      'name' => 'Umhverfis- og skipulagssvið',
      'categories' =>
        [
          [
            'category' => 'Götur og gangstéttar',
            'sub_categories' => [
              'Malbik',
              'Hellur',
              'Steypa',
              'Kantsteinar',
              'Hleðslur/veggir',
              'Tröppur/rampar',
              'Skilti',
              'Pollar',
              'Annað',
            ],
          ],
          [
            'category' => 'Gróður og götugögn',
            'sub_categories' => [
              'Grassvæði',
              'Trjábeð/blómabeð',
              'Götutré',
              'Gróðurker/körfur',
              'Ruslafötur',
              'Bekkir/borð',
              'Styttur/listaverk',
              'Leiktæki/æfingatæki',
              'Annað',
            ],
          ],
          [
            'category' => 'Lagnir og lýsing',
            'sub_categories' => [
              'Ljósastaurar',
              'Lýsing',
              'Rafmagnskassar',
              'Niðurföll/ristar',
              'Drykkjafontar',
              'Annað',
            ],
          ],
          [
            'category' => 'Umferð',
            'sub_categories' => [
              'Umferðarljós',
              'Umferðarskilti',
              'Gatnamerkingar',
              'Hlið',
              'Girðingar/vegrið',
              'Strætóskýli',
              'Annað',
            ],
          ],
          [
            'category' => 'Vetrarþjónusta',
            'sub_categories' => [
              'Götur',
              'Göngu- og hjólaleiðir',
              'Hitakerfi',
              'Stofnanalóðir',
              'Annað',
            ],
          ],
          [
            'category' => 'Grassláttur',
            'sub_categories' => [
              'Grunn- og leikskólar',
              'Önnur svæði',
            ],
          ],
          [
            'category' => 'Hreinsun',
            'sub_categories' => [
              'Götur',
              'Göngu- og hjólaleiðir',
              'Miðborgarhreinsun',
              'Veggjakrot',
              'Annað',
            ],
          ],
      ],
    ],
    [
      'name' => 'Skóla- og frístundasvið',
      'categories' =>
        [
          [
            'category' => 'Mötuneyti',
          ],
        ],
    ],
    [
      'name' => 'Velferðarsvið',
      'categories' => [

      ],
    ],
    [
      'name' => 'Íþrótta- og tómstundasvið',
      'categories' =>
        [

        ],
    ],
    [
      'name' => 'Menningar- og ferðamálasvið',
      'categories' =>
        [

       ],
    ],
    [
      'name' => 'Skrifstofur Ráðhúss',
      'categories' =>
        [

        ],
    ],
    [
      'name' => 'Stofnanir og fyrirtæki',
      'categories' =>
        [

        ],
    ],
    [
      'name' => 'Þjónustuver',
      'categories' =>
        [

        ],
    ],
  ];

  foreach($departments as $department) {
    //Do stuff for root
    drush_print($department['name']);
    if(sizeof($department['categories']) > 0) {
      foreach($department['categories'] as $category) {
        drush_print('---' . $category['category']);

        if(isset($category['sub_categories'])) {
          foreach($category['sub_categories'] as $sub_category) {
            //ADD SUBCATEGORIES
            drush_print('    ----' . $sub_category);
          }
        }
      }
    }
  }
}

function drush_rvk_ticketing_import_checkword_items() {

}