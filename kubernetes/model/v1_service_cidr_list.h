/*
 * v1_service_cidr_list.h
 *
 * ServiceCIDRList contains a list of ServiceCIDR objects.
 */

#ifndef _v1_service_cidr_list_H_
#define _v1_service_cidr_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_cidr_list_t v1_service_cidr_list_t;

#include "v1_list_meta.h"
#include "v1_service_cidr.h"



typedef struct v1_service_cidr_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_service_cidr_list_t;

__attribute__((deprecated)) v1_service_cidr_list_t *v1_service_cidr_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_service_cidr_list_free(v1_service_cidr_list_t *v1_service_cidr_list);

v1_service_cidr_list_t *v1_service_cidr_list_parseFromJSON(cJSON *v1_service_cidr_listJSON);

cJSON *v1_service_cidr_list_convertToJSON(v1_service_cidr_list_t *v1_service_cidr_list);

#endif /* _v1_service_cidr_list_H_ */

