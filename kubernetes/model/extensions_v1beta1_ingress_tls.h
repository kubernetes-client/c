/*
 * extensions_v1beta1_ingress_tls.h
 *
 * IngressTLS describes the transport layer security associated with an Ingress.
 */

#ifndef _extensions_v1beta1_ingress_tls_H_
#define _extensions_v1beta1_ingress_tls_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_ingress_tls_t extensions_v1beta1_ingress_tls_t;




typedef struct extensions_v1beta1_ingress_tls_t {
    list_t *hosts; //primitive container
    char *secret_name; // string

} extensions_v1beta1_ingress_tls_t;

extensions_v1beta1_ingress_tls_t *extensions_v1beta1_ingress_tls_create(
    list_t *hosts,
    char *secret_name
);

void extensions_v1beta1_ingress_tls_free(extensions_v1beta1_ingress_tls_t *extensions_v1beta1_ingress_tls);

extensions_v1beta1_ingress_tls_t *extensions_v1beta1_ingress_tls_parseFromJSON(cJSON *extensions_v1beta1_ingress_tlsJSON);

cJSON *extensions_v1beta1_ingress_tls_convertToJSON(extensions_v1beta1_ingress_tls_t *extensions_v1beta1_ingress_tls);

#endif /* _extensions_v1beta1_ingress_tls_H_ */

