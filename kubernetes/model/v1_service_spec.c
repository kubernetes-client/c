#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_spec.h"



v1_service_spec_t *v1_service_spec_create(
    int allocate_load_balancer_node_ports,
    char *cluster_ip,
    list_t *cluster_ips,
    list_t *external_ips,
    char *external_name,
    char *external_traffic_policy,
    int health_check_node_port,
    char *internal_traffic_policy,
    list_t *ip_families,
    char *ip_family_policy,
    char *load_balancer_class,
    char *load_balancer_ip,
    list_t *load_balancer_source_ranges,
    list_t *ports,
    int publish_not_ready_addresses,
    list_t* selector,
    char *session_affinity,
    v1_session_affinity_config_t *session_affinity_config,
    char *type
    ) {
    v1_service_spec_t *v1_service_spec_local_var = malloc(sizeof(v1_service_spec_t));
    if (!v1_service_spec_local_var) {
        return NULL;
    }
    v1_service_spec_local_var->allocate_load_balancer_node_ports = allocate_load_balancer_node_ports;
    v1_service_spec_local_var->cluster_ip = cluster_ip;
    v1_service_spec_local_var->cluster_ips = cluster_ips;
    v1_service_spec_local_var->external_ips = external_ips;
    v1_service_spec_local_var->external_name = external_name;
    v1_service_spec_local_var->external_traffic_policy = external_traffic_policy;
    v1_service_spec_local_var->health_check_node_port = health_check_node_port;
    v1_service_spec_local_var->internal_traffic_policy = internal_traffic_policy;
    v1_service_spec_local_var->ip_families = ip_families;
    v1_service_spec_local_var->ip_family_policy = ip_family_policy;
    v1_service_spec_local_var->load_balancer_class = load_balancer_class;
    v1_service_spec_local_var->load_balancer_ip = load_balancer_ip;
    v1_service_spec_local_var->load_balancer_source_ranges = load_balancer_source_ranges;
    v1_service_spec_local_var->ports = ports;
    v1_service_spec_local_var->publish_not_ready_addresses = publish_not_ready_addresses;
    v1_service_spec_local_var->selector = selector;
    v1_service_spec_local_var->session_affinity = session_affinity;
    v1_service_spec_local_var->session_affinity_config = session_affinity_config;
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
    if (v1_service_spec->cluster_ips) {
        list_ForEach(listEntry, v1_service_spec->cluster_ips) {
            free(listEntry->data);
        }
        list_freeList(v1_service_spec->cluster_ips);
        v1_service_spec->cluster_ips = NULL;
    }
    if (v1_service_spec->external_ips) {
        list_ForEach(listEntry, v1_service_spec->external_ips) {
            free(listEntry->data);
        }
        list_freeList(v1_service_spec->external_ips);
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
    if (v1_service_spec->internal_traffic_policy) {
        free(v1_service_spec->internal_traffic_policy);
        v1_service_spec->internal_traffic_policy = NULL;
    }
    if (v1_service_spec->ip_families) {
        list_ForEach(listEntry, v1_service_spec->ip_families) {
            free(listEntry->data);
        }
        list_freeList(v1_service_spec->ip_families);
        v1_service_spec->ip_families = NULL;
    }
    if (v1_service_spec->ip_family_policy) {
        free(v1_service_spec->ip_family_policy);
        v1_service_spec->ip_family_policy = NULL;
    }
    if (v1_service_spec->load_balancer_class) {
        free(v1_service_spec->load_balancer_class);
        v1_service_spec->load_balancer_class = NULL;
    }
    if (v1_service_spec->load_balancer_ip) {
        free(v1_service_spec->load_balancer_ip);
        v1_service_spec->load_balancer_ip = NULL;
    }
    if (v1_service_spec->load_balancer_source_ranges) {
        list_ForEach(listEntry, v1_service_spec->load_balancer_source_ranges) {
            free(listEntry->data);
        }
        list_freeList(v1_service_spec->load_balancer_source_ranges);
        v1_service_spec->load_balancer_source_ranges = NULL;
    }
    if (v1_service_spec->ports) {
        list_ForEach(listEntry, v1_service_spec->ports) {
            v1_service_port_free(listEntry->data);
        }
        list_freeList(v1_service_spec->ports);
        v1_service_spec->ports = NULL;
    }
    if (v1_service_spec->selector) {
        list_ForEach(listEntry, v1_service_spec->selector) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_service_spec->selector);
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
    if (v1_service_spec->type) {
        free(v1_service_spec->type);
        v1_service_spec->type = NULL;
    }
    free(v1_service_spec);
}

cJSON *v1_service_spec_convertToJSON(v1_service_spec_t *v1_service_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_spec->allocate_load_balancer_node_ports
    if(v1_service_spec->allocate_load_balancer_node_ports) {
    if(cJSON_AddBoolToObject(item, "allocateLoadBalancerNodePorts", v1_service_spec->allocate_load_balancer_node_ports) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_service_spec->cluster_ip
    if(v1_service_spec->cluster_ip) {
    if(cJSON_AddStringToObject(item, "clusterIP", v1_service_spec->cluster_ip) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_spec->cluster_ips
    if(v1_service_spec->cluster_ips) {
    cJSON *cluster_ips = cJSON_AddArrayToObject(item, "clusterIPs");
    if(cluster_ips == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *cluster_ipsListEntry;
    list_ForEach(cluster_ipsListEntry, v1_service_spec->cluster_ips) {
    if(cJSON_AddStringToObject(cluster_ips, "", (char*)cluster_ipsListEntry->data) == NULL)
    {
        goto fail;
    }
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


    // v1_service_spec->internal_traffic_policy
    if(v1_service_spec->internal_traffic_policy) {
    if(cJSON_AddStringToObject(item, "internalTrafficPolicy", v1_service_spec->internal_traffic_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_spec->ip_families
    if(v1_service_spec->ip_families) {
    cJSON *ip_families = cJSON_AddArrayToObject(item, "ipFamilies");
    if(ip_families == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *ip_familiesListEntry;
    list_ForEach(ip_familiesListEntry, v1_service_spec->ip_families) {
    if(cJSON_AddStringToObject(ip_families, "", (char*)ip_familiesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_service_spec->ip_family_policy
    if(v1_service_spec->ip_family_policy) {
    if(cJSON_AddStringToObject(item, "ipFamilyPolicy", v1_service_spec->ip_family_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_spec->load_balancer_class
    if(v1_service_spec->load_balancer_class) {
    if(cJSON_AddStringToObject(item, "loadBalancerClass", v1_service_spec->load_balancer_class) == NULL) {
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

    // define the local list for v1_service_spec->cluster_ips
    list_t *cluster_ipsList = NULL;

    // define the local list for v1_service_spec->external_ips
    list_t *external_ipsList = NULL;

    // define the local list for v1_service_spec->ip_families
    list_t *ip_familiesList = NULL;

    // define the local list for v1_service_spec->load_balancer_source_ranges
    list_t *load_balancer_source_rangesList = NULL;

    // define the local list for v1_service_spec->ports
    list_t *portsList = NULL;

    // define the local map for v1_service_spec->selector
    list_t *selectorList = NULL;

    // define the local variable for v1_service_spec->session_affinity_config
    v1_session_affinity_config_t *session_affinity_config_local_nonprim = NULL;

    // v1_service_spec->allocate_load_balancer_node_ports
    cJSON *allocate_load_balancer_node_ports = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "allocateLoadBalancerNodePorts");
    if (allocate_load_balancer_node_ports) { 
    if(!cJSON_IsBool(allocate_load_balancer_node_ports))
    {
    goto end; //Bool
    }
    }

    // v1_service_spec->cluster_ip
    cJSON *cluster_ip = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "clusterIP");
    if (cluster_ip) { 
    if(!cJSON_IsString(cluster_ip))
    {
    goto end; //String
    }
    }

    // v1_service_spec->cluster_ips
    cJSON *cluster_ips = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "clusterIPs");
    if (cluster_ips) { 
    cJSON *cluster_ips_local = NULL;
    if(!cJSON_IsArray(cluster_ips)) {
        goto end;//primitive container
    }
    cluster_ipsList = list_createList();

    cJSON_ArrayForEach(cluster_ips_local, cluster_ips)
    {
        if(!cJSON_IsString(cluster_ips_local))
        {
            goto end;
        }
        list_addElement(cluster_ipsList , strdup(cluster_ips_local->valuestring));
    }
    }

    // v1_service_spec->external_ips
    cJSON *external_ips = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "externalIPs");
    if (external_ips) { 
    cJSON *external_ips_local = NULL;
    if(!cJSON_IsArray(external_ips)) {
        goto end;//primitive container
    }
    external_ipsList = list_createList();

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

    // v1_service_spec->internal_traffic_policy
    cJSON *internal_traffic_policy = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "internalTrafficPolicy");
    if (internal_traffic_policy) { 
    if(!cJSON_IsString(internal_traffic_policy))
    {
    goto end; //String
    }
    }

    // v1_service_spec->ip_families
    cJSON *ip_families = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "ipFamilies");
    if (ip_families) { 
    cJSON *ip_families_local = NULL;
    if(!cJSON_IsArray(ip_families)) {
        goto end;//primitive container
    }
    ip_familiesList = list_createList();

    cJSON_ArrayForEach(ip_families_local, ip_families)
    {
        if(!cJSON_IsString(ip_families_local))
        {
            goto end;
        }
        list_addElement(ip_familiesList , strdup(ip_families_local->valuestring));
    }
    }

    // v1_service_spec->ip_family_policy
    cJSON *ip_family_policy = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "ipFamilyPolicy");
    if (ip_family_policy) { 
    if(!cJSON_IsString(ip_family_policy))
    {
    goto end; //String
    }
    }

    // v1_service_spec->load_balancer_class
    cJSON *load_balancer_class = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "loadBalancerClass");
    if (load_balancer_class) { 
    if(!cJSON_IsString(load_balancer_class))
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
    if (load_balancer_source_ranges) { 
    cJSON *load_balancer_source_ranges_local = NULL;
    if(!cJSON_IsArray(load_balancer_source_ranges)) {
        goto end;//primitive container
    }
    load_balancer_source_rangesList = list_createList();

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
    if (selector) { 
    cJSON *selector_local_map = NULL;
    if(!cJSON_IsObject(selector)) {
        goto end;//primitive map container
    }
    selectorList = list_createList();
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
    if (session_affinity_config) { 
    session_affinity_config_local_nonprim = v1_session_affinity_config_parseFromJSON(session_affinity_config); //nonprimitive
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
        allocate_load_balancer_node_ports ? allocate_load_balancer_node_ports->valueint : 0,
        cluster_ip ? strdup(cluster_ip->valuestring) : NULL,
        cluster_ips ? cluster_ipsList : NULL,
        external_ips ? external_ipsList : NULL,
        external_name ? strdup(external_name->valuestring) : NULL,
        external_traffic_policy ? strdup(external_traffic_policy->valuestring) : NULL,
        health_check_node_port ? health_check_node_port->valuedouble : 0,
        internal_traffic_policy ? strdup(internal_traffic_policy->valuestring) : NULL,
        ip_families ? ip_familiesList : NULL,
        ip_family_policy ? strdup(ip_family_policy->valuestring) : NULL,
        load_balancer_class ? strdup(load_balancer_class->valuestring) : NULL,
        load_balancer_ip ? strdup(load_balancer_ip->valuestring) : NULL,
        load_balancer_source_ranges ? load_balancer_source_rangesList : NULL,
        ports ? portsList : NULL,
        publish_not_ready_addresses ? publish_not_ready_addresses->valueint : 0,
        selector ? selectorList : NULL,
        session_affinity ? strdup(session_affinity->valuestring) : NULL,
        session_affinity_config ? session_affinity_config_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_service_spec_local_var;
end:
    if (cluster_ipsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, cluster_ipsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(cluster_ipsList);
        cluster_ipsList = NULL;
    }
    if (external_ipsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, external_ipsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(external_ipsList);
        external_ipsList = NULL;
    }
    if (ip_familiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ip_familiesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ip_familiesList);
        ip_familiesList = NULL;
    }
    if (load_balancer_source_rangesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, load_balancer_source_rangesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(load_balancer_source_rangesList);
        load_balancer_source_rangesList = NULL;
    }
    if (portsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, portsList) {
            v1_service_port_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(portsList);
        portsList = NULL;
    }
    if (selectorList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, selectorList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(selectorList);
        selectorList = NULL;
    }
    if (session_affinity_config_local_nonprim) {
        v1_session_affinity_config_free(session_affinity_config_local_nonprim);
        session_affinity_config_local_nonprim = NULL;
    }
    return NULL;

}
