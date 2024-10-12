/*
 * v1beta1_parent_reference.h
 *
 * ParentReference describes a reference to a parent object.
 */

#ifndef _v1beta1_parent_reference_H_
#define _v1beta1_parent_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_parent_reference_t v1beta1_parent_reference_t;




typedef struct v1beta1_parent_reference_t {
    char *group; // string
    char *name; // string
    char *_namespace; // string
    char *resource; // string

} v1beta1_parent_reference_t;

v1beta1_parent_reference_t *v1beta1_parent_reference_create(
    char *group,
    char *name,
    char *_namespace,
    char *resource
);

void v1beta1_parent_reference_free(v1beta1_parent_reference_t *v1beta1_parent_reference);

v1beta1_parent_reference_t *v1beta1_parent_reference_parseFromJSON(cJSON *v1beta1_parent_referenceJSON);

cJSON *v1beta1_parent_reference_convertToJSON(v1beta1_parent_reference_t *v1beta1_parent_reference);

#endif /* _v1beta1_parent_reference_H_ */

