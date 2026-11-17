/*
 * v1_pod_certificate_request_spec.h
 *
 * PodCertificateRequestSpec describes the certificate request.  All fields are immutable after creation.
 */

#ifndef _v1_pod_certificate_request_spec_H_
#define _v1_pod_certificate_request_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_certificate_request_spec_t v1_pod_certificate_request_spec_t;




typedef struct v1_pod_certificate_request_spec_t {
    int *max_expiration_seconds; //numeric
    char *node_name; // string
    char *node_uid; // string
    char *pod_name; // string
    char *pod_uid; // string
    char *service_account_name; // string
    char *service_account_uid; // string
    char *signer_name; // string
    char *stub_pkcs10_request; //ByteArray
    list_t* unverified_user_annotations; //map

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_certificate_request_spec_t;

__attribute__((deprecated)) v1_pod_certificate_request_spec_t *v1_pod_certificate_request_spec_create(
    int *max_expiration_seconds,
    char *node_name,
    char *node_uid,
    char *pod_name,
    char *pod_uid,
    char *service_account_name,
    char *service_account_uid,
    char *signer_name,
    char *stub_pkcs10_request,
    list_t* unverified_user_annotations
);

void v1_pod_certificate_request_spec_free(v1_pod_certificate_request_spec_t *v1_pod_certificate_request_spec);

v1_pod_certificate_request_spec_t *v1_pod_certificate_request_spec_parseFromJSON(cJSON *v1_pod_certificate_request_specJSON);

cJSON *v1_pod_certificate_request_spec_convertToJSON(v1_pod_certificate_request_spec_t *v1_pod_certificate_request_spec);

#endif /* _v1_pod_certificate_request_spec_H_ */

