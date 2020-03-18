/*
 * v1_git_repo_volume_source.h
 *
 * Represents a volume that is populated with the contents of a git repository. Git repo volumes do not support ownership management. Git repo volumes support SELinux relabeling.  DEPRECATED: GitRepo is deprecated. To provision a container with a git repo, mount an EmptyDir into an InitContainer that clones the repo using git, then mount the EmptyDir into the Pod&#39;s container.
 */

#ifndef _v1_git_repo_volume_source_H_
#define _v1_git_repo_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_git_repo_volume_source_t {
    char *directory; // string
    char *repository; // string
    char *revision; // string

} v1_git_repo_volume_source_t;

v1_git_repo_volume_source_t *v1_git_repo_volume_source_create(
    char *directory,
    char *repository,
    char *revision
);

void v1_git_repo_volume_source_free(v1_git_repo_volume_source_t *v1_git_repo_volume_source);

v1_git_repo_volume_source_t *v1_git_repo_volume_source_parseFromJSON(cJSON *v1_git_repo_volume_sourceJSON);

cJSON *v1_git_repo_volume_source_convertToJSON(v1_git_repo_volume_source_t *v1_git_repo_volume_source);

#endif /* _v1_git_repo_volume_source_H_ */

