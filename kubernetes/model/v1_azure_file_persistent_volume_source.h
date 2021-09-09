/*
 * v1_azure_file_persistent_volume_source.h
 *
 * AzureFile represents an Azure File Service mount on the host and bind mount to the pod.
 */

#ifndef _v1_azure_file_persistent_volume_source_H_
#define _v1_azure_file_persistent_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_azure_file_persistent_volume_source_t v1_azure_file_persistent_volume_source_t;




typedef struct v1_azure_file_persistent_volume_source_t {
    int read_only; //boolean
    char *secret_name; // string
    char *secret_namespace; // string
    char *share_name; // string

} v1_azure_file_persistent_volume_source_t;

v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_create(
    int read_only,
    char *secret_name,
    char *secret_namespace,
    char *share_name
);

void v1_azure_file_persistent_volume_source_free(v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source);

v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source_parseFromJSON(cJSON *v1_azure_file_persistent_volume_sourceJSON);

cJSON *v1_azure_file_persistent_volume_source_convertToJSON(v1_azure_file_persistent_volume_source_t *v1_azure_file_persistent_volume_source);

#endif /* _v1_azure_file_persistent_volume_source_H_ */

