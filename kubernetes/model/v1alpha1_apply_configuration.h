/*
 * v1alpha1_apply_configuration.h
 *
 * ApplyConfiguration defines the desired configuration values of an object.
 */

#ifndef _v1alpha1_apply_configuration_H_
#define _v1alpha1_apply_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_apply_configuration_t v1alpha1_apply_configuration_t;




typedef struct v1alpha1_apply_configuration_t {
    char *expression; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_apply_configuration_t;

__attribute__((deprecated)) v1alpha1_apply_configuration_t *v1alpha1_apply_configuration_create(
    char *expression
);

void v1alpha1_apply_configuration_free(v1alpha1_apply_configuration_t *v1alpha1_apply_configuration);

v1alpha1_apply_configuration_t *v1alpha1_apply_configuration_parseFromJSON(cJSON *v1alpha1_apply_configurationJSON);

cJSON *v1alpha1_apply_configuration_convertToJSON(v1alpha1_apply_configuration_t *v1alpha1_apply_configuration);

#endif /* _v1alpha1_apply_configuration_H_ */

