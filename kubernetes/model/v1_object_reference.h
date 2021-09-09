/*
 * v1_object_reference.h
 *
 * ObjectReference contains enough information to let you inspect or modify the referred object.
 */

#ifndef _v1_object_reference_H_
#define _v1_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_object_reference_t v1_object_reference_t;




typedef struct v1_object_reference_t {
    char *api_version; // string
    char *field_path; // string
    char *kind; // string
    char *name; // string
    char *_namespace; // string
    char *resource_version; // string
    char *uid; // string

} v1_object_reference_t;

v1_object_reference_t *v1_object_reference_create(
    char *api_version,
    char *field_path,
    char *kind,
    char *name,
    char *_namespace,
    char *resource_version,
    char *uid
);

void v1_object_reference_free(v1_object_reference_t *v1_object_reference);

v1_object_reference_t *v1_object_reference_parseFromJSON(cJSON *v1_object_referenceJSON);

cJSON *v1_object_reference_convertToJSON(v1_object_reference_t *v1_object_reference);

#endif /* _v1_object_reference_H_ */

