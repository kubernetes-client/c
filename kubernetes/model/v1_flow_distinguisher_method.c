#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_flow_distinguisher_method.h"



static v1_flow_distinguisher_method_t *v1_flow_distinguisher_method_create_internal(
    char *type
    ) {
    v1_flow_distinguisher_method_t *v1_flow_distinguisher_method_local_var = malloc(sizeof(v1_flow_distinguisher_method_t));
    if (!v1_flow_distinguisher_method_local_var) {
        return NULL;
    }
    v1_flow_distinguisher_method_local_var->type = type;

    v1_flow_distinguisher_method_local_var->_library_owned = 1;
    return v1_flow_distinguisher_method_local_var;
}

__attribute__((deprecated)) v1_flow_distinguisher_method_t *v1_flow_distinguisher_method_create(
    char *type
    ) {
    return v1_flow_distinguisher_method_create_internal (
        type
        );
}

void v1_flow_distinguisher_method_free(v1_flow_distinguisher_method_t *v1_flow_distinguisher_method) {
    if(NULL == v1_flow_distinguisher_method){
        return ;
    }
    if(v1_flow_distinguisher_method->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_flow_distinguisher_method_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_flow_distinguisher_method->type) {
        free(v1_flow_distinguisher_method->type);
        v1_flow_distinguisher_method->type = NULL;
    }
    free(v1_flow_distinguisher_method);
}

cJSON *v1_flow_distinguisher_method_convertToJSON(v1_flow_distinguisher_method_t *v1_flow_distinguisher_method) {
    cJSON *item = cJSON_CreateObject();

    // v1_flow_distinguisher_method->type
    if (!v1_flow_distinguisher_method->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_flow_distinguisher_method->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_flow_distinguisher_method_t *v1_flow_distinguisher_method_parseFromJSON(cJSON *v1_flow_distinguisher_methodJSON){

    v1_flow_distinguisher_method_t *v1_flow_distinguisher_method_local_var = NULL;

    // v1_flow_distinguisher_method->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_flow_distinguisher_methodJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_flow_distinguisher_method_local_var = v1_flow_distinguisher_method_create_internal (
        strdup(type->valuestring)
        );

    return v1_flow_distinguisher_method_local_var;
end:
    return NULL;

}
