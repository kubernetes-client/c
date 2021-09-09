/*
 * extensions_v1beta1_ingress.h
 *
 * Ingress is a collection of rules that allow inbound connections to reach the endpoints defined by a backend. An Ingress can be configured to give services externally-reachable urls, load balance traffic, terminate SSL, offer name based virtual hosting etc. DEPRECATED - This group version of Ingress is deprecated by networking.k8s.io/v1beta1 Ingress. See the release notes for more information.
 */

#ifndef _extensions_v1beta1_ingress_H_
#define _extensions_v1beta1_ingress_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_ingress_t extensions_v1beta1_ingress_t;

#include "extensions_v1beta1_ingress_spec.h"
#include "extensions_v1beta1_ingress_status.h"
#include "v1_object_meta.h"



typedef struct extensions_v1beta1_ingress_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct extensions_v1beta1_ingress_spec_t *spec; //model
    struct extensions_v1beta1_ingress_status_t *status; //model

} extensions_v1beta1_ingress_t;

extensions_v1beta1_ingress_t *extensions_v1beta1_ingress_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    extensions_v1beta1_ingress_spec_t *spec,
    extensions_v1beta1_ingress_status_t *status
);

void extensions_v1beta1_ingress_free(extensions_v1beta1_ingress_t *extensions_v1beta1_ingress);

extensions_v1beta1_ingress_t *extensions_v1beta1_ingress_parseFromJSON(cJSON *extensions_v1beta1_ingressJSON);

cJSON *extensions_v1beta1_ingress_convertToJSON(extensions_v1beta1_ingress_t *extensions_v1beta1_ingress);

#endif /* _extensions_v1beta1_ingress_H_ */

