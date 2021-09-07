/*
 * v1_service.h
 *
 * Service is a named abstraction of software service (for example, mysql) consisting of local port (for example 3306) that the proxy listens on, and the selector that determines which pods will answer requests sent through the proxy.
 */

#ifndef _v1_service_H_
#define _v1_service_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_t v1_service_t;

#include "v1_object_meta.h"
#include "v1_service_spec.h"
#include "v1_service_status.h"



typedef struct v1_service_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_service_spec_t *spec; //model
    struct v1_service_status_t *status; //model

} v1_service_t;

v1_service_t *v1_service_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_service_spec_t *spec,
    v1_service_status_t *status
);

void v1_service_free(v1_service_t *v1_service);

v1_service_t *v1_service_parseFromJSON(cJSON *v1_serviceJSON);

cJSON *v1_service_convertToJSON(v1_service_t *v1_service);

#endif /* _v1_service_H_ */

