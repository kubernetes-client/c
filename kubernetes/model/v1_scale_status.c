#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scale_status.h"



v1_scale_status_t *v1_scale_status_create(
    int replicas,
    char *selector
    ) {
    v1_scale_status_t *v1_scale_status_local_var = malloc(sizeof(v1_scale_status_t));
    if (!v1_scale_status_local_var) {
        return NULL;
    }
    v1_scale_status_local_var->replicas = replicas;
    v1_scale_status_local_var->selector = selector;

    return v1_scale_status_local_var;
}


void v1_scale_status_free(v1_scale_status_t *v1_scale_status) {
    if(NULL == v1_scale_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_scale_status->selector) {
        free(v1_scale_status->selector);
        v1_scale_status->selector = NULL;
    }
    free(v1_scale_status);
}

cJSON *v1_scale_status_convertToJSON(v1_scale_status_t *v1_scale_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_scale_status->replicas
    if (!v1_scale_status->replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "replicas", v1_scale_status->replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_scale_status->selector
    if(v1_scale_status->selector) { 
    if(cJSON_AddStringToObject(item, "selector", v1_scale_status->selector) == NULL) {
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

v1_scale_status_t *v1_scale_status_parseFromJSON(cJSON *v1_scale_statusJSON){

    v1_scale_status_t *v1_scale_status_local_var = NULL;

    // v1_scale_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_scale_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }

    // v1_scale_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_scale_statusJSON, "selector");
    if (selector) { 
    if(!cJSON_IsString(selector))
    {
    goto end; //String
    }
    }


    v1_scale_status_local_var = v1_scale_status_create (
        replicas->valuedouble,
        selector ? strdup(selector->valuestring) : NULL
        );

    return v1_scale_status_local_var;
end:
    return NULL;

}
