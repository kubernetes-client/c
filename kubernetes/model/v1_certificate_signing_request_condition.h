/*
 * v1_certificate_signing_request_condition.h
 *
 * CertificateSigningRequestCondition describes a condition of a CertificateSigningRequest object
 */

#ifndef _v1_certificate_signing_request_condition_H_
#define _v1_certificate_signing_request_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_certificate_signing_request_condition_t v1_certificate_signing_request_condition_t;




typedef struct v1_certificate_signing_request_condition_t {
    char *last_transition_time; //date time
    char *last_update_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

} v1_certificate_signing_request_condition_t;

v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition_create(
    char *last_transition_time,
    char *last_update_time,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v1_certificate_signing_request_condition_free(v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition);

v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition_parseFromJSON(cJSON *v1_certificate_signing_request_conditionJSON);

cJSON *v1_certificate_signing_request_condition_convertToJSON(v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition);

#endif /* _v1_certificate_signing_request_condition_H_ */

