/*
 * v1alpha1_pod_certificate_request_status.h
 *
 * PodCertificateRequestStatus describes the status of the request, and holds the certificate data if the request is issued.
 */

#ifndef _v1alpha1_pod_certificate_request_status_H_
#define _v1alpha1_pod_certificate_request_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_pod_certificate_request_status_t v1alpha1_pod_certificate_request_status_t;

#include "v1_condition.h"



typedef struct v1alpha1_pod_certificate_request_status_t {
    char *begin_refresh_at; //date time
    char *certificate_chain; // string
    list_t *conditions; //nonprimitive container
    char *not_after; //date time
    char *not_before; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_pod_certificate_request_status_t;

__attribute__((deprecated)) v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status_create(
    char *begin_refresh_at,
    char *certificate_chain,
    list_t *conditions,
    char *not_after,
    char *not_before
);

void v1alpha1_pod_certificate_request_status_free(v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status);

v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status_parseFromJSON(cJSON *v1alpha1_pod_certificate_request_statusJSON);

cJSON *v1alpha1_pod_certificate_request_status_convertToJSON(v1alpha1_pod_certificate_request_status_t *v1alpha1_pod_certificate_request_status);

#endif /* _v1alpha1_pod_certificate_request_status_H_ */

