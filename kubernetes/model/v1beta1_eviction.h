/*
 * v1beta1_eviction.h
 *
 * Eviction evicts a pod from its node subject to certain policies and safety constraints. This is a subresource of Pod.  A request to cause such an eviction is created by POSTing to .../pods/&lt;pod name&gt;/evictions.
 */

#ifndef _v1beta1_eviction_H_
#define _v1beta1_eviction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_eviction_t v1beta1_eviction_t;

#include "v1_delete_options.h"
#include "v1_object_meta.h"



typedef struct v1beta1_eviction_t {
    char *api_version; // string
    struct v1_delete_options_t *delete_options; //model
    char *kind; // string
    struct v1_object_meta_t *metadata; //model

} v1beta1_eviction_t;

v1beta1_eviction_t *v1beta1_eviction_create(
    char *api_version,
    v1_delete_options_t *delete_options,
    char *kind,
    v1_object_meta_t *metadata
);

void v1beta1_eviction_free(v1beta1_eviction_t *v1beta1_eviction);

v1beta1_eviction_t *v1beta1_eviction_parseFromJSON(cJSON *v1beta1_evictionJSON);

cJSON *v1beta1_eviction_convertToJSON(v1beta1_eviction_t *v1beta1_eviction);

#endif /* _v1beta1_eviction_H_ */

