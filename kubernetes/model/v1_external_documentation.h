/*
 * v1_external_documentation.h
 *
 * ExternalDocumentation allows referencing an external resource for extended documentation.
 */

#ifndef _v1_external_documentation_H_
#define _v1_external_documentation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_external_documentation_t {
    char *description; // string
    char *url; // string

} v1_external_documentation_t;

v1_external_documentation_t *v1_external_documentation_create(
    char *description,
    char *url
);

void v1_external_documentation_free(v1_external_documentation_t *v1_external_documentation);

v1_external_documentation_t *v1_external_documentation_parseFromJSON(cJSON *v1_external_documentationJSON);

cJSON *v1_external_documentation_convertToJSON(v1_external_documentation_t *v1_external_documentation);

#endif /* _v1_external_documentation_H_ */

