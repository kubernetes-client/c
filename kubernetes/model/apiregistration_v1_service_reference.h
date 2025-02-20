/*
 * apiregistration_v1_service_reference.h
 *
 * ServiceReference holds a reference to Service.legacy.k8s.io
 */

#ifndef _apiregistration_v1_service_reference_H_
#define _apiregistration_v1_service_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apiregistration_v1_service_reference_t apiregistration_v1_service_reference_t;




typedef struct apiregistration_v1_service_reference_t {
    char *name; // string
    char *_namespace; // string
    int port; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} apiregistration_v1_service_reference_t;

__attribute__((deprecated)) apiregistration_v1_service_reference_t *apiregistration_v1_service_reference_create(
    char *name,
    char *_namespace,
    int port
);

void apiregistration_v1_service_reference_free(apiregistration_v1_service_reference_t *apiregistration_v1_service_reference);

apiregistration_v1_service_reference_t *apiregistration_v1_service_reference_parseFromJSON(cJSON *apiregistration_v1_service_referenceJSON);

cJSON *apiregistration_v1_service_reference_convertToJSON(apiregistration_v1_service_reference_t *apiregistration_v1_service_reference);

#endif /* _apiregistration_v1_service_reference_H_ */

