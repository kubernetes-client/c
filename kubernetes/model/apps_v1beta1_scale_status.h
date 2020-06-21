/*
 * apps_v1beta1_scale_status.h
 *
 * ScaleStatus represents the current status of a scale subresource.
 */

#ifndef _apps_v1beta1_scale_status_H_
#define _apps_v1beta1_scale_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apps_v1beta1_scale_status_t apps_v1beta1_scale_status_t;




typedef struct apps_v1beta1_scale_status_t {
    int replicas; //numeric
    list_t* selector; //map
    char *target_selector; // string

} apps_v1beta1_scale_status_t;

apps_v1beta1_scale_status_t *apps_v1beta1_scale_status_create(
    int replicas,
    list_t* selector,
    char *target_selector
);

void apps_v1beta1_scale_status_free(apps_v1beta1_scale_status_t *apps_v1beta1_scale_status);

apps_v1beta1_scale_status_t *apps_v1beta1_scale_status_parseFromJSON(cJSON *apps_v1beta1_scale_statusJSON);

cJSON *apps_v1beta1_scale_status_convertToJSON(apps_v1beta1_scale_status_t *apps_v1beta1_scale_status);

#endif /* _apps_v1beta1_scale_status_H_ */

