/*
 * v1_resource_health.h
 *
 * ResourceHealth represents the health of a resource. It has the latest device health information. This is a part of KEP https://kep.k8s.io/4680 and historical health changes are planned to be added in future iterations of a KEP.
 */

#ifndef _v1_resource_health_H_
#define _v1_resource_health_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_health_t v1_resource_health_t;




typedef struct v1_resource_health_t {
    char *health; // string
    char *resource_id; // string

} v1_resource_health_t;

v1_resource_health_t *v1_resource_health_create(
    char *health,
    char *resource_id
);

void v1_resource_health_free(v1_resource_health_t *v1_resource_health);

v1_resource_health_t *v1_resource_health_parseFromJSON(cJSON *v1_resource_healthJSON);

cJSON *v1_resource_health_convertToJSON(v1_resource_health_t *v1_resource_health);

#endif /* _v1_resource_health_H_ */

