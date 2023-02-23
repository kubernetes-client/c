/*
 * v1alpha1_param_ref.h
 *
 * ParamRef references a parameter resource
 */

#ifndef _v1alpha1_param_ref_H_
#define _v1alpha1_param_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_param_ref_t v1alpha1_param_ref_t;




typedef struct v1alpha1_param_ref_t {
    char *name; // string
    char *_namespace; // string

} v1alpha1_param_ref_t;

v1alpha1_param_ref_t *v1alpha1_param_ref_create(
    char *name,
    char *_namespace
);

void v1alpha1_param_ref_free(v1alpha1_param_ref_t *v1alpha1_param_ref);

v1alpha1_param_ref_t *v1alpha1_param_ref_parseFromJSON(cJSON *v1alpha1_param_refJSON);

cJSON *v1alpha1_param_ref_convertToJSON(v1alpha1_param_ref_t *v1alpha1_param_ref);

#endif /* _v1alpha1_param_ref_H_ */

