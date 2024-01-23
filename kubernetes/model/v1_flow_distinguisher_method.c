#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_flow_distinguisher_method.h"



v1_flow_distinguisher_method_t *v1_flow_distinguisher_method_create(
    char *type
    ) {
    v1_flow_distinguisher_method_t *v1_flow_distinguisher_method_local_var = malloc(sizeof(v1_flow_distinguisher_method_t));
    if (!v1_flow_distinguisher_method_local_var) {
        return NULL;
    }
    v1_flow_distinguisher_method_local_var->type = type;

    return v1_flow_distinguisher_method_local_var;
}


void v1_flow_distinguisher_method_free(v1_flow_distinguisher_method_t *v1_flow_distinguisher_method) {
    if(NULL == v1_flow_distinguisher_method){
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
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_flow_distinguisher_method_local_var = v1_flow_distinguisher_method_create (
        strdup(type->valuestring)
        );

    return v1_flow_distinguisher_method_local_var;
end:
    return NULL;

}
