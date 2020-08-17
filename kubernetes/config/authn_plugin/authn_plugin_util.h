#ifndef _AUTHN_PLUGIN_UTIL_H
#define _AUTHN_PLUGIN_UTIL_H

#include "../../include/apiClient.h"

#ifdef  __cplusplus
extern "C" {
#endif

#define HTTP_REQUEST_GET "GET"
#define HTTP_REQUEST_POST "POST"
#define HTTP_REQUEST_DELETE "DELETE"
#define HTTP_REQUEST_PATCH "PATCH"

typedef enum shc_http_rc_t {
    HTTP_RC_OK = 200,
    HTTP_RC_UNAUTHORIZED = 400
} shc_http_rc_t;

/*
 * shc_request
 *
 * Description:
 *
 * Issue a http(s) request
 *
 * Return:
 *
 *  HTTP request return code
 *
 * Parameter:
 *
 * IN:
 * request_type : HTTP_REQUEST_GET,HTTP_REQUEST_POST,HTTP_REQUEST_DELETE or HTTP_REQUEST_PATCH
 * url          : http request url
 * sc           : security context for SSL/TLS
 * apiKeys      : key-value list including basic or bearer token for HTTP authentication
 * contentType  : string list including HTTP content type
 * post_data    : post data string when request_type is "POST"
 *
 * OUT:
 * p_http_response          : pointer that pointing to HTTP response raw string, the memory is allocated in shc_request, but user should free it out of shc_request after it is useless.
 * p_http_response_length   : pointer that pointing to the length of p_http_response
 *
 */
int shc_request(char **p_http_response, int *p_http_response_length, char *request_type, const char *url, sslConfig_t * sc, list_t * apiKeys, list_t * contentType, char *post_data);

/*
 * shc_get_string_from_json
 *
 * Description:
 *
 * Get a string value from json by a key
 *
 * Return:
 *
 *  char *   :   the value string 
 *  NULL     :   cannot find the value by key
 *
 * Parameter:
 *
 * IN:
 * json_string  : a json string that includes key-value string
 * key          : the key needs to find
 *
 * OUT:
 * None
 *
 */
char *shc_get_string_from_json(const char *json_string, const char *key);

#ifdef  __cplusplus
}
#endif
#endif                          /* _AUTHN_PLUGIN_UTIL_H */
