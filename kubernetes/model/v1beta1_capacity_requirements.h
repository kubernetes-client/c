/*
 * v1beta1_capacity_requirements.h
 *
 * CapacityRequirements defines the capacity requirements for a specific device request.
 */

#ifndef _v1beta1_capacity_requirements_H_
#define _v1beta1_capacity_requirements_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_capacity_requirements_t v1beta1_capacity_requirements_t;




typedef struct v1beta1_capacity_requirements_t {
    list_t* requests; //map

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_capacity_requirements_t;

__attribute__((deprecated)) v1beta1_capacity_requirements_t *v1beta1_capacity_requirements_create(
    list_t* requests
);

void v1beta1_capacity_requirements_free(v1beta1_capacity_requirements_t *v1beta1_capacity_requirements);

v1beta1_capacity_requirements_t *v1beta1_capacity_requirements_parseFromJSON(cJSON *v1beta1_capacity_requirementsJSON);

cJSON *v1beta1_capacity_requirements_convertToJSON(v1beta1_capacity_requirements_t *v1beta1_capacity_requirements);

#endif /* _v1beta1_capacity_requirements_H_ */

