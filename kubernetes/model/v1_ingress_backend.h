/*
 * v1_ingress_backend.h
 *
 * IngressBackend describes all endpoints for a given service and port.
 */

#ifndef _v1_ingress_backend_H_
#define _v1_ingress_backend_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_backend_t v1_ingress_backend_t;

#include "v1_ingress_service_backend.h"
#include "v1_typed_local_object_reference.h"



typedef struct v1_ingress_backend_t {
    struct v1_typed_local_object_reference_t *resource; //model
    struct v1_ingress_service_backend_t *service; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_ingress_backend_t;

__attribute__((deprecated)) v1_ingress_backend_t *v1_ingress_backend_create(
    v1_typed_local_object_reference_t *resource,
    v1_ingress_service_backend_t *service
);

void v1_ingress_backend_free(v1_ingress_backend_t *v1_ingress_backend);

v1_ingress_backend_t *v1_ingress_backend_parseFromJSON(cJSON *v1_ingress_backendJSON);

cJSON *v1_ingress_backend_convertToJSON(v1_ingress_backend_t *v1_ingress_backend);

#endif /* _v1_ingress_backend_H_ */

