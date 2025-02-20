/*
 * v1_secret_reference.h
 *
 * SecretReference represents a Secret Reference. It has enough information to retrieve secret in any namespace
 */

#ifndef _v1_secret_reference_H_
#define _v1_secret_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_secret_reference_t v1_secret_reference_t;




typedef struct v1_secret_reference_t {
    char *name; // string
    char *_namespace; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_secret_reference_t;

__attribute__((deprecated)) v1_secret_reference_t *v1_secret_reference_create(
    char *name,
    char *_namespace
);

void v1_secret_reference_free(v1_secret_reference_t *v1_secret_reference);

v1_secret_reference_t *v1_secret_reference_parseFromJSON(cJSON *v1_secret_referenceJSON);

cJSON *v1_secret_reference_convertToJSON(v1_secret_reference_t *v1_secret_reference);

#endif /* _v1_secret_reference_H_ */

