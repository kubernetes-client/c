#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_endpoint_conditions.h"



v1beta1_endpoint_conditions_t *v1beta1_endpoint_conditions_create(
    int ready,
    int serving,
    int terminating
    ) {
    v1beta1_endpoint_conditions_t *v1beta1_endpoint_conditions_local_var = malloc(sizeof(v1beta1_endpoint_conditions_t));
    if (!v1beta1_endpoint_conditions_local_var) {
        return NULL;
    }
    v1beta1_endpoint_conditions_local_var->ready = ready;
    v1beta1_endpoint_conditions_local_var->serving = serving;
    v1beta1_endpoint_conditions_local_var->terminating = terminating;

    return v1beta1_endpoint_conditions_local_var;
}


void v1beta1_endpoint_conditions_free(v1beta1_endpoint_conditions_t *v1beta1_endpoint_conditions) {
    if(NULL == v1beta1_endpoint_conditions){
        return ;
    }
    listEntry_t *listEntry;
    free(v1beta1_endpoint_conditions);
}

cJSON *v1beta1_endpoint_conditions_convertToJSON(v1beta1_endpoint_conditions_t *v1beta1_endpoint_conditions) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_endpoint_conditions->ready
    if(v1beta1_endpoint_conditions->ready) { 
    if(cJSON_AddBoolToObject(item, "ready", v1beta1_endpoint_conditions->ready) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_endpoint_conditions->serving
    if(v1beta1_endpoint_conditions->serving) { 
    if(cJSON_AddBoolToObject(item, "serving", v1beta1_endpoint_conditions->serving) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_endpoint_conditions->terminating
    if(v1beta1_endpoint_conditions->terminating) { 
    if(cJSON_AddBoolToObject(item, "terminating", v1beta1_endpoint_conditions->terminating) == NULL) {
    goto fail; //Bool
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_endpoint_conditions_t *v1beta1_endpoint_conditions_parseFromJSON(cJSON *v1beta1_endpoint_conditionsJSON){

    v1beta1_endpoint_conditions_t *v1beta1_endpoint_conditions_local_var = NULL;

    // v1beta1_endpoint_conditions->ready
    cJSON *ready = cJSON_GetObjectItemCaseSensitive(v1beta1_endpoint_conditionsJSON, "ready");
    if (ready) { 
    if(!cJSON_IsBool(ready))
    {
    goto end; //Bool
    }
    }

    // v1beta1_endpoint_conditions->serving
    cJSON *serving = cJSON_GetObjectItemCaseSensitive(v1beta1_endpoint_conditionsJSON, "serving");
    if (serving) { 
    if(!cJSON_IsBool(serving))
    {
    goto end; //Bool
    }
    }

    // v1beta1_endpoint_conditions->terminating
    cJSON *terminating = cJSON_GetObjectItemCaseSensitive(v1beta1_endpoint_conditionsJSON, "terminating");
    if (terminating) { 
    if(!cJSON_IsBool(terminating))
    {
    goto end; //Bool
    }
    }


    v1beta1_endpoint_conditions_local_var = v1beta1_endpoint_conditions_create (
        ready ? ready->valueint : 0,
        serving ? serving->valueint : 0,
        terminating ? terminating->valueint : 0
        );

    return v1beta1_endpoint_conditions_local_var;
end:
    return NULL;

}
