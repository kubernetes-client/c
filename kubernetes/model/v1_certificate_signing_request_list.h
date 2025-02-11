/*
 * v1_certificate_signing_request_list.h
 *
 * CertificateSigningRequestList is a collection of CertificateSigningRequest objects
 */

#ifndef _v1_certificate_signing_request_list_H_
#define _v1_certificate_signing_request_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_certificate_signing_request_list_t v1_certificate_signing_request_list_t;

#include "v1_certificate_signing_request.h"
#include "v1_list_meta.h"



typedef struct v1_certificate_signing_request_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_certificate_signing_request_list_t;

__attribute__((deprecated)) v1_certificate_signing_request_list_t *v1_certificate_signing_request_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_certificate_signing_request_list_free(v1_certificate_signing_request_list_t *v1_certificate_signing_request_list);

v1_certificate_signing_request_list_t *v1_certificate_signing_request_list_parseFromJSON(cJSON *v1_certificate_signing_request_listJSON);

cJSON *v1_certificate_signing_request_list_convertToJSON(v1_certificate_signing_request_list_t *v1_certificate_signing_request_list);

#endif /* _v1_certificate_signing_request_list_H_ */

