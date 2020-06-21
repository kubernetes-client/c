/*
 * networking_v1beta1_ingress_spec.h
 *
 * IngressSpec describes the Ingress the user wishes to exist.
 */

#ifndef _networking_v1beta1_ingress_spec_H_
#define _networking_v1beta1_ingress_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct networking_v1beta1_ingress_spec_t networking_v1beta1_ingress_spec_t;

#include "networking_v1beta1_ingress_backend.h"
#include "networking_v1beta1_ingress_rule.h"
#include "networking_v1beta1_ingress_tls.h"



typedef struct networking_v1beta1_ingress_spec_t {
    struct networking_v1beta1_ingress_backend_t *backend; //model
    list_t *rules; //nonprimitive container
    list_t *tls; //nonprimitive container

} networking_v1beta1_ingress_spec_t;

networking_v1beta1_ingress_spec_t *networking_v1beta1_ingress_spec_create(
    networking_v1beta1_ingress_backend_t *backend,
    list_t *rules,
    list_t *tls
);

void networking_v1beta1_ingress_spec_free(networking_v1beta1_ingress_spec_t *networking_v1beta1_ingress_spec);

networking_v1beta1_ingress_spec_t *networking_v1beta1_ingress_spec_parseFromJSON(cJSON *networking_v1beta1_ingress_specJSON);

cJSON *networking_v1beta1_ingress_spec_convertToJSON(networking_v1beta1_ingress_spec_t *networking_v1beta1_ingress_spec);

#endif /* _networking_v1beta1_ingress_spec_H_ */

