/*
 * v1_modify_volume_status.h
 *
 * ModifyVolumeStatus represents the status object of ControllerModifyVolume operation
 */

#ifndef _v1_modify_volume_status_H_
#define _v1_modify_volume_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_modify_volume_status_t v1_modify_volume_status_t;




typedef struct v1_modify_volume_status_t {
    char *status; // string
    char *target_volume_attributes_class_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_modify_volume_status_t;

__attribute__((deprecated)) v1_modify_volume_status_t *v1_modify_volume_status_create(
    char *status,
    char *target_volume_attributes_class_name
);

void v1_modify_volume_status_free(v1_modify_volume_status_t *v1_modify_volume_status);

v1_modify_volume_status_t *v1_modify_volume_status_parseFromJSON(cJSON *v1_modify_volume_statusJSON);

cJSON *v1_modify_volume_status_convertToJSON(v1_modify_volume_status_t *v1_modify_volume_status);

#endif /* _v1_modify_volume_status_H_ */

