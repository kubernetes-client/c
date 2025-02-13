/*
 * v1_expression_warning.h
 *
 * ExpressionWarning is a warning information that targets a specific expression.
 */

#ifndef _v1_expression_warning_H_
#define _v1_expression_warning_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_expression_warning_t v1_expression_warning_t;




typedef struct v1_expression_warning_t {
    char *field_ref; // string
    char *warning; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_expression_warning_t;

__attribute__((deprecated)) v1_expression_warning_t *v1_expression_warning_create(
    char *field_ref,
    char *warning
);

void v1_expression_warning_free(v1_expression_warning_t *v1_expression_warning);

v1_expression_warning_t *v1_expression_warning_parseFromJSON(cJSON *v1_expression_warningJSON);

cJSON *v1_expression_warning_convertToJSON(v1_expression_warning_t *v1_expression_warning);

#endif /* _v1_expression_warning_H_ */

