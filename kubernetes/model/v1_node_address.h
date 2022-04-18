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


// Enum TYPE for v1_node_address

typedef enum  { kubernetes_v1_node_address_TYPE_NULL = 0, kubernetes_v1_node_address_TYPE_ExternalDNS, kubernetes_v1_node_address_TYPE_ExternalIP, kubernetes_v1_node_address_TYPE_Hostname, kubernetes_v1_node_address_TYPE_InternalDNS, kubernetes_v1_node_address_TYPE_InternalIP } kubernetes_v1_node_address_TYPE_e;

char* v1_node_address_type_ToString(kubernetes_v1_node_address_TYPE_e type);

kubernetes_v1_node_address_TYPE_e v1_node_address_type_FromString(char* type);



typedef struct v1_node_address_t {
    char *address; // string
    kubernetes_v1_node_address_TYPE_e type; //enum

} v1_node_address_t;

v1_node_address_t *v1_node_address_create(
    char *address,
    kubernetes_v1_node_address_TYPE_e type
);

void v1_node_address_free(v1_node_address_t *v1_node_address);

v1_node_address_t *v1_node_address_parseFromJSON(cJSON *v1_node_addressJSON);

cJSON *v1_node_address_convertToJSON(v1_node_address_t *v1_node_address);

#endif /* _v1_node_address_H_ */

