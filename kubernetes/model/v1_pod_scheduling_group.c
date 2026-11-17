#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_scheduling_group.h"



static v1_pod_scheduling_group_t *v1_pod_scheduling_group_create_internal(
    char *pod_group_name
    ) {
    v1_pod_scheduling_group_t *v1_pod_scheduling_group_local_var = malloc(sizeof(v1_pod_scheduling_group_t));
    if (!v1_pod_scheduling_group_local_var) {
        return NULL;
    }
    memset(v1_pod_scheduling_group_local_var, 0, sizeof(v1_pod_scheduling_group_t));
    v1_pod_scheduling_group_local_var->_library_owned = 1;
    v1_pod_scheduling_group_local_var->pod_group_name = pod_group_name;
    return v1_pod_scheduling_group_local_var;
}

__attribute__((deprecated)) v1_pod_scheduling_group_t *v1_pod_scheduling_group_create(
    char *pod_group_name
    ) {
    v1_pod_scheduling_group_t *result = v1_pod_scheduling_group_create_internal (
        pod_group_name
        );
    if (!result) {
    }
    return result;
}

void v1_pod_scheduling_group_free(v1_pod_scheduling_group_t *v1_pod_scheduling_group) {
    if(NULL == v1_pod_scheduling_group){
        return ;
    }
    if(v1_pod_scheduling_group->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_scheduling_group_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_scheduling_group->pod_group_name) {
        free(v1_pod_scheduling_group->pod_group_name);
        v1_pod_scheduling_group->pod_group_name = NULL;
    }
    free(v1_pod_scheduling_group);
}

cJSON *v1_pod_scheduling_group_convertToJSON(v1_pod_scheduling_group_t *v1_pod_scheduling_group) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_scheduling_group->pod_group_name
    if(v1_pod_scheduling_group->pod_group_name) {
    if(cJSON_AddStringToObject(item, "podGroupName", v1_pod_scheduling_group->pod_group_name) == NULL) {
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

v1_pod_scheduling_group_t *v1_pod_scheduling_group_parseFromJSON(cJSON *v1_pod_scheduling_groupJSON){

    v1_pod_scheduling_group_t *v1_pod_scheduling_group_local_var = NULL;

    char *pod_group_name_local_str = NULL;

    // v1_pod_scheduling_group->pod_group_name
    cJSON *pod_group_name = cJSON_GetObjectItemCaseSensitive(v1_pod_scheduling_groupJSON, "podGroupName");
    if (cJSON_IsNull(pod_group_name)) {
        pod_group_name = NULL;
    }
    if (pod_group_name) { 
    if(!cJSON_IsString(pod_group_name) && !cJSON_IsNull(pod_group_name))
    {
    goto end; //String
    }
    }


    if (pod_group_name && !cJSON_IsNull(pod_group_name)) pod_group_name_local_str = strdup(pod_group_name->valuestring);

    v1_pod_scheduling_group_local_var = v1_pod_scheduling_group_create_internal (
        pod_group_name_local_str
        );

    if (!v1_pod_scheduling_group_local_var) {
        goto end;
    }

    return v1_pod_scheduling_group_local_var;
end:
    if (pod_group_name_local_str) {
        free(pod_group_name_local_str);
        pod_group_name_local_str = NULL;
    }
    return NULL;

}
