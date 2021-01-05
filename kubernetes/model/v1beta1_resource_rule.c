#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_resource_rule.h"



v1beta1_resource_rule_t *v1beta1_resource_rule_create(
    list_t *api_groups,
    list_t *resource_names,
    list_t *resources,
    list_t *verbs
    ) {
    v1beta1_resource_rule_t *v1beta1_resource_rule_local_var = malloc(sizeof(v1beta1_resource_rule_t));
    if (!v1beta1_resource_rule_local_var) {
        return NULL;
    }
    v1beta1_resource_rule_local_var->api_groups = api_groups;
    v1beta1_resource_rule_local_var->resource_names = resource_names;
    v1beta1_resource_rule_local_var->resources = resources;
    v1beta1_resource_rule_local_var->verbs = verbs;

    return v1beta1_resource_rule_local_var;
}


void v1beta1_resource_rule_free(v1beta1_resource_rule_t *v1beta1_resource_rule) {
    if(NULL == v1beta1_resource_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_resource_rule->api_groups) {
        list_ForEach(listEntry, v1beta1_resource_rule->api_groups) {
            free(listEntry->data);
        }
        list_free(v1beta1_resource_rule->api_groups);
        v1beta1_resource_rule->api_groups = NULL;
    }
    if (v1beta1_resource_rule->resource_names) {
        list_ForEach(listEntry, v1beta1_resource_rule->resource_names) {
            free(listEntry->data);
        }
        list_free(v1beta1_resource_rule->resource_names);
        v1beta1_resource_rule->resource_names = NULL;
    }
    if (v1beta1_resource_rule->resources) {
        list_ForEach(listEntry, v1beta1_resource_rule->resources) {
            free(listEntry->data);
        }
        list_free(v1beta1_resource_rule->resources);
        v1beta1_resource_rule->resources = NULL;
    }
    if (v1beta1_resource_rule->verbs) {
        list_ForEach(listEntry, v1beta1_resource_rule->verbs) {
            free(listEntry->data);
        }
        list_free(v1beta1_resource_rule->verbs);
        v1beta1_resource_rule->verbs = NULL;
    }
    free(v1beta1_resource_rule);
}

cJSON *v1beta1_resource_rule_convertToJSON(v1beta1_resource_rule_t *v1beta1_resource_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_resource_rule->api_groups
    if(v1beta1_resource_rule->api_groups) { 
    cJSON *api_groups = cJSON_AddArrayToObject(item, "apiGroups");
    if(api_groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *api_groupsListEntry;
    list_ForEach(api_groupsListEntry, v1beta1_resource_rule->api_groups) {
    if(cJSON_AddStringToObject(api_groups, "", (char*)api_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_resource_rule->resource_names
    if(v1beta1_resource_rule->resource_names) { 
    cJSON *resource_names = cJSON_AddArrayToObject(item, "resourceNames");
    if(resource_names == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *resource_namesListEntry;
    list_ForEach(resource_namesListEntry, v1beta1_resource_rule->resource_names) {
    if(cJSON_AddStringToObject(resource_names, "", (char*)resource_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_resource_rule->resources
    if(v1beta1_resource_rule->resources) { 
    cJSON *resources = cJSON_AddArrayToObject(item, "resources");
    if(resources == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *resourcesListEntry;
    list_ForEach(resourcesListEntry, v1beta1_resource_rule->resources) {
    if(cJSON_AddStringToObject(resources, "", (char*)resourcesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_resource_rule->verbs
    if (!v1beta1_resource_rule->verbs) {
        goto fail;
    }
    
    cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1beta1_resource_rule->verbs) {
    if(cJSON_AddStringToObject(verbs, "", (char*)verbsListEntry->data) == NULL)
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

v1beta1_resource_rule_t *v1beta1_resource_rule_parseFromJSON(cJSON *v1beta1_resource_ruleJSON){

    v1beta1_resource_rule_t *v1beta1_resource_rule_local_var = NULL;

    // v1beta1_resource_rule->api_groups
    cJSON *api_groups = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_ruleJSON, "apiGroups");
    list_t *api_groupsList;
    if (api_groups) { 
    cJSON *api_groups_local;
    if(!cJSON_IsArray(api_groups)) {
        goto end;//primitive container
    }
    api_groupsList = list_create();

    cJSON_ArrayForEach(api_groups_local, api_groups)
    {
        if(!cJSON_IsString(api_groups_local))
        {
            goto end;
        }
        list_addElement(api_groupsList , strdup(api_groups_local->valuestring));
    }
    }

    // v1beta1_resource_rule->resource_names
    cJSON *resource_names = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_ruleJSON, "resourceNames");
    list_t *resource_namesList;
    if (resource_names) { 
    cJSON *resource_names_local;
    if(!cJSON_IsArray(resource_names)) {
        goto end;//primitive container
    }
    resource_namesList = list_create();

    cJSON_ArrayForEach(resource_names_local, resource_names)
    {
        if(!cJSON_IsString(resource_names_local))
        {
            goto end;
        }
        list_addElement(resource_namesList , strdup(resource_names_local->valuestring));
    }
    }

    // v1beta1_resource_rule->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_ruleJSON, "resources");
    list_t *resourcesList;
    if (resources) { 
    cJSON *resources_local;
    if(!cJSON_IsArray(resources)) {
        goto end;//primitive container
    }
    resourcesList = list_create();

    cJSON_ArrayForEach(resources_local, resources)
    {
        if(!cJSON_IsString(resources_local))
        {
            goto end;
        }
        list_addElement(resourcesList , strdup(resources_local->valuestring));
    }
    }

    // v1beta1_resource_rule->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_ruleJSON, "verbs");
    if (!verbs) {
        goto end;
    }

    list_t *verbsList;
    
    cJSON *verbs_local;
    if(!cJSON_IsArray(verbs)) {
        goto end;//primitive container
    }
    verbsList = list_create();

    cJSON_ArrayForEach(verbs_local, verbs)
    {
        if(!cJSON_IsString(verbs_local))
        {
            goto end;
        }
        list_addElement(verbsList , strdup(verbs_local->valuestring));
    }


    v1beta1_resource_rule_local_var = v1beta1_resource_rule_create (
        api_groups ? api_groupsList : NULL,
        resource_names ? resource_namesList : NULL,
        resources ? resourcesList : NULL,
        verbsList
        );

    return v1beta1_resource_rule_local_var;
end:
    return NULL;

}
