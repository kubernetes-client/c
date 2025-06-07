/*
 * v1beta1_device_taint.h
 *
 * The device this taint is attached to has the \&quot;effect\&quot; on any claim which does not tolerate the taint and, through the claim, to pods using the claim.
 */

#ifndef _v1beta1_device_taint_H_
#define _v1beta1_device_taint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_device_taint_t v1beta1_device_taint_t;




typedef struct v1beta1_device_taint_t {
    char *effect; // string
    char *key; // string
    char *time_added; //date time
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_device_taint_t;

__attribute__((deprecated)) v1beta1_device_taint_t *v1beta1_device_taint_create(
    char *effect,
    char *key,
    char *time_added,
    char *value
);

void v1beta1_device_taint_free(v1beta1_device_taint_t *v1beta1_device_taint);

v1beta1_device_taint_t *v1beta1_device_taint_parseFromJSON(cJSON *v1beta1_device_taintJSON);

cJSON *v1beta1_device_taint_convertToJSON(v1beta1_device_taint_t *v1beta1_device_taint);

#endif /* _v1beta1_device_taint_H_ */

