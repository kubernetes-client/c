/*
 * v1_http_get_action.h
 *
 * HTTPGetAction describes an action based on HTTP Get requests.
 */

#ifndef _v1_http_get_action_H_
#define _v1_http_get_action_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_http_get_action_t v1_http_get_action_t;

#include "object.h"
#include "v1_http_header.h"



typedef struct v1_http_get_action_t {
    char *host; // string
    list_t *http_headers; //nonprimitive container
    char *path; // string
    object_t *port; //object
    char *scheme; // string

} v1_http_get_action_t;

v1_http_get_action_t *v1_http_get_action_create(
    char *host,
    list_t *http_headers,
    char *path,
    object_t *port,
    char *scheme
);

void v1_http_get_action_free(v1_http_get_action_t *v1_http_get_action);

v1_http_get_action_t *v1_http_get_action_parseFromJSON(cJSON *v1_http_get_actionJSON);

cJSON *v1_http_get_action_convertToJSON(v1_http_get_action_t *v1_http_get_action);

#endif /* _v1_http_get_action_H_ */

