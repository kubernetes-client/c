/*
 * v1beta1_expression_warning.h
 *
 * ExpressionWarning is a warning information that targets a specific expression.
 */

#ifndef _v1beta1_expression_warning_H_
#define _v1beta1_expression_warning_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_expression_warning_t v1beta1_expression_warning_t;




typedef struct v1beta1_expression_warning_t {
    char *field_ref; // string
    char *warning; // string

} v1beta1_expression_warning_t;

v1beta1_expression_warning_t *v1beta1_expression_warning_create(
    char *field_ref,
    char *warning
);

void v1beta1_expression_warning_free(v1beta1_expression_warning_t *v1beta1_expression_warning);

v1beta1_expression_warning_t *v1beta1_expression_warning_parseFromJSON(cJSON *v1beta1_expression_warningJSON);

cJSON *v1beta1_expression_warning_convertToJSON(v1beta1_expression_warning_t *v1beta1_expression_warning);

#endif /* _v1beta1_expression_warning_H_ */

