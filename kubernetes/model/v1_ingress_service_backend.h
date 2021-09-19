/*
 * v1_ingress_service_backend.h
 *
 * IngressServiceBackend references a Kubernetes Service as a Backend.
 */

#ifndef _v1_ingress_service_backend_H_
#define _v1_ingress_service_backend_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_service_backend_t v1_ingress_service_backend_t;

#include "v1_service_backend_port.h"



typedef struct v1_ingress_service_backend_t {
    char *name; // string
    struct v1_service_backend_port_t *port; //model

} v1_ingress_service_backend_t;

v1_ingress_service_backend_t *v1_ingress_service_backend_create(
    char *name,
    v1_service_backend_port_t *port
);

void v1_ingress_service_backend_free(v1_ingress_service_backend_t *v1_ingress_service_backend);

v1_ingress_service_backend_t *v1_ingress_service_backend_parseFromJSON(cJSON *v1_ingress_service_backendJSON);

cJSON *v1_ingress_service_backend_convertToJSON(v1_ingress_service_backend_t *v1_ingress_service_backend);

#endif /* _v1_ingress_service_backend_H_ */

