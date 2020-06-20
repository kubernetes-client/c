/*
 * v1beta2_stateful_set_list.h
 *
 * StatefulSetList is a collection of StatefulSets.
 */

#ifndef _v1beta2_stateful_set_list_H_
#define _v1beta2_stateful_set_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_stateful_set_list_t v1beta2_stateful_set_list_t;

#include "v1_list_meta.h"
#include "v1beta2_stateful_set.h"



typedef struct v1beta2_stateful_set_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v1beta2_stateful_set_list_t;

v1beta2_stateful_set_list_t *v1beta2_stateful_set_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1beta2_stateful_set_list_free(v1beta2_stateful_set_list_t *v1beta2_stateful_set_list);

v1beta2_stateful_set_list_t *v1beta2_stateful_set_list_parseFromJSON(cJSON *v1beta2_stateful_set_listJSON);

cJSON *v1beta2_stateful_set_list_convertToJSON(v1beta2_stateful_set_list_t *v1beta2_stateful_set_list);

#endif /* _v1beta2_stateful_set_list_H_ */

