/*
 * v1_certificate_signing_request_status.h
 *
 * CertificateSigningRequestStatus contains conditions used to indicate approved/denied/failed status of the request, and the issued certificate.
 */

#ifndef _v1_certificate_signing_request_status_H_
#define _v1_certificate_signing_request_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_certificate_signing_request_status_t v1_certificate_signing_request_status_t;

#include "v1_certificate_signing_request_condition.h"



typedef struct v1_certificate_signing_request_status_t {
    char *certificate; //ByteArray
    list_t *conditions; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_certificate_signing_request_status_t;

__attribute__((deprecated)) v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_create(
    char *certificate,
    list_t *conditions
);

void v1_certificate_signing_request_status_free(v1_certificate_signing_request_status_t *v1_certificate_signing_request_status);

v1_certificate_signing_request_status_t *v1_certificate_signing_request_status_parseFromJSON(cJSON *v1_certificate_signing_request_statusJSON);

cJSON *v1_certificate_signing_request_status_convertToJSON(v1_certificate_signing_request_status_t *v1_certificate_signing_request_status);

#endif /* _v1_certificate_signing_request_status_H_ */

