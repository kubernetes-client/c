/*
 * extensions_v1beta1_ingress_backend.h
 *
 * IngressBackend describes all endpoints for a given service and port.
 */

#ifndef _extensions_v1beta1_ingress_backend_H_
#define _extensions_v1beta1_ingress_backend_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_ingress_backend_t extensions_v1beta1_ingress_backend_t;

#include "object.h"



typedef struct extensions_v1beta1_ingress_backend_t {
    char *service_name; // string
    object_t *service_port; //object

} extensions_v1beta1_ingress_backend_t;

extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_create(
    char *service_name,
    object_t *service_port
);

void extensions_v1beta1_ingress_backend_free(extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend);

extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_parseFromJSON(cJSON *extensions_v1beta1_ingress_backendJSON);

cJSON *extensions_v1beta1_ingress_backend_convertToJSON(extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend);

#endif /* _extensions_v1beta1_ingress_backend_H_ */

