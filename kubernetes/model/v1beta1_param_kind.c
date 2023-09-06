#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_param_kind.h"



v1beta1_param_kind_t *v1beta1_param_kind_create(
    char *api_version,
    char *kind
    ) {
    v1beta1_param_kind_t *v1beta1_param_kind_local_var = malloc(sizeof(v1beta1_param_kind_t));
    if (!v1beta1_param_kind_local_var) {
        return NULL;
    }
    v1beta1_param_kind_local_var->api_version = api_version;
    v1beta1_param_kind_local_var->kind = kind;

    return v1beta1_param_kind_local_var;
}


void v1beta1_param_kind_free(v1beta1_param_kind_t *v1beta1_param_kind) {
    if(NULL == v1beta1_param_kind){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_param_kind->api_version) {
        free(v1beta1_param_kind->api_version);
        v1beta1_param_kind->api_version = NULL;
    }
    if (v1beta1_param_kind->kind) {
        free(v1beta1_param_kind->kind);
        v1beta1_param_kind->kind = NULL;
    }
    free(v1beta1_param_kind);
}

cJSON *v1beta1_param_kind_convertToJSON(v1beta1_param_kind_t *v1beta1_param_kind) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_param_kind->api_version
    if(v1beta1_param_kind->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_param_kind->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_param_kind->kind
    if(v1beta1_param_kind->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1beta1_param_kind->kind) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_param_kind_t *v1beta1_param_kind_parseFromJSON(cJSON *v1beta1_param_kindJSON){

    v1beta1_param_kind_t *v1beta1_param_kind_local_var = NULL;

    // v1beta1_param_kind->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta1_param_kindJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1beta1_param_kind->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_param_kindJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }


    v1beta1_param_kind_local_var = v1beta1_param_kind_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL
        );

    return v1beta1_param_kind_local_var;
end:
    return NULL;

}
