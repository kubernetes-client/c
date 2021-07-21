/*
 * apiextensions_v1beta1_webhook_client_config.h
 *
 * WebhookClientConfig contains the information to make a TLS connection with the webhook.
 */

#ifndef _apiextensions_v1beta1_webhook_client_config_H_
#define _apiextensions_v1beta1_webhook_client_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct apiextensions_v1beta1_webhook_client_config_t apiextensions_v1beta1_webhook_client_config_t;

#include "apiextensions_v1beta1_service_reference.h"



typedef struct apiextensions_v1beta1_webhook_client_config_t {
    char *ca_bundle; //ByteArray
    struct apiextensions_v1beta1_service_reference_t *service; //model
    char *url; // string

} apiextensions_v1beta1_webhook_client_config_t;

apiextensions_v1beta1_webhook_client_config_t *apiextensions_v1beta1_webhook_client_config_create(
    char *ca_bundle,
    apiextensions_v1beta1_service_reference_t *service,
    char *url
);

void apiextensions_v1beta1_webhook_client_config_free(apiextensions_v1beta1_webhook_client_config_t *apiextensions_v1beta1_webhook_client_config);

apiextensions_v1beta1_webhook_client_config_t *apiextensions_v1beta1_webhook_client_config_parseFromJSON(cJSON *apiextensions_v1beta1_webhook_client_configJSON);

cJSON *apiextensions_v1beta1_webhook_client_config_convertToJSON(apiextensions_v1beta1_webhook_client_config_t *apiextensions_v1beta1_webhook_client_config);

#endif /* _apiextensions_v1beta1_webhook_client_config_H_ */

