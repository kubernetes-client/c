/*
 * v1_secret_volume_source.h
 *
 * Adapts a Secret into a volume.  The contents of the target Secret&#39;s Data field will be presented in a volume as files using the keys in the Data field as the file names. Secret volumes support ownership management and SELinux relabeling.
 */

#ifndef _v1_secret_volume_source_H_
#define _v1_secret_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_secret_volume_source_t v1_secret_volume_source_t;

#include "v1_key_to_path.h"



typedef struct v1_secret_volume_source_t {
    int default_mode; //numeric
    list_t *items; //nonprimitive container
    int optional; //boolean
    char *secret_name; // string

} v1_secret_volume_source_t;

v1_secret_volume_source_t *v1_secret_volume_source_create(
    int default_mode,
    list_t *items,
    int optional,
    char *secret_name
);

void v1_secret_volume_source_free(v1_secret_volume_source_t *v1_secret_volume_source);

v1_secret_volume_source_t *v1_secret_volume_source_parseFromJSON(cJSON *v1_secret_volume_sourceJSON);

cJSON *v1_secret_volume_source_convertToJSON(v1_secret_volume_source_t *v1_secret_volume_source);

#endif /* _v1_secret_volume_source_H_ */

