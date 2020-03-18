/*
 * v1beta1_volume_error.h
 *
 * VolumeError captures an error encountered during a volume operation.
 */

#ifndef _v1beta1_volume_error_H_
#define _v1beta1_volume_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_volume_error_t {
    char *message; // string
    char *time; //date time

} v1beta1_volume_error_t;

v1beta1_volume_error_t *v1beta1_volume_error_create(
    char *message,
    char *time
);

void v1beta1_volume_error_free(v1beta1_volume_error_t *v1beta1_volume_error);

v1beta1_volume_error_t *v1beta1_volume_error_parseFromJSON(cJSON *v1beta1_volume_errorJSON);

cJSON *v1beta1_volume_error_convertToJSON(v1beta1_volume_error_t *v1beta1_volume_error);

#endif /* _v1beta1_volume_error_H_ */

