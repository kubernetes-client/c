/*
 * v1_node_swap_status.h
 *
 * NodeSwapStatus represents swap memory information.
 */

#ifndef _v1_node_swap_status_H_
#define _v1_node_swap_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_swap_status_t v1_node_swap_status_t;




typedef struct v1_node_swap_status_t {
    long capacity; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1_node_swap_status_t;

__attribute__((deprecated)) v1_node_swap_status_t *v1_node_swap_status_create(
    long capacity
);

void v1_node_swap_status_free(v1_node_swap_status_t *v1_node_swap_status);

v1_node_swap_status_t *v1_node_swap_status_parseFromJSON(cJSON *v1_node_swap_statusJSON);

cJSON *v1_node_swap_status_convertToJSON(v1_node_swap_status_t *v1_node_swap_status);

#endif /* _v1_node_swap_status_H_ */

