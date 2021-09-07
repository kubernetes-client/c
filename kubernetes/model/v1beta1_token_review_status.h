/*
 * v1beta1_token_review_status.h
 *
 * TokenReviewStatus is the result of the token authentication request.
 */

#ifndef _v1beta1_token_review_status_H_
#define _v1beta1_token_review_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_token_review_status_t v1beta1_token_review_status_t;

#include "v1beta1_user_info.h"



typedef struct v1beta1_token_review_status_t {
    list_t *audiences; //primitive container
    int authenticated; //boolean
    char *error; // string
    struct v1beta1_user_info_t *user; //model

} v1beta1_token_review_status_t;

v1beta1_token_review_status_t *v1beta1_token_review_status_create(
    list_t *audiences,
    int authenticated,
    char *error,
    v1beta1_user_info_t *user
);

void v1beta1_token_review_status_free(v1beta1_token_review_status_t *v1beta1_token_review_status);

v1beta1_token_review_status_t *v1beta1_token_review_status_parseFromJSON(cJSON *v1beta1_token_review_statusJSON);

cJSON *v1beta1_token_review_status_convertToJSON(v1beta1_token_review_status_t *v1beta1_token_review_status);

#endif /* _v1beta1_token_review_status_H_ */

