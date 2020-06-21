/*
 * v1_role_ref.h
 *
 * RoleRef contains information that points to the role being used
 */

#ifndef _v1_role_ref_H_
#define _v1_role_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_role_ref_t v1_role_ref_t;




typedef struct v1_role_ref_t {
    char *api_group; // string
    char *kind; // string
    char *name; // string

} v1_role_ref_t;

v1_role_ref_t *v1_role_ref_create(
    char *api_group,
    char *kind,
    char *name
);

void v1_role_ref_free(v1_role_ref_t *v1_role_ref);

v1_role_ref_t *v1_role_ref_parseFromJSON(cJSON *v1_role_refJSON);

cJSON *v1_role_ref_convertToJSON(v1_role_ref_t *v1_role_ref);

#endif /* _v1_role_ref_H_ */

