<?php

/**
 * @file
 * Administration page callbacks for the DDU Demo module.
 */

/**
 * Form builder. Configure DDU Demo settings.
 *
 * @ingroup forms
 * @see system_settings_form().
 */
function ddudemo_admin_settings(&$form, &$form_state) {
  $form = array();
  $form['ddudemo_artwork_view_display'] = array(
    '#type' => 'select',
    '#title' => t('Artwork view display'),
    '#description' => t('Set which view display to use for the artwork listing.'),
    '#options' => array(
      'page_teasers' => t('Teaser listing'),
      'page_grid' => t('Grid'),
    ),
    '#default_value' => variable_get('ddudemo_artwork_view_display', 'page_teasers'),
  );
  $form['ddudemo_artwork_view_items_per_page'] = array(
    '#type' => 'select',
    '#title' => t('Artwork view items per page'),
    '#options' => array_combine(range(1, 100), range(1, 100)),
    '#default_value' => variable_get('ddudemo_artwork_view_items_per_page', 6),
  );
  $form['ddudemo_artwork_block_show'] = array(
    '#type' => 'select',
    '#title' => t('Artwork block display'),
    '#options' => array(
      'featured' => t('Only show featured artwork'),
      'any' => t('Show all artwork for an individual artist'),
    ),
    '#default_value' => variable_get('ddudemo_artwork_block_show', 'featured'),
  );
  return system_settings_form($form);
}


