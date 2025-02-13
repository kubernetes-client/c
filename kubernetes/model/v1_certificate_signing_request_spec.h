/*
 * v1_certificate_signing_request_spec.h
 *
 * CertificateSigningRequestSpec contains the certificate request.
 */

#ifndef _v1_certificate_signing_request_spec_H_
#define _v1_certificate_signing_request_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_certificate_signing_request_spec_t v1_certificate_signing_request_spec_t;




typedef struct v1_certificate_signing_request_spec_t {
    int expiration_seconds; //numeric
    list_t* extra; //map
    list_t *groups; //primitive container
    char *request; //ByteArray
    char *signer_name; // string
    char *uid; // string
    list_t *usages; //primitive container
    char *username; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_certificate_signing_request_spec_t;

__attribute__((deprecated)) v1_certificate_signing_request_spec_t *v1_certificate_signing_request_spec_create(
    int expiration_seconds,
    list_t* extra,
    list_t *groups,
    char *request,
    char *signer_name,
    char *uid,
    list_t *usages,
    char *username
);

void v1_certificate_signing_request_spec_free(v1_certificate_signing_request_spec_t *v1_certificate_signing_request_spec);

v1_certificate_signing_request_spec_t *v1_certificate_signing_request_spec_parseFromJSON(cJSON *v1_certificate_signing_request_specJSON);

cJSON *v1_certificate_signing_request_spec_convertToJSON(v1_certificate_signing_request_spec_t *v1_certificate_signing_request_spec);

#endif /* _v1_certificate_signing_request_spec_H_ */

