/*
 * v1beta1_non_resource_attributes.h
 *
 * NonResourceAttributes includes the authorization attributes available for non-resource requests to the Authorizer interface
 */

#ifndef _v1beta1_non_resource_attributes_H_
#define _v1beta1_non_resource_attributes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_non_resource_attributes_t {
    char *path; // string
    char *verb; // string

} v1beta1_non_resource_attributes_t;

v1beta1_non_resource_attributes_t *v1beta1_non_resource_attributes_create(
    char *path,
    char *verb
);

void v1beta1_non_resource_attributes_free(v1beta1_non_resource_attributes_t *v1beta1_non_resource_attributes);

v1beta1_non_resource_attributes_t *v1beta1_non_resource_attributes_parseFromJSON(cJSON *v1beta1_non_resource_attributesJSON);

cJSON *v1beta1_non_resource_attributes_convertToJSON(v1beta1_non_resource_attributes_t *v1beta1_non_resource_attributes);

#endif /* _v1beta1_non_resource_attributes_H_ */

