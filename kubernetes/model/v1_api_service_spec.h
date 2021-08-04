/*
 * v1_api_service_spec.h
 *
 * APIServiceSpec contains information for locating and communicating with a server. Only https is supported, though you are able to disable certificate verification.
 */

#ifndef _v1_api_service_spec_H_
#define _v1_api_service_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_api_service_spec_t v1_api_service_spec_t;

#include "apiregistration_v1_service_reference.h"



typedef struct v1_api_service_spec_t {
    char *ca_bundle; //ByteArray
    char *group; // string
    int group_priority_minimum; //numeric
    int insecure_skip_tls_verify; //boolean
    struct apiregistration_v1_service_reference_t *service; //model
    char *version; // string
    int version_priority; //numeric

} v1_api_service_spec_t;

v1_api_service_spec_t *v1_api_service_spec_create(
    char *ca_bundle,
    char *group,
    int group_priority_minimum,
    int insecure_skip_tls_verify,
    apiregistration_v1_service_reference_t *service,
    char *version,
    int version_priority
);

void v1_api_service_spec_free(v1_api_service_spec_t *v1_api_service_spec);

v1_api_service_spec_t *v1_api_service_spec_parseFromJSON(cJSON *v1_api_service_specJSON);

cJSON *v1_api_service_spec_convertToJSON(v1_api_service_spec_t *v1_api_service_spec);

#endif /* _v1_api_service_spec_H_ */

