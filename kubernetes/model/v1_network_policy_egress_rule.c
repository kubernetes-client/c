#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_network_policy_egress_rule.h"



static v1_network_policy_egress_rule_t *v1_network_policy_egress_rule_create_internal(
    list_t *ports,
    list_t *to
    ) {
    v1_network_policy_egress_rule_t *v1_network_policy_egress_rule_local_var = malloc(sizeof(v1_network_policy_egress_rule_t));
    if (!v1_network_policy_egress_rule_local_var) {
        return NULL;
    }
    v1_network_policy_egress_rule_local_var->ports = ports;
    v1_network_policy_egress_rule_local_var->to = to;

    v1_network_policy_egress_rule_local_var->_library_owned = 1;
    return v1_network_policy_egress_rule_local_var;
}

__attribute__((deprecated)) v1_network_policy_egress_rule_t *v1_network_policy_egress_rule_create(
    list_t *ports,
    list_t *to
    ) {
    return v1_network_policy_egress_rule_create_internal (
        ports,
        to
        );
}

void v1_network_policy_egress_rule_free(v1_network_policy_egress_rule_t *v1_network_policy_egress_rule) {
    if(NULL == v1_network_policy_egress_rule){
        return ;
    }
    if(v1_network_policy_egress_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_network_policy_egress_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_network_policy_egress_rule->ports) {
        list_ForEach(listEntry, v1_network_policy_egress_rule->ports) {
            v1_network_policy_port_free(listEntry->data);
        }
        list_freeList(v1_network_policy_egress_rule->ports);
        v1_network_policy_egress_rule->ports = NULL;
    }
    if (v1_network_policy_egress_rule->to) {
        list_ForEach(listEntry, v1_network_policy_egress_rule->to) {
            v1_network_policy_peer_free(listEntry->data);
        }
        list_freeList(v1_network_policy_egress_rule->to);
        v1_network_policy_egress_rule->to = NULL;
    }
    free(v1_network_policy_egress_rule);
}

cJSON *v1_network_policy_egress_rule_convertToJSON(v1_network_policy_egress_rule_t *v1_network_policy_egress_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1_network_policy_egress_rule->ports
    if(v1_network_policy_egress_rule->ports) {
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1_network_policy_egress_rule->ports) {
    list_ForEach(portsListEntry, v1_network_policy_egress_rule->ports) {
    cJSON *itemLocal = v1_network_policy_port_convertToJSON(portsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ports, itemLocal);
    }
    }
    }


    // v1_network_policy_egress_rule->to
    if(v1_network_policy_egress_rule->to) {
    cJSON *to = cJSON_AddArrayToObject(item, "to");
    if(to == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *toListEntry;
    if (v1_network_policy_egress_rule->to) {
    list_ForEach(toListEntry, v1_network_policy_egress_rule->to) {
    cJSON *itemLocal = v1_network_policy_peer_convertToJSON(toListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(to, itemLocal);
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

v1_network_policy_egress_rule_t *v1_network_policy_egress_rule_parseFromJSON(cJSON *v1_network_policy_egress_ruleJSON){

    v1_network_policy_egress_rule_t *v1_network_policy_egress_rule_local_var = NULL;

    // define the local list for v1_network_policy_egress_rule->ports
    list_t *portsList = NULL;

    // define the local list for v1_network_policy_egress_rule->to
    list_t *toList = NULL;

    // v1_network_policy_egress_rule->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1_network_policy_egress_ruleJSON, "ports");
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

    // v1_network_policy_egress_rule->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(v1_network_policy_egress_ruleJSON, "to");
    if (cJSON_IsNull(to)) {
        to = NULL;
    }
    if (to) { 
    cJSON *to_local_nonprimitive = NULL;
    if(!cJSON_IsArray(to)){
        goto end; //nonprimitive container
    }

    toList = list_createList();

    cJSON_ArrayForEach(to_local_nonprimitive,to )
    {
        if(!cJSON_IsObject(to_local_nonprimitive)){
            goto end;
        }
        v1_network_policy_peer_t *toItem = v1_network_policy_peer_parseFromJSON(to_local_nonprimitive);

        list_addElement(toList, toItem);
    }
    }


    v1_network_policy_egress_rule_local_var = v1_network_policy_egress_rule_create_internal (
        ports ? portsList : NULL,
        to ? toList : NULL
        );

    return v1_network_policy_egress_rule_local_var;
end:
    if (portsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, portsList) {
            v1_network_policy_port_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(portsList);
        portsList = NULL;
    }
    if (toList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, toList) {
            v1_network_policy_peer_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(toList);
        toList = NULL;
    }
    return NULL;

}
