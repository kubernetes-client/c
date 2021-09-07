/*
 * networking_v1beta1_ingress.h
 *
 * Ingress is a collection of rules that allow inbound connections to reach the endpoints defined by a backend. An Ingress can be configured to give services externally-reachable urls, load balance traffic, terminate SSL, offer name based virtual hosting etc.
 */

#ifndef _networking_v1beta1_ingress_H_
#define _networking_v1beta1_ingress_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct networking_v1beta1_ingress_t networking_v1beta1_ingress_t;

#include "networking_v1beta1_ingress_spec.h"
#include "networking_v1beta1_ingress_status.h"
#include "v1_object_meta.h"



typedef struct networking_v1beta1_ingress_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct networking_v1beta1_ingress_spec_t *spec; //model
    struct networking_v1beta1_ingress_status_t *status; //model

} networking_v1beta1_ingress_t;

networking_v1beta1_ingress_t *networking_v1beta1_ingress_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    networking_v1beta1_ingress_spec_t *spec,
    networking_v1beta1_ingress_status_t *status
);

void networking_v1beta1_ingress_free(networking_v1beta1_ingress_t *networking_v1beta1_ingress);

networking_v1beta1_ingress_t *networking_v1beta1_ingress_parseFromJSON(cJSON *networking_v1beta1_ingressJSON);

cJSON *networking_v1beta1_ingress_convertToJSON(networking_v1beta1_ingress_t *networking_v1beta1_ingress);

#endif /* _networking_v1beta1_ingress_H_ */

