/*
 * networking_v1beta1_ingress_tls.h
 *
 * IngressTLS describes the transport layer security associated with an Ingress.
 */

#ifndef _networking_v1beta1_ingress_tls_H_
#define _networking_v1beta1_ingress_tls_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct networking_v1beta1_ingress_tls_t networking_v1beta1_ingress_tls_t;




typedef struct networking_v1beta1_ingress_tls_t {
    list_t *hosts; //primitive container
    char *secret_name; // string

} networking_v1beta1_ingress_tls_t;

networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls_create(
    list_t *hosts,
    char *secret_name
);

void networking_v1beta1_ingress_tls_free(networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls);

networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls_parseFromJSON(cJSON *networking_v1beta1_ingress_tlsJSON);

cJSON *networking_v1beta1_ingress_tls_convertToJSON(networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls);

#endif /* _networking_v1beta1_ingress_tls_H_ */

