/*
 * v1_http_ingress_path.h
 *
 * HTTPIngressPath associates a path with a backend. Incoming urls matching the path are forwarded to the backend.
 */

#ifndef _v1_http_ingress_path_H_
#define _v1_http_ingress_path_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_http_ingress_path_t v1_http_ingress_path_t;

#include "v1_ingress_backend.h"



typedef struct v1_http_ingress_path_t {
    struct v1_ingress_backend_t *backend; //model
    char *path; // string
    char *path_type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_http_ingress_path_t;

__attribute__((deprecated)) v1_http_ingress_path_t *v1_http_ingress_path_create(
    v1_ingress_backend_t *backend,
    char *path,
    char *path_type
);

void v1_http_ingress_path_free(v1_http_ingress_path_t *v1_http_ingress_path);

v1_http_ingress_path_t *v1_http_ingress_path_parseFromJSON(cJSON *v1_http_ingress_pathJSON);

cJSON *v1_http_ingress_path_convertToJSON(v1_http_ingress_path_t *v1_http_ingress_path);

#endif /* _v1_http_ingress_path_H_ */

