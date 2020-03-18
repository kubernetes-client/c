/*
 * v1_http_header.h
 *
 * HTTPHeader describes a custom header to be used in HTTP probes
 */

#ifndef _v1_http_header_H_
#define _v1_http_header_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_http_header_t {
    char *name; // string
    char *value; // string

} v1_http_header_t;

v1_http_header_t *v1_http_header_create(
    char *name,
    char *value
);

void v1_http_header_free(v1_http_header_t *v1_http_header);

v1_http_header_t *v1_http_header_parseFromJSON(cJSON *v1_http_headerJSON);

cJSON *v1_http_header_convertToJSON(v1_http_header_t *v1_http_header);

#endif /* _v1_http_header_H_ */

