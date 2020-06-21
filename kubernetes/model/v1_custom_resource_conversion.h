/*
 * v1_custom_resource_conversion.h
 *
 * CustomResourceConversion describes how to convert different versions of a CR.
 */

#ifndef _v1_custom_resource_conversion_H_
#define _v1_custom_resource_conversion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_custom_resource_conversion_t v1_custom_resource_conversion_t;

#include "v1_webhook_conversion.h"



typedef struct v1_custom_resource_conversion_t {
    char *strategy; // string
    struct v1_webhook_conversion_t *webhook; //model

} v1_custom_resource_conversion_t;

v1_custom_resource_conversion_t *v1_custom_resource_conversion_create(
    char *strategy,
    v1_webhook_conversion_t *webhook
);

void v1_custom_resource_conversion_free(v1_custom_resource_conversion_t *v1_custom_resource_conversion);

v1_custom_resource_conversion_t *v1_custom_resource_conversion_parseFromJSON(cJSON *v1_custom_resource_conversionJSON);

cJSON *v1_custom_resource_conversion_convertToJSON(v1_custom_resource_conversion_t *v1_custom_resource_conversion);

#endif /* _v1_custom_resource_conversion_H_ */

