/*
 * v1alpha1_pod_certificate_request.h
 *
 * PodCertificateRequest encodes a pod requesting a certificate from a given signer.  Kubelets use this API to implement podCertificate projected volumes
 */

#ifndef _v1alpha1_pod_certificate_request_H_
#define _v1alpha1_pod_certificate_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_pod_certificate_request_t v1alpha1_pod_certificate_request_t;

#include "v1_object_meta.h"
#include "v1alpha1_pod_certificate_request_spec.h"
#include "v1alpha1_pod_certificate_request_status.h"



typedef struct v1alpha1_pod_certificate_request_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha1_pod_certificate_request_spec_t *spec; //model
    struct v1alpha1_pod_certificate_request_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_pod_certificate_request_t;

__attribute__((deprecated)) v1alpha1_pod_certificate_request_t *v1alpha1_pod_certificate_request_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_pod_certificate_request_spec_t *spec,
    v1alpha1_pod_certificate_request_status_t *status
);

void v1alpha1_pod_certificate_request_free(v1alpha1_pod_certificate_request_t *v1alpha1_pod_certificate_request);

v1alpha1_pod_certificate_request_t *v1alpha1_pod_certificate_request_parseFromJSON(cJSON *v1alpha1_pod_certificate_requestJSON);

cJSON *v1alpha1_pod_certificate_request_convertToJSON(v1alpha1_pod_certificate_request_t *v1alpha1_pod_certificate_request);

#endif /* _v1alpha1_pod_certificate_request_H_ */

