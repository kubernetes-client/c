/*
 * v1beta1_certificate_signing_request_condition.h
 *
 * 
 */

#ifndef _v1beta1_certificate_signing_request_condition_H_
#define _v1beta1_certificate_signing_request_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_certificate_signing_request_condition_t v1beta1_certificate_signing_request_condition_t;




typedef struct v1beta1_certificate_signing_request_condition_t {
    char *last_update_time; //date time
    char *message; // string
    char *reason; // string
    char *type; // string

} v1beta1_certificate_signing_request_condition_t;

v1beta1_certificate_signing_request_condition_t *v1beta1_certificate_signing_request_condition_create(
    char *last_update_time,
    char *message,
    char *reason,
    char *type
);

void v1beta1_certificate_signing_request_condition_free(v1beta1_certificate_signing_request_condition_t *v1beta1_certificate_signing_request_condition);

v1beta1_certificate_signing_request_condition_t *v1beta1_certificate_signing_request_condition_parseFromJSON(cJSON *v1beta1_certificate_signing_request_conditionJSON);

cJSON *v1beta1_certificate_signing_request_condition_convertToJSON(v1beta1_certificate_signing_request_condition_t *v1beta1_certificate_signing_request_condition);

#endif /* _v1beta1_certificate_signing_request_condition_H_ */

