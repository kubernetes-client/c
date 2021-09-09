/*
 * v1_quobyte_volume_source.h
 *
 * Represents a Quobyte mount that lasts the lifetime of a pod. Quobyte volumes do not support ownership management or SELinux relabeling.
 */

#ifndef _v1_quobyte_volume_source_H_
#define _v1_quobyte_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_quobyte_volume_source_t v1_quobyte_volume_source_t;




typedef struct v1_quobyte_volume_source_t {
    char *group; // string
    int read_only; //boolean
    char *registry; // string
    char *tenant; // string
    char *user; // string
    char *volume; // string

} v1_quobyte_volume_source_t;

v1_quobyte_volume_source_t *v1_quobyte_volume_source_create(
    char *group,
    int read_only,
    char *registry,
    char *tenant,
    char *user,
    char *volume
);

void v1_quobyte_volume_source_free(v1_quobyte_volume_source_t *v1_quobyte_volume_source);

v1_quobyte_volume_source_t *v1_quobyte_volume_source_parseFromJSON(cJSON *v1_quobyte_volume_sourceJSON);

cJSON *v1_quobyte_volume_source_convertToJSON(v1_quobyte_volume_source_t *v1_quobyte_volume_source);

#endif /* _v1_quobyte_volume_source_H_ */

