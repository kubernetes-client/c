/*
 * v1_secret.h
 *
 * Secret holds secret data of a certain type. The total bytes of the values in the Data field must be less than MaxSecretSize bytes.
 */

#ifndef _v1_secret_H_
#define _v1_secret_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_secret_t v1_secret_t;

#include "v1_object_meta.h"



typedef struct v1_secret_t {
    char *api_version; // string
    list_t* data; //map
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t* string_data; //map
    char *type; // string

} v1_secret_t;

v1_secret_t *v1_secret_create(
    char *api_version,
    list_t* data,
    char *kind,
    v1_object_meta_t *metadata,
    list_t* string_data,
    char *type
);

void v1_secret_free(v1_secret_t *v1_secret);

v1_secret_t *v1_secret_parseFromJSON(cJSON *v1_secretJSON);

cJSON *v1_secret_convertToJSON(v1_secret_t *v1_secret);

#endif /* _v1_secret_H_ */

