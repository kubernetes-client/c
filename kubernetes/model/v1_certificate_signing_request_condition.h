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


// Enum TYPE for v1_certificate_signing_request_condition

typedef enum  { kubernetes_v1_certificate_signing_request_condition_TYPE_NULL = 0, kubernetes_v1_certificate_signing_request_condition_TYPE_Approved, kubernetes_v1_certificate_signing_request_condition_TYPE_Denied, kubernetes_v1_certificate_signing_request_condition_TYPE_Failed } kubernetes_v1_certificate_signing_request_condition_TYPE_e;

char* v1_certificate_signing_request_condition_type_ToString(kubernetes_v1_certificate_signing_request_condition_TYPE_e type);

kubernetes_v1_certificate_signing_request_condition_TYPE_e v1_certificate_signing_request_condition_type_FromString(char* type);



typedef struct v1_certificate_signing_request_condition_t {
    char *last_transition_time; //date time
    char *last_update_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    kubernetes_v1_certificate_signing_request_condition_TYPE_e type; //enum

} v1_certificate_signing_request_condition_t;

v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition_create(
    char *last_transition_time,
    char *last_update_time,
    char *message,
    char *reason,
    char *status,
    kubernetes_v1_certificate_signing_request_condition_TYPE_e type
);

void v1_certificate_signing_request_condition_free(v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition);

v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition_parseFromJSON(cJSON *v1_certificate_signing_request_conditionJSON);

cJSON *v1_certificate_signing_request_condition_convertToJSON(v1_certificate_signing_request_condition_t *v1_certificate_signing_request_condition);

#endif /* _v1_certificate_signing_request_condition_H_ */

