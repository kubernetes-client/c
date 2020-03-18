/*
 * v1beta1_certificate_signing_request_spec.h
 *
 * This information is immutable after the request is created. Only the Request and Usages fields can be set on creation, other fields are derived by Kubernetes and cannot be modified by users.
 */

#ifndef _v1beta1_certificate_signing_request_spec_H_
#define _v1beta1_certificate_signing_request_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_certificate_signing_request_spec_t {
    list_t* extra; //map
    list_t *groups; //primitive container
    char request; //Byte
    char *uid; // string
    list_t *usages; //primitive container
    char *username; // string

} v1beta1_certificate_signing_request_spec_t;

v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec_create(
    list_t* extra,
    list_t *groups,
    char request,
    char *uid,
    list_t *usages,
    char *username
);

void v1beta1_certificate_signing_request_spec_free(v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec);

v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec_parseFromJSON(cJSON *v1beta1_certificate_signing_request_specJSON);

cJSON *v1beta1_certificate_signing_request_spec_convertToJSON(v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec);

#endif /* _v1beta1_certificate_signing_request_spec_H_ */

