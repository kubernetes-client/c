/*
 * v1_non_resource_attributes.h
 *
 * NonResourceAttributes includes the authorization attributes available for non-resource requests to the Authorizer interface
 */

#ifndef _v1_non_resource_attributes_H_
#define _v1_non_resource_attributes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_non_resource_attributes_t v1_non_resource_attributes_t;




typedef struct v1_non_resource_attributes_t {
    char *path; // string
    char *verb; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_non_resource_attributes_t;

__attribute__((deprecated)) v1_non_resource_attributes_t *v1_non_resource_attributes_create(
    char *path,
    char *verb
);

void v1_non_resource_attributes_free(v1_non_resource_attributes_t *v1_non_resource_attributes);

v1_non_resource_attributes_t *v1_non_resource_attributes_parseFromJSON(cJSON *v1_non_resource_attributesJSON);

cJSON *v1_non_resource_attributes_convertToJSON(v1_non_resource_attributes_t *v1_non_resource_attributes);

#endif /* _v1_non_resource_attributes_H_ */

