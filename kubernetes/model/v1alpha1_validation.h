/*
 * v1alpha1_validation.h
 *
 * Validation specifies the CEL expression which is used to apply the validation.
 */

#ifndef _v1alpha1_validation_H_
#define _v1alpha1_validation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_validation_t v1alpha1_validation_t;




typedef struct v1alpha1_validation_t {
    char *expression; // string
    char *message; // string
    char *reason; // string

} v1alpha1_validation_t;

v1alpha1_validation_t *v1alpha1_validation_create(
    char *expression,
    char *message,
    char *reason
);

void v1alpha1_validation_free(v1alpha1_validation_t *v1alpha1_validation);

v1alpha1_validation_t *v1alpha1_validation_parseFromJSON(cJSON *v1alpha1_validationJSON);

cJSON *v1alpha1_validation_convertToJSON(v1alpha1_validation_t *v1alpha1_validation);

#endif /* _v1alpha1_validation_H_ */

