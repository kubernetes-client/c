/*
 * v1_status_details.h
 *
 * StatusDetails is a set of additional properties that MAY be set by the server to provide additional information about a response. The Reason field of a Status object defines what attributes will be set. Clients must ignore fields that do not match the defined type of each attribute, and should assume that any attribute may be empty, invalid, or under defined.
 */

#ifndef _v1_status_details_H_
#define _v1_status_details_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_status_details_t v1_status_details_t;

#include "v1_status_cause.h"



typedef struct v1_status_details_t {
    list_t *causes; //nonprimitive container
    char *group; // string
    char *kind; // string
    char *name; // string
    int retry_after_seconds; //numeric
    char *uid; // string

} v1_status_details_t;

v1_status_details_t *v1_status_details_create(
    list_t *causes,
    char *group,
    char *kind,
    char *name,
    int retry_after_seconds,
    char *uid
);

void v1_status_details_free(v1_status_details_t *v1_status_details);

v1_status_details_t *v1_status_details_parseFromJSON(cJSON *v1_status_detailsJSON);

cJSON *v1_status_details_convertToJSON(v1_status_details_t *v1_status_details);

#endif /* _v1_status_details_H_ */

