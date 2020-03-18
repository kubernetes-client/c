/*
 * v1beta1_external_documentation.h
 *
 * ExternalDocumentation allows referencing an external resource for extended documentation.
 */

#ifndef _v1beta1_external_documentation_H_
#define _v1beta1_external_documentation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_external_documentation_t {
    char *description; // string
    char *url; // string

} v1beta1_external_documentation_t;

v1beta1_external_documentation_t *v1beta1_external_documentation_create(
    char *description,
    char *url
);

void v1beta1_external_documentation_free(v1beta1_external_documentation_t *v1beta1_external_documentation);

v1beta1_external_documentation_t *v1beta1_external_documentation_parseFromJSON(cJSON *v1beta1_external_documentationJSON);

cJSON *v1beta1_external_documentation_convertToJSON(v1beta1_external_documentation_t *v1beta1_external_documentation);

#endif /* _v1beta1_external_documentation_H_ */

