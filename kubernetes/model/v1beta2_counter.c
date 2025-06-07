#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_counter.h"



static v1beta2_counter_t *v1beta2_counter_create_internal(
    char *value
    ) {
    v1beta2_counter_t *v1beta2_counter_local_var = malloc(sizeof(v1beta2_counter_t));
    if (!v1beta2_counter_local_var) {
        return NULL;
    }
    v1beta2_counter_local_var->value = value;

    v1beta2_counter_local_var->_library_owned = 1;
    return v1beta2_counter_local_var;
}

__attribute__((deprecated)) v1beta2_counter_t *v1beta2_counter_create(
    char *value
    ) {
    return v1beta2_counter_create_internal (
        value
        );
}

void v1beta2_counter_free(v1beta2_counter_t *v1beta2_counter) {
    if(NULL == v1beta2_counter){
        return ;
    }
    if(v1beta2_counter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_counter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_counter->value) {
        free(v1beta2_counter->value);
        v1beta2_counter->value = NULL;
    }
    free(v1beta2_counter);
}

cJSON *v1beta2_counter_convertToJSON(v1beta2_counter_t *v1beta2_counter) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_counter->value
    if (!v1beta2_counter->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", v1beta2_counter->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta2_counter_t *v1beta2_counter_parseFromJSON(cJSON *v1beta2_counterJSON){

    v1beta2_counter_t *v1beta2_counter_local_var = NULL;

    // v1beta2_counter->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1beta2_counterJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    v1beta2_counter_local_var = v1beta2_counter_create_internal (
        strdup(value->valuestring)
        );

    return v1beta2_counter_local_var;
end:
    return NULL;

}
