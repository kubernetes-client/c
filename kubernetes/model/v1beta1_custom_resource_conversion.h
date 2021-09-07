/*
 * v1beta1_custom_resource_conversion.h
 *
 * CustomResourceConversion describes how to convert different versions of a CR.
 */

#ifndef _v1beta1_custom_resource_conversion_H_
#define _v1beta1_custom_resource_conversion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_custom_resource_conversion_t v1beta1_custom_resource_conversion_t;

#include "apiextensions_v1beta1_webhook_client_config.h"



typedef struct v1beta1_custom_resource_conversion_t {
    list_t *conversion_review_versions; //primitive container
    char *strategy; // string
    struct apiextensions_v1beta1_webhook_client_config_t *webhook_client_config; //model

} v1beta1_custom_resource_conversion_t;

v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion_create(
    list_t *conversion_review_versions,
    char *strategy,
    apiextensions_v1beta1_webhook_client_config_t *webhook_client_config
);

void v1beta1_custom_resource_conversion_free(v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion);

v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion_parseFromJSON(cJSON *v1beta1_custom_resource_conversionJSON);

cJSON *v1beta1_custom_resource_conversion_convertToJSON(v1beta1_custom_resource_conversion_t *v1beta1_custom_resource_conversion);

#endif /* _v1beta1_custom_resource_conversion_H_ */

