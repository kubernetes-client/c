/*
 * v1beta3_flow_distinguisher_method.h
 *
 * FlowDistinguisherMethod specifies the method of a flow distinguisher.
 */

#ifndef _v1beta3_flow_distinguisher_method_H_
#define _v1beta3_flow_distinguisher_method_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta3_flow_distinguisher_method_t v1beta3_flow_distinguisher_method_t;




typedef struct v1beta3_flow_distinguisher_method_t {
    char *type; // string

} v1beta3_flow_distinguisher_method_t;

v1beta3_flow_distinguisher_method_t *v1beta3_flow_distinguisher_method_create(
    char *type
);

void v1beta3_flow_distinguisher_method_free(v1beta3_flow_distinguisher_method_t *v1beta3_flow_distinguisher_method);

v1beta3_flow_distinguisher_method_t *v1beta3_flow_distinguisher_method_parseFromJSON(cJSON *v1beta3_flow_distinguisher_methodJSON);

cJSON *v1beta3_flow_distinguisher_method_convertToJSON(v1beta3_flow_distinguisher_method_t *v1beta3_flow_distinguisher_method);

#endif /* _v1beta3_flow_distinguisher_method_H_ */

