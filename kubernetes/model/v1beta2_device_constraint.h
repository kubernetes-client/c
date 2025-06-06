/*
 * v1beta2_device_constraint.h
 *
 * DeviceConstraint must have exactly one field set besides Requests.
 */

#ifndef _v1beta2_device_constraint_H_
#define _v1beta2_device_constraint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_device_constraint_t v1beta2_device_constraint_t;




typedef struct v1beta2_device_constraint_t {
    char *match_attribute; // string
    list_t *requests; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_device_constraint_t;

__attribute__((deprecated)) v1beta2_device_constraint_t *v1beta2_device_constraint_create(
    char *match_attribute,
    list_t *requests
);

void v1beta2_device_constraint_free(v1beta2_device_constraint_t *v1beta2_device_constraint);

v1beta2_device_constraint_t *v1beta2_device_constraint_parseFromJSON(cJSON *v1beta2_device_constraintJSON);

cJSON *v1beta2_device_constraint_convertToJSON(v1beta2_device_constraint_t *v1beta2_device_constraint);

#endif /* _v1beta2_device_constraint_H_ */

