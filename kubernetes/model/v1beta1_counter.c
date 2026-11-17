#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_counter.h"



static v1beta1_counter_t *v1beta1_counter_create_internal(
    char *value
    ) {
    v1beta1_counter_t *v1beta1_counter_local_var = malloc(sizeof(v1beta1_counter_t));
    if (!v1beta1_counter_local_var) {
        return NULL;
    }
    memset(v1beta1_counter_local_var, 0, sizeof(v1beta1_counter_t));
    v1beta1_counter_local_var->_library_owned = 1;
    v1beta1_counter_local_var->value = value;
    return v1beta1_counter_local_var;
}

__attribute__((deprecated)) v1beta1_counter_t *v1beta1_counter_create(
    char *value
    ) {
    v1beta1_counter_t *result = v1beta1_counter_create_internal (
        value
        );
    if (!result) {
    }
    return result;
}

void v1beta1_counter_free(v1beta1_counter_t *v1beta1_counter) {
    if(NULL == v1beta1_counter){
        return ;
    }
    if(v1beta1_counter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_counter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_counter->value) {
        free(v1beta1_counter->value);
        v1beta1_counter->value = NULL;
    }
    free(v1beta1_counter);
}

cJSON *v1beta1_counter_convertToJSON(v1beta1_counter_t *v1beta1_counter) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_counter->value
    if (!v1beta1_counter->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", v1beta1_counter->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_counter_t *v1beta1_counter_parseFromJSON(cJSON *v1beta1_counterJSON){

    v1beta1_counter_t *v1beta1_counter_local_var = NULL;

    char *value_local_str = NULL;

    // v1beta1_counter->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1beta1_counterJSON, "value");
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


    if (value && !cJSON_IsNull(value)) value_local_str = strdup(value->valuestring);

    v1beta1_counter_local_var = v1beta1_counter_create_internal (
        value_local_str
        );

    if (!v1beta1_counter_local_var) {
        goto end;
    }

    return v1beta1_counter_local_var;
end:
    if (value_local_str) {
        free(value_local_str);
        value_local_str = NULL;
    }
    return NULL;

}
