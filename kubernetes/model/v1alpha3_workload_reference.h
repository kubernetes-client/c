/*
 * v1alpha3_workload_reference.h
 *
 * WorkloadReference references the Workload object together with the template that was used to create a particular PodGroup.
 */

#ifndef _v1alpha3_workload_reference_H_
#define _v1alpha3_workload_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_workload_reference_t v1alpha3_workload_reference_t;




typedef struct v1alpha3_workload_reference_t {
    char *template_name; // string
    char *workload_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_workload_reference_t;

__attribute__((deprecated)) v1alpha3_workload_reference_t *v1alpha3_workload_reference_create(
    char *template_name,
    char *workload_name
);

void v1alpha3_workload_reference_free(v1alpha3_workload_reference_t *v1alpha3_workload_reference);

v1alpha3_workload_reference_t *v1alpha3_workload_reference_parseFromJSON(cJSON *v1alpha3_workload_referenceJSON);

cJSON *v1alpha3_workload_reference_convertToJSON(v1alpha3_workload_reference_t *v1alpha3_workload_reference);

#endif /* _v1alpha3_workload_reference_H_ */

