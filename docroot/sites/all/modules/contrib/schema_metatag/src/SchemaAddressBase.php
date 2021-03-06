<?php

/**
 * Schema.org PostalAddress items should extend this class.
 */
class SchemaAddressBase extends SchemaNameBase {

  /**
   * Traits provide re-usable form elements.
   */
  use SchemaAddressTrait;
  use SchemaPivotTrait;

  /**
   * The top level keys on this form.
   */
  public function form_keys() {
    return ['pivot'] + $this->postal_address_form_keys();
  }

  /**
   * {@inheritdoc}
   */
  public function getForm(array $options = array()) {

    $value = SchemaMetatagManager::unserialize($this->value());
    $input_values = [
      'title' => $this->label(),
      'description' => $this->description(),
      'value' => $value,
      '#required' => isset($element['#required']) ? $element['#required'] : FALSE,
      'visibility_selector' => $this->visibilitySelector() . '[@type]',
    ];

    $form = parent::getForm($options);
    $form['value'] = $this->postal_address_form($input_values);

    // Validation from parent::getForm() got wiped out, so add callback.
    $form['value']['#element_validate'][] = 'schema_metatag_element_validate';

    if (!empty($this->info['multiple'])) {
      $form['value']['pivot'] = $this->pivot_form($value);
      $form['value']['pivot']['#states'] = ['invisible' => [
        ':input[name="' . $input_values['visibility_selector'] . '"]' => [
			    'value' => '']
        ]
      ];
    }
    return $form;
  }

}
