/*
 * extensions_v1beta1_http_ingress_path.h
 *
 * HTTPIngressPath associates a path regex with a backend. Incoming urls matching the path are forwarded to the backend.
 */

#ifndef _extensions_v1beta1_http_ingress_path_H_
#define _extensions_v1beta1_http_ingress_path_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_http_ingress_path_t extensions_v1beta1_http_ingress_path_t;

#include "extensions_v1beta1_ingress_backend.h"



typedef struct extensions_v1beta1_http_ingress_path_t {
    struct extensions_v1beta1_ingress_backend_t *backend; //model
    char *path; // string

} extensions_v1beta1_http_ingress_path_t;

extensions_v1beta1_http_ingress_path_t *extensions_v1beta1_http_ingress_path_create(
    extensions_v1beta1_ingress_backend_t *backend,
    char *path
);

void extensions_v1beta1_http_ingress_path_free(extensions_v1beta1_http_ingress_path_t *extensions_v1beta1_http_ingress_path);

extensions_v1beta1_http_ingress_path_t *extensions_v1beta1_http_ingress_path_parseFromJSON(cJSON *extensions_v1beta1_http_ingress_pathJSON);

cJSON *extensions_v1beta1_http_ingress_path_convertToJSON(extensions_v1beta1_http_ingress_path_t *extensions_v1beta1_http_ingress_path);

#endif /* _extensions_v1beta1_http_ingress_path_H_ */

