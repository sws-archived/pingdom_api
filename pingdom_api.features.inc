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
    "operations" : {
      "modify_multiple_checks" : {
        "type" : "PUT",
        "url" : "api\/2.0\/checks",
        "label" : "Modify Multiple Checks",
        "parameter" : {
          "paused" : { "type" : "boolean", "optional" : true, "allow null" : 0 },
          "resolution" : { "type" : "integer", "optional" : true, "allow null" : 0 },
          "checkids" : { "type" : "list\u003Ctext\u003E", "allow null" : 0 }
        },
        "result" : { "type" : "text", "label" : "Response" }
      },
      "get_check_list" : {
        "url" : "api\/2.0\/checks",
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
          }
        },
        "name" : "get_check_list",
        "result" : { "type" : "text", "label" : "Check List" },
        "type" : "GET"
      },
      "rest_request_get" : {
        "type" : "GET",
        "url" : "",
        "label" : "GET Request",
        "parameter" : { "method" : { "type" : "text", "allow null" : 0 } },
        "name" : "rest_request_get"
      },
      "rest_request_post" : {
        "type" : "POST",
        "url" : "",
        "label" : "POST Request",
        "parameter" : { "method" : { "type" : "text", "allow null" : 0 } }
      },
      "rest_request_put" : {
        "type" : "PUT",
        "url" : "",
        "label" : "PUT Request",
        "parameter" : { "method" : { "type" : "text", "allow null" : 0 } }
      },
      "rest_request_delete" : {
        "type" : "DELETE",
        "url" : "",
        "label" : "DELETE Request",
        "parameter" : { "method" : { "type" : "text", "allow null" : 0 } }
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
