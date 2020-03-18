/*
 * admissionregistration_v1beta1_service_reference.h
 *
 * ServiceReference holds a reference to Service.legacy.k8s.io
 */

#ifndef _admissionregistration_v1beta1_service_reference_H_
#define _admissionregistration_v1beta1_service_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct admissionregistration_v1beta1_service_reference_t {
    char *name; // string
    char *namespace; // string
    char *path; // string
    int port; //numeric

} admissionregistration_v1beta1_service_reference_t;

admissionregistration_v1beta1_service_reference_t *admissionregistration_v1beta1_service_reference_create(
    char *name,
    char *namespace,
    char *path,
    int port
);

void admissionregistration_v1beta1_service_reference_free(admissionregistration_v1beta1_service_reference_t *admissionregistration_v1beta1_service_reference);

admissionregistration_v1beta1_service_reference_t *admissionregistration_v1beta1_service_reference_parseFromJSON(cJSON *admissionregistration_v1beta1_service_referenceJSON);

cJSON *admissionregistration_v1beta1_service_reference_convertToJSON(admissionregistration_v1beta1_service_reference_t *admissionregistration_v1beta1_service_reference);

#endif /* _admissionregistration_v1beta1_service_reference_H_ */

