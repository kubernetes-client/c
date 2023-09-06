/*
 * v1beta1_validation.h
 *
 * Validation specifies the CEL expression which is used to apply the validation.
 */

#ifndef _v1beta1_validation_H_
#define _v1beta1_validation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_validation_t v1beta1_validation_t;




typedef struct v1beta1_validation_t {
    char *expression; // string
    char *message; // string
    char *message_expression; // string
    char *reason; // string

} v1beta1_validation_t;

v1beta1_validation_t *v1beta1_validation_create(
    char *expression,
    char *message,
    char *message_expression,
    char *reason
);

void v1beta1_validation_free(v1beta1_validation_t *v1beta1_validation);

v1beta1_validation_t *v1beta1_validation_parseFromJSON(cJSON *v1beta1_validationJSON);

cJSON *v1beta1_validation_convertToJSON(v1beta1_validation_t *v1beta1_validation);

#endif /* _v1beta1_validation_H_ */

