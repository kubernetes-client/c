/*
 * v1_namespace.h
 *
 * Namespace provides a scope for Names. Use of multiple namespaces is optional.
 */

#ifndef _v1_namespace_H_
#define _v1_namespace_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_namespace_t v1_namespace_t;

#include "v1_namespace_spec.h"
#include "v1_namespace_status.h"
#include "v1_object_meta.h"



typedef struct v1_namespace_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_namespace_spec_t *spec; //model
    struct v1_namespace_status_t *status; //model

} v1_namespace_t;

v1_namespace_t *v1_namespace_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_namespace_spec_t *spec,
    v1_namespace_status_t *status
);

void v1_namespace_free(v1_namespace_t *v1_namespace);

v1_namespace_t *v1_namespace_parseFromJSON(cJSON *v1_namespaceJSON);

cJSON *v1_namespace_convertToJSON(v1_namespace_t *v1_namespace);

#endif /* _v1_namespace_H_ */

