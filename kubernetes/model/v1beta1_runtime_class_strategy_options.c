#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_runtime_class_strategy_options.h"



v1beta1_runtime_class_strategy_options_t *v1beta1_runtime_class_strategy_options_create(
    list_t *allowed_runtime_class_names,
    char *default_runtime_class_name
    ) {
    v1beta1_runtime_class_strategy_options_t *v1beta1_runtime_class_strategy_options_local_var = malloc(sizeof(v1beta1_runtime_class_strategy_options_t));
    if (!v1beta1_runtime_class_strategy_options_local_var) {
        return NULL;
    }
    v1beta1_runtime_class_strategy_options_local_var->allowed_runtime_class_names = allowed_runtime_class_names;
    v1beta1_runtime_class_strategy_options_local_var->default_runtime_class_name = default_runtime_class_name;

    return v1beta1_runtime_class_strategy_options_local_var;
}


void v1beta1_runtime_class_strategy_options_free(v1beta1_runtime_class_strategy_options_t *v1beta1_runtime_class_strategy_options) {
    if(NULL == v1beta1_runtime_class_strategy_options){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_runtime_class_strategy_options->allowed_runtime_class_names) {
        list_ForEach(listEntry, v1beta1_runtime_class_strategy_options->allowed_runtime_class_names) {
            free(listEntry->data);
        }
        list_freeList(v1beta1_runtime_class_strategy_options->allowed_runtime_class_names);
        v1beta1_runtime_class_strategy_options->allowed_runtime_class_names = NULL;
    }
    if (v1beta1_runtime_class_strategy_options->default_runtime_class_name) {
        free(v1beta1_runtime_class_strategy_options->default_runtime_class_name);
        v1beta1_runtime_class_strategy_options->default_runtime_class_name = NULL;
    }
    free(v1beta1_runtime_class_strategy_options);
}

cJSON *v1beta1_runtime_class_strategy_options_convertToJSON(v1beta1_runtime_class_strategy_options_t *v1beta1_runtime_class_strategy_options) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_runtime_class_strategy_options->allowed_runtime_class_names
    if (!v1beta1_runtime_class_strategy_options->allowed_runtime_class_names) {
        goto fail;
    }
    
    cJSON *allowed_runtime_class_names = cJSON_AddArrayToObject(item, "allowedRuntimeClassNames");
    if(allowed_runtime_class_names == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_runtime_class_namesListEntry;
    list_ForEach(allowed_runtime_class_namesListEntry, v1beta1_runtime_class_strategy_options->allowed_runtime_class_names) {
    if(cJSON_AddStringToObject(allowed_runtime_class_names, "", (char*)allowed_runtime_class_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1beta1_runtime_class_strategy_options->default_runtime_class_name
    if(v1beta1_runtime_class_strategy_options->default_runtime_class_name) { 
    if(cJSON_AddStringToObject(item, "defaultRuntimeClassName", v1beta1_runtime_class_strategy_options->default_runtime_class_name) == NULL) {
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

v1beta1_runtime_class_strategy_options_t *v1beta1_runtime_class_strategy_options_parseFromJSON(cJSON *v1beta1_runtime_class_strategy_optionsJSON){

    v1beta1_runtime_class_strategy_options_t *v1beta1_runtime_class_strategy_options_local_var = NULL;

    // define the local list for v1beta1_runtime_class_strategy_options->allowed_runtime_class_names
    list_t *allowed_runtime_class_namesList = NULL;

    // v1beta1_runtime_class_strategy_options->allowed_runtime_class_names
    cJSON *allowed_runtime_class_names = cJSON_GetObjectItemCaseSensitive(v1beta1_runtime_class_strategy_optionsJSON, "allowedRuntimeClassNames");
    if (!allowed_runtime_class_names) {
        goto end;
    }

    
    cJSON *allowed_runtime_class_names_local = NULL;
    if(!cJSON_IsArray(allowed_runtime_class_names)) {
        goto end;//primitive container
    }
    allowed_runtime_class_namesList = list_createList();

    cJSON_ArrayForEach(allowed_runtime_class_names_local, allowed_runtime_class_names)
    {
        if(!cJSON_IsString(allowed_runtime_class_names_local))
        {
            goto end;
        }
        list_addElement(allowed_runtime_class_namesList , strdup(allowed_runtime_class_names_local->valuestring));
    }

    // v1beta1_runtime_class_strategy_options->default_runtime_class_name
    cJSON *default_runtime_class_name = cJSON_GetObjectItemCaseSensitive(v1beta1_runtime_class_strategy_optionsJSON, "defaultRuntimeClassName");
    if (default_runtime_class_name) { 
    if(!cJSON_IsString(default_runtime_class_name))
    {
    goto end; //String
    }
    }


    v1beta1_runtime_class_strategy_options_local_var = v1beta1_runtime_class_strategy_options_create (
        allowed_runtime_class_namesList,
        default_runtime_class_name ? strdup(default_runtime_class_name->valuestring) : NULL
        );

    return v1beta1_runtime_class_strategy_options_local_var;
end:
    if (allowed_runtime_class_namesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_runtime_class_namesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_runtime_class_namesList);
        allowed_runtime_class_namesList = NULL;
    }
    return NULL;

}
