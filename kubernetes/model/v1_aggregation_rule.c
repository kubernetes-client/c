#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_aggregation_rule.h"



v1_aggregation_rule_t *v1_aggregation_rule_create(
    list_t *cluster_role_selectors
    ) {
    v1_aggregation_rule_t *v1_aggregation_rule_local_var = malloc(sizeof(v1_aggregation_rule_t));
    if (!v1_aggregation_rule_local_var) {
        return NULL;
    }
    v1_aggregation_rule_local_var->cluster_role_selectors = cluster_role_selectors;

    return v1_aggregation_rule_local_var;
}


void v1_aggregation_rule_free(v1_aggregation_rule_t *v1_aggregation_rule) {
    if(NULL == v1_aggregation_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_aggregation_rule->cluster_role_selectors) {
        list_ForEach(listEntry, v1_aggregation_rule->cluster_role_selectors) {
            v1_label_selector_free(listEntry->data);
        }
        list_free(v1_aggregation_rule->cluster_role_selectors);
        v1_aggregation_rule->cluster_role_selectors = NULL;
    }
    free(v1_aggregation_rule);
}

cJSON *v1_aggregation_rule_convertToJSON(v1_aggregation_rule_t *v1_aggregation_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_aggregation_rule->cluster_role_selectors
    if(v1_aggregation_rule->cluster_role_selectors) { 
    cJSON *cluster_role_selectors = cJSON_AddArrayToObject(item, "clusterRoleSelectors");
    if(cluster_role_selectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *cluster_role_selectorsListEntry;
    if (v1_aggregation_rule->cluster_role_selectors) {
    list_ForEach(cluster_role_selectorsListEntry, v1_aggregation_rule->cluster_role_selectors) {
    cJSON *itemLocal = v1_label_selector_convertToJSON(cluster_role_selectorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(cluster_role_selectors, itemLocal);
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

v1_aggregation_rule_t *v1_aggregation_rule_parseFromJSON(cJSON *v1_aggregation_ruleJSON){

    v1_aggregation_rule_t *v1_aggregation_rule_local_var = NULL;

    // v1_aggregation_rule->cluster_role_selectors
    cJSON *cluster_role_selectors = cJSON_GetObjectItemCaseSensitive(v1_aggregation_ruleJSON, "clusterRoleSelectors");
    list_t *cluster_role_selectorsList;
    if (cluster_role_selectors) { 
    cJSON *cluster_role_selectors_local_nonprimitive;
    if(!cJSON_IsArray(cluster_role_selectors)){
        goto end; //nonprimitive container
    }

    cluster_role_selectorsList = list_create();

    cJSON_ArrayForEach(cluster_role_selectors_local_nonprimitive,cluster_role_selectors )
    {
        if(!cJSON_IsObject(cluster_role_selectors_local_nonprimitive)){
            goto end;
        }
        v1_label_selector_t *cluster_role_selectorsItem = v1_label_selector_parseFromJSON(cluster_role_selectors_local_nonprimitive);

        list_addElement(cluster_role_selectorsList, cluster_role_selectorsItem);
    }
    }


    v1_aggregation_rule_local_var = v1_aggregation_rule_create (
        cluster_role_selectors ? cluster_role_selectorsList : NULL
        );

    return v1_aggregation_rule_local_var;
end:
    return NULL;

}
