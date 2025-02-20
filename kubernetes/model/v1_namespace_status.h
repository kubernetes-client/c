/*
 * v1_namespace_status.h
 *
 * NamespaceStatus is information about the current status of a Namespace.
 */

#ifndef _v1_namespace_status_H_
#define _v1_namespace_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_namespace_status_t v1_namespace_status_t;

#include "v1_namespace_condition.h"



typedef struct v1_namespace_status_t {
    list_t *conditions; //nonprimitive container
    char *phase; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_namespace_status_t;

__attribute__((deprecated)) v1_namespace_status_t *v1_namespace_status_create(
    list_t *conditions,
    char *phase
);

void v1_namespace_status_free(v1_namespace_status_t *v1_namespace_status);

v1_namespace_status_t *v1_namespace_status_parseFromJSON(cJSON *v1_namespace_statusJSON);

cJSON *v1_namespace_status_convertToJSON(v1_namespace_status_t *v1_namespace_status);

#endif /* _v1_namespace_status_H_ */

