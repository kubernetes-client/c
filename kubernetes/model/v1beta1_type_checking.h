/*
 * v1beta1_type_checking.h
 *
 * TypeChecking contains results of type checking the expressions in the ValidatingAdmissionPolicy
 */

#ifndef _v1beta1_type_checking_H_
#define _v1beta1_type_checking_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_type_checking_t v1beta1_type_checking_t;

#include "v1beta1_expression_warning.h"



typedef struct v1beta1_type_checking_t {
    list_t *expression_warnings; //nonprimitive container

} v1beta1_type_checking_t;

v1beta1_type_checking_t *v1beta1_type_checking_create(
    list_t *expression_warnings
);

void v1beta1_type_checking_free(v1beta1_type_checking_t *v1beta1_type_checking);

v1beta1_type_checking_t *v1beta1_type_checking_parseFromJSON(cJSON *v1beta1_type_checkingJSON);

cJSON *v1beta1_type_checking_convertToJSON(v1beta1_type_checking_t *v1beta1_type_checking);

#endif /* _v1beta1_type_checking_H_ */

