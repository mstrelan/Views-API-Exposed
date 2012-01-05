<?php

class ddudemo_handler_price_edit extends views_handler_field {
  function render($values) {
    return '<!--form-item-' . $this->options['id'] . '--' . $this->view->row_index . '-->';
  }
  
  function views_form(&$form, &$form_state) {
    // The view is empty, abort.
    if (empty($this->view->result)) {
      return;
    }
    
    $field_name = $this->options['id'];
    $form[$field_name] = array(
      '#tree' => TRUE,
    );
    // At this point, the query has already been run, so we can access the results
    foreach ($this->view->result as $row_id => $row) {
      $form[$field_name][$row_id] = array(
        '#type' => 'textfield',
        '#default_value' => isset($row->field_field_price[0]['raw']['value']) ? $row->field_field_price[0]['raw']['value'] : '',
      );
    }
  }
  
  // Optional validate function.
  function views_form_validate($form, &$form_state) {
    $field_name = $this->options['id'];
    foreach ($form_state['values'][$field_name] as $row_id => $value) {
      if (!empty($value) && !is_numeric($value)) {
        form_set_error($field_name . '][' . $row_id, "Price must be numeric or empty.");
      }
    }
  }
  
  // Optional submit function.
  function views_form_submit($form, &$form_state) {
    $results = $this->view->result;
    foreach ($form_state['values']['price_edit'] as $row_id => $value) {
      if (isset($results[$row_id]) && isset($results[$row_id]->field_field_price[0]['raw']['value'])) {
        $original_value = $results[$row_id]->field_field_price[0]['raw']['value'];
      }
      else {
        $original_value = '';
      }
      if ($value != $original_value) {
        $node = node_load($results[$row_id]->nid);
        $node->field_price['und'][0]['value'] = $value;
        node_save($node);
      }
    }
  }  
}