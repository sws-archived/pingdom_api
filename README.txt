Pingdom API provides a set of functions to interact with the Pingdom API.

Dependencies: The wsclient module (including wsclient_rest), entity, and features.

This is a developer module; it provides little end-user-facing functionality
 out of the box.

To use:

Go to admin/config/services/pingdomapi and enter your Pingdom credentials
  Note: You first will need to create a Pingdom Application Key to access
   the API.
You then have several functions available to use from other modules:
  pingdom_api_wsclient_get_check_list($limit = 25000, $offset = 0)
  pingdom_api_wsclient_modify_multiple_checks($paused, $resolution, $checkids)
