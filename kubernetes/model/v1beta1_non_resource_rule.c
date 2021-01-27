#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_non_resource_rule.h"



v1beta1_non_resource_rule_t *v1beta1_non_resource_rule_create(
    list_t *non_resource_urls,
    list_t *verbs
    ) {
    v1beta1_non_resource_rule_t *v1beta1_non_resource_rule_local_var = malloc(sizeof(v1beta1_non_resource_rule_t));
    if (!v1beta1_non_resource_rule_local_var) {
        return NULL;
    }
    v1beta1_non_resource_rule_local_var->non_resource_urls = non_resource_urls;
    v1beta1_non_resource_rule_local_var->verbs = verbs;

    return v1beta1_non_resource_rule_local_var;
}


void v1beta1_non_resource_rule_free(v1beta1_non_resource_rule_t *v1beta1_non_resource_rule) {
    if(NULL == v1beta1_non_resource_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_non_resource_rule->non_resource_urls) {
        list_ForEach(listEntry, v1beta1_non_resource_rule->non_resource_urls) {
            free(listEntry->data);
        }
        list_free(v1beta1_non_resource_rule->non_resource_urls);
        v1beta1_non_resource_rule->non_resource_urls = NULL;
    }
    if (v1beta1_non_resource_rule->verbs) {
        list_ForEach(listEntry, v1beta1_non_resource_rule->verbs) {
            free(listEntry->data);
        }
        list_free(v1beta1_non_resource_rule->verbs);
        v1beta1_non_resource_rule->verbs = NULL;
    }
    free(v1beta1_non_resource_rule);
}

cJSON *v1beta1_non_resource_rule_convertToJSON(v1beta1_non_resource_rule_t *v1beta1_non_resource_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_non_resource_rule->non_resource_urls
    if(v1beta1_non_resource_rule->non_resource_urls) { 
    cJSON *non_resource_urls = cJSON_AddArrayToObject(item, "nonResourceURLs");
    if(non_resource_urls == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *non_resource_urlsListEntry;
    list_ForEach(non_resource_urlsListEntry, v1beta1_non_resource_rule->non_resource_urls) {
    if(cJSON_AddStringToObject(non_resource_urls, "", (char*)non_resource_urlsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1beta1_non_resource_rule->verbs
    if (!v1beta1_non_resource_rule->verbs) {
        goto fail;
    }
    
    cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1beta1_non_resource_rule->verbs) {
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

v1beta1_non_resource_rule_t *v1beta1_non_resource_rule_parseFromJSON(cJSON *v1beta1_non_resource_ruleJSON){

    v1beta1_non_resource_rule_t *v1beta1_non_resource_rule_local_var = NULL;

    // v1beta1_non_resource_rule->non_resource_urls
    cJSON *non_resource_urls = cJSON_GetObjectItemCaseSensitive(v1beta1_non_resource_ruleJSON, "nonResourceURLs");
    list_t *non_resource_urlsList;
    if (non_resource_urls) { 
    cJSON *non_resource_urls_local;
    if(!cJSON_IsArray(non_resource_urls)) {
        goto end;//primitive container
    }
    non_resource_urlsList = list_create();

    cJSON_ArrayForEach(non_resource_urls_local, non_resource_urls)
    {
        if(!cJSON_IsString(non_resource_urls_local))
        {
            goto end;
        }
        list_addElement(non_resource_urlsList , strdup(non_resource_urls_local->valuestring));
    }
    }

    // v1beta1_non_resource_rule->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v1beta1_non_resource_ruleJSON, "verbs");
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


    v1beta1_non_resource_rule_local_var = v1beta1_non_resource_rule_create (
        non_resource_urls ? non_resource_urlsList : NULL,
        verbsList
        );

    return v1beta1_non_resource_rule_local_var;
end:
    return NULL;

}
