/*
 * v1_shard_info.h
 *
 * ShardInfo describes the shard selector that was applied to produce a list response. Its presence on a list response indicates the list is a filtered subset.
 */

#ifndef _v1_shard_info_H_
#define _v1_shard_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_shard_info_t v1_shard_info_t;




typedef struct v1_shard_info_t {
    char *selector; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_shard_info_t;

__attribute__((deprecated)) v1_shard_info_t *v1_shard_info_create(
    char *selector
);

void v1_shard_info_free(v1_shard_info_t *v1_shard_info);

v1_shard_info_t *v1_shard_info_parseFromJSON(cJSON *v1_shard_infoJSON);

cJSON *v1_shard_info_convertToJSON(v1_shard_info_t *v1_shard_info);

#endif /* _v1_shard_info_H_ */

