/*
 * v1beta2_queuing_configuration.h
 *
 * QueuingConfiguration holds the configuration parameters for queuing
 */

#ifndef _v1beta2_queuing_configuration_H_
#define _v1beta2_queuing_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_queuing_configuration_t v1beta2_queuing_configuration_t;




typedef struct v1beta2_queuing_configuration_t {
    int hand_size; //numeric
    int queue_length_limit; //numeric
    int queues; //numeric

} v1beta2_queuing_configuration_t;

v1beta2_queuing_configuration_t *v1beta2_queuing_configuration_create(
    int hand_size,
    int queue_length_limit,
    int queues
);

void v1beta2_queuing_configuration_free(v1beta2_queuing_configuration_t *v1beta2_queuing_configuration);

v1beta2_queuing_configuration_t *v1beta2_queuing_configuration_parseFromJSON(cJSON *v1beta2_queuing_configurationJSON);

cJSON *v1beta2_queuing_configuration_convertToJSON(v1beta2_queuing_configuration_t *v1beta2_queuing_configuration);

#endif /* _v1beta2_queuing_configuration_H_ */

