/*
 * v1_node_address.h
 *
 * NodeAddress contains information for the node&#39;s address.
 */

#ifndef _v1_node_address_H_
#define _v1_node_address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_address_t v1_node_address_t;




typedef struct v1_node_address_t {
    char *address; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_node_address_t;

__attribute__((deprecated)) v1_node_address_t *v1_node_address_create(
    char *address,
    char *type
);

void v1_node_address_free(v1_node_address_t *v1_node_address);

v1_node_address_t *v1_node_address_parseFromJSON(cJSON *v1_node_addressJSON);

cJSON *v1_node_address_convertToJSON(v1_node_address_t *v1_node_address);

#endif /* _v1_node_address_H_ */

