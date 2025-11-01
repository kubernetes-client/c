#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_counter.h"



static v1_counter_t *v1_counter_create_internal(
    char *value
    ) {
    v1_counter_t *v1_counter_local_var = malloc(sizeof(v1_counter_t));
    if (!v1_counter_local_var) {
        return NULL;
    }
    v1_counter_local_var->value = value;

    v1_counter_local_var->_library_owned = 1;
    return v1_counter_local_var;
}

__attribute__((deprecated)) v1_counter_t *v1_counter_create(
    char *value
    ) {
    return v1_counter_create_internal (
        value
        );
}

void v1_counter_free(v1_counter_t *v1_counter) {
    if(NULL == v1_counter){
        return ;
    }
    if(v1_counter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_counter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_counter->value) {
        free(v1_counter->value);
        v1_counter->value = NULL;
    }
    free(v1_counter);
}

cJSON *v1_counter_convertToJSON(v1_counter_t *v1_counter) {
    cJSON *item = cJSON_CreateObject();

    // v1_counter->value
    if (!v1_counter->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", v1_counter->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_counter_t *v1_counter_parseFromJSON(cJSON *v1_counterJSON){

    v1_counter_t *v1_counter_local_var = NULL;

    // v1_counter->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_counterJSON, "value");
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


    v1_counter_local_var = v1_counter_create_internal (
        strdup(value->valuestring)
        );

    return v1_counter_local_var;
end:
    return NULL;

}
