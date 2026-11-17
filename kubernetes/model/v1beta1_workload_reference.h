/*
 * v1beta1_workload_reference.h
 *
 * WorkloadReference references the Workload object together with the template that was used to create a particular PodGroup.
 */

#ifndef _v1beta1_workload_reference_H_
#define _v1beta1_workload_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_workload_reference_t v1beta1_workload_reference_t;




typedef struct v1beta1_workload_reference_t {
    char *template_name; // string
    char *workload_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_workload_reference_t;

__attribute__((deprecated)) v1beta1_workload_reference_t *v1beta1_workload_reference_create(
    char *template_name,
    char *workload_name
);

void v1beta1_workload_reference_free(v1beta1_workload_reference_t *v1beta1_workload_reference);

v1beta1_workload_reference_t *v1beta1_workload_reference_parseFromJSON(cJSON *v1beta1_workload_referenceJSON);

cJSON *v1beta1_workload_reference_convertToJSON(v1beta1_workload_reference_t *v1beta1_workload_reference);

#endif /* _v1beta1_workload_reference_H_ */

