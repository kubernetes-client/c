/*
 * v1_component_status.h
 *
 * ComponentStatus (and ComponentStatusList) holds the cluster validation info. Deprecated: This API is deprecated in v1.19+
 */

#ifndef _v1_component_status_H_
#define _v1_component_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_component_status_t v1_component_status_t;

#include "v1_component_condition.h"
#include "v1_object_meta.h"



typedef struct v1_component_status_t {
    char *api_version; // string
    list_t *conditions; //nonprimitive container
    char *kind; // string
    struct v1_object_meta_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_component_status_t;

__attribute__((deprecated)) v1_component_status_t *v1_component_status_create(
    char *api_version,
    list_t *conditions,
    char *kind,
    v1_object_meta_t *metadata
);

void v1_component_status_free(v1_component_status_t *v1_component_status);

v1_component_status_t *v1_component_status_parseFromJSON(cJSON *v1_component_statusJSON);

cJSON *v1_component_status_convertToJSON(v1_component_status_t *v1_component_status);

#endif /* _v1_component_status_H_ */

