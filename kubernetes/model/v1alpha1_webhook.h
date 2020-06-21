/*
 * v1alpha1_webhook.h
 *
 * Webhook holds the configuration of the webhook
 */

#ifndef _v1alpha1_webhook_H_
#define _v1alpha1_webhook_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_webhook_t v1alpha1_webhook_t;

#include "v1alpha1_webhook_client_config.h"
#include "v1alpha1_webhook_throttle_config.h"



typedef struct v1alpha1_webhook_t {
    struct v1alpha1_webhook_client_config_t *client_config; //model
    struct v1alpha1_webhook_throttle_config_t *throttle; //model

} v1alpha1_webhook_t;

v1alpha1_webhook_t *v1alpha1_webhook_create(
    v1alpha1_webhook_client_config_t *client_config,
    v1alpha1_webhook_throttle_config_t *throttle
);

void v1alpha1_webhook_free(v1alpha1_webhook_t *v1alpha1_webhook);

v1alpha1_webhook_t *v1alpha1_webhook_parseFromJSON(cJSON *v1alpha1_webhookJSON);

cJSON *v1alpha1_webhook_convertToJSON(v1alpha1_webhook_t *v1alpha1_webhook);

#endif /* _v1alpha1_webhook_H_ */

