/*
 * v1_validating_webhook_configuration.h
 *
 * ValidatingWebhookConfiguration describes the configuration of and admission webhook that accept or reject and object without changing it.
 */

#ifndef _v1_validating_webhook_configuration_H_
#define _v1_validating_webhook_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_validating_webhook_configuration_t v1_validating_webhook_configuration_t;

#include "v1_object_meta.h"
#include "v1_validating_webhook.h"



typedef struct v1_validating_webhook_configuration_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t *webhooks; //nonprimitive container

} v1_validating_webhook_configuration_t;

v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *webhooks
);

void v1_validating_webhook_configuration_free(v1_validating_webhook_configuration_t *v1_validating_webhook_configuration);

v1_validating_webhook_configuration_t *v1_validating_webhook_configuration_parseFromJSON(cJSON *v1_validating_webhook_configurationJSON);

cJSON *v1_validating_webhook_configuration_convertToJSON(v1_validating_webhook_configuration_t *v1_validating_webhook_configuration);

#endif /* _v1_validating_webhook_configuration_H_ */

