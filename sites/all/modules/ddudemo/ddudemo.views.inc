<?php
/**
 * Implementation of hook_views_data().
 */
function ddudemo_views_data() {
  $data['node']['price_edit'] = array(
    'title' => t('Price edit'),
    'field' => array(
      'handler' => 'ddudemo_handler_price_edit',
    ),
    'real field' => 'nid',
  );
  
  return $data;
}