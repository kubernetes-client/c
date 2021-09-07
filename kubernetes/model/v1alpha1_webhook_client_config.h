/*
 * v1alpha1_webhook_client_config.h
 *
 * WebhookClientConfig contains the information to make a connection with the webhook
 */

#ifndef _v1alpha1_webhook_client_config_H_
#define _v1alpha1_webhook_client_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_webhook_client_config_t v1alpha1_webhook_client_config_t;

#include "v1alpha1_service_reference.h"



typedef struct v1alpha1_webhook_client_config_t {
    char *ca_bundle; //ByteArray
    struct v1alpha1_service_reference_t *service; //model
    char *url; // string

} v1alpha1_webhook_client_config_t;

v1alpha1_webhook_client_config_t *v1alpha1_webhook_client_config_create(
    char *ca_bundle,
    v1alpha1_service_reference_t *service,
    char *url
);

void v1alpha1_webhook_client_config_free(v1alpha1_webhook_client_config_t *v1alpha1_webhook_client_config);

v1alpha1_webhook_client_config_t *v1alpha1_webhook_client_config_parseFromJSON(cJSON *v1alpha1_webhook_client_configJSON);

cJSON *v1alpha1_webhook_client_config_convertToJSON(v1alpha1_webhook_client_config_t *v1alpha1_webhook_client_config);

#endif /* _v1alpha1_webhook_client_config_H_ */

