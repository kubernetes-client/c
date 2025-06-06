/*
 * v1alpha3_counter_set.h
 *
 * CounterSet defines a named set of counters that are available to be used by devices defined in the ResourceSlice.  The counters are not allocatable by themselves, but can be referenced by devices. When a device is allocated, the portion of counters it uses will no longer be available for use by other devices.
 */

#ifndef _v1alpha3_counter_set_H_
#define _v1alpha3_counter_set_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_counter_set_t v1alpha3_counter_set_t;

#include "v1alpha3_counter.h"



typedef struct v1alpha3_counter_set_t {
    list_t* counters; //map
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_counter_set_t;

__attribute__((deprecated)) v1alpha3_counter_set_t *v1alpha3_counter_set_create(
    list_t* counters,
    char *name
);

void v1alpha3_counter_set_free(v1alpha3_counter_set_t *v1alpha3_counter_set);

v1alpha3_counter_set_t *v1alpha3_counter_set_parseFromJSON(cJSON *v1alpha3_counter_setJSON);

cJSON *v1alpha3_counter_set_convertToJSON(v1alpha3_counter_set_t *v1alpha3_counter_set);

#endif /* _v1alpha3_counter_set_H_ */

