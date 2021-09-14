/*
 * v1_ingress_tls.h
 *
 * IngressTLS describes the transport layer security associated with an Ingress.
 */

#ifndef _v1_ingress_tls_H_
#define _v1_ingress_tls_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_tls_t v1_ingress_tls_t;




typedef struct v1_ingress_tls_t {
    list_t *hosts; //primitive container
    char *secret_name; // string

} v1_ingress_tls_t;

v1_ingress_tls_t *v1_ingress_tls_create(
    list_t *hosts,
    char *secret_name
);

void v1_ingress_tls_free(v1_ingress_tls_t *v1_ingress_tls);

v1_ingress_tls_t *v1_ingress_tls_parseFromJSON(cJSON *v1_ingress_tlsJSON);

cJSON *v1_ingress_tls_convertToJSON(v1_ingress_tls_t *v1_ingress_tls);

#endif /* _v1_ingress_tls_H_ */

