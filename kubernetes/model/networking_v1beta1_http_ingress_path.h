/*
 * networking_v1beta1_http_ingress_path.h
 *
 * HTTPIngressPath associates a path regex with a backend. Incoming urls matching the path are forwarded to the backend.
 */

#ifndef _networking_v1beta1_http_ingress_path_H_
#define _networking_v1beta1_http_ingress_path_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct networking_v1beta1_http_ingress_path_t networking_v1beta1_http_ingress_path_t;

#include "networking_v1beta1_ingress_backend.h"



typedef struct networking_v1beta1_http_ingress_path_t {
    struct networking_v1beta1_ingress_backend_t *backend; //model
    char *path; // string

} networking_v1beta1_http_ingress_path_t;

networking_v1beta1_http_ingress_path_t *networking_v1beta1_http_ingress_path_create(
    networking_v1beta1_ingress_backend_t *backend,
    char *path
);

void networking_v1beta1_http_ingress_path_free(networking_v1beta1_http_ingress_path_t *networking_v1beta1_http_ingress_path);

networking_v1beta1_http_ingress_path_t *networking_v1beta1_http_ingress_path_parseFromJSON(cJSON *networking_v1beta1_http_ingress_pathJSON);

cJSON *networking_v1beta1_http_ingress_path_convertToJSON(networking_v1beta1_http_ingress_path_t *networking_v1beta1_http_ingress_path);

#endif /* _networking_v1beta1_http_ingress_path_H_ */

