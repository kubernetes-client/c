/*
 * v1_list_meta.h
 *
 * ListMeta describes metadata that synthetic resources must have, including lists and various status objects. A resource may have only one of {ObjectMeta, ListMeta}.
 */

#ifndef _v1_list_meta_H_
#define _v1_list_meta_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_list_meta_t v1_list_meta_t;




typedef struct v1_list_meta_t {
    char *_continue; // string
    long remaining_item_count; //numeric
    char *resource_version; // string
    char *self_link; // string

} v1_list_meta_t;

v1_list_meta_t *v1_list_meta_create(
    char *_continue,
    long remaining_item_count,
    char *resource_version,
    char *self_link
);

void v1_list_meta_free(v1_list_meta_t *v1_list_meta);

v1_list_meta_t *v1_list_meta_parseFromJSON(cJSON *v1_list_metaJSON);

cJSON *v1_list_meta_convertToJSON(v1_list_meta_t *v1_list_meta);

#endif /* _v1_list_meta_H_ */

