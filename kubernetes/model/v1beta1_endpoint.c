#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_endpoint.h"



v1beta1_endpoint_t *v1beta1_endpoint_create(
    list_t *addresses,
    v1beta1_endpoint_conditions_t *conditions,
    char *hostname,
    v1_object_reference_t *target_ref,
    list_t* topology
    ) {
    v1beta1_endpoint_t *v1beta1_endpoint_local_var = malloc(sizeof(v1beta1_endpoint_t));
    if (!v1beta1_endpoint_local_var) {
        return NULL;
    }
    v1beta1_endpoint_local_var->addresses = addresses;
    v1beta1_endpoint_local_var->conditions = conditions;
    v1beta1_endpoint_local_var->hostname = hostname;
    v1beta1_endpoint_local_var->target_ref = target_ref;
    v1beta1_endpoint_local_var->topology = topology;

    return v1beta1_endpoint_local_var;
}


void v1beta1_endpoint_free(v1beta1_endpoint_t *v1beta1_endpoint) {
    if(NULL == v1beta1_endpoint){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_endpoint->addresses) {
        list_ForEach(listEntry, v1beta1_endpoint->addresses) {
            free(listEntry->data);
        }
        list_free(v1beta1_endpoint->addresses);
        v1beta1_endpoint->addresses = NULL;
    }
    if (v1beta1_endpoint->conditions) {
        v1beta1_endpoint_conditions_free(v1beta1_endpoint->conditions);
        v1beta1_endpoint->conditions = NULL;
    }
    if (v1beta1_endpoint->hostname) {
        free(v1beta1_endpoint->hostname);
        v1beta1_endpoint->hostname = NULL;
    }
    if (v1beta1_endpoint->target_ref) {
        v1_object_reference_free(v1beta1_endpoint->target_ref);
        v1beta1_endpoint->target_ref = NULL;
    }
    if (v1beta1_endpoint->topology) {
        list_ForEach(listEntry, v1beta1_endpoint->topology) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1beta1_endpoint->topology);
        v1beta1_endpoint->topology = NULL;
    }
    free(v1beta1_endpoint);
}

cJSON *v1beta1_endpoint_convertToJSON(v1beta1_endpoint_t *v1beta1_endpoint) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_endpoint->addresses
    if (!v1beta1_endpoint->addresses) {
        goto fail;
    }
    
    cJSON *addresses = cJSON_AddArrayToObject(item, "addresses");
    if(addresses == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *addressesListEntry;
    list_ForEach(addressesListEntry, v1beta1_endpoint->addresses) {
    if(cJSON_AddStringToObject(addresses, "", (char*)addressesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // v1beta1_endpoint->conditions
    if(v1beta1_endpoint->conditions) { 
    cJSON *conditions_local_JSON = v1beta1_endpoint_conditions_convertToJSON(v1beta1_endpoint->conditions);
    if(conditions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "conditions", conditions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_endpoint->hostname
    if(v1beta1_endpoint->hostname) { 
    if(cJSON_AddStringToObject(item, "hostname", v1beta1_endpoint->hostname) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_endpoint->target_ref
    if(v1beta1_endpoint->target_ref) { 
    cJSON *target_ref_local_JSON = v1_object_reference_convertToJSON(v1beta1_endpoint->target_ref);
    if(target_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "targetRef", target_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_endpoint->topology
    if(v1beta1_endpoint->topology) { 
    cJSON *topology = cJSON_AddObjectToObject(item, "topology");
    if(topology == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = topology;
    listEntry_t *topologyListEntry;
    if (v1beta1_endpoint->topology) {
    list_ForEach(topologyListEntry, v1beta1_endpoint->topology) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)topologyListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
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

v1beta1_endpoint_t *v1beta1_endpoint_parseFromJSON(cJSON *v1beta1_endpointJSON){

    v1beta1_endpoint_t *v1beta1_endpoint_local_var = NULL;

    // v1beta1_endpoint->addresses
    cJSON *addresses = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "addresses");
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

    // v1beta1_endpoint->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "conditions");
    v1beta1_endpoint_conditions_t *conditions_local_nonprim = NULL;
    if (conditions) { 
    conditions_local_nonprim = v1beta1_endpoint_conditions_parseFromJSON(conditions); //nonprimitive
    }

    // v1beta1_endpoint->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "hostname");
    if (hostname) { 
    if(!cJSON_IsString(hostname))
    {
    goto end; //String
    }
    }

    // v1beta1_endpoint->target_ref
    cJSON *target_ref = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "targetRef");
    v1_object_reference_t *target_ref_local_nonprim = NULL;
    if (target_ref) { 
    target_ref_local_nonprim = v1_object_reference_parseFromJSON(target_ref); //nonprimitive
    }

    // v1beta1_endpoint->topology
    cJSON *topology = cJSON_GetObjectItemCaseSensitive(v1beta1_endpointJSON, "topology");
    list_t *topologyList;
    if (topology) { 
    cJSON *topology_local_map;
    if(!cJSON_IsObject(topology)) {
        goto end;//primitive map container
    }
    topologyList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(topology_local_map, topology)
    {
		cJSON *localMapObject = topology_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(topologyList , localMapKeyPair);
    }
    }


    v1beta1_endpoint_local_var = v1beta1_endpoint_create (
        addressesList,
        conditions ? conditions_local_nonprim : NULL,
        hostname ? strdup(hostname->valuestring) : NULL,
        target_ref ? target_ref_local_nonprim : NULL,
        topology ? topologyList : NULL
        );

    return v1beta1_endpoint_local_var;
end:
    if (conditions_local_nonprim) {
        v1beta1_endpoint_conditions_free(conditions_local_nonprim);
        conditions_local_nonprim = NULL;
    }
    if (target_ref_local_nonprim) {
        v1_object_reference_free(target_ref_local_nonprim);
        target_ref_local_nonprim = NULL;
    }
    return NULL;

}
