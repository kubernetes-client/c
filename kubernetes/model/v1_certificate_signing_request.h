/*
 * v1_certificate_signing_request.h
 *
 * CertificateSigningRequest objects provide a mechanism to obtain x509 certificates by submitting a certificate signing request, and having it asynchronously approved and issued.  Kubelets use this API to obtain:  1. client certificates to authenticate to kube-apiserver (with the \&quot;kubernetes.io/kube-apiserver-client-kubelet\&quot; signerName).  2. serving certificates for TLS endpoints kube-apiserver can connect to securely (with the \&quot;kubernetes.io/kubelet-serving\&quot; signerName).  This API can be used to request client certificates to authenticate to kube-apiserver (with the \&quot;kubernetes.io/kube-apiserver-client\&quot; signerName), or to obtain certificates from custom non-Kubernetes signers.
 */

#ifndef _v1_certificate_signing_request_H_
#define _v1_certificate_signing_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_certificate_signing_request_t v1_certificate_signing_request_t;

#include "v1_certificate_signing_request_spec.h"
#include "v1_certificate_signing_request_status.h"
#include "v1_object_meta.h"



typedef struct v1_certificate_signing_request_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_certificate_signing_request_spec_t *spec; //model
    struct v1_certificate_signing_request_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_certificate_signing_request_t;

__attribute__((deprecated)) v1_certificate_signing_request_t *v1_certificate_signing_request_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_certificate_signing_request_spec_t *spec,
    v1_certificate_signing_request_status_t *status
);

void v1_certificate_signing_request_free(v1_certificate_signing_request_t *v1_certificate_signing_request);

v1_certificate_signing_request_t *v1_certificate_signing_request_parseFromJSON(cJSON *v1_certificate_signing_requestJSON);

cJSON *v1_certificate_signing_request_convertToJSON(v1_certificate_signing_request_t *v1_certificate_signing_request);

#endif /* _v1_certificate_signing_request_H_ */

