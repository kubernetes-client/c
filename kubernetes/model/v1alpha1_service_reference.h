/*
 * v1alpha1_service_reference.h
 *
 * ServiceReference holds a reference to Service.legacy.k8s.io
 */

#ifndef _v1alpha1_service_reference_H_
#define _v1alpha1_service_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1alpha1_service_reference_t {
    char *name; // string
    char *namespace; // string
    char *path; // string
    int port; //numeric

} v1alpha1_service_reference_t;

v1alpha1_service_reference_t *v1alpha1_service_reference_create(
    char *name,
    char *namespace,
    char *path,
    int port
);

void v1alpha1_service_reference_free(v1alpha1_service_reference_t *v1alpha1_service_reference);

v1alpha1_service_reference_t *v1alpha1_service_reference_parseFromJSON(cJSON *v1alpha1_service_referenceJSON);

cJSON *v1alpha1_service_reference_convertToJSON(v1alpha1_service_reference_t *v1alpha1_service_reference);

#endif /* _v1alpha1_service_reference_H_ */

