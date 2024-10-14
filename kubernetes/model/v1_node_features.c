#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_features.h"



v1_node_features_t *v1_node_features_create(
    int supplemental_groups_policy
    ) {
    v1_node_features_t *v1_node_features_local_var = malloc(sizeof(v1_node_features_t));
    if (!v1_node_features_local_var) {
        return NULL;
    }
    v1_node_features_local_var->supplemental_groups_policy = supplemental_groups_policy;

    return v1_node_features_local_var;
}


void v1_node_features_free(v1_node_features_t *v1_node_features) {
    if(NULL == v1_node_features){
        return ;
    }
    listEntry_t *listEntry;
    free(v1_node_features);
}

cJSON *v1_node_features_convertToJSON(v1_node_features_t *v1_node_features) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_features->supplemental_groups_policy
    if(v1_node_features->supplemental_groups_policy) {
    if(cJSON_AddBoolToObject(item, "supplementalGroupsPolicy", v1_node_features->supplemental_groups_policy) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_node_features_t *v1_node_features_parseFromJSON(cJSON *v1_node_featuresJSON){

    v1_node_features_t *v1_node_features_local_var = NULL;

    // v1_node_features->supplemental_groups_policy
    cJSON *supplemental_groups_policy = cJSON_GetObjectItemCaseSensitive(v1_node_featuresJSON, "supplementalGroupsPolicy");
    if (supplemental_groups_policy) { 
    if(!cJSON_IsBool(supplemental_groups_policy))
    {
    goto end; //Bool
    }
    }


    v1_node_features_local_var = v1_node_features_create (
        supplemental_groups_policy ? supplemental_groups_policy->valueint : 0
        );

    return v1_node_features_local_var;
end:
    return NULL;

}
