/*
 * version_info.h
 *
 * Info contains versioning information. how we&#39;ll want to distribute that information.
 */

#ifndef _version_info_H_
#define _version_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct version_info_t version_info_t;




typedef struct version_info_t {
    char *build_date; // string
    char *compiler; // string
    char *git_commit; // string
    char *git_tree_state; // string
    char *git_version; // string
    char *go_version; // string
    char *major; // string
    char *minor; // string
    char *platform; // string

} version_info_t;

version_info_t *version_info_create(
    char *build_date,
    char *compiler,
    char *git_commit,
    char *git_tree_state,
    char *git_version,
    char *go_version,
    char *major,
    char *minor,
    char *platform
);

void version_info_free(version_info_t *version_info);

version_info_t *version_info_parseFromJSON(cJSON *version_infoJSON);

cJSON *version_info_convertToJSON(version_info_t *version_info);

#endif /* _version_info_H_ */

