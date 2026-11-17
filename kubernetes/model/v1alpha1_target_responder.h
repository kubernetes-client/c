/*
 * v1alpha1_target_responder.h
 *
 * TargetResponder allows you to specify the responder reacting to the Eviction. Responders should observe and communicate through the Eviction API (see .state) to help with the graceful eviction of a target (e.g. termination of a pod).
 */

#ifndef _v1alpha1_target_responder_H_
#define _v1alpha1_target_responder_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_target_responder_t v1alpha1_target_responder_t;




typedef struct v1alpha1_target_responder_t {
    char *name; // string
    int *priority; //numeric
    char *state; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_target_responder_t;

__attribute__((deprecated)) v1alpha1_target_responder_t *v1alpha1_target_responder_create(
    char *name,
    int *priority,
    char *state
);

void v1alpha1_target_responder_free(v1alpha1_target_responder_t *v1alpha1_target_responder);

v1alpha1_target_responder_t *v1alpha1_target_responder_parseFromJSON(cJSON *v1alpha1_target_responderJSON);

cJSON *v1alpha1_target_responder_convertToJSON(v1alpha1_target_responder_t *v1alpha1_target_responder);

#endif /* _v1alpha1_target_responder_H_ */

