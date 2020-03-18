/*
 * v1beta1_resource_attributes.h
 *
 * ResourceAttributes includes the authorization attributes available for resource requests to the Authorizer interface
 */

#ifndef _v1beta1_resource_attributes_H_
#define _v1beta1_resource_attributes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_resource_attributes_t {
    char *group; // string
    char *name; // string
    char *namespace; // string
    char *resource; // string
    char *subresource; // string
    char *verb; // string
    char *version; // string

} v1beta1_resource_attributes_t;

v1beta1_resource_attributes_t *v1beta1_resource_attributes_create(
    char *group,
    char *name,
    char *namespace,
    char *resource,
    char *subresource,
    char *verb,
    char *version
);

void v1beta1_resource_attributes_free(v1beta1_resource_attributes_t *v1beta1_resource_attributes);

v1beta1_resource_attributes_t *v1beta1_resource_attributes_parseFromJSON(cJSON *v1beta1_resource_attributesJSON);

cJSON *v1beta1_resource_attributes_convertToJSON(v1beta1_resource_attributes_t *v1beta1_resource_attributes);

#endif /* _v1beta1_resource_attributes_H_ */

