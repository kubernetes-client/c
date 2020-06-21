/*
 * v1_azure_disk_volume_source.h
 *
 * AzureDisk represents an Azure Data Disk mount on the host and bind mount to the pod.
 */

#ifndef _v1_azure_disk_volume_source_H_
#define _v1_azure_disk_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_azure_disk_volume_source_t v1_azure_disk_volume_source_t;




typedef struct v1_azure_disk_volume_source_t {
    char *caching_mode; // string
    char *disk_name; // string
    char *disk_uri; // string
    char *fs_type; // string
    char *kind; // string
    int read_only; //boolean

} v1_azure_disk_volume_source_t;

v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_create(
    char *caching_mode,
    char *disk_name,
    char *disk_uri,
    char *fs_type,
    char *kind,
    int read_only
);

void v1_azure_disk_volume_source_free(v1_azure_disk_volume_source_t *v1_azure_disk_volume_source);

v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_parseFromJSON(cJSON *v1_azure_disk_volume_sourceJSON);

cJSON *v1_azure_disk_volume_source_convertToJSON(v1_azure_disk_volume_source_t *v1_azure_disk_volume_source);

#endif /* _v1_azure_disk_volume_source_H_ */

