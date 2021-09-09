/*
 * v1_service_account_token_projection.h
 *
 * ServiceAccountTokenProjection represents a projected service account token volume. This projection can be used to insert a service account token into the pods runtime filesystem for use against APIs (Kubernetes API Server or otherwise).
 */

#ifndef _v1_service_account_token_projection_H_
#define _v1_service_account_token_projection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_account_token_projection_t v1_service_account_token_projection_t;




typedef struct v1_service_account_token_projection_t {
    char *audience; // string
    long expiration_seconds; //numeric
    char *path; // string

} v1_service_account_token_projection_t;

v1_service_account_token_projection_t *v1_service_account_token_projection_create(
    char *audience,
    long expiration_seconds,
    char *path
);

void v1_service_account_token_projection_free(v1_service_account_token_projection_t *v1_service_account_token_projection);

v1_service_account_token_projection_t *v1_service_account_token_projection_parseFromJSON(cJSON *v1_service_account_token_projectionJSON);

cJSON *v1_service_account_token_projection_convertToJSON(v1_service_account_token_projection_t *v1_service_account_token_projection);

#endif /* _v1_service_account_token_projection_H_ */

