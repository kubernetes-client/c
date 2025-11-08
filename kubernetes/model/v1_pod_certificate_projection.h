/*
 * v1_pod_certificate_projection.h
 *
 * PodCertificateProjection provides a private key and X.509 certificate in the pod filesystem.
 */

#ifndef _v1_pod_certificate_projection_H_
#define _v1_pod_certificate_projection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_certificate_projection_t v1_pod_certificate_projection_t;




typedef struct v1_pod_certificate_projection_t {
    char *certificate_chain_path; // string
    char *credential_bundle_path; // string
    char *key_path; // string
    char *key_type; // string
    int max_expiration_seconds; //numeric
    char *signer_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_certificate_projection_t;

__attribute__((deprecated)) v1_pod_certificate_projection_t *v1_pod_certificate_projection_create(
    char *certificate_chain_path,
    char *credential_bundle_path,
    char *key_path,
    char *key_type,
    int max_expiration_seconds,
    char *signer_name
);

void v1_pod_certificate_projection_free(v1_pod_certificate_projection_t *v1_pod_certificate_projection);

v1_pod_certificate_projection_t *v1_pod_certificate_projection_parseFromJSON(cJSON *v1_pod_certificate_projectionJSON);

cJSON *v1_pod_certificate_projection_convertToJSON(v1_pod_certificate_projection_t *v1_pod_certificate_projection);

#endif /* _v1_pod_certificate_projection_H_ */

