/*
 * v1_fc_volume_source.h
 *
 * Represents a Fibre Channel volume. Fibre Channel volumes can only be mounted as read/write once. Fibre Channel volumes support ownership management and SELinux relabeling.
 */

#ifndef _v1_fc_volume_source_H_
#define _v1_fc_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_fc_volume_source_t v1_fc_volume_source_t;




typedef struct v1_fc_volume_source_t {
    char *fs_type; // string
    int lun; //numeric
    int read_only; //boolean
    list_t *target_wwns; //primitive container
    list_t *wwids; //primitive container

} v1_fc_volume_source_t;

v1_fc_volume_source_t *v1_fc_volume_source_create(
    char *fs_type,
    int lun,
    int read_only,
    list_t *target_wwns,
    list_t *wwids
);

void v1_fc_volume_source_free(v1_fc_volume_source_t *v1_fc_volume_source);

v1_fc_volume_source_t *v1_fc_volume_source_parseFromJSON(cJSON *v1_fc_volume_sourceJSON);

cJSON *v1_fc_volume_source_convertToJSON(v1_fc_volume_source_t *v1_fc_volume_source);

#endif /* _v1_fc_volume_source_H_ */

