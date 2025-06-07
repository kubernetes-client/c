/*
 * v1_lifecycle.h
 *
 * Lifecycle describes actions that the management system should take in response to container lifecycle events. For the PostStart and PreStop lifecycle handlers, management of the container blocks until the action is complete, unless the container process fails, in which case the handler is aborted.
 */

#ifndef _v1_lifecycle_H_
#define _v1_lifecycle_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_lifecycle_t v1_lifecycle_t;

#include "v1_lifecycle_handler.h"



typedef struct v1_lifecycle_t {
    struct v1_lifecycle_handler_t *post_start; //model
    struct v1_lifecycle_handler_t *pre_stop; //model
    char *stop_signal; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_lifecycle_t;

__attribute__((deprecated)) v1_lifecycle_t *v1_lifecycle_create(
    v1_lifecycle_handler_t *post_start,
    v1_lifecycle_handler_t *pre_stop,
    char *stop_signal
);

void v1_lifecycle_free(v1_lifecycle_t *v1_lifecycle);

v1_lifecycle_t *v1_lifecycle_parseFromJSON(cJSON *v1_lifecycleJSON);

cJSON *v1_lifecycle_convertToJSON(v1_lifecycle_t *v1_lifecycle);

#endif /* _v1_lifecycle_H_ */

