#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_counter.h"



static v1alpha3_counter_t *v1alpha3_counter_create_internal(
    char *value
    ) {
    v1alpha3_counter_t *v1alpha3_counter_local_var = malloc(sizeof(v1alpha3_counter_t));
    if (!v1alpha3_counter_local_var) {
        return NULL;
    }
    v1alpha3_counter_local_var->value = value;

    v1alpha3_counter_local_var->_library_owned = 1;
    return v1alpha3_counter_local_var;
}

__attribute__((deprecated)) v1alpha3_counter_t *v1alpha3_counter_create(
    char *value
    ) {
    return v1alpha3_counter_create_internal (
        value
        );
}

void v1alpha3_counter_free(v1alpha3_counter_t *v1alpha3_counter) {
    if(NULL == v1alpha3_counter){
        return ;
    }
    if(v1alpha3_counter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_counter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_counter->value) {
        free(v1alpha3_counter->value);
        v1alpha3_counter->value = NULL;
    }
    free(v1alpha3_counter);
}

cJSON *v1alpha3_counter_convertToJSON(v1alpha3_counter_t *v1alpha3_counter) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_counter->value
    if (!v1alpha3_counter->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", v1alpha3_counter->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_counter_t *v1alpha3_counter_parseFromJSON(cJSON *v1alpha3_counterJSON){

    v1alpha3_counter_t *v1alpha3_counter_local_var = NULL;

    // v1alpha3_counter->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1alpha3_counterJSON, "value");
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


    v1alpha3_counter_local_var = v1alpha3_counter_create_internal (
        strdup(value->valuestring)
        );

    return v1alpha3_counter_local_var;
end:
    return NULL;

}
