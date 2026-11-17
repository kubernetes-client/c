/*
 * v1alpha1_responder_status.h
 *
 * ResponderStatus represents the last observed status of the eviction process of the responder. It should be only updated by the designated responder whose name is .name field.
 */

#ifndef _v1alpha1_responder_status_H_
#define _v1alpha1_responder_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_responder_status_t v1alpha1_responder_status_t;




typedef struct v1alpha1_responder_status_t {
    char *completion_time; //date time
    char *expected_completion_time; //date time
    char *heartbeat_time; //date time
    char *message; // string
    char *name; // string
    char *start_time; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_responder_status_t;

__attribute__((deprecated)) v1alpha1_responder_status_t *v1alpha1_responder_status_create(
    char *completion_time,
    char *expected_completion_time,
    char *heartbeat_time,
    char *message,
    char *name,
    char *start_time
);

void v1alpha1_responder_status_free(v1alpha1_responder_status_t *v1alpha1_responder_status);

v1alpha1_responder_status_t *v1alpha1_responder_status_parseFromJSON(cJSON *v1alpha1_responder_statusJSON);

cJSON *v1alpha1_responder_status_convertToJSON(v1alpha1_responder_status_t *v1alpha1_responder_status);

#endif /* _v1alpha1_responder_status_H_ */

