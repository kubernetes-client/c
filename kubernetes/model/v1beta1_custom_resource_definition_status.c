#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_custom_resource_definition_status.h"



v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status_create(
    v1beta1_custom_resource_definition_names_t *accepted_names,
    list_t *conditions,
    list_t *stored_versions
    ) {
    v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status_local_var = malloc(sizeof(v1beta1_custom_resource_definition_status_t));
    if (!v1beta1_custom_resource_definition_status_local_var) {
        return NULL;
    }
    v1beta1_custom_resource_definition_status_local_var->accepted_names = accepted_names;
    v1beta1_custom_resource_definition_status_local_var->conditions = conditions;
    v1beta1_custom_resource_definition_status_local_var->stored_versions = stored_versions;

    return v1beta1_custom_resource_definition_status_local_var;
}


void v1beta1_custom_resource_definition_status_free(v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status) {
    if(NULL == v1beta1_custom_resource_definition_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_custom_resource_definition_status->accepted_names) {
        v1beta1_custom_resource_definition_names_free(v1beta1_custom_resource_definition_status->accepted_names);
        v1beta1_custom_resource_definition_status->accepted_names = NULL;
    }
    if (v1beta1_custom_resource_definition_status->conditions) {
        list_ForEach(listEntry, v1beta1_custom_resource_definition_status->conditions) {
            v1beta1_custom_resource_definition_condition_free(listEntry->data);
        }
        list_free(v1beta1_custom_resource_definition_status->conditions);
        v1beta1_custom_resource_definition_status->conditions = NULL;
    }
    if (v1beta1_custom_resource_definition_status->stored_versions) {
        list_ForEach(listEntry, v1beta1_custom_resource_definition_status->stored_versions) {
            free(listEntry->data);
        }
        list_free(v1beta1_custom_resource_definition_status->stored_versions);
        v1beta1_custom_resource_definition_status->stored_versions = NULL;
    }
    free(v1beta1_custom_resource_definition_status);
}

cJSON *v1beta1_custom_resource_definition_status_convertToJSON(v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_custom_resource_definition_status->accepted_names
    if (!v1beta1_custom_resource_definition_status->accepted_names) {
        goto fail;
    }
    
    cJSON *accepted_names_local_JSON = v1beta1_custom_resource_definition_names_convertToJSON(v1beta1_custom_resource_definition_status->accepted_names);
    if(accepted_names_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "acceptedNames", accepted_names_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta1_custom_resource_definition_status->conditions
    if(v1beta1_custom_resource_definition_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1beta1_custom_resource_definition_status->conditions) {
    list_ForEach(conditionsListEntry, v1beta1_custom_resource_definition_status->conditions) {
    cJSON *itemLocal = v1beta1_custom_resource_definition_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


    // v1beta1_custom_resource_definition_status->stored_versions
    if (!v1beta1_custom_resource_definition_status->stored_versions) {
        goto fail;
    }
    
    cJSON *stored_versions = cJSON_AddArrayToObject(item, "storedVersions");
    if(stored_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *stored_versionsListEntry;
    list_ForEach(stored_versionsListEntry, v1beta1_custom_resource_definition_status->stored_versions) {
    if(cJSON_AddStringToObject(stored_versions, "", (char*)stored_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status_parseFromJSON(cJSON *v1beta1_custom_resource_definition_statusJSON){

    v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status_local_var = NULL;

    // v1beta1_custom_resource_definition_status->accepted_names
    cJSON *accepted_names = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_statusJSON, "acceptedNames");
    if (!accepted_names) {
        goto end;
    }

    v1beta1_custom_resource_definition_names_t *accepted_names_local_nonprim = NULL;
    
    accepted_names_local_nonprim = v1beta1_custom_resource_definition_names_parseFromJSON(accepted_names); //nonprimitive

    // v1beta1_custom_resource_definition_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_statusJSON, "conditions");
    list_t *conditionsList;
    if (conditions) { 
    cJSON *conditions_local_nonprimitive;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_create();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1beta1_custom_resource_definition_condition_t *conditionsItem = v1beta1_custom_resource_definition_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1beta1_custom_resource_definition_status->stored_versions
    cJSON *stored_versions = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_statusJSON, "storedVersions");
    if (!stored_versions) {
        goto end;
    }

    list_t *stored_versionsList;
    
    cJSON *stored_versions_local;
    if(!cJSON_IsArray(stored_versions)) {
        goto end;//primitive container
    }
    stored_versionsList = list_create();

    cJSON_ArrayForEach(stored_versions_local, stored_versions)
    {
        if(!cJSON_IsString(stored_versions_local))
        {
            goto end;
        }
        list_addElement(stored_versionsList , strdup(stored_versions_local->valuestring));
    }


    v1beta1_custom_resource_definition_status_local_var = v1beta1_custom_resource_definition_status_create (
        accepted_names_local_nonprim,
        conditions ? conditionsList : NULL,
        stored_versionsList
        );

    return v1beta1_custom_resource_definition_status_local_var;
end:
    if (accepted_names_local_nonprim) {
        v1beta1_custom_resource_definition_names_free(accepted_names_local_nonprim);
        accepted_names_local_nonprim = NULL;
    }
    return NULL;

}
