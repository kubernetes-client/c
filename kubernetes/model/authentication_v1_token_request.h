/*
 * authentication_v1_token_request.h
 *
 * TokenRequest requests a token for a given service account.
 */

#ifndef _authentication_v1_token_request_H_
#define _authentication_v1_token_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct authentication_v1_token_request_t authentication_v1_token_request_t;

#include "v1_object_meta.h"
#include "v1_token_request_spec.h"
#include "v1_token_request_status.h"



typedef struct authentication_v1_token_request_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_token_request_spec_t *spec; //model
    struct v1_token_request_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} authentication_v1_token_request_t;

__attribute__((deprecated)) authentication_v1_token_request_t *authentication_v1_token_request_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_token_request_spec_t *spec,
    v1_token_request_status_t *status
);

void authentication_v1_token_request_free(authentication_v1_token_request_t *authentication_v1_token_request);

authentication_v1_token_request_t *authentication_v1_token_request_parseFromJSON(cJSON *authentication_v1_token_requestJSON);

cJSON *authentication_v1_token_request_convertToJSON(authentication_v1_token_request_t *authentication_v1_token_request);

#endif /* _authentication_v1_token_request_H_ */

