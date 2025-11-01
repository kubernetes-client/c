/*
 * v1_device_counter_consumption.h
 *
 * DeviceCounterConsumption defines a set of counters that a device will consume from a CounterSet.
 */

#ifndef _v1_device_counter_consumption_H_
#define _v1_device_counter_consumption_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_device_counter_consumption_t v1_device_counter_consumption_t;

#include "v1_counter.h"



typedef struct v1_device_counter_consumption_t {
    char *counter_set; // string
    list_t* counters; //map

    int _library_owned; // Is the library responsible for freeing this object?
} v1_device_counter_consumption_t;

__attribute__((deprecated)) v1_device_counter_consumption_t *v1_device_counter_consumption_create(
    char *counter_set,
    list_t* counters
);

void v1_device_counter_consumption_free(v1_device_counter_consumption_t *v1_device_counter_consumption);

v1_device_counter_consumption_t *v1_device_counter_consumption_parseFromJSON(cJSON *v1_device_counter_consumptionJSON);

cJSON *v1_device_counter_consumption_convertToJSON(v1_device_counter_consumption_t *v1_device_counter_consumption);

#endif /* _v1_device_counter_consumption_H_ */

