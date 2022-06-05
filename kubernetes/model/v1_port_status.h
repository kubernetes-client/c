/*
 * v1_port_status.h
 *
 * 
 */

#ifndef _v1_port_status_H_
#define _v1_port_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_port_status_t v1_port_status_t;




typedef struct v1_port_status_t {
    char *error; // string
    int port; //numeric
    char *protocol; // string

} v1_port_status_t;

v1_port_status_t *v1_port_status_create(
    char *error,
    int port,
    char *protocol
);

void v1_port_status_free(v1_port_status_t *v1_port_status);

v1_port_status_t *v1_port_status_parseFromJSON(cJSON *v1_port_statusJSON);

cJSON *v1_port_status_convertToJSON(v1_port_status_t *v1_port_status);

#endif /* _v1_port_status_H_ */

