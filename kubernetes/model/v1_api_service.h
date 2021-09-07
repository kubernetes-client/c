/*
 * v1_api_service.h
 *
 * APIService represents a server for a particular GroupVersion. Name must be \&quot;version.group\&quot;.
 */

#ifndef _v1_api_service_H_
#define _v1_api_service_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_api_service_t v1_api_service_t;

#include "v1_api_service_spec.h"
#include "v1_api_service_status.h"
#include "v1_object_meta.h"



typedef struct v1_api_service_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_api_service_spec_t *spec; //model
    struct v1_api_service_status_t *status; //model

} v1_api_service_t;

v1_api_service_t *v1_api_service_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_api_service_spec_t *spec,
    v1_api_service_status_t *status
);

void v1_api_service_free(v1_api_service_t *v1_api_service);

v1_api_service_t *v1_api_service_parseFromJSON(cJSON *v1_api_serviceJSON);

cJSON *v1_api_service_convertToJSON(v1_api_service_t *v1_api_service);

#endif /* _v1_api_service_H_ */

