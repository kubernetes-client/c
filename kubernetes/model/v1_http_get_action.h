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

#include "int_or_string.h"
#include "v1_http_header.h"

// Enum SCHEME for v1_http_get_action

typedef enum  { kubernetes_v1_http_get_action_SCHEME_NULL = 0, kubernetes_v1_http_get_action_SCHEME_HTTP, kubernetes_v1_http_get_action_SCHEME_HTTPS } kubernetes_v1_http_get_action_SCHEME_e;

char* v1_http_get_action_scheme_ToString(kubernetes_v1_http_get_action_SCHEME_e scheme);

kubernetes_v1_http_get_action_SCHEME_e v1_http_get_action_scheme_FromString(char* scheme);



typedef struct v1_http_get_action_t {
    char *host; // string
    list_t *http_headers; //nonprimitive container
    char *path; // string
    int_or_string_t *port; // custom
    kubernetes_v1_http_get_action_SCHEME_e scheme; //enum

} v1_http_get_action_t;

v1_http_get_action_t *v1_http_get_action_create(
    char *host,
    list_t *http_headers,
    char *path,
    int_or_string_t *port,
    kubernetes_v1_http_get_action_SCHEME_e scheme
);

void v1_http_get_action_free(v1_http_get_action_t *v1_http_get_action);

v1_http_get_action_t *v1_http_get_action_parseFromJSON(cJSON *v1_http_get_actionJSON);

cJSON *v1_http_get_action_convertToJSON(v1_http_get_action_t *v1_http_get_action);

#endif /* _v1_http_get_action_H_ */

