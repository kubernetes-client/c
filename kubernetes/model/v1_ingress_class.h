/*
 * v1_ingress_class.h
 *
 * IngressClass represents the class of the Ingress, referenced by the Ingress Spec. The &#x60;ingressclass.kubernetes.io/is-default-class&#x60; annotation can be used to indicate that an IngressClass should be considered default. When a single IngressClass resource has this annotation set to true, new Ingress resources without a class specified will be assigned this default class.
 */

#ifndef _v1_ingress_class_H_
#define _v1_ingress_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_class_t v1_ingress_class_t;

#include "v1_ingress_class_spec.h"
#include "v1_object_meta.h"



typedef struct v1_ingress_class_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_ingress_class_spec_t *spec; //model

} v1_ingress_class_t;

v1_ingress_class_t *v1_ingress_class_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_ingress_class_spec_t *spec
);

void v1_ingress_class_free(v1_ingress_class_t *v1_ingress_class);

v1_ingress_class_t *v1_ingress_class_parseFromJSON(cJSON *v1_ingress_classJSON);

cJSON *v1_ingress_class_convertToJSON(v1_ingress_class_t *v1_ingress_class);

#endif /* _v1_ingress_class_H_ */

