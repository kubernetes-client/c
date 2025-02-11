#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_non_resource_rule.h"



static v1_non_resource_rule_t *v1_non_resource_rule_create_internal(
    list_t *non_resource_urls,
    list_t *verbs
    ) {
    v1_non_resource_rule_t *v1_non_resource_rule_local_var = malloc(sizeof(v1_non_resource_rule_t));
    if (!v1_non_resource_rule_local_var) {
        return NULL;
    }
    v1_non_resource_rule_local_var->non_resource_urls = non_resource_urls;
    v1_non_resource_rule_local_var->verbs = verbs;

    v1_non_resource_rule_local_var->_library_owned = 1;
    return v1_non_resource_rule_local_var;
}

__attribute__((deprecated)) v1_non_resource_rule_t *v1_non_resource_rule_create(
    list_t *non_resource_urls,
    list_t *verbs
    ) {
    return v1_non_resource_rule_create_internal (
        non_resource_urls,
        verbs
        );
}

void v1_non_resource_rule_free(v1_non_resource_rule_t *v1_non_resource_rule) {
    if(NULL == v1_non_resource_rule){
        return ;
    }
    if(v1_non_resource_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_non_resource_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_non_resource_rule->non_resource_urls) {
        list_ForEach(listEntry, v1_non_resource_rule->non_resource_urls) {
            free(listEntry->data);
        }
        list_freeList(v1_non_resource_rule->non_resource_urls);
        v1_non_resource_rule->non_resource_urls = NULL;
    }
    if (v1_non_resource_rule->verbs) {
        list_ForEach(listEntry, v1_non_resource_rule->verbs) {
            free(listEntry->data);
        }
        list_freeList(v1_non_resource_rule->verbs);
        v1_non_resource_rule->verbs = NULL;
    }
    free(v1_non_resource_rule);
}

cJSON *v1_non_resource_rule_convertToJSON(v1_non_resource_rule_t *v1_non_resource_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_non_resource_rule->non_resource_urls
    if(v1_non_resource_rule->non_resource_urls) {
    cJSON *non_resource_urls = cJSON_AddArrayToObject(item, "nonResourceURLs");
    if(non_resource_urls == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *non_resource_urlsListEntry;
    list_ForEach(non_resource_urlsListEntry, v1_non_resource_rule->non_resource_urls) {
    if(cJSON_AddStringToObject(non_resource_urls, "", non_resource_urlsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_non_resource_rule->verbs
    if (!v1_non_resource_rule->verbs) {
        goto fail;
    }
    cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
    if(verbs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1_non_resource_rule->verbs) {
    if(cJSON_AddStringToObject(verbs, "", verbsListEntry->data) == NULL)
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

v1_non_resource_rule_t *v1_non_resource_rule_parseFromJSON(cJSON *v1_non_resource_ruleJSON){

    v1_non_resource_rule_t *v1_non_resource_rule_local_var = NULL;

    // define the local list for v1_non_resource_rule->non_resource_urls
    list_t *non_resource_urlsList = NULL;

    // define the local list for v1_non_resource_rule->verbs
    list_t *verbsList = NULL;

    // v1_non_resource_rule->non_resource_urls
    cJSON *non_resource_urls = cJSON_GetObjectItemCaseSensitive(v1_non_resource_ruleJSON, "nonResourceURLs");
    if (cJSON_IsNull(non_resource_urls)) {
        non_resource_urls = NULL;
    }
    if (non_resource_urls) { 
    cJSON *non_resource_urls_local = NULL;
    if(!cJSON_IsArray(non_resource_urls)) {
        goto end;//primitive container
    }
    non_resource_urlsList = list_createList();

    cJSON_ArrayForEach(non_resource_urls_local, non_resource_urls)
    {
        if(!cJSON_IsString(non_resource_urls_local))
        {
            goto end;
        }
        list_addElement(non_resource_urlsList , strdup(non_resource_urls_local->valuestring));
    }
    }

    // v1_non_resource_rule->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v1_non_resource_ruleJSON, "verbs");
    if (cJSON_IsNull(verbs)) {
        verbs = NULL;
    }
    if (!verbs) {
        goto end;
    }

    
    cJSON *verbs_local = NULL;
    if(!cJSON_IsArray(verbs)) {
        goto end;//primitive container
    }
    verbsList = list_createList();

    cJSON_ArrayForEach(verbs_local, verbs)
    {
        if(!cJSON_IsString(verbs_local))
        {
            goto end;
        }
        list_addElement(verbsList , strdup(verbs_local->valuestring));
    }


    v1_non_resource_rule_local_var = v1_non_resource_rule_create_internal (
        non_resource_urls ? non_resource_urlsList : NULL,
        verbsList
        );

    return v1_non_resource_rule_local_var;
end:
    if (non_resource_urlsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, non_resource_urlsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(non_resource_urlsList);
        non_resource_urlsList = NULL;
    }
    if (verbsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, verbsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(verbsList);
        verbsList = NULL;
    }
    return NULL;

}
