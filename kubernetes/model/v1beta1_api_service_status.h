/*
 * v1beta1_api_service_status.h
 *
 * APIServiceStatus contains derived information about an API server
 */

#ifndef _v1beta1_api_service_status_H_
#define _v1beta1_api_service_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta1_api_service_condition.h"



typedef struct v1beta1_api_service_status_t {
    list_t *conditions; //nonprimitive container

} v1beta1_api_service_status_t;

v1beta1_api_service_status_t *v1beta1_api_service_status_create(
    list_t *conditions
);

void v1beta1_api_service_status_free(v1beta1_api_service_status_t *v1beta1_api_service_status);

v1beta1_api_service_status_t *v1beta1_api_service_status_parseFromJSON(cJSON *v1beta1_api_service_statusJSON);

cJSON *v1beta1_api_service_status_convertToJSON(v1beta1_api_service_status_t *v1beta1_api_service_status);

#endif /* _v1beta1_api_service_status_H_ */

