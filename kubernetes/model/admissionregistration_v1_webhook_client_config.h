/*
 * admissionregistration_v1_webhook_client_config.h
 *
 * WebhookClientConfig contains the information to make a TLS connection with the webhook
 */

#ifndef _admissionregistration_v1_webhook_client_config_H_
#define _admissionregistration_v1_webhook_client_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct admissionregistration_v1_webhook_client_config_t admissionregistration_v1_webhook_client_config_t;

#include "admissionregistration_v1_service_reference.h"



typedef struct admissionregistration_v1_webhook_client_config_t {
    char *ca_bundle; //ByteArray
    struct admissionregistration_v1_service_reference_t *service; //model
    char *url; // string

} admissionregistration_v1_webhook_client_config_t;

admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_create(
    char *ca_bundle,
    admissionregistration_v1_service_reference_t *service,
    char *url
);

void admissionregistration_v1_webhook_client_config_free(admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config);

admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config_parseFromJSON(cJSON *admissionregistration_v1_webhook_client_configJSON);

cJSON *admissionregistration_v1_webhook_client_config_convertToJSON(admissionregistration_v1_webhook_client_config_t *admissionregistration_v1_webhook_client_config);

#endif /* _admissionregistration_v1_webhook_client_config_H_ */

