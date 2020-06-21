/*
 * v1_owner_reference.h
 *
 * OwnerReference contains enough information to let you identify an owning object. An owning object must be in the same namespace as the dependent, or be cluster-scoped, so there is no namespace field.
 */

#ifndef _v1_owner_reference_H_
#define _v1_owner_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_owner_reference_t v1_owner_reference_t;




typedef struct v1_owner_reference_t {
    char *api_version; // string
    int block_owner_deletion; //boolean
    int controller; //boolean
    char *kind; // string
    char *name; // string
    char *uid; // string

} v1_owner_reference_t;

v1_owner_reference_t *v1_owner_reference_create(
    char *api_version,
    int block_owner_deletion,
    int controller,
    char *kind,
    char *name,
    char *uid
);

void v1_owner_reference_free(v1_owner_reference_t *v1_owner_reference);

v1_owner_reference_t *v1_owner_reference_parseFromJSON(cJSON *v1_owner_referenceJSON);

cJSON *v1_owner_reference_convertToJSON(v1_owner_reference_t *v1_owner_reference);

#endif /* _v1_owner_reference_H_ */

