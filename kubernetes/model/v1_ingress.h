/*
 * v1_ingress.h
 *
 * Ingress is a collection of rules that allow inbound connections to reach the endpoints defined by a backend. An Ingress can be configured to give services externally-reachable urls, load balance traffic, terminate SSL, offer name based virtual hosting etc.
 */

#ifndef _v1_ingress_H_
#define _v1_ingress_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_t v1_ingress_t;

#include "v1_ingress_spec.h"
#include "v1_ingress_status.h"
#include "v1_object_meta.h"



typedef struct v1_ingress_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_ingress_spec_t *spec; //model
    struct v1_ingress_status_t *status; //model

} v1_ingress_t;

v1_ingress_t *v1_ingress_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_ingress_spec_t *spec,
    v1_ingress_status_t *status
);

void v1_ingress_free(v1_ingress_t *v1_ingress);

v1_ingress_t *v1_ingress_parseFromJSON(cJSON *v1_ingressJSON);

cJSON *v1_ingress_convertToJSON(v1_ingress_t *v1_ingress);

#endif /* _v1_ingress_H_ */

