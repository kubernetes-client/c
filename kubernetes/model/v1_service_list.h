/*
 * v1_service_list.h
 *
 * ServiceList holds a list of services.
 */

#ifndef _v1_service_list_H_
#define _v1_service_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_list_t v1_service_list_t;

#include "v1_list_meta.h"
#include "v1_service.h"



typedef struct v1_service_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v1_service_list_t;

v1_service_list_t *v1_service_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_service_list_free(v1_service_list_t *v1_service_list);

v1_service_list_t *v1_service_list_parseFromJSON(cJSON *v1_service_listJSON);

cJSON *v1_service_list_convertToJSON(v1_service_list_t *v1_service_list);

#endif /* _v1_service_list_H_ */

