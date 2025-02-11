/*
 * v1_service_backend_port.h
 *
 * ServiceBackendPort is the service port being referenced.
 */

#ifndef _v1_service_backend_port_H_
#define _v1_service_backend_port_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_backend_port_t v1_service_backend_port_t;




typedef struct v1_service_backend_port_t {
    char *name; // string
    int number; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v1_service_backend_port_t;

__attribute__((deprecated)) v1_service_backend_port_t *v1_service_backend_port_create(
    char *name,
    int number
);

void v1_service_backend_port_free(v1_service_backend_port_t *v1_service_backend_port);

v1_service_backend_port_t *v1_service_backend_port_parseFromJSON(cJSON *v1_service_backend_portJSON);

cJSON *v1_service_backend_port_convertToJSON(v1_service_backend_port_t *v1_service_backend_port);

#endif /* _v1_service_backend_port_H_ */

