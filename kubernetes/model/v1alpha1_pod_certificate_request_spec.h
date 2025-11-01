/*
 * v1alpha1_pod_certificate_request_spec.h
 *
 * PodCertificateRequestSpec describes the certificate request.  All fields are immutable after creation.
 */

#ifndef _v1alpha1_pod_certificate_request_spec_H_
#define _v1alpha1_pod_certificate_request_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_pod_certificate_request_spec_t v1alpha1_pod_certificate_request_spec_t;




typedef struct v1alpha1_pod_certificate_request_spec_t {
    int max_expiration_seconds; //numeric
    char *node_name; // string
    char *node_uid; // string
    char *pkix_public_key; //ByteArray
    char *pod_name; // string
    char *pod_uid; // string
    char *proof_of_possession; //ByteArray
    char *service_account_name; // string
    char *service_account_uid; // string
    char *signer_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_pod_certificate_request_spec_t;

__attribute__((deprecated)) v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec_create(
    int max_expiration_seconds,
    char *node_name,
    char *node_uid,
    char *pkix_public_key,
    char *pod_name,
    char *pod_uid,
    char *proof_of_possession,
    char *service_account_name,
    char *service_account_uid,
    char *signer_name
);

void v1alpha1_pod_certificate_request_spec_free(v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec);

v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec_parseFromJSON(cJSON *v1alpha1_pod_certificate_request_specJSON);

cJSON *v1alpha1_pod_certificate_request_spec_convertToJSON(v1alpha1_pod_certificate_request_spec_t *v1alpha1_pod_certificate_request_spec);

#endif /* _v1alpha1_pod_certificate_request_spec_H_ */

