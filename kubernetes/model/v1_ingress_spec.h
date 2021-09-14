/*
 * v1_ingress_spec.h
 *
 * IngressSpec describes the Ingress the user wishes to exist.
 */

#ifndef _v1_ingress_spec_H_
#define _v1_ingress_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_spec_t v1_ingress_spec_t;

#include "v1_ingress_backend.h"
#include "v1_ingress_rule.h"
#include "v1_ingress_tls.h"



typedef struct v1_ingress_spec_t {
    struct v1_ingress_backend_t *default_backend; //model
    char *ingress_class_name; // string
    list_t *rules; //nonprimitive container
    list_t *tls; //nonprimitive container

} v1_ingress_spec_t;

v1_ingress_spec_t *v1_ingress_spec_create(
    v1_ingress_backend_t *default_backend,
    char *ingress_class_name,
    list_t *rules,
    list_t *tls
);

void v1_ingress_spec_free(v1_ingress_spec_t *v1_ingress_spec);

v1_ingress_spec_t *v1_ingress_spec_parseFromJSON(cJSON *v1_ingress_specJSON);

cJSON *v1_ingress_spec_convertToJSON(v1_ingress_spec_t *v1_ingress_spec);

#endif /* _v1_ingress_spec_H_ */

