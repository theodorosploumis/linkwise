<?php

/**
 * @file
 * Settings form.
 */

/**
 * Form builder. Configure module.
 */
function linkwise_admin_settings() {
  $form['linkwise_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Linkwise Advertiser tracking'),
    '#default_value' => variable_get('linkwise_enable', FALSE),
    '#description' => t('Enable or disable the tracking without uninstalling
    the module.'),
  );

  $form['linkwise_advertiser_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Your Advertiser ID'),
    '#default_value' => variable_get('linkwise_advertiser_id', ""),
    '#size' => 5,
    '#maxlength' => 5,
    '#element_validate' => array('linkwise_validate_advertiser_id'),
    '#description' => t('This ID will be used to send data to the affiliate
    network each time an order is completed. Get your id at the <a
    href="@url" target="_blank">Linkwise Advertiser page</a>',
      array(
        '@url'=>'https://gr-affiliate.linkwi.se/en/advertiser-register.html')
    ),
  );

  return system_settings_form($form);
}