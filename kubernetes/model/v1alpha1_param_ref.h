/*
 * v1alpha1_param_ref.h
 *
 * ParamRef describes how to locate the params to be used as input to expressions of rules applied by a policy binding.
 */

#ifndef _v1alpha1_param_ref_H_
#define _v1alpha1_param_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_param_ref_t v1alpha1_param_ref_t;

#include "v1_label_selector.h"



typedef struct v1alpha1_param_ref_t {
    char *name; // string
    char *_namespace; // string
    char *parameter_not_found_action; // string
    struct v1_label_selector_t *selector; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_param_ref_t;

__attribute__((deprecated)) v1alpha1_param_ref_t *v1alpha1_param_ref_create(
    char *name,
    char *_namespace,
    char *parameter_not_found_action,
    v1_label_selector_t *selector
);

void v1alpha1_param_ref_free(v1alpha1_param_ref_t *v1alpha1_param_ref);

v1alpha1_param_ref_t *v1alpha1_param_ref_parseFromJSON(cJSON *v1alpha1_param_refJSON);

cJSON *v1alpha1_param_ref_convertToJSON(v1alpha1_param_ref_t *v1alpha1_param_ref);

#endif /* _v1alpha1_param_ref_H_ */

