/*
 * storage_v1_token_request.h
 *
 * TokenRequest contains parameters of a service account token.
 */

#ifndef _storage_v1_token_request_H_
#define _storage_v1_token_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct storage_v1_token_request_t storage_v1_token_request_t;




typedef struct storage_v1_token_request_t {
    char *audience; // string
    long expiration_seconds; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} storage_v1_token_request_t;

__attribute__((deprecated)) storage_v1_token_request_t *storage_v1_token_request_create(
    char *audience,
    long expiration_seconds
);

void storage_v1_token_request_free(storage_v1_token_request_t *storage_v1_token_request);

storage_v1_token_request_t *storage_v1_token_request_parseFromJSON(cJSON *storage_v1_token_requestJSON);

cJSON *storage_v1_token_request_convertToJSON(storage_v1_token_request_t *storage_v1_token_request);

#endif /* _storage_v1_token_request_H_ */

