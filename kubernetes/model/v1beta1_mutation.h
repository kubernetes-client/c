/*
 * v1beta1_mutation.h
 *
 * Mutation specifies the CEL expression which is used to apply the Mutation.
 */

#ifndef _v1beta1_mutation_H_
#define _v1beta1_mutation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_mutation_t v1beta1_mutation_t;

#include "v1beta1_apply_configuration.h"
#include "v1beta1_json_patch.h"



typedef struct v1beta1_mutation_t {
    struct v1beta1_apply_configuration_t *apply_configuration; //model
    struct v1beta1_json_patch_t *json_patch; //model
    char *patch_type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_mutation_t;

__attribute__((deprecated)) v1beta1_mutation_t *v1beta1_mutation_create(
    v1beta1_apply_configuration_t *apply_configuration,
    v1beta1_json_patch_t *json_patch,
    char *patch_type
);

void v1beta1_mutation_free(v1beta1_mutation_t *v1beta1_mutation);

v1beta1_mutation_t *v1beta1_mutation_parseFromJSON(cJSON *v1beta1_mutationJSON);

cJSON *v1beta1_mutation_convertToJSON(v1beta1_mutation_t *v1beta1_mutation);

#endif /* _v1beta1_mutation_H_ */

