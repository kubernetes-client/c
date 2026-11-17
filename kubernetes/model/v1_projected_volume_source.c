#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_projected_volume_source.h"



static v1_projected_volume_source_t *v1_projected_volume_source_create_internal(
    int *default_mode,
    long *default_user,
    list_t *sources
    ) {
    v1_projected_volume_source_t *v1_projected_volume_source_local_var = malloc(sizeof(v1_projected_volume_source_t));
    if (!v1_projected_volume_source_local_var) {
        return NULL;
    }
    memset(v1_projected_volume_source_local_var, 0, sizeof(v1_projected_volume_source_t));
    v1_projected_volume_source_local_var->_library_owned = 1;
    v1_projected_volume_source_local_var->default_mode = default_mode;
    v1_projected_volume_source_local_var->default_user = default_user;
    v1_projected_volume_source_local_var->sources = sources;
    return v1_projected_volume_source_local_var;
}

__attribute__((deprecated)) v1_projected_volume_source_t *v1_projected_volume_source_create(
    int *default_mode,
    long *default_user,
    list_t *sources
    ) {
    int *default_mode_copy = NULL;
    if (default_mode) {
        default_mode_copy = malloc(sizeof(int));
        if (default_mode_copy) *default_mode_copy = *default_mode;
    }
    long *default_user_copy = NULL;
    if (default_user) {
        default_user_copy = malloc(sizeof(long));
        if (default_user_copy) *default_user_copy = *default_user;
    }
    v1_projected_volume_source_t *result = v1_projected_volume_source_create_internal (
        default_mode_copy,
        default_user_copy,
        sources
        );
    if (!result) {
        free(default_mode_copy);
        free(default_user_copy);
    }
    return result;
}

void v1_projected_volume_source_free(v1_projected_volume_source_t *v1_projected_volume_source) {
    if(NULL == v1_projected_volume_source){
        return ;
    }
    if(v1_projected_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_projected_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_projected_volume_source->default_mode) {
        free(v1_projected_volume_source->default_mode);
        v1_projected_volume_source->default_mode = NULL;
    }
    if (v1_projected_volume_source->default_user) {
        free(v1_projected_volume_source->default_user);
        v1_projected_volume_source->default_user = NULL;
    }
    if (v1_projected_volume_source->sources) {
        list_ForEach(listEntry, v1_projected_volume_source->sources) {
            v1_volume_projection_free(listEntry->data);
        }
        list_freeList(v1_projected_volume_source->sources);
        v1_projected_volume_source->sources = NULL;
    }
    free(v1_projected_volume_source);
}

cJSON *v1_projected_volume_source_convertToJSON(v1_projected_volume_source_t *v1_projected_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_projected_volume_source->default_mode
    if(v1_projected_volume_source->default_mode) {
    if(cJSON_AddNumberToObject(item, "defaultMode", *v1_projected_volume_source->default_mode) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_projected_volume_source->default_user
    if(v1_projected_volume_source->default_user) {
    if(cJSON_AddNumberToObject(item, "defaultUser", *v1_projected_volume_source->default_user) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_projected_volume_source->sources
    if(v1_projected_volume_source->sources) {
    cJSON *sources = cJSON_AddArrayToObject(item, "sources");
    if(sources == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *sourcesListEntry;
    if (v1_projected_volume_source->sources) {
    list_ForEach(sourcesListEntry, v1_projected_volume_source->sources) {
    cJSON *itemLocal = v1_volume_projection_convertToJSON(sourcesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(sources, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_projected_volume_source_t *v1_projected_volume_source_parseFromJSON(cJSON *v1_projected_volume_sourceJSON){

    v1_projected_volume_source_t *v1_projected_volume_source_local_var = NULL;

    // define the local variable for v1_projected_volume_source->default_mode
    int *default_mode_local_var = NULL;

    // define the local variable for v1_projected_volume_source->default_user
    long *default_user_local_var = NULL;

    // define the local list for v1_projected_volume_source->sources
    list_t *sourcesList = NULL;

    // v1_projected_volume_source->default_mode
    cJSON *default_mode = cJSON_GetObjectItemCaseSensitive(v1_projected_volume_sourceJSON, "defaultMode");
    if (cJSON_IsNull(default_mode)) {
        default_mode = NULL;
    }
    if (default_mode) { 
    if(!cJSON_IsNumber(default_mode))
    {
    goto end; //Numeric
    }
    default_mode_local_var = malloc(sizeof(int));
    if(!default_mode_local_var)
    {
        goto end;
    }
    *default_mode_local_var = default_mode->valuedouble;
    }

    // v1_projected_volume_source->default_user
    cJSON *default_user = cJSON_GetObjectItemCaseSensitive(v1_projected_volume_sourceJSON, "defaultUser");
    if (cJSON_IsNull(default_user)) {
        default_user = NULL;
    }
    if (default_user) { 
    if(!cJSON_IsNumber(default_user))
    {
    goto end; //Numeric
    }
    default_user_local_var = malloc(sizeof(long));
    if(!default_user_local_var)
    {
        goto end;
    }
    *default_user_local_var = default_user->valuedouble;
    }

    // v1_projected_volume_source->sources
    cJSON *sources = cJSON_GetObjectItemCaseSensitive(v1_projected_volume_sourceJSON, "sources");
    if (cJSON_IsNull(sources)) {
        sources = NULL;
    }
    if (sources) { 
    cJSON *sources_local_nonprimitive = NULL;
    if(!cJSON_IsArray(sources)){
        goto end; //nonprimitive container
    }

    sourcesList = list_createList();

    cJSON_ArrayForEach(sources_local_nonprimitive,sources )
    {
        if(!cJSON_IsObject(sources_local_nonprimitive)){
            goto end;
        }
        v1_volume_projection_t *sourcesItem = v1_volume_projection_parseFromJSON(sources_local_nonprimitive);

        list_addElement(sourcesList, sourcesItem);
    }
    }



    v1_projected_volume_source_local_var = v1_projected_volume_source_create_internal (
        default_mode_local_var,
        default_user_local_var,
        sources ? sourcesList : NULL
        );

    if (!v1_projected_volume_source_local_var) {
        goto end;
    }

    return v1_projected_volume_source_local_var;
end:
    if (default_mode_local_var) {
        free(default_mode_local_var);
        default_mode_local_var = NULL;
    }
    if (default_user_local_var) {
        free(default_user_local_var);
        default_user_local_var = NULL;
    }
    if (sourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, sourcesList) {
            v1_volume_projection_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(sourcesList);
        sourcesList = NULL;
    }
    return NULL;

}
