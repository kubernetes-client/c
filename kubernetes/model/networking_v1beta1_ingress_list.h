/*
 * networking_v1beta1_ingress_list.h
 *
 * IngressList is a collection of Ingress.
 */

#ifndef _networking_v1beta1_ingress_list_H_
#define _networking_v1beta1_ingress_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct networking_v1beta1_ingress_list_t networking_v1beta1_ingress_list_t;

#include "networking_v1beta1_ingress.h"
#include "v1_list_meta.h"



typedef struct networking_v1beta1_ingress_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} networking_v1beta1_ingress_list_t;

networking_v1beta1_ingress_list_t *networking_v1beta1_ingress_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void networking_v1beta1_ingress_list_free(networking_v1beta1_ingress_list_t *networking_v1beta1_ingress_list);

networking_v1beta1_ingress_list_t *networking_v1beta1_ingress_list_parseFromJSON(cJSON *networking_v1beta1_ingress_listJSON);

cJSON *networking_v1beta1_ingress_list_convertToJSON(networking_v1beta1_ingress_list_t *networking_v1beta1_ingress_list);

#endif /* _networking_v1beta1_ingress_list_H_ */

