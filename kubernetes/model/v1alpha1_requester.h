/*
 * v1alpha1_requester.h
 *
 * Requester allows you to identify the entity, that requested the eviction of the target.
 */

#ifndef _v1alpha1_requester_H_
#define _v1alpha1_requester_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_requester_t v1alpha1_requester_t;




typedef struct v1alpha1_requester_t {
    char *intent; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_requester_t;

__attribute__((deprecated)) v1alpha1_requester_t *v1alpha1_requester_create(
    char *intent,
    char *name
);

void v1alpha1_requester_free(v1alpha1_requester_t *v1alpha1_requester);

v1alpha1_requester_t *v1alpha1_requester_parseFromJSON(cJSON *v1alpha1_requesterJSON);

cJSON *v1alpha1_requester_convertToJSON(v1alpha1_requester_t *v1alpha1_requester);

#endif /* _v1alpha1_requester_H_ */

