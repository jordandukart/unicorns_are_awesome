<?php
/**
 * @file
 * This file contains all theme and preprocess functions for unicorns.
 */


/**
 * Implements hook_preprocess().
 */
function unicorns_are_awesome_preprocess_unicorns_are_awesome_display(array &$variables) {
  $object = $variables['islandora_object'];
  if (islandora_datastream_access(ISLANDORA_VIEW_OBJECTS, $object['DC'])) {
    try {
      $dc = $object['DC']->content;
    }
    catch (Exception $e) {
      drupal_set_message(t('Error retrieving object %s %t', array('%s' => $object->id, '%t' => $e->getMessage())), 'error', FALSE);
    }
  }
  // Using the Islandora 6 object details XSLT let's transform the DC datastream
  // to HTML output.
  if ($dc) {
    $file = drupal_get_path('module', 'unicorns_are_awesome') . '/xsl/convertQDC.xsl';
    $xslt = new XSLTProcessor();
    $xslt_dom = new DOMDocument();
    $xslt_dom->load($file);
    $input = new DOMDocument();
    $did_load_ok = $input->loadXML($dc);
    if ($did_load_ok) {
      $xslt->importStylesheet($xslt_dom);
      $variables['metadata'] = $xslt->transformToXml($input);
    }
  }
}

/**
 * Implements hook_preprocess().
 */
function unicorns_are_awesome_preprocess_unicorns_are_awesome_description(array &$variables) {
  $object = $variables['islandora_object'];
  $variables['description'] = t('Templated descriptions for unicorns on @object!', array(
    '@object' => $object->id,
  ));
}
