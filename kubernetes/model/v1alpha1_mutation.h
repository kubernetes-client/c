/*
 * v1alpha1_mutation.h
 *
 * Mutation specifies the CEL expression which is used to apply the Mutation.
 */

#ifndef _v1alpha1_mutation_H_
#define _v1alpha1_mutation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_mutation_t v1alpha1_mutation_t;

#include "v1alpha1_apply_configuration.h"
#include "v1alpha1_json_patch.h"



typedef struct v1alpha1_mutation_t {
    struct v1alpha1_apply_configuration_t *apply_configuration; //model
    struct v1alpha1_json_patch_t *json_patch; //model
    char *patch_type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_mutation_t;

__attribute__((deprecated)) v1alpha1_mutation_t *v1alpha1_mutation_create(
    v1alpha1_apply_configuration_t *apply_configuration,
    v1alpha1_json_patch_t *json_patch,
    char *patch_type
);

void v1alpha1_mutation_free(v1alpha1_mutation_t *v1alpha1_mutation);

v1alpha1_mutation_t *v1alpha1_mutation_parseFromJSON(cJSON *v1alpha1_mutationJSON);

cJSON *v1alpha1_mutation_convertToJSON(v1alpha1_mutation_t *v1alpha1_mutation);

#endif /* _v1alpha1_mutation_H_ */

