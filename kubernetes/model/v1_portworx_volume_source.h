/*
 * v1_portworx_volume_source.h
 *
 * PortworxVolumeSource represents a Portworx volume resource.
 */

#ifndef _v1_portworx_volume_source_H_
#define _v1_portworx_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_portworx_volume_source_t v1_portworx_volume_source_t;




typedef struct v1_portworx_volume_source_t {
    char *fs_type; // string
    int read_only; //boolean
    char *volume_id; // string

} v1_portworx_volume_source_t;

v1_portworx_volume_source_t *v1_portworx_volume_source_create(
    char *fs_type,
    int read_only,
    char *volume_id
);

void v1_portworx_volume_source_free(v1_portworx_volume_source_t *v1_portworx_volume_source);

v1_portworx_volume_source_t *v1_portworx_volume_source_parseFromJSON(cJSON *v1_portworx_volume_sourceJSON);

cJSON *v1_portworx_volume_source_convertToJSON(v1_portworx_volume_source_t *v1_portworx_volume_source);

#endif /* _v1_portworx_volume_source_H_ */

