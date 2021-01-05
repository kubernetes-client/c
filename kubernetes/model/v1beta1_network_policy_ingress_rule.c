#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_network_policy_ingress_rule.h"



v1beta1_network_policy_ingress_rule_t *v1beta1_network_policy_ingress_rule_create(
    list_t *from,
    list_t *ports
    ) {
    v1beta1_network_policy_ingress_rule_t *v1beta1_network_policy_ingress_rule_local_var = malloc(sizeof(v1beta1_network_policy_ingress_rule_t));
    if (!v1beta1_network_policy_ingress_rule_local_var) {
        return NULL;
    }
    v1beta1_network_policy_ingress_rule_local_var->from = from;
    v1beta1_network_policy_ingress_rule_local_var->ports = ports;

    return v1beta1_network_policy_ingress_rule_local_var;
}


void v1beta1_network_policy_ingress_rule_free(v1beta1_network_policy_ingress_rule_t *v1beta1_network_policy_ingress_rule) {
    if(NULL == v1beta1_network_policy_ingress_rule){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_network_policy_ingress_rule->from) {
        list_ForEach(listEntry, v1beta1_network_policy_ingress_rule->from) {
            v1beta1_network_policy_peer_free(listEntry->data);
        }
        list_free(v1beta1_network_policy_ingress_rule->from);
        v1beta1_network_policy_ingress_rule->from = NULL;
    }
    if (v1beta1_network_policy_ingress_rule->ports) {
        list_ForEach(listEntry, v1beta1_network_policy_ingress_rule->ports) {
            v1beta1_network_policy_port_free(listEntry->data);
        }
        list_free(v1beta1_network_policy_ingress_rule->ports);
        v1beta1_network_policy_ingress_rule->ports = NULL;
    }
    free(v1beta1_network_policy_ingress_rule);
}

cJSON *v1beta1_network_policy_ingress_rule_convertToJSON(v1beta1_network_policy_ingress_rule_t *v1beta1_network_policy_ingress_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_network_policy_ingress_rule->from
    if(v1beta1_network_policy_ingress_rule->from) { 
    cJSON *from = cJSON_AddArrayToObject(item, "from");
    if(from == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *fromListEntry;
    if (v1beta1_network_policy_ingress_rule->from) {
    list_ForEach(fromListEntry, v1beta1_network_policy_ingress_rule->from) {
    cJSON *itemLocal = v1beta1_network_policy_peer_convertToJSON(fromListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(from, itemLocal);
    }
    }
     } 


    // v1beta1_network_policy_ingress_rule->ports
    if(v1beta1_network_policy_ingress_rule->ports) { 
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1beta1_network_policy_ingress_rule->ports) {
    list_ForEach(portsListEntry, v1beta1_network_policy_ingress_rule->ports) {
    cJSON *itemLocal = v1beta1_network_policy_port_convertToJSON(portsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ports, itemLocal);
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

v1beta1_network_policy_ingress_rule_t *v1beta1_network_policy_ingress_rule_parseFromJSON(cJSON *v1beta1_network_policy_ingress_ruleJSON){

    v1beta1_network_policy_ingress_rule_t *v1beta1_network_policy_ingress_rule_local_var = NULL;

    // v1beta1_network_policy_ingress_rule->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policy_ingress_ruleJSON, "from");
    list_t *fromList;
    if (from) { 
    cJSON *from_local_nonprimitive;
    if(!cJSON_IsArray(from)){
        goto end; //nonprimitive container
    }

    fromList = list_create();

    cJSON_ArrayForEach(from_local_nonprimitive,from )
    {
        if(!cJSON_IsObject(from_local_nonprimitive)){
            goto end;
        }
        v1beta1_network_policy_peer_t *fromItem = v1beta1_network_policy_peer_parseFromJSON(from_local_nonprimitive);

        list_addElement(fromList, fromItem);
    }
    }

    // v1beta1_network_policy_ingress_rule->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policy_ingress_ruleJSON, "ports");
    list_t *portsList;
    if (ports) { 
    cJSON *ports_local_nonprimitive;
    if(!cJSON_IsArray(ports)){
        goto end; //nonprimitive container
    }

    portsList = list_create();

    cJSON_ArrayForEach(ports_local_nonprimitive,ports )
    {
        if(!cJSON_IsObject(ports_local_nonprimitive)){
            goto end;
        }
        v1beta1_network_policy_port_t *portsItem = v1beta1_network_policy_port_parseFromJSON(ports_local_nonprimitive);

        list_addElement(portsList, portsItem);
    }
    }


    v1beta1_network_policy_ingress_rule_local_var = v1beta1_network_policy_ingress_rule_create (
        from ? fromList : NULL,
        ports ? portsList : NULL
        );

    return v1beta1_network_policy_ingress_rule_local_var;
end:
    return NULL;

}
