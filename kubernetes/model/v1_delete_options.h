/*
 * v1_delete_options.h
 *
 * DeleteOptions may be provided when deleting an API object.
 */

#ifndef _v1_delete_options_H_
#define _v1_delete_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_delete_options_t v1_delete_options_t;

#include "v1_preconditions.h"



typedef struct v1_delete_options_t {
    char *api_version; // string
    list_t *dry_run; //primitive container
    long grace_period_seconds; //numeric
    char *kind; // string
    int orphan_dependents; //boolean
    struct v1_preconditions_t *preconditions; //model
    char *propagation_policy; // string

} v1_delete_options_t;

v1_delete_options_t *v1_delete_options_create(
    char *api_version,
    list_t *dry_run,
    long grace_period_seconds,
    char *kind,
    int orphan_dependents,
    v1_preconditions_t *preconditions,
    char *propagation_policy
);

void v1_delete_options_free(v1_delete_options_t *v1_delete_options);

v1_delete_options_t *v1_delete_options_parseFromJSON(cJSON *v1_delete_optionsJSON);

cJSON *v1_delete_options_convertToJSON(v1_delete_options_t *v1_delete_options);

#endif /* _v1_delete_options_H_ */

