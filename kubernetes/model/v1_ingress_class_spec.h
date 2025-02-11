/*
 * v1_ingress_class_spec.h
 *
 * IngressClassSpec provides information about the class of an Ingress.
 */

#ifndef _v1_ingress_class_spec_H_
#define _v1_ingress_class_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_class_spec_t v1_ingress_class_spec_t;

#include "v1_ingress_class_parameters_reference.h"



typedef struct v1_ingress_class_spec_t {
    char *controller; // string
    struct v1_ingress_class_parameters_reference_t *parameters; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_ingress_class_spec_t;

__attribute__((deprecated)) v1_ingress_class_spec_t *v1_ingress_class_spec_create(
    char *controller,
    v1_ingress_class_parameters_reference_t *parameters
);

void v1_ingress_class_spec_free(v1_ingress_class_spec_t *v1_ingress_class_spec);

v1_ingress_class_spec_t *v1_ingress_class_spec_parseFromJSON(cJSON *v1_ingress_class_specJSON);

cJSON *v1_ingress_class_spec_convertToJSON(v1_ingress_class_spec_t *v1_ingress_class_spec);

#endif /* _v1_ingress_class_spec_H_ */

