/*
 * v1_secret_key_selector.h
 *
 * SecretKeySelector selects a key of a Secret.
 */

#ifndef _v1_secret_key_selector_H_
#define _v1_secret_key_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_secret_key_selector_t {
    char *key; // string
    char *name; // string
    int optional; //boolean

} v1_secret_key_selector_t;

v1_secret_key_selector_t *v1_secret_key_selector_create(
    char *key,
    char *name,
    int optional
);

void v1_secret_key_selector_free(v1_secret_key_selector_t *v1_secret_key_selector);

v1_secret_key_selector_t *v1_secret_key_selector_parseFromJSON(cJSON *v1_secret_key_selectorJSON);

cJSON *v1_secret_key_selector_convertToJSON(v1_secret_key_selector_t *v1_secret_key_selector);

#endif /* _v1_secret_key_selector_H_ */

