#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_runtime_class_strategy_options.h"



extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options_create(
    list_t *allowed_runtime_class_names,
    char *default_runtime_class_name
    ) {
    extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options_local_var = malloc(sizeof(extensions_v1beta1_runtime_class_strategy_options_t));
    if (!extensions_v1beta1_runtime_class_strategy_options_local_var) {
        return NULL;
    }
    extensions_v1beta1_runtime_class_strategy_options_local_var->allowed_runtime_class_names = allowed_runtime_class_names;
    extensions_v1beta1_runtime_class_strategy_options_local_var->default_runtime_class_name = default_runtime_class_name;

    return extensions_v1beta1_runtime_class_strategy_options_local_var;
}


void extensions_v1beta1_runtime_class_strategy_options_free(extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options) {
    if(NULL == extensions_v1beta1_runtime_class_strategy_options){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_runtime_class_strategy_options->allowed_runtime_class_names) {
        list_ForEach(listEntry, extensions_v1beta1_runtime_class_strategy_options->allowed_runtime_class_names) {
            free(listEntry->data);
        }
        list_free(extensions_v1beta1_runtime_class_strategy_options->allowed_runtime_class_names);
        extensions_v1beta1_runtime_class_strategy_options->allowed_runtime_class_names = NULL;
    }
    if (extensions_v1beta1_runtime_class_strategy_options->default_runtime_class_name) {
        free(extensions_v1beta1_runtime_class_strategy_options->default_runtime_class_name);
        extensions_v1beta1_runtime_class_strategy_options->default_runtime_class_name = NULL;
    }
    free(extensions_v1beta1_runtime_class_strategy_options);
}

cJSON *extensions_v1beta1_runtime_class_strategy_options_convertToJSON(extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_runtime_class_strategy_options->allowed_runtime_class_names
    if (!extensions_v1beta1_runtime_class_strategy_options->allowed_runtime_class_names) {
        goto fail;
    }
    
    cJSON *allowed_runtime_class_names = cJSON_AddArrayToObject(item, "allowedRuntimeClassNames");
    if(allowed_runtime_class_names == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_runtime_class_namesListEntry;
    list_ForEach(allowed_runtime_class_namesListEntry, extensions_v1beta1_runtime_class_strategy_options->allowed_runtime_class_names) {
    if(cJSON_AddStringToObject(allowed_runtime_class_names, "", (char*)allowed_runtime_class_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // extensions_v1beta1_runtime_class_strategy_options->default_runtime_class_name
    if(extensions_v1beta1_runtime_class_strategy_options->default_runtime_class_name) { 
    if(cJSON_AddStringToObject(item, "defaultRuntimeClassName", extensions_v1beta1_runtime_class_strategy_options->default_runtime_class_name) == NULL) {
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

extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options_parseFromJSON(cJSON *extensions_v1beta1_runtime_class_strategy_optionsJSON){

    extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options_local_var = NULL;

    // extensions_v1beta1_runtime_class_strategy_options->allowed_runtime_class_names
    cJSON *allowed_runtime_class_names = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_runtime_class_strategy_optionsJSON, "allowedRuntimeClassNames");
    if (!allowed_runtime_class_names) {
        goto end;
    }

    list_t *allowed_runtime_class_namesList;
    
    cJSON *allowed_runtime_class_names_local;
    if(!cJSON_IsArray(allowed_runtime_class_names)) {
        goto end;//primitive container
    }
    allowed_runtime_class_namesList = list_create();

    cJSON_ArrayForEach(allowed_runtime_class_names_local, allowed_runtime_class_names)
    {
        if(!cJSON_IsString(allowed_runtime_class_names_local))
        {
            goto end;
        }
        list_addElement(allowed_runtime_class_namesList , strdup(allowed_runtime_class_names_local->valuestring));
    }

    // extensions_v1beta1_runtime_class_strategy_options->default_runtime_class_name
    cJSON *default_runtime_class_name = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_runtime_class_strategy_optionsJSON, "defaultRuntimeClassName");
    if (default_runtime_class_name) { 
    if(!cJSON_IsString(default_runtime_class_name))
    {
    goto end; //String
    }
    }


    extensions_v1beta1_runtime_class_strategy_options_local_var = extensions_v1beta1_runtime_class_strategy_options_create (
        allowed_runtime_class_namesList,
        default_runtime_class_name ? strdup(default_runtime_class_name->valuestring) : NULL
        );

    return extensions_v1beta1_runtime_class_strategy_options_local_var;
end:
    return NULL;

}
