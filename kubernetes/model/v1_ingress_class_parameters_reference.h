/*
 * v1_ingress_class_parameters_reference.h
 *
 * IngressClassParametersReference identifies an API object. This can be used to specify a cluster or namespace-scoped resource.
 */

#ifndef _v1_ingress_class_parameters_reference_H_
#define _v1_ingress_class_parameters_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_class_parameters_reference_t v1_ingress_class_parameters_reference_t;




typedef struct v1_ingress_class_parameters_reference_t {
    char *api_group; // string
    char *kind; // string
    char *name; // string
    char *_namespace; // string
    char *scope; // string

} v1_ingress_class_parameters_reference_t;

v1_ingress_class_parameters_reference_t *v1_ingress_class_parameters_reference_create(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace,
    char *scope
);

void v1_ingress_class_parameters_reference_free(v1_ingress_class_parameters_reference_t *v1_ingress_class_parameters_reference);

v1_ingress_class_parameters_reference_t *v1_ingress_class_parameters_reference_parseFromJSON(cJSON *v1_ingress_class_parameters_referenceJSON);

cJSON *v1_ingress_class_parameters_reference_convertToJSON(v1_ingress_class_parameters_reference_t *v1_ingress_class_parameters_reference);

#endif /* _v1_ingress_class_parameters_reference_H_ */

