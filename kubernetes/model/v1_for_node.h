/*
 * v1_for_node.h
 *
 * ForNode provides information about which nodes should consume this endpoint.
 */

#ifndef _v1_for_node_H_
#define _v1_for_node_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_for_node_t v1_for_node_t;




typedef struct v1_for_node_t {
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_for_node_t;

__attribute__((deprecated)) v1_for_node_t *v1_for_node_create(
    char *name
);

void v1_for_node_free(v1_for_node_t *v1_for_node);

v1_for_node_t *v1_for_node_parseFromJSON(cJSON *v1_for_nodeJSON);

cJSON *v1_for_node_convertToJSON(v1_for_node_t *v1_for_node);

#endif /* _v1_for_node_H_ */

