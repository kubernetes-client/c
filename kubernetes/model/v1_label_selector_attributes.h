/*
 * v1_label_selector_attributes.h
 *
 * LabelSelectorAttributes indicates a label limited access. Webhook authors are encouraged to * ensure rawSelector and requirements are not both set * consider the requirements field if set * not try to parse or consider the rawSelector field if set. This is to avoid another CVE-2022-2880 (i.e. getting different systems to agree on how exactly to parse a query is not something we want), see https://www.oxeye.io/resources/golang-parameter-smuggling-attack for more details. For the *SubjectAccessReview endpoints of the kube-apiserver: * If rawSelector is empty and requirements are empty, the request is not limited. * If rawSelector is present and requirements are empty, the rawSelector will be parsed and limited if the parsing succeeds. * If rawSelector is empty and requirements are present, the requirements should be honored * If rawSelector is present and requirements are present, the request is invalid.
 */

#ifndef _v1_label_selector_attributes_H_
#define _v1_label_selector_attributes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_label_selector_attributes_t v1_label_selector_attributes_t;

#include "v1_label_selector_requirement.h"



typedef struct v1_label_selector_attributes_t {
    char *raw_selector; // string
    list_t *requirements; //nonprimitive container

} v1_label_selector_attributes_t;

v1_label_selector_attributes_t *v1_label_selector_attributes_create(
    char *raw_selector,
    list_t *requirements
);

void v1_label_selector_attributes_free(v1_label_selector_attributes_t *v1_label_selector_attributes);

v1_label_selector_attributes_t *v1_label_selector_attributes_parseFromJSON(cJSON *v1_label_selector_attributesJSON);

cJSON *v1_label_selector_attributes_convertToJSON(v1_label_selector_attributes_t *v1_label_selector_attributes);

#endif /* _v1_label_selector_attributes_H_ */

