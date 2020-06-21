/*
 * v1_component_status_list.h
 *
 * Status of all the conditions for the component as a list of ComponentStatus objects.
 */

#ifndef _v1_component_status_list_H_
#define _v1_component_status_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_component_status_list_t v1_component_status_list_t;

#include "v1_component_status.h"
#include "v1_list_meta.h"



typedef struct v1_component_status_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v1_component_status_list_t;

v1_component_status_list_t *v1_component_status_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_component_status_list_free(v1_component_status_list_t *v1_component_status_list);

v1_component_status_list_t *v1_component_status_list_parseFromJSON(cJSON *v1_component_status_listJSON);

cJSON *v1_component_status_list_convertToJSON(v1_component_status_list_t *v1_component_status_list);

#endif /* _v1_component_status_list_H_ */

