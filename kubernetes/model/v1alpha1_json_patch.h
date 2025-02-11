/*
 * v1alpha1_json_patch.h
 *
 * JSONPatch defines a JSON Patch.
 */

#ifndef _v1alpha1_json_patch_H_
#define _v1alpha1_json_patch_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_json_patch_t v1alpha1_json_patch_t;




typedef struct v1alpha1_json_patch_t {
    char *expression; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha1_json_patch_t;

__attribute__((deprecated)) v1alpha1_json_patch_t *v1alpha1_json_patch_create(
    char *expression
);

void v1alpha1_json_patch_free(v1alpha1_json_patch_t *v1alpha1_json_patch);

v1alpha1_json_patch_t *v1alpha1_json_patch_parseFromJSON(cJSON *v1alpha1_json_patchJSON);

cJSON *v1alpha1_json_patch_convertToJSON(v1alpha1_json_patch_t *v1alpha1_json_patch);

#endif /* _v1alpha1_json_patch_H_ */

