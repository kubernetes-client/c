/*
 * v1_token_request_status.h
 *
 * TokenRequestStatus is the result of a token request.
 */

#ifndef _v1_token_request_status_H_
#define _v1_token_request_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_token_request_status_t v1_token_request_status_t;




typedef struct v1_token_request_status_t {
    char *expiration_timestamp; //date time
    char *token; // string

} v1_token_request_status_t;

v1_token_request_status_t *v1_token_request_status_create(
    char *expiration_timestamp,
    char *token
);

void v1_token_request_status_free(v1_token_request_status_t *v1_token_request_status);

v1_token_request_status_t *v1_token_request_status_parseFromJSON(cJSON *v1_token_request_statusJSON);

cJSON *v1_token_request_status_convertToJSON(v1_token_request_status_t *v1_token_request_status);

#endif /* _v1_token_request_status_H_ */

