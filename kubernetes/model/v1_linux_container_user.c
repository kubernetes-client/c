#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_linux_container_user.h"



v1_linux_container_user_t *v1_linux_container_user_create(
    long gid,
    list_t *supplemental_groups,
    long uid
    ) {
    v1_linux_container_user_t *v1_linux_container_user_local_var = malloc(sizeof(v1_linux_container_user_t));
    if (!v1_linux_container_user_local_var) {
        return NULL;
    }
    v1_linux_container_user_local_var->gid = gid;
    v1_linux_container_user_local_var->supplemental_groups = supplemental_groups;
    v1_linux_container_user_local_var->uid = uid;

    return v1_linux_container_user_local_var;
}


void v1_linux_container_user_free(v1_linux_container_user_t *v1_linux_container_user) {
    if(NULL == v1_linux_container_user){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_linux_container_user->supplemental_groups) {
        list_ForEach(listEntry, v1_linux_container_user->supplemental_groups) {
            free(listEntry->data);
        }
        list_freeList(v1_linux_container_user->supplemental_groups);
        v1_linux_container_user->supplemental_groups = NULL;
    }
    free(v1_linux_container_user);
}

cJSON *v1_linux_container_user_convertToJSON(v1_linux_container_user_t *v1_linux_container_user) {
    cJSON *item = cJSON_CreateObject();

    // v1_linux_container_user->gid
    if (!v1_linux_container_user->gid) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "gid", v1_linux_container_user->gid) == NULL) {
    goto fail; //Numeric
    }


    // v1_linux_container_user->supplemental_groups
    if(v1_linux_container_user->supplemental_groups) {
    cJSON *supplemental_groups = cJSON_AddArrayToObject(item, "supplementalGroups");
    if(supplemental_groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *supplemental_groupsListEntry;
    list_ForEach(supplemental_groupsListEntry, v1_linux_container_user->supplemental_groups) {
    if(cJSON_AddNumberToObject(supplemental_groups, "", *(double *)supplemental_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_linux_container_user->uid
    if (!v1_linux_container_user->uid) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "uid", v1_linux_container_user->uid) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_linux_container_user_t *v1_linux_container_user_parseFromJSON(cJSON *v1_linux_container_userJSON){

    v1_linux_container_user_t *v1_linux_container_user_local_var = NULL;

    // define the local list for v1_linux_container_user->supplemental_groups
    list_t *supplemental_groupsList = NULL;

    // v1_linux_container_user->gid
    cJSON *gid = cJSON_GetObjectItemCaseSensitive(v1_linux_container_userJSON, "gid");
    if (!gid) {
        goto end;
    }

    
    if(!cJSON_IsNumber(gid))
    {
    goto end; //Numeric
    }

    // v1_linux_container_user->supplemental_groups
    cJSON *supplemental_groups = cJSON_GetObjectItemCaseSensitive(v1_linux_container_userJSON, "supplementalGroups");
    if (supplemental_groups) { 
    cJSON *supplemental_groups_local = NULL;
    if(!cJSON_IsArray(supplemental_groups)) {
        goto end;//primitive container
    }
    supplemental_groupsList = list_createList();

    cJSON_ArrayForEach(supplemental_groups_local, supplemental_groups)
    {
        if(!cJSON_IsNumber(supplemental_groups_local))
        {
            goto end;
        }
        double *supplemental_groups_local_value = (double *)calloc(1, sizeof(double));
        if(!supplemental_groups_local_value)
        {
            goto end;
        }
        *supplemental_groups_local_value = supplemental_groups_local->valuedouble;
        list_addElement(supplemental_groupsList , supplemental_groups_local_value);
    }
    }

    // v1_linux_container_user->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_linux_container_userJSON, "uid");
    if (!uid) {
        goto end;
    }

    
    if(!cJSON_IsNumber(uid))
    {
    goto end; //Numeric
    }


    v1_linux_container_user_local_var = v1_linux_container_user_create (
        gid->valuedouble,
        supplemental_groups ? supplemental_groupsList : NULL,
        uid->valuedouble
        );

    return v1_linux_container_user_local_var;
end:
    if (supplemental_groupsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, supplemental_groupsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(supplemental_groupsList);
        supplemental_groupsList = NULL;
    }
    return NULL;

}
