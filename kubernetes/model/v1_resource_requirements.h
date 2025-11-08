/*
 * v1_resource_requirements.h
 *
 * ResourceRequirements describes the compute resource requirements.
 */

#ifndef _v1_resource_requirements_H_
#define _v1_resource_requirements_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_requirements_t v1_resource_requirements_t;

#include "core_v1_resource_claim.h"



typedef struct v1_resource_requirements_t {
    list_t *claims; //nonprimitive container
    list_t* limits; //map
    list_t* requests; //map

    int _library_owned; // Is the library responsible for freeing this object?
} v1_resource_requirements_t;

__attribute__((deprecated)) v1_resource_requirements_t *v1_resource_requirements_create(
    list_t *claims,
    list_t* limits,
    list_t* requests
);

void v1_resource_requirements_free(v1_resource_requirements_t *v1_resource_requirements);

v1_resource_requirements_t *v1_resource_requirements_parseFromJSON(cJSON *v1_resource_requirementsJSON);

cJSON *v1_resource_requirements_convertToJSON(v1_resource_requirements_t *v1_resource_requirements);

#endif /* _v1_resource_requirements_H_ */

