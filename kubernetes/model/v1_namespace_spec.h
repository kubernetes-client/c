/*
 * v1_namespace_spec.h
 *
 * NamespaceSpec describes the attributes on a Namespace.
 */

#ifndef _v1_namespace_spec_H_
#define _v1_namespace_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_namespace_spec_t v1_namespace_spec_t;




typedef struct v1_namespace_spec_t {
    list_t *finalizers; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_namespace_spec_t;

__attribute__((deprecated)) v1_namespace_spec_t *v1_namespace_spec_create(
    list_t *finalizers
);

void v1_namespace_spec_free(v1_namespace_spec_t *v1_namespace_spec);

v1_namespace_spec_t *v1_namespace_spec_parseFromJSON(cJSON *v1_namespace_specJSON);

cJSON *v1_namespace_spec_convertToJSON(v1_namespace_spec_t *v1_namespace_spec);

#endif /* _v1_namespace_spec_H_ */

