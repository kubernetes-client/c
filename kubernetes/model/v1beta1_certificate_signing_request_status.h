/*
 * v1beta1_certificate_signing_request_status.h
 *
 * 
 */

#ifndef _v1beta1_certificate_signing_request_status_H_
#define _v1beta1_certificate_signing_request_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta1_certificate_signing_request_condition.h"



typedef struct v1beta1_certificate_signing_request_status_t {
    char certificate; //Byte
    list_t *conditions; //nonprimitive container

} v1beta1_certificate_signing_request_status_t;

v1beta1_certificate_signing_request_status_t *v1beta1_certificate_signing_request_status_create(
    char certificate,
    list_t *conditions
);

void v1beta1_certificate_signing_request_status_free(v1beta1_certificate_signing_request_status_t *v1beta1_certificate_signing_request_status);

v1beta1_certificate_signing_request_status_t *v1beta1_certificate_signing_request_status_parseFromJSON(cJSON *v1beta1_certificate_signing_request_statusJSON);

cJSON *v1beta1_certificate_signing_request_status_convertToJSON(v1beta1_certificate_signing_request_status_t *v1beta1_certificate_signing_request_status);

#endif /* _v1beta1_certificate_signing_request_status_H_ */

