/*
 * v1_service_account.h
 *
 * ServiceAccount binds together: * a name, understood by users, and perhaps by peripheral systems, for an identity * a principal that can be authenticated and authorized * a set of secrets
 */

#ifndef _v1_service_account_H_
#define _v1_service_account_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_account_t v1_service_account_t;

#include "v1_local_object_reference.h"
#include "v1_object_meta.h"
#include "v1_object_reference.h"



typedef struct v1_service_account_t {
    char *api_version; // string
    int automount_service_account_token; //boolean
    list_t *image_pull_secrets; //nonprimitive container
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t *secrets; //nonprimitive container

} v1_service_account_t;

v1_service_account_t *v1_service_account_create(
    char *api_version,
    int automount_service_account_token,
    list_t *image_pull_secrets,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *secrets
);

void v1_service_account_free(v1_service_account_t *v1_service_account);

v1_service_account_t *v1_service_account_parseFromJSON(cJSON *v1_service_accountJSON);

cJSON *v1_service_account_convertToJSON(v1_service_account_t *v1_service_account);

#endif /* _v1_service_account_H_ */

