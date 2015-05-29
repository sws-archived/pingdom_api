INTRODUCTION
------------
Pingdom API provides a set of functions to interact with the Pingdom API.

DEPENDENCIES
------------
The wsclient module (including wsclient_rest), entity,
  and features.

This is a developer module; it provides little end-user-facing functionality
 out of the box.

TO USE
------
Go to admin/config/services/pingdomapi and enter your Pingdom credentials
  Note: You first will need to create a Pingdom Application Key to access
   the API.
You then have several functions available to use from other modules:
  pingdom_api_wsclient_get_check_list($limit = 25000, $offset = 0)
  pingdom_api_wsclient_modify_multiple_checks($paused, $resolution, $checkids)
  pingdom_api_rest_request(
    $httpmethod,
    $method,
    $params = array(),
    $url_args = array()
  );

EXAMPLES
--------

pingdom_api_wsclient_get_check_list('20', '5');

Returns an array with the following keys: 'checks' and 'counts'.
'checks' includes the metadata about 20 checks, starting with the 5th one.
'counts' includes metadata about the number of checks.


pingdom_api_wsclient_modify_multiple_checks('true', '15', '1613855');

Pause the check with ID=1613855, and set its check resolution to
  every 15 minutes.

Returns an array with the key:
  'message' => 'Modification of <n> checks was successful!'


pingdom_api_rest_request(
  'POST',
  'checks',
  array(
    'name' => 'Beluga Cam',
    'type' => 'http',
    'host' => 'www.vanaqua.org',
    'url' => '/learn/see-and-learn/live-cams/beluga-cam'
  )
);

Creates an HTTP check named "Beluga Cam" checking
  the URL http://www.vanaqua.org/learn/see-and-learn/live-cams/beluga-cam


pingdom_api_rest_request(
  'PUT',
  'checks',
  array(
    'name' => 'Beluga Cam New Name'
  ),
  array(
    '1613855'
  )
);

Modifies the check with ID=1613855 and sets the name to "Beluga Cam New Name"


pingdom_api_rest_request('DELETE', 'checks', array(), array('1613855'));

Deletes the check with ID=1613855 (sad trombone).
