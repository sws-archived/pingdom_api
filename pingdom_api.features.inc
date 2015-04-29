<?php
/**
 * @file
 * pingdom_api.features.inc
 */

/**
 * Implements hook_default_wsclient_service().
 */
function pingdom_api_default_wsclient_service() {
  $items = array();
  $items['pingdom'] = entity_import('wsclient_service', '{
    "settings" : {
      "send_formatter" : {
        "class" : "WsclientRestFormFormatter",
        "settings" : { "default_root" : "result", "adaptive_root" : 0 }
      },
      "receive_formatter" : {
        "class" : "WsclientRestJSONFormatter",
        "settings" : { "default_root" : "result", "adaptive_root" : 0 }
      },
      "curl options" : {"10005" : ":", "10023" : [ "App-Key: " ] }
    },
    "operations" : { "get_check_list" : {
        "url" : "api\\/2.0\\/checks",
        "label" : "Get Check List",
        "parameter" : {
          "limit" : {
            "type" : "integer",
            "default value" : "25000",
            "optional" : true,
            "allow null" : 0
          },
          "offset" : {
            "type" : "integer",
            "default value" : "0",
            "optional" : true,
            "allow null" : 0
          },
          "tags" : { "type" : "text", "optional" : true, "allow null" : 0 }
        },
        "name" : "get_check_list",
        "result" : { "type" : "list\\u003Ccheck\\u003E", "label" : "Check List" },
        "type" : "GET"
      }
    },
    "datatypes" : [],
    "global_parameters" : [],
    "name" : "pingdom",
    "label" : "Pingdom",
    "url" : "https:\\/\\/api.pingdom.com\\/",
    "type" : "rest",
    "authentication" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
