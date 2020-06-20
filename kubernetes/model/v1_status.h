/*
 * v1_status.h
 *
 * Status is a return value for calls that don&#39;t return other objects.
 */

#ifndef _v1_status_H_
#define _v1_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_status_t v1_status_t;

#include "v1_list_meta.h"
#include "v1_status_details.h"



typedef struct v1_status_t {
    char *api_version; // string
    int code; //numeric
    struct v1_status_details_t *details; //model
    char *kind; // string
    char *message; // string
    struct v1_list_meta_t *metadata; //model
    char *reason; // string
    char *status; // string

} v1_status_t;

v1_status_t *v1_status_create(
    char *api_version,
    int code,
    v1_status_details_t *details,
    char *kind,
    char *message,
    v1_list_meta_t *metadata,
    char *reason,
    char *status
);

void v1_status_free(v1_status_t *v1_status);

v1_status_t *v1_status_parseFromJSON(cJSON *v1_statusJSON);

cJSON *v1_status_convertToJSON(v1_status_t *v1_status);

#endif /* _v1_status_H_ */

