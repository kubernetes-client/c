#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_endpoint.h"



v1_endpoint_t *v1_endpoint_create(
    list_t *addresses,
    v1_endpoint_conditions_t *conditions,
    list_t* deprecated_topology,
    v1_endpoint_hints_t *hints,
    char *hostname,
    char *node_name,
    v1_object_reference_t *target_ref,
    char *zone
    ) {
    v1_endpoint_t *v1_endpoint_local_var = malloc(sizeof(v1_endpoint_t));
    if (!v1_endpoint_local_var) {
        return NULL;
    }
    v1_endpoint_local_var->addresses = addresses;
    v1_endpoint_local_var->conditions = conditions;
    v1_endpoint_local_var->deprecated_topology = deprecated_topology;
    v1_endpoint_local_var->hints = hints;
    v1_endpoint_local_var->hostname = hostname;
    v1_endpoint_local_var->node_name = node_name;
    v1_endpoint_local_var->target_ref = target_ref;
    v1_endpoint_local_var->zone = zone;

    return v1_endpoint_local_var;
}


void v1_endpoint_free(v1_endpoint_t *v1_endpoint) {
    if(NULL == v1_endpoint){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_endpoint->addresses) {
        list_ForEach(listEntry, v1_endpoint->addresses) {
            free(listEntry->data);
        }
        list_free(v1_endpoint->addresses);
        v1_endpoint->addresses = NULL;
    }
    if (v1_endpoint->conditions) {
        v1_endpoint_conditions_free(v1_endpoint->conditions);
        v1_endpoint->conditions = NULL;
    }
    if (v1_endpoint->deprecated_topology) {
        list_ForEach(listEntry, v1_endpoint->deprecated_topology) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_endpoint->deprecated_topology);
        v1_endpoint->deprecated_topology = NULL;
    }
    if (v1_endpoint->hints) {
        v1_endpoint_hints_free(v1_endpoint->hints);
        v1_endpoint->hints = NULL;
    }
    if (v1_endpoint->hostname) {
        free(v1_endpoint->hostname);
        v1_endpoint->hostname = NULL;
    }
    if (v1_endpoint->node_name) {
        free(v1_endpoint->node_name);
        v1_endpoint->node_name = NULL;
    }
    if (v1_endpoint->target_ref) {
        v1_object_reference_free(v1_endpoint->target_ref);
        v1_endpoint->target_ref = NULL;
    }
    if (v1_endpoint->zone) {
        free(v1_endpoint->zone);
        v1_endpoint->zone = NULL;
    }
    free(v1_endpoint);
}

cJSON *v1_endpoint_convertToJSON(v1_endpoint_t *v1_endpoint) {
    cJSON *item = cJSON_CreateObject();

    // v1_endpoint->addresses
    if (!v1_endpoint->addresses) {
        goto fail;
    }
    
    cJSON *addresses = cJSON_AddArrayToObject(item, "addresses");
    if(addresses == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *addressesListEntry;
    list_ForEach(addressesListEntry, v1_endpoint->addresses) {
    if(cJSON_AddStringToObject(addresses, "", (char*)addressesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1_endpoint->conditions
    if(v1_endpoint->conditions) { 
    cJSON *conditions_local_JSON = v1_endpoint_conditions_convertToJSON(v1_endpoint->conditions);
    if(conditions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "conditions", conditions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_endpoint->deprecated_topology
    if(v1_endpoint->deprecated_topology) { 
    cJSON *deprecated_topology = cJSON_AddObjectToObject(item, "deprecatedTopology");
    if(deprecated_topology == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = deprecated_topology;
    listEntry_t *deprecated_topologyListEntry;
    if (v1_endpoint->deprecated_topology) {
    list_ForEach(deprecated_topologyListEntry, v1_endpoint->deprecated_topology) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)deprecated_topologyListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_endpoint->hints
    if(v1_endpoint->hints) { 
    cJSON *hints_local_JSON = v1_endpoint_hints_convertToJSON(v1_endpoint->hints);
    if(hints_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hints", hints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_endpoint->hostname
    if(v1_endpoint->hostname) { 
    if(cJSON_AddStringToObject(item, "hostname", v1_endpoint->hostname) == NULL) {
    goto fail; //String
    }
     } 


    // v1_endpoint->node_name
    if(v1_endpoint->node_name) { 
    if(cJSON_AddStringToObject(item, "nodeName", v1_endpoint->node_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_endpoint->target_ref
    if(v1_endpoint->target_ref) { 
    cJSON *target_ref_local_JSON = v1_object_reference_convertToJSON(v1_endpoint->target_ref);
    if(target_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "targetRef", target_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_endpoint->zone
    if(v1_endpoint->zone) { 
    if(cJSON_AddStringToObject(item, "zone", v1_endpoint->zone) == NULL) {
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

v1_endpoint_t *v1_endpoint_parseFromJSON(cJSON *v1_endpointJSON){

    v1_endpoint_t *v1_endpoint_local_var = NULL;

    // v1_endpoint->addresses
    cJSON *addresses = cJSON_GetObjectItemCaseSensitive(v1_endpointJSON, "addresses");
    if (!addresses) {
        goto end;
    }

    list_t *addressesList;
    
    cJSON *addresses_local;
    if(!cJSON_IsArray(addresses)) {
        goto end;//primitive container
    }
    addressesList = list_create();

    cJSON_ArrayForEach(addresses_local, addresses)
    {
        if(!cJSON_IsString(addresses_local))
        {
            goto end;
        }
        list_addElement(addressesList , strdup(addresses_local->valuestring));
    }

    // v1_endpoint->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_endpointJSON, "conditions");
    v1_endpoint_conditions_t *conditions_local_nonprim = NULL;
    if (conditions) { 
    conditions_local_nonprim = v1_endpoint_conditions_parseFromJSON(conditions); //nonprimitive
    }

    // v1_endpoint->deprecated_topology
    cJSON *deprecated_topology = cJSON_GetObjectItemCaseSensitive(v1_endpointJSON, "deprecatedTopology");
    list_t *deprecated_topologyList;
    if (deprecated_topology) { 
    cJSON *deprecated_topology_local_map;
    if(!cJSON_IsObject(deprecated_topology)) {
        goto end;//primitive map container
    }
    deprecated_topologyList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(deprecated_topology_local_map, deprecated_topology)
    {
		cJSON *localMapObject = deprecated_topology_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(deprecated_topologyList , localMapKeyPair);
    }
    }

    // v1_endpoint->hints
    cJSON *hints = cJSON_GetObjectItemCaseSensitive(v1_endpointJSON, "hints");
    v1_endpoint_hints_t *hints_local_nonprim = NULL;
    if (hints) { 
    hints_local_nonprim = v1_endpoint_hints_parseFromJSON(hints); //nonprimitive
    }

    // v1_endpoint->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(v1_endpointJSON, "hostname");
    if (hostname) { 
    if(!cJSON_IsString(hostname))
    {
    goto end; //String
    }
    }

    // v1_endpoint->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1_endpointJSON, "nodeName");
    if (node_name) { 
    if(!cJSON_IsString(node_name))
    {
    goto end; //String
    }
    }

    // v1_endpoint->target_ref
    cJSON *target_ref = cJSON_GetObjectItemCaseSensitive(v1_endpointJSON, "targetRef");
    v1_object_reference_t *target_ref_local_nonprim = NULL;
    if (target_ref) { 
    target_ref_local_nonprim = v1_object_reference_parseFromJSON(target_ref); //nonprimitive
    }

    // v1_endpoint->zone
    cJSON *zone = cJSON_GetObjectItemCaseSensitive(v1_endpointJSON, "zone");
    if (zone) { 
    if(!cJSON_IsString(zone))
    {
    goto end; //String
    }
    }


    v1_endpoint_local_var = v1_endpoint_create (
        addressesList,
        conditions ? conditions_local_nonprim : NULL,
        deprecated_topology ? deprecated_topologyList : NULL,
        hints ? hints_local_nonprim : NULL,
        hostname ? strdup(hostname->valuestring) : NULL,
        node_name ? strdup(node_name->valuestring) : NULL,
        target_ref ? target_ref_local_nonprim : NULL,
        zone ? strdup(zone->valuestring) : NULL
        );

    return v1_endpoint_local_var;
end:
    if (conditions_local_nonprim) {
        v1_endpoint_conditions_free(conditions_local_nonprim);
        conditions_local_nonprim = NULL;
    }
    if (hints_local_nonprim) {
        v1_endpoint_hints_free(hints_local_nonprim);
        hints_local_nonprim = NULL;
    }
    if (target_ref_local_nonprim) {
        v1_object_reference_free(target_ref_local_nonprim);
        target_ref_local_nonprim = NULL;
    }
    return NULL;

}
