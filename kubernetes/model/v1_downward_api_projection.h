/*
 * v1_downward_api_projection.h
 *
 * Represents downward API info for projecting into a projected volume. Note that this is identical to a downwardAPI volume source without the default mode.
 */

#ifndef _v1_downward_api_projection_H_
#define _v1_downward_api_projection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_downward_api_volume_file.h"



typedef struct v1_downward_api_projection_t {
    list_t *items; //nonprimitive container

} v1_downward_api_projection_t;

v1_downward_api_projection_t *v1_downward_api_projection_create(
    list_t *items
);

void v1_downward_api_projection_free(v1_downward_api_projection_t *v1_downward_api_projection);

v1_downward_api_projection_t *v1_downward_api_projection_parseFromJSON(cJSON *v1_downward_api_projectionJSON);

cJSON *v1_downward_api_projection_convertToJSON(v1_downward_api_projection_t *v1_downward_api_projection);

#endif /* _v1_downward_api_projection_H_ */

