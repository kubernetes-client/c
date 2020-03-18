/*
 * v1beta1_token_review_spec.h
 *
 * TokenReviewSpec is a description of the token authentication request.
 */

#ifndef _v1beta1_token_review_spec_H_
#define _v1beta1_token_review_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_token_review_spec_t {
    list_t *audiences; //primitive container
    char *token; // string

} v1beta1_token_review_spec_t;

v1beta1_token_review_spec_t *v1beta1_token_review_spec_create(
    list_t *audiences,
    char *token
);

void v1beta1_token_review_spec_free(v1beta1_token_review_spec_t *v1beta1_token_review_spec);

v1beta1_token_review_spec_t *v1beta1_token_review_spec_parseFromJSON(cJSON *v1beta1_token_review_specJSON);

cJSON *v1beta1_token_review_spec_convertToJSON(v1beta1_token_review_spec_t *v1beta1_token_review_spec);

#endif /* _v1beta1_token_review_spec_H_ */

