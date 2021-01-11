#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_spec.h"



v1_service_spec_t *v1_service_spec_create(
    char *cluster_ip,
    list_t *external_ips,
    char *external_name,
    char *external_traffic_policy,
    int health_check_node_port,
    char *ip_family,
    char *load_balancer_ip,
    list_t *load_balancer_source_ranges,
    list_t *ports,
    int publish_not_ready_addresses,
    list_t* selector,
    char *session_affinity,
    v1_session_affinity_config_t *session_affinity_config,
    list_t *topology_keys,
    char *type
    ) {
    v1_service_spec_t *v1_service_spec_local_var = malloc(sizeof(v1_service_spec_t));
    if (!v1_service_spec_local_var) {
        return NULL;
    }
    v1_service_spec_local_var->cluster_ip = cluster_ip;
    v1_service_spec_local_var->external_ips = external_ips;
    v1_service_spec_local_var->external_name = external_name;
    v1_service_spec_local_var->external_traffic_policy = external_traffic_policy;
    v1_service_spec_local_var->health_check_node_port = health_check_node_port;
    v1_service_spec_local_var->ip_family = ip_family;
    v1_service_spec_local_var->load_balancer_ip = load_balancer_ip;
    v1_service_spec_local_var->load_balancer_source_ranges = load_balancer_source_ranges;
    v1_service_spec_local_var->ports = ports;
    v1_service_spec_local_var->publish_not_ready_addresses = publish_not_ready_addresses;
    v1_service_spec_local_var->selector = selector;
    v1_service_spec_local_var->session_affinity = session_affinity;
    v1_service_spec_local_var->session_affinity_config = session_affinity_config;
    v1_service_spec_local_var->topology_keys = topology_keys;
    v1_service_spec_local_var->type = type;

    return v1_service_spec_local_var;
}


void v1_service_spec_free(v1_service_spec_t *v1_service_spec) {
    if(NULL == v1_service_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_spec->cluster_ip) {
        free(v1_service_spec->cluster_ip);
        v1_service_spec->cluster_ip = NULL;
    }
    if (v1_service_spec->external_ips) {
        list_ForEach(listEntry, v1_service_spec->external_ips) {
            free(listEntry->data);
        }
        list_free(v1_service_spec->external_ips);
        v1_service_spec->external_ips = NULL;
    }
    if (v1_service_spec->external_name) {
        free(v1_service_spec->external_name);
        v1_service_spec->external_name = NULL;
    }
    if (v1_service_spec->external_traffic_policy) {
        free(v1_service_spec->external_traffic_policy);
        v1_service_spec->external_traffic_policy = NULL;
    }
    if (v1_service_spec->ip_family) {
        free(v1_service_spec->ip_family);
        v1_service_spec->ip_family = NULL;
    }
    if (v1_service_spec->load_balancer_ip) {
        free(v1_service_spec->load_balancer_ip);
        v1_service_spec->load_balancer_ip = NULL;
    }
    if (v1_service_spec->load_balancer_source_ranges) {
        list_ForEach(listEntry, v1_service_spec->load_balancer_source_ranges) {
            free(listEntry->data);
        }
        list_free(v1_service_spec->load_balancer_source_ranges);
        v1_service_spec->load_balancer_source_ranges = NULL;
    }
    if (v1_service_spec->ports) {
        list_ForEach(listEntry, v1_service_spec->ports) {
            v1_service_port_free(listEntry->data);
        }
        list_free(v1_service_spec->ports);
        v1_service_spec->ports = NULL;
    }
    if (v1_service_spec->selector) {
        list_ForEach(listEntry, v1_service_spec->selector) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_service_spec->selector);
        v1_service_spec->selector = NULL;
    }
    if (v1_service_spec->session_affinity) {
        free(v1_service_spec->session_affinity);
        v1_service_spec->session_affinity = NULL;
    }
    if (v1_service_spec->session_affinity_config) {
        v1_session_affinity_config_free(v1_service_spec->session_affinity_config);
        v1_service_spec->session_affinity_config = NULL;
    }
    if (v1_service_spec->topology_keys) {
        list_ForEach(listEntry, v1_service_spec->topology_keys) {
            free(listEntry->data);
        }
        list_free(v1_service_spec->topology_keys);
        v1_service_spec->topology_keys = NULL;
    }
    if (v1_service_spec->type) {
        free(v1_service_spec->type);
        v1_service_spec->type = NULL;
    }
    free(v1_service_spec);
}

cJSON *v1_service_spec_convertToJSON(v1_service_spec_t *v1_service_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_spec->cluster_ip
    if(v1_service_spec->cluster_ip) { 
    if(cJSON_AddStringToObject(item, "clusterIP", v1_service_spec->cluster_ip) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_spec->external_ips
    if(v1_service_spec->external_ips) { 
    cJSON *external_ips = cJSON_AddArrayToObject(item, "externalIPs");
    if(external_ips == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *external_ipsListEntry;
    list_ForEach(external_ipsListEntry, v1_service_spec->external_ips) {
    if(cJSON_AddStringToObject(external_ips, "", (char*)external_ipsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_service_spec->external_name
    if(v1_service_spec->external_name) { 
    if(cJSON_AddStringToObject(item, "externalName", v1_service_spec->external_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_spec->external_traffic_policy
    if(v1_service_spec->external_traffic_policy) { 
    if(cJSON_AddStringToObject(item, "externalTrafficPolicy", v1_service_spec->external_traffic_policy) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_spec->health_check_node_port
    if(v1_service_spec->health_check_node_port) { 
    if(cJSON_AddNumberToObject(item, "healthCheckNodePort", v1_service_spec->health_check_node_port) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_service_spec->ip_family
    if(v1_service_spec->ip_family) { 
    if(cJSON_AddStringToObject(item, "ipFamily", v1_service_spec->ip_family) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_spec->load_balancer_ip
    if(v1_service_spec->load_balancer_ip) { 
    if(cJSON_AddStringToObject(item, "loadBalancerIP", v1_service_spec->load_balancer_ip) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_spec->load_balancer_source_ranges
    if(v1_service_spec->load_balancer_source_ranges) { 
    cJSON *load_balancer_source_ranges = cJSON_AddArrayToObject(item, "loadBalancerSourceRanges");
    if(load_balancer_source_ranges == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *load_balancer_source_rangesListEntry;
    list_ForEach(load_balancer_source_rangesListEntry, v1_service_spec->load_balancer_source_ranges) {
    if(cJSON_AddStringToObject(load_balancer_source_ranges, "", (char*)load_balancer_source_rangesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_service_spec->ports
    if(v1_service_spec->ports) { 
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1_service_spec->ports) {
    list_ForEach(portsListEntry, v1_service_spec->ports) {
    cJSON *itemLocal = v1_service_port_convertToJSON(portsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ports, itemLocal);
    }
    }
     } 


    // v1_service_spec->publish_not_ready_addresses
    if(v1_service_spec->publish_not_ready_addresses) { 
    if(cJSON_AddBoolToObject(item, "publishNotReadyAddresses", v1_service_spec->publish_not_ready_addresses) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_service_spec->selector
    if(v1_service_spec->selector) { 
    cJSON *selector = cJSON_AddObjectToObject(item, "selector");
    if(selector == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = selector;
    listEntry_t *selectorListEntry;
    if (v1_service_spec->selector) {
    list_ForEach(selectorListEntry, v1_service_spec->selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_service_spec->session_affinity
    if(v1_service_spec->session_affinity) { 
    if(cJSON_AddStringToObject(item, "sessionAffinity", v1_service_spec->session_affinity) == NULL) {
    goto fail; //String
    }
     } 


    // v1_service_spec->session_affinity_config
    if(v1_service_spec->session_affinity_config) { 
    cJSON *session_affinity_config_local_JSON = v1_session_affinity_config_convertToJSON(v1_service_spec->session_affinity_config);
    if(session_affinity_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sessionAffinityConfig", session_affinity_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_service_spec->topology_keys
    if(v1_service_spec->topology_keys) { 
    cJSON *topology_keys = cJSON_AddArrayToObject(item, "topologyKeys");
    if(topology_keys == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *topology_keysListEntry;
    list_ForEach(topology_keysListEntry, v1_service_spec->topology_keys) {
    if(cJSON_AddStringToObject(topology_keys, "", (char*)topology_keysListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_service_spec->type
    if(v1_service_spec->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_service_spec->type) == NULL) {
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

v1_service_spec_t *v1_service_spec_parseFromJSON(cJSON *v1_service_specJSON){

    v1_service_spec_t *v1_service_spec_local_var = NULL;

    // v1_service_spec->cluster_ip
    cJSON *cluster_ip = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "clusterIP");
    if (cluster_ip) { 
    if(!cJSON_IsString(cluster_ip))
    {
    goto end; //String
    }
    }

    // v1_service_spec->external_ips
    cJSON *external_ips = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "externalIPs");
    list_t *external_ipsList;
    if (external_ips) { 
    cJSON *external_ips_local;
    if(!cJSON_IsArray(external_ips)) {
        goto end;//primitive container
    }
    external_ipsList = list_create();

    cJSON_ArrayForEach(external_ips_local, external_ips)
    {
        if(!cJSON_IsString(external_ips_local))
        {
            goto end;
        }
        list_addElement(external_ipsList , strdup(external_ips_local->valuestring));
    }
    }

    // v1_service_spec->external_name
    cJSON *external_name = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "externalName");
    if (external_name) { 
    if(!cJSON_IsString(external_name))
    {
    goto end; //String
    }
    }

    // v1_service_spec->external_traffic_policy
    cJSON *external_traffic_policy = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "externalTrafficPolicy");
    if (external_traffic_policy) { 
    if(!cJSON_IsString(external_traffic_policy))
    {
    goto end; //String
    }
    }

    // v1_service_spec->health_check_node_port
    cJSON *health_check_node_port = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "healthCheckNodePort");
    if (health_check_node_port) { 
    if(!cJSON_IsNumber(health_check_node_port))
    {
    goto end; //Numeric
    }
    }

    // v1_service_spec->ip_family
    cJSON *ip_family = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "ipFamily");
    if (ip_family) { 
    if(!cJSON_IsString(ip_family))
    {
    goto end; //String
    }
    }

    // v1_service_spec->load_balancer_ip
    cJSON *load_balancer_ip = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "loadBalancerIP");
    if (load_balancer_ip) { 
    if(!cJSON_IsString(load_balancer_ip))
    {
    goto end; //String
    }
    }

    // v1_service_spec->load_balancer_source_ranges
    cJSON *load_balancer_source_ranges = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "loadBalancerSourceRanges");
    list_t *load_balancer_source_rangesList;
    if (load_balancer_source_ranges) { 
    cJSON *load_balancer_source_ranges_local;
    if(!cJSON_IsArray(load_balancer_source_ranges)) {
        goto end;//primitive container
    }
    load_balancer_source_rangesList = list_create();

    cJSON_ArrayForEach(load_balancer_source_ranges_local, load_balancer_source_ranges)
    {
        if(!cJSON_IsString(load_balancer_source_ranges_local))
        {
            goto end;
        }
        list_addElement(load_balancer_source_rangesList , strdup(load_balancer_source_ranges_local->valuestring));
    }
    }

    // v1_service_spec->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "ports");
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
        v1_service_port_t *portsItem = v1_service_port_parseFromJSON(ports_local_nonprimitive);

        list_addElement(portsList, portsItem);
    }
    }

    // v1_service_spec->publish_not_ready_addresses
    cJSON *publish_not_ready_addresses = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "publishNotReadyAddresses");
    if (publish_not_ready_addresses) { 
    if(!cJSON_IsBool(publish_not_ready_addresses))
    {
    goto end; //Bool
    }
    }

    // v1_service_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "selector");
    list_t *selectorList;
    if (selector) { 
    cJSON *selector_local_map;
    if(!cJSON_IsObject(selector)) {
        goto end;//primitive map container
    }
    selectorList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(selector_local_map, selector)
    {
		cJSON *localMapObject = selector_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(selectorList , localMapKeyPair);
    }
    }

    // v1_service_spec->session_affinity
    cJSON *session_affinity = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "sessionAffinity");
    if (session_affinity) { 
    if(!cJSON_IsString(session_affinity))
    {
    goto end; //String
    }
    }

    // v1_service_spec->session_affinity_config
    cJSON *session_affinity_config = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "sessionAffinityConfig");
    v1_session_affinity_config_t *session_affinity_config_local_nonprim = NULL;
    if (session_affinity_config) { 
    session_affinity_config_local_nonprim = v1_session_affinity_config_parseFromJSON(session_affinity_config); //nonprimitive
    }

    // v1_service_spec->topology_keys
    cJSON *topology_keys = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "topologyKeys");
    list_t *topology_keysList;
    if (topology_keys) { 
    cJSON *topology_keys_local;
    if(!cJSON_IsArray(topology_keys)) {
        goto end;//primitive container
    }
    topology_keysList = list_create();

    cJSON_ArrayForEach(topology_keys_local, topology_keys)
    {
        if(!cJSON_IsString(topology_keys_local))
        {
            goto end;
        }
        list_addElement(topology_keysList , strdup(topology_keys_local->valuestring));
    }
    }

    // v1_service_spec->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_service_spec_local_var = v1_service_spec_create (
        cluster_ip ? strdup(cluster_ip->valuestring) : NULL,
        external_ips ? external_ipsList : NULL,
        external_name ? strdup(external_name->valuestring) : NULL,
        external_traffic_policy ? strdup(external_traffic_policy->valuestring) : NULL,
        health_check_node_port ? health_check_node_port->valuedouble : 0,
        ip_family ? strdup(ip_family->valuestring) : NULL,
        load_balancer_ip ? strdup(load_balancer_ip->valuestring) : NULL,
        load_balancer_source_ranges ? load_balancer_source_rangesList : NULL,
        ports ? portsList : NULL,
        publish_not_ready_addresses ? publish_not_ready_addresses->valueint : 0,
        selector ? selectorList : NULL,
        session_affinity ? strdup(session_affinity->valuestring) : NULL,
        session_affinity_config ? session_affinity_config_local_nonprim : NULL,
        topology_keys ? topology_keysList : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_service_spec_local_var;
end:
    if (session_affinity_config_local_nonprim) {
        v1_session_affinity_config_free(session_affinity_config_local_nonprim);
        session_affinity_config_local_nonprim = NULL;
    }
    return NULL;

}
