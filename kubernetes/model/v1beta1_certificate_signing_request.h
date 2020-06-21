/*
 * v1beta1_certificate_signing_request.h
 *
 * Describes a certificate signing request
 */

#ifndef _v1beta1_certificate_signing_request_H_
#define _v1beta1_certificate_signing_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_certificate_signing_request_t v1beta1_certificate_signing_request_t;

#include "v1_object_meta.h"
#include "v1beta1_certificate_signing_request_spec.h"
#include "v1beta1_certificate_signing_request_status.h"



typedef struct v1beta1_certificate_signing_request_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_certificate_signing_request_spec_t *spec; //model
    struct v1beta1_certificate_signing_request_status_t *status; //model

} v1beta1_certificate_signing_request_t;

v1beta1_certificate_signing_request_t *v1beta1_certificate_signing_request_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_certificate_signing_request_spec_t *spec,
    v1beta1_certificate_signing_request_status_t *status
);

void v1beta1_certificate_signing_request_free(v1beta1_certificate_signing_request_t *v1beta1_certificate_signing_request);

v1beta1_certificate_signing_request_t *v1beta1_certificate_signing_request_parseFromJSON(cJSON *v1beta1_certificate_signing_requestJSON);

cJSON *v1beta1_certificate_signing_request_convertToJSON(v1beta1_certificate_signing_request_t *v1beta1_certificate_signing_request);

#endif /* _v1beta1_certificate_signing_request_H_ */

