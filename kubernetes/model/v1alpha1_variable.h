/*
 * v1alpha1_variable.h
 *
 * Variable is the definition of a variable that is used for composition.
 */

#ifndef _v1alpha1_variable_H_
#define _v1alpha1_variable_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_variable_t v1alpha1_variable_t;




typedef struct v1alpha1_variable_t {
    char *expression; // string
    char *name; // string

} v1alpha1_variable_t;

v1alpha1_variable_t *v1alpha1_variable_create(
    char *expression,
    char *name
);

void v1alpha1_variable_free(v1alpha1_variable_t *v1alpha1_variable);

v1alpha1_variable_t *v1alpha1_variable_parseFromJSON(cJSON *v1alpha1_variableJSON);

cJSON *v1alpha1_variable_convertToJSON(v1alpha1_variable_t *v1alpha1_variable);

#endif /* _v1alpha1_variable_H_ */

