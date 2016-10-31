<?php
/**
 * @file
 * tiffin_sidebar_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tiffin_sidebar_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-about-tu_commencement:node/211.
  $menu_links['menu-about-tu_commencement:node/211'] = array(
    'menu_name' => 'menu-about-tu',
    'link_path' => 'node/211',
    'router_path' => 'node/%',
    'link_title' => 'Commencement',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-about-tu_commencement:node/211',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'language' => 'en',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-about-tu_employment:node/131.
  $menu_links['menu-about-tu_employment:node/131'] = array(
    'menu_name' => 'menu-about-tu',
    'link_path' => 'node/131',
    'router_path' => 'node/%',
    'link_title' => 'Employment',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-about-tu_employment:node/131',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 8,
    'customized' => 0,
    'language' => 'en',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-about-tu_host-an-event:http://eventscheduling.tiffin.edu/virtualems/.
  $menu_links['menu-about-tu_host-an-event:http://eventscheduling.tiffin.edu/virtualems/'] = array(
    'menu_name' => 'menu-about-tu',
    'link_path' => 'http://eventscheduling.tiffin.edu/virtualems/',
    'router_path' => '',
    'link_title' => 'Host An Event',
    'options' => array(
      'external' => 1,
      'identifier' => 'menu-about-tu_host-an-event:http://eventscheduling.tiffin.edu/virtualems/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
    'customized' => 0,
    'language' => 'en',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-about-tu_institutional-diversity:node/36.
  $menu_links['menu-about-tu_institutional-diversity:node/36'] = array(
    'menu_name' => 'menu-about-tu',
    'link_path' => 'node/36',
    'router_path' => 'node/%',
    'link_title' => 'Institutional Diversity',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-about-tu_institutional-diversity:node/36',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 0,
    'language' => 'en',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-about-tu_maps--directions:node/196.
  $menu_links['menu-about-tu_maps--directions:node/196'] = array(
    'menu_name' => 'menu-about-tu',
    'link_path' => 'node/196',
    'router_path' => 'node/%',
    'link_title' => 'Maps & Directions',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-about-tu_maps--directions:node/196',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 0,
    'language' => 'en',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-about-tu_meet-our-faculty:node/236.
  $menu_links['menu-about-tu_meet-our-faculty:node/236'] = array(
    'menu_name' => 'menu-about-tu',
    'link_path' => 'node/236',
    'router_path' => 'node/%',
    'link_title' => 'Meet Our Faculty',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-about-tu_meet-our-faculty:node/236',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'language' => 'en',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-about-tu_our-campuses:node/246.
  $menu_links['menu-about-tu_our-campuses:node/246'] = array(
    'menu_name' => 'menu-about-tu',
    'link_path' => 'node/246',
    'router_path' => 'node/%',
    'link_title' => 'Our Campuses',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-about-tu_our-campuses:node/246',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 0,
    'language' => 'en',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-about-tu_presidents-welcome:node/16.
  $menu_links['menu-about-tu_presidents-welcome:node/16'] = array(
    'menu_name' => 'menu-about-tu',
    'link_path' => 'node/16',
    'router_path' => 'node/%',
    'link_title' => 'President\'s Welcome',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-about-tu_presidents-welcome:node/16',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'en',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-about-tu_tu-at-a-glance:node/216.
  $menu_links['menu-about-tu_tu-at-a-glance:node/216'] = array(
    'menu_name' => 'menu-about-tu',
    'link_path' => 'node/216',
    'router_path' => 'node/%',
    'link_title' => 'TU At A Glance',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-about-tu_tu-at-a-glance:node/216',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 0,
    'language' => 'en',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-about-tu_visiting-tiffin-oh:node/81.
  $menu_links['menu-about-tu_visiting-tiffin-oh:node/81'] = array(
    'menu_name' => 'menu-about-tu',
    'link_path' => 'node/81',
    'router_path' => 'node/%',
    'link_title' => 'Visiting Tiffin, OH',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-about-tu_visiting-tiffin-oh:node/81',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 0,
    'language' => 'en',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-academics_academic-resources:node/1856.
  $menu_links['menu-academics_academic-resources:node/1856'] = array(
    'menu_name' => 'menu-academics',
    'link_path' => 'node/1856',
    'router_path' => 'node/%',
    'link_title' => 'Academic Resources',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-academics_academic-resources:node/1856',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-academics_assessment:node/1631.
  $menu_links['menu-academics_assessment:node/1631'] = array(
    'menu_name' => 'menu-academics',
    'link_path' => 'node/1631',
    'router_path' => 'node/%',
    'link_title' => 'Assessment',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-academics_assessment:node/1631',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 8,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-academics_china-program:node/651.
  $menu_links['menu-academics_china-program:node/651'] = array(
    'menu_name' => 'menu-academics',
    'link_path' => 'node/651',
    'router_path' => 'node/%',
    'link_title' => 'China Program',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-academics_china-program:node/651',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-academics_disability-services:node/121.
  $menu_links['menu-academics_disability-services:node/121'] = array(
    'menu_name' => 'menu-academics',
    'link_path' => 'node/121',
    'router_path' => 'node/%',
    'link_title' => 'Disability Services',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-academics_disability-services:node/121',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-academics_library:node/1111.
  $menu_links['menu-academics_library:node/1111'] = array(
    'menu_name' => 'menu-academics',
    'link_path' => 'node/1111',
    'router_path' => 'node/%',
    'link_title' => 'Library',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-academics_library:node/1111',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-academics_meet-our-faculty:node/236.
  $menu_links['menu-academics_meet-our-faculty:node/236'] = array(
    'menu_name' => 'menu-academics',
    'link_path' => 'node/236',
    'router_path' => 'node/%',
    'link_title' => 'Meet Our Faculty',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-academics_meet-our-faculty:node/236',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-academics_schools:node/1176.
  $menu_links['menu-academics_schools:node/1176'] = array(
    'menu_name' => 'menu-academics',
    'link_path' => 'node/1176',
    'router_path' => 'node/%',
    'link_title' => 'Schools',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-academics_schools:node/1176',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-academics_special-programs:node/1756.
  $menu_links['menu-academics_special-programs:node/1756'] = array(
    'menu_name' => 'menu-academics',
    'link_path' => 'node/1756',
    'router_path' => 'node/%',
    'link_title' => 'Special Programs',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-academics_special-programs:node/1756',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-academics_transcript-request:node/1626.
  $menu_links['menu-academics_transcript-request:node/1626'] = array(
    'menu_name' => 'menu-academics',
    'link_path' => 'node/1626',
    'router_path' => 'node/%',
    'link_title' => 'Transcript Request',
    'options' => array(
      'external' => 0,
      'identifier' => 'menu-academics_transcript-request:node/1626',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-admissions_apply-now:home.
  $menu_links['menu-admissions_apply-now:home'] = array(
    'menu_name' => 'menu-admissions',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Apply Now',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-admissions_apply-now:home',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admissions_financial-aid:home.
  $menu_links['menu-admissions_financial-aid:home'] = array(
    'menu_name' => 'menu-admissions',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Financial Aid',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-admissions_financial-aid:home',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admissions_graduate:home.
  $menu_links['menu-admissions_graduate:home'] = array(
    'menu_name' => 'menu-admissions',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Graduate',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-admissions_graduate:home',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admissions_international:home.
  $menu_links['menu-admissions_international:home'] = array(
    'menu_name' => 'menu-admissions',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'International',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-admissions_international:home',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admissions_online-and-off-campus-bachelor-degree-programs:home.
  $menu_links['menu-admissions_online-and-off-campus-bachelor-degree-programs:home'] = array(
    'menu_name' => 'menu-admissions',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Online and Off-Campus Bachelor Degree Programs',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-admissions_online-and-off-campus-bachelor-degree-programs:home',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admissions_transfer:home.
  $menu_links['menu-admissions_transfer:home'] = array(
    'menu_name' => 'menu-admissions',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Transfer',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-admissions_transfer:home',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admissions_undergraduate:home.
  $menu_links['menu-admissions_undergraduate:home'] = array(
    'menu_name' => 'menu-admissions',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Undergraduate',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-admissions_undergraduate:home',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admissions_visit-tiffin-university:home.
  $menu_links['menu-admissions_visit-tiffin-university:home'] = array(
    'menu_name' => 'menu-admissions',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Visit Tiffin University',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-admissions_visit-tiffin-university:home',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Academic Resources');
  t('Apply Now');
  t('Assessment');
  t('China Program');
  t('Commencement');
  t('Disability Services');
  t('Employment');
  t('Financial Aid');
  t('Graduate');
  t('Host An Event');
  t('Institutional Diversity');
  t('International');
  t('Library');
  t('Maps & Directions');
  t('Meet Our Faculty');
  t('Online and Off-Campus Bachelor Degree Programs');
  t('Our Campuses');
  t('President\'s Welcome');
  t('Schools');
  t('Special Programs');
  t('TU At A Glance');
  t('Transcript Request');
  t('Transfer');
  t('Undergraduate');
  t('Visit Tiffin University');
  t('Visiting Tiffin, OH');

  return $menu_links;
}
