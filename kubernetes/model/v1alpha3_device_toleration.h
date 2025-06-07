/*
 * v1alpha3_device_toleration.h
 *
 * The ResourceClaim this DeviceToleration is attached to tolerates any taint that matches the triple &lt;key,value,effect&gt; using the matching operator &lt;operator&gt;.
 */

#ifndef _v1alpha3_device_toleration_H_
#define _v1alpha3_device_toleration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_toleration_t v1alpha3_device_toleration_t;




typedef struct v1alpha3_device_toleration_t {
    char *effect; // string
    char *key; // string
    char *_operator; // string
    long toleration_seconds; //numeric
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_device_toleration_t;

__attribute__((deprecated)) v1alpha3_device_toleration_t *v1alpha3_device_toleration_create(
    char *effect,
    char *key,
    char *_operator,
    long toleration_seconds,
    char *value
);

void v1alpha3_device_toleration_free(v1alpha3_device_toleration_t *v1alpha3_device_toleration);

v1alpha3_device_toleration_t *v1alpha3_device_toleration_parseFromJSON(cJSON *v1alpha3_device_tolerationJSON);

cJSON *v1alpha3_device_toleration_convertToJSON(v1alpha3_device_toleration_t *v1alpha3_device_toleration);

#endif /* _v1alpha3_device_toleration_H_ */

