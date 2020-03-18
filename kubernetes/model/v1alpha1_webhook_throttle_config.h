/*
 * v1alpha1_webhook_throttle_config.h
 *
 * WebhookThrottleConfig holds the configuration for throttling events
 */

#ifndef _v1alpha1_webhook_throttle_config_H_
#define _v1alpha1_webhook_throttle_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1alpha1_webhook_throttle_config_t {
    long burst; //numeric
    long qps; //numeric

} v1alpha1_webhook_throttle_config_t;

v1alpha1_webhook_throttle_config_t *v1alpha1_webhook_throttle_config_create(
    long burst,
    long qps
);

void v1alpha1_webhook_throttle_config_free(v1alpha1_webhook_throttle_config_t *v1alpha1_webhook_throttle_config);

v1alpha1_webhook_throttle_config_t *v1alpha1_webhook_throttle_config_parseFromJSON(cJSON *v1alpha1_webhook_throttle_configJSON);

cJSON *v1alpha1_webhook_throttle_config_convertToJSON(v1alpha1_webhook_throttle_config_t *v1alpha1_webhook_throttle_config);

#endif /* _v1alpha1_webhook_throttle_config_H_ */

