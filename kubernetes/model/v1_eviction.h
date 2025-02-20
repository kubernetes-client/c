/*
 * v1_eviction.h
 *
 * Eviction evicts a pod from its node subject to certain policies and safety constraints. This is a subresource of Pod.  A request to cause such an eviction is created by POSTing to .../pods/&lt;pod name&gt;/evictions.
 */

#ifndef _v1_eviction_H_
#define _v1_eviction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_eviction_t v1_eviction_t;

#include "v1_delete_options.h"
#include "v1_object_meta.h"



typedef struct v1_eviction_t {
    char *api_version; // string
    struct v1_delete_options_t *delete_options; //model
    char *kind; // string
    struct v1_object_meta_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_eviction_t;

__attribute__((deprecated)) v1_eviction_t *v1_eviction_create(
    char *api_version,
    v1_delete_options_t *delete_options,
    char *kind,
    v1_object_meta_t *metadata
);

void v1_eviction_free(v1_eviction_t *v1_eviction);

v1_eviction_t *v1_eviction_parseFromJSON(cJSON *v1_evictionJSON);

cJSON *v1_eviction_convertToJSON(v1_eviction_t *v1_eviction);

#endif /* _v1_eviction_H_ */

