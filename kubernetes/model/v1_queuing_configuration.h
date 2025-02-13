/*
 * v1_queuing_configuration.h
 *
 * QueuingConfiguration holds the configuration parameters for queuing
 */

#ifndef _v1_queuing_configuration_H_
#define _v1_queuing_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_queuing_configuration_t v1_queuing_configuration_t;




typedef struct v1_queuing_configuration_t {
    int hand_size; //numeric
    int queue_length_limit; //numeric
    int queues; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1_queuing_configuration_t;

__attribute__((deprecated)) v1_queuing_configuration_t *v1_queuing_configuration_create(
    int hand_size,
    int queue_length_limit,
    int queues
);

void v1_queuing_configuration_free(v1_queuing_configuration_t *v1_queuing_configuration);

v1_queuing_configuration_t *v1_queuing_configuration_parseFromJSON(cJSON *v1_queuing_configurationJSON);

cJSON *v1_queuing_configuration_convertToJSON(v1_queuing_configuration_t *v1_queuing_configuration);

#endif /* _v1_queuing_configuration_H_ */

