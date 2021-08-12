#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_security_context.h"



v1_pod_security_context_t *v1_pod_security_context_create(
    long fs_group,
    long run_as_group,
    int run_as_non_root,
    long run_as_user,
    v1_se_linux_options_t *se_linux_options,
    list_t *supplemental_groups,
    list_t *sysctls,
    v1_windows_security_context_options_t *windows_options
    ) {
    v1_pod_security_context_t *v1_pod_security_context_local_var = malloc(sizeof(v1_pod_security_context_t));
    if (!v1_pod_security_context_local_var) {
        return NULL;
    }
    v1_pod_security_context_local_var->fs_group = fs_group;
    v1_pod_security_context_local_var->run_as_group = run_as_group;
    v1_pod_security_context_local_var->run_as_non_root = run_as_non_root;
    v1_pod_security_context_local_var->run_as_user = run_as_user;
    v1_pod_security_context_local_var->se_linux_options = se_linux_options;
    v1_pod_security_context_local_var->supplemental_groups = supplemental_groups;
    v1_pod_security_context_local_var->sysctls = sysctls;
    v1_pod_security_context_local_var->windows_options = windows_options;

    return v1_pod_security_context_local_var;
}


void v1_pod_security_context_free(v1_pod_security_context_t *v1_pod_security_context) {
    if(NULL == v1_pod_security_context){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_security_context->se_linux_options) {
        v1_se_linux_options_free(v1_pod_security_context->se_linux_options);
        v1_pod_security_context->se_linux_options = NULL;
    }
    if (v1_pod_security_context->supplemental_groups) {
        list_ForEach(listEntry, v1_pod_security_context->supplemental_groups) {
            free(listEntry->data);
        }
        list_free(v1_pod_security_context->supplemental_groups);
        v1_pod_security_context->supplemental_groups = NULL;
    }
    if (v1_pod_security_context->sysctls) {
        list_ForEach(listEntry, v1_pod_security_context->sysctls) {
            v1_sysctl_free(listEntry->data);
        }
        list_free(v1_pod_security_context->sysctls);
        v1_pod_security_context->sysctls = NULL;
    }
    if (v1_pod_security_context->windows_options) {
        v1_windows_security_context_options_free(v1_pod_security_context->windows_options);
        v1_pod_security_context->windows_options = NULL;
    }
    free(v1_pod_security_context);
}

cJSON *v1_pod_security_context_convertToJSON(v1_pod_security_context_t *v1_pod_security_context) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_security_context->fs_group
    if(v1_pod_security_context->fs_group) { 
    if(cJSON_AddNumberToObject(item, "fsGroup", v1_pod_security_context->fs_group) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_pod_security_context->run_as_group
    if(v1_pod_security_context->run_as_group) { 
    if(cJSON_AddNumberToObject(item, "runAsGroup", v1_pod_security_context->run_as_group) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_pod_security_context->run_as_non_root
    if(v1_pod_security_context->run_as_non_root) { 
    if(cJSON_AddBoolToObject(item, "runAsNonRoot", v1_pod_security_context->run_as_non_root) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_pod_security_context->run_as_user
    if(v1_pod_security_context->run_as_user) { 
    if(cJSON_AddNumberToObject(item, "runAsUser", v1_pod_security_context->run_as_user) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_pod_security_context->se_linux_options
    if(v1_pod_security_context->se_linux_options) { 
    cJSON *se_linux_options_local_JSON = v1_se_linux_options_convertToJSON(v1_pod_security_context->se_linux_options);
    if(se_linux_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "seLinuxOptions", se_linux_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_pod_security_context->supplemental_groups
    if(v1_pod_security_context->supplemental_groups) { 
    cJSON *supplemental_groups = cJSON_AddArrayToObject(item, "supplementalGroups");
    if(supplemental_groups == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *supplemental_groupsListEntry;
    list_ForEach(supplemental_groupsListEntry, v1_pod_security_context->supplemental_groups) {
    if(cJSON_AddNumberToObject(supplemental_groups, "", *(double *)supplemental_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_pod_security_context->sysctls
    if(v1_pod_security_context->sysctls) { 
    cJSON *sysctls = cJSON_AddArrayToObject(item, "sysctls");
    if(sysctls == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *sysctlsListEntry;
    if (v1_pod_security_context->sysctls) {
    list_ForEach(sysctlsListEntry, v1_pod_security_context->sysctls) {
    cJSON *itemLocal = v1_sysctl_convertToJSON(sysctlsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(sysctls, itemLocal);
    }
    }
     } 


    // v1_pod_security_context->windows_options
    if(v1_pod_security_context->windows_options) { 
    cJSON *windows_options_local_JSON = v1_windows_security_context_options_convertToJSON(v1_pod_security_context->windows_options);
    if(windows_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "windowsOptions", windows_options_local_JSON);
    if(item->child == NULL) {
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

v1_pod_security_context_t *v1_pod_security_context_parseFromJSON(cJSON *v1_pod_security_contextJSON){

    v1_pod_security_context_t *v1_pod_security_context_local_var = NULL;

    // v1_pod_security_context->fs_group
    cJSON *fs_group = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "fsGroup");
    if (fs_group) { 
    if(!cJSON_IsNumber(fs_group))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_security_context->run_as_group
    cJSON *run_as_group = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "runAsGroup");
    if (run_as_group) { 
    if(!cJSON_IsNumber(run_as_group))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_security_context->run_as_non_root
    cJSON *run_as_non_root = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "runAsNonRoot");
    if (run_as_non_root) { 
    if(!cJSON_IsBool(run_as_non_root))
    {
    goto end; //Bool
    }
    }

    // v1_pod_security_context->run_as_user
    cJSON *run_as_user = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "runAsUser");
    if (run_as_user) { 
    if(!cJSON_IsNumber(run_as_user))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_security_context->se_linux_options
    cJSON *se_linux_options = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "seLinuxOptions");
    v1_se_linux_options_t *se_linux_options_local_nonprim = NULL;
    if (se_linux_options) { 
    se_linux_options_local_nonprim = v1_se_linux_options_parseFromJSON(se_linux_options); //nonprimitive
    }

    // v1_pod_security_context->supplemental_groups
    cJSON *supplemental_groups = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "supplementalGroups");
    list_t *supplemental_groupsList;
    if (supplemental_groups) { 
    cJSON *supplemental_groups_local;
    if(!cJSON_IsArray(supplemental_groups)) {
        goto end;//primitive container
    }
    supplemental_groupsList = list_create();

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

    // v1_pod_security_context->sysctls
    cJSON *sysctls = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "sysctls");
    list_t *sysctlsList;
    if (sysctls) { 
    cJSON *sysctls_local_nonprimitive;
    if(!cJSON_IsArray(sysctls)){
        goto end; //nonprimitive container
    }

    sysctlsList = list_create();

    cJSON_ArrayForEach(sysctls_local_nonprimitive,sysctls )
    {
        if(!cJSON_IsObject(sysctls_local_nonprimitive)){
            goto end;
        }
        v1_sysctl_t *sysctlsItem = v1_sysctl_parseFromJSON(sysctls_local_nonprimitive);

        list_addElement(sysctlsList, sysctlsItem);
    }
    }

    // v1_pod_security_context->windows_options
    cJSON *windows_options = cJSON_GetObjectItemCaseSensitive(v1_pod_security_contextJSON, "windowsOptions");
    v1_windows_security_context_options_t *windows_options_local_nonprim = NULL;
    if (windows_options) { 
    windows_options_local_nonprim = v1_windows_security_context_options_parseFromJSON(windows_options); //nonprimitive
    }


    v1_pod_security_context_local_var = v1_pod_security_context_create (
        fs_group ? fs_group->valuedouble : 0,
        run_as_group ? run_as_group->valuedouble : 0,
        run_as_non_root ? run_as_non_root->valueint : 0,
        run_as_user ? run_as_user->valuedouble : 0,
        se_linux_options ? se_linux_options_local_nonprim : NULL,
        supplemental_groups ? supplemental_groupsList : NULL,
        sysctls ? sysctlsList : NULL,
        windows_options ? windows_options_local_nonprim : NULL
        );

    return v1_pod_security_context_local_var;
end:
    if (se_linux_options_local_nonprim) {
        v1_se_linux_options_free(se_linux_options_local_nonprim);
        se_linux_options_local_nonprim = NULL;
    }
    if (windows_options_local_nonprim) {
        v1_windows_security_context_options_free(windows_options_local_nonprim);
        windows_options_local_nonprim = NULL;
    }
    return NULL;

}
