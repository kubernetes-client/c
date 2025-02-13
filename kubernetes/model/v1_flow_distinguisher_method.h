/*
 * v1_flow_distinguisher_method.h
 *
 * FlowDistinguisherMethod specifies the method of a flow distinguisher.
 */

#ifndef _v1_flow_distinguisher_method_H_
#define _v1_flow_distinguisher_method_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_flow_distinguisher_method_t v1_flow_distinguisher_method_t;




typedef struct v1_flow_distinguisher_method_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_flow_distinguisher_method_t;

__attribute__((deprecated)) v1_flow_distinguisher_method_t *v1_flow_distinguisher_method_create(
    char *type
);

void v1_flow_distinguisher_method_free(v1_flow_distinguisher_method_t *v1_flow_distinguisher_method);

v1_flow_distinguisher_method_t *v1_flow_distinguisher_method_parseFromJSON(cJSON *v1_flow_distinguisher_methodJSON);

cJSON *v1_flow_distinguisher_method_convertToJSON(v1_flow_distinguisher_method_t *v1_flow_distinguisher_method);

#endif /* _v1_flow_distinguisher_method_H_ */

