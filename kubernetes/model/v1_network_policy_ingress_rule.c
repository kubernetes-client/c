#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_network_policy_ingress_rule.h"



static v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule_create_internal(
    list_t *from,
    list_t *ports
    ) {
    v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule_local_var = malloc(sizeof(v1_network_policy_ingress_rule_t));
    if (!v1_network_policy_ingress_rule_local_var) {
        return NULL;
    }
    v1_network_policy_ingress_rule_local_var->from = from;
    v1_network_policy_ingress_rule_local_var->ports = ports;

    v1_network_policy_ingress_rule_local_var->_library_owned = 1;
    return v1_network_policy_ingress_rule_local_var;
}

__attribute__((deprecated)) v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule_create(
    list_t *from,
    list_t *ports
    ) {
    return v1_network_policy_ingress_rule_create_internal (
        from,
        ports
        );
}

void v1_network_policy_ingress_rule_free(v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule) {
    if(NULL == v1_network_policy_ingress_rule){
        return ;
    }
    if(v1_network_policy_ingress_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_network_policy_ingress_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_network_policy_ingress_rule->from) {
        list_ForEach(listEntry, v1_network_policy_ingress_rule->from) {
            v1_network_policy_peer_free(listEntry->data);
        }
        list_freeList(v1_network_policy_ingress_rule->from);
        v1_network_policy_ingress_rule->from = NULL;
    }
    if (v1_network_policy_ingress_rule->ports) {
        list_ForEach(listEntry, v1_network_policy_ingress_rule->ports) {
            v1_network_policy_port_free(listEntry->data);
        }
        list_freeList(v1_network_policy_ingress_rule->ports);
        v1_network_policy_ingress_rule->ports = NULL;
    }
    free(v1_network_policy_ingress_rule);
}

cJSON *v1_network_policy_ingress_rule_convertToJSON(v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_network_policy_ingress_rule->from
    if(v1_network_policy_ingress_rule->from) {
    cJSON *from = cJSON_AddArrayToObject(item, "from");
    if(from == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *fromListEntry;
    if (v1_network_policy_ingress_rule->from) {
    list_ForEach(fromListEntry, v1_network_policy_ingress_rule->from) {
    cJSON *itemLocal = v1_network_policy_peer_convertToJSON(fromListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(from, itemLocal);
    }
    }
    }


    // v1_network_policy_ingress_rule->ports
    if(v1_network_policy_ingress_rule->ports) {
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1_network_policy_ingress_rule->ports) {
    list_ForEach(portsListEntry, v1_network_policy_ingress_rule->ports) {
    cJSON *itemLocal = v1_network_policy_port_convertToJSON(portsListEntry->data);
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

v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule_parseFromJSON(cJSON *v1_network_policy_ingress_ruleJSON){

    v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule_local_var = NULL;

    // define the local list for v1_network_policy_ingress_rule->from
    list_t *fromList = NULL;

    // define the local list for v1_network_policy_ingress_rule->ports
    list_t *portsList = NULL;

    // v1_network_policy_ingress_rule->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(v1_network_policy_ingress_ruleJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (from) { 
    cJSON *from_local_nonprimitive = NULL;
    if(!cJSON_IsArray(from)){
        goto end; //nonprimitive container
    }

    fromList = list_createList();

    cJSON_ArrayForEach(from_local_nonprimitive,from )
    {
        if(!cJSON_IsObject(from_local_nonprimitive)){
            goto end;
        }
        v1_network_policy_peer_t *fromItem = v1_network_policy_peer_parseFromJSON(from_local_nonprimitive);

        list_addElement(fromList, fromItem);
    }
    }

    // v1_network_policy_ingress_rule->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1_network_policy_ingress_ruleJSON, "ports");
    if (cJSON_IsNull(ports)) {
        ports = NULL;
    }
    if (ports) { 
    cJSON *ports_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ports)){
        goto end; //nonprimitive container
    }

    portsList = list_createList();

    cJSON_ArrayForEach(ports_local_nonprimitive,ports )
    {
        if(!cJSON_IsObject(ports_local_nonprimitive)){
            goto end;
        }
        v1_network_policy_port_t *portsItem = v1_network_policy_port_parseFromJSON(ports_local_nonprimitive);

        list_addElement(portsList, portsItem);
    }
    }


    v1_network_policy_ingress_rule_local_var = v1_network_policy_ingress_rule_create_internal (
        from ? fromList : NULL,
        ports ? portsList : NULL
        );

    return v1_network_policy_ingress_rule_local_var;
end:
    if (fromList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, fromList) {
            v1_network_policy_peer_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(fromList);
        fromList = NULL;
    }
    if (portsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, portsList) {
            v1_network_policy_port_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(portsList);
        portsList = NULL;
    }
    return NULL;

}
