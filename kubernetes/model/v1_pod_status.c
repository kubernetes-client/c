#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_status.h"



static v1_pod_status_t *v1_pod_status_create_internal(
    list_t* allocated_resources,
    list_t *conditions,
    list_t *container_statuses,
    list_t *ephemeral_container_statuses,
    v1_pod_extended_resource_claim_status_t *extended_resource_claim_status,
    char *host_ip,
    list_t *host_ips,
    list_t *init_container_statuses,
    char *message,
    list_t *node_allocatable_resource_claim_statuses,
    char *nominated_node_name,
    long *observed_generation,
    char *phase,
    char *pod_ip,
    list_t *pod_ips,
    char *qos_class,
    char *reason,
    char *resize,
    list_t *resource_claim_statuses,
    v1_resource_requirements_t *resources,
    char *start_time,
    list_t *volume_health
    ) {
    v1_pod_status_t *v1_pod_status_local_var = malloc(sizeof(v1_pod_status_t));
    if (!v1_pod_status_local_var) {
        return NULL;
    }
    memset(v1_pod_status_local_var, 0, sizeof(v1_pod_status_t));
    v1_pod_status_local_var->_library_owned = 1;
    v1_pod_status_local_var->allocated_resources = allocated_resources;
    v1_pod_status_local_var->conditions = conditions;
    v1_pod_status_local_var->container_statuses = container_statuses;
    v1_pod_status_local_var->ephemeral_container_statuses = ephemeral_container_statuses;
    v1_pod_status_local_var->extended_resource_claim_status = extended_resource_claim_status;
    v1_pod_status_local_var->host_ip = host_ip;
    v1_pod_status_local_var->host_ips = host_ips;
    v1_pod_status_local_var->init_container_statuses = init_container_statuses;
    v1_pod_status_local_var->message = message;
    v1_pod_status_local_var->node_allocatable_resource_claim_statuses = node_allocatable_resource_claim_statuses;
    v1_pod_status_local_var->nominated_node_name = nominated_node_name;
    v1_pod_status_local_var->observed_generation = observed_generation;
    v1_pod_status_local_var->phase = phase;
    v1_pod_status_local_var->pod_ip = pod_ip;
    v1_pod_status_local_var->pod_ips = pod_ips;
    v1_pod_status_local_var->qos_class = qos_class;
    v1_pod_status_local_var->reason = reason;
    v1_pod_status_local_var->resize = resize;
    v1_pod_status_local_var->resource_claim_statuses = resource_claim_statuses;
    v1_pod_status_local_var->resources = resources;
    v1_pod_status_local_var->start_time = start_time;
    v1_pod_status_local_var->volume_health = volume_health;
    return v1_pod_status_local_var;
}

__attribute__((deprecated)) v1_pod_status_t *v1_pod_status_create(
    list_t* allocated_resources,
    list_t *conditions,
    list_t *container_statuses,
    list_t *ephemeral_container_statuses,
    v1_pod_extended_resource_claim_status_t *extended_resource_claim_status,
    char *host_ip,
    list_t *host_ips,
    list_t *init_container_statuses,
    char *message,
    list_t *node_allocatable_resource_claim_statuses,
    char *nominated_node_name,
    long *observed_generation,
    char *phase,
    char *pod_ip,
    list_t *pod_ips,
    char *qos_class,
    char *reason,
    char *resize,
    list_t *resource_claim_statuses,
    v1_resource_requirements_t *resources,
    char *start_time,
    list_t *volume_health
    ) {
    long *observed_generation_copy = NULL;
    if (observed_generation) {
        observed_generation_copy = malloc(sizeof(long));
        if (observed_generation_copy) *observed_generation_copy = *observed_generation;
    }
    v1_pod_status_t *result = v1_pod_status_create_internal (
        allocated_resources,
        conditions,
        container_statuses,
        ephemeral_container_statuses,
        extended_resource_claim_status,
        host_ip,
        host_ips,
        init_container_statuses,
        message,
        node_allocatable_resource_claim_statuses,
        nominated_node_name,
        observed_generation_copy,
        phase,
        pod_ip,
        pod_ips,
        qos_class,
        reason,
        resize,
        resource_claim_statuses,
        resources,
        start_time,
        volume_health
        );
    if (!result) {
        free(observed_generation_copy);
    }
    return result;
}

void v1_pod_status_free(v1_pod_status_t *v1_pod_status) {
    if(NULL == v1_pod_status){
        return ;
    }
    if(v1_pod_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_status->allocated_resources) {
        list_ForEach(listEntry, v1_pod_status->allocated_resources) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_pod_status->allocated_resources);
        v1_pod_status->allocated_resources = NULL;
    }
    if (v1_pod_status->conditions) {
        list_ForEach(listEntry, v1_pod_status->conditions) {
            v1_pod_condition_free(listEntry->data);
        }
        list_freeList(v1_pod_status->conditions);
        v1_pod_status->conditions = NULL;
    }
    if (v1_pod_status->container_statuses) {
        list_ForEach(listEntry, v1_pod_status->container_statuses) {
            v1_container_status_free(listEntry->data);
        }
        list_freeList(v1_pod_status->container_statuses);
        v1_pod_status->container_statuses = NULL;
    }
    if (v1_pod_status->ephemeral_container_statuses) {
        list_ForEach(listEntry, v1_pod_status->ephemeral_container_statuses) {
            v1_container_status_free(listEntry->data);
        }
        list_freeList(v1_pod_status->ephemeral_container_statuses);
        v1_pod_status->ephemeral_container_statuses = NULL;
    }
    if (v1_pod_status->extended_resource_claim_status) {
        v1_pod_extended_resource_claim_status_free(v1_pod_status->extended_resource_claim_status);
        v1_pod_status->extended_resource_claim_status = NULL;
    }
    if (v1_pod_status->host_ip) {
        free(v1_pod_status->host_ip);
        v1_pod_status->host_ip = NULL;
    }
    if (v1_pod_status->host_ips) {
        list_ForEach(listEntry, v1_pod_status->host_ips) {
            v1_host_ip_free(listEntry->data);
        }
        list_freeList(v1_pod_status->host_ips);
        v1_pod_status->host_ips = NULL;
    }
    if (v1_pod_status->init_container_statuses) {
        list_ForEach(listEntry, v1_pod_status->init_container_statuses) {
            v1_container_status_free(listEntry->data);
        }
        list_freeList(v1_pod_status->init_container_statuses);
        v1_pod_status->init_container_statuses = NULL;
    }
    if (v1_pod_status->message) {
        free(v1_pod_status->message);
        v1_pod_status->message = NULL;
    }
    if (v1_pod_status->node_allocatable_resource_claim_statuses) {
        list_ForEach(listEntry, v1_pod_status->node_allocatable_resource_claim_statuses) {
            v1_node_allocatable_resource_claim_status_free(listEntry->data);
        }
        list_freeList(v1_pod_status->node_allocatable_resource_claim_statuses);
        v1_pod_status->node_allocatable_resource_claim_statuses = NULL;
    }
    if (v1_pod_status->nominated_node_name) {
        free(v1_pod_status->nominated_node_name);
        v1_pod_status->nominated_node_name = NULL;
    }
    if (v1_pod_status->observed_generation) {
        free(v1_pod_status->observed_generation);
        v1_pod_status->observed_generation = NULL;
    }
    if (v1_pod_status->phase) {
        free(v1_pod_status->phase);
        v1_pod_status->phase = NULL;
    }
    if (v1_pod_status->pod_ip) {
        free(v1_pod_status->pod_ip);
        v1_pod_status->pod_ip = NULL;
    }
    if (v1_pod_status->pod_ips) {
        list_ForEach(listEntry, v1_pod_status->pod_ips) {
            v1_pod_ip_free(listEntry->data);
        }
        list_freeList(v1_pod_status->pod_ips);
        v1_pod_status->pod_ips = NULL;
    }
    if (v1_pod_status->qos_class) {
        free(v1_pod_status->qos_class);
        v1_pod_status->qos_class = NULL;
    }
    if (v1_pod_status->reason) {
        free(v1_pod_status->reason);
        v1_pod_status->reason = NULL;
    }
    if (v1_pod_status->resize) {
        free(v1_pod_status->resize);
        v1_pod_status->resize = NULL;
    }
    if (v1_pod_status->resource_claim_statuses) {
        list_ForEach(listEntry, v1_pod_status->resource_claim_statuses) {
            v1_pod_resource_claim_status_free(listEntry->data);
        }
        list_freeList(v1_pod_status->resource_claim_statuses);
        v1_pod_status->resource_claim_statuses = NULL;
    }
    if (v1_pod_status->resources) {
        v1_resource_requirements_free(v1_pod_status->resources);
        v1_pod_status->resources = NULL;
    }
    if (v1_pod_status->start_time) {
        free(v1_pod_status->start_time);
        v1_pod_status->start_time = NULL;
    }
    if (v1_pod_status->volume_health) {
        list_ForEach(listEntry, v1_pod_status->volume_health) {
            v1_pod_volume_health_free(listEntry->data);
        }
        list_freeList(v1_pod_status->volume_health);
        v1_pod_status->volume_health = NULL;
    }
    free(v1_pod_status);
}

cJSON *v1_pod_status_convertToJSON(v1_pod_status_t *v1_pod_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_status->allocated_resources
    if(v1_pod_status->allocated_resources) {
    cJSON *allocated_resources = cJSON_AddObjectToObject(item, "allocatedResources");
    if(allocated_resources == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = allocated_resources;
    listEntry_t *allocated_resourcesListEntry;
    if (v1_pod_status->allocated_resources) {
    list_ForEach(allocated_resourcesListEntry, v1_pod_status->allocated_resources) {
        keyValuePair_t *localKeyValue = allocated_resourcesListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_pod_status->conditions
    if(v1_pod_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_pod_status->conditions) {
    list_ForEach(conditionsListEntry, v1_pod_status->conditions) {
    cJSON *itemLocal = v1_pod_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_pod_status->container_statuses
    if(v1_pod_status->container_statuses) {
    cJSON *container_statuses = cJSON_AddArrayToObject(item, "containerStatuses");
    if(container_statuses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *container_statusesListEntry;
    if (v1_pod_status->container_statuses) {
    list_ForEach(container_statusesListEntry, v1_pod_status->container_statuses) {
    cJSON *itemLocal = v1_container_status_convertToJSON(container_statusesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(container_statuses, itemLocal);
    }
    }
    }


    // v1_pod_status->ephemeral_container_statuses
    if(v1_pod_status->ephemeral_container_statuses) {
    cJSON *ephemeral_container_statuses = cJSON_AddArrayToObject(item, "ephemeralContainerStatuses");
    if(ephemeral_container_statuses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ephemeral_container_statusesListEntry;
    if (v1_pod_status->ephemeral_container_statuses) {
    list_ForEach(ephemeral_container_statusesListEntry, v1_pod_status->ephemeral_container_statuses) {
    cJSON *itemLocal = v1_container_status_convertToJSON(ephemeral_container_statusesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ephemeral_container_statuses, itemLocal);
    }
    }
    }


    // v1_pod_status->extended_resource_claim_status
    if(v1_pod_status->extended_resource_claim_status) {
    cJSON *extended_resource_claim_status_local_JSON = v1_pod_extended_resource_claim_status_convertToJSON(v1_pod_status->extended_resource_claim_status);
    if(extended_resource_claim_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "extendedResourceClaimStatus", extended_resource_claim_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_pod_status->host_ip
    if(v1_pod_status->host_ip) {
    if(cJSON_AddStringToObject(item, "hostIP", v1_pod_status->host_ip) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_status->host_ips
    if(v1_pod_status->host_ips) {
    cJSON *host_ips = cJSON_AddArrayToObject(item, "hostIPs");
    if(host_ips == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *host_ipsListEntry;
    if (v1_pod_status->host_ips) {
    list_ForEach(host_ipsListEntry, v1_pod_status->host_ips) {
    cJSON *itemLocal = v1_host_ip_convertToJSON(host_ipsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(host_ips, itemLocal);
    }
    }
    }


    // v1_pod_status->init_container_statuses
    if(v1_pod_status->init_container_statuses) {
    cJSON *init_container_statuses = cJSON_AddArrayToObject(item, "initContainerStatuses");
    if(init_container_statuses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *init_container_statusesListEntry;
    if (v1_pod_status->init_container_statuses) {
    list_ForEach(init_container_statusesListEntry, v1_pod_status->init_container_statuses) {
    cJSON *itemLocal = v1_container_status_convertToJSON(init_container_statusesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(init_container_statuses, itemLocal);
    }
    }
    }


    // v1_pod_status->message
    if(v1_pod_status->message) {
    if(cJSON_AddStringToObject(item, "message", v1_pod_status->message) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_status->node_allocatable_resource_claim_statuses
    if(v1_pod_status->node_allocatable_resource_claim_statuses) {
    cJSON *node_allocatable_resource_claim_statuses = cJSON_AddArrayToObject(item, "nodeAllocatableResourceClaimStatuses");
    if(node_allocatable_resource_claim_statuses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *node_allocatable_resource_claim_statusesListEntry;
    if (v1_pod_status->node_allocatable_resource_claim_statuses) {
    list_ForEach(node_allocatable_resource_claim_statusesListEntry, v1_pod_status->node_allocatable_resource_claim_statuses) {
    cJSON *itemLocal = v1_node_allocatable_resource_claim_status_convertToJSON(node_allocatable_resource_claim_statusesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(node_allocatable_resource_claim_statuses, itemLocal);
    }
    }
    }


    // v1_pod_status->nominated_node_name
    if(v1_pod_status->nominated_node_name) {
    if(cJSON_AddStringToObject(item, "nominatedNodeName", v1_pod_status->nominated_node_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_status->observed_generation
    if(v1_pod_status->observed_generation) {
    if(cJSON_AddNumberToObject(item, "observedGeneration", *v1_pod_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_pod_status->phase
    if(v1_pod_status->phase) {
    if(cJSON_AddStringToObject(item, "phase", v1_pod_status->phase) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_status->pod_ip
    if(v1_pod_status->pod_ip) {
    if(cJSON_AddStringToObject(item, "podIP", v1_pod_status->pod_ip) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_status->pod_ips
    if(v1_pod_status->pod_ips) {
    cJSON *pod_ips = cJSON_AddArrayToObject(item, "podIPs");
    if(pod_ips == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pod_ipsListEntry;
    if (v1_pod_status->pod_ips) {
    list_ForEach(pod_ipsListEntry, v1_pod_status->pod_ips) {
    cJSON *itemLocal = v1_pod_ip_convertToJSON(pod_ipsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(pod_ips, itemLocal);
    }
    }
    }


    // v1_pod_status->qos_class
    if(v1_pod_status->qos_class) {
    if(cJSON_AddStringToObject(item, "qosClass", v1_pod_status->qos_class) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_status->reason
    if(v1_pod_status->reason) {
    if(cJSON_AddStringToObject(item, "reason", v1_pod_status->reason) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_status->resize
    if(v1_pod_status->resize) {
    if(cJSON_AddStringToObject(item, "resize", v1_pod_status->resize) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_status->resource_claim_statuses
    if(v1_pod_status->resource_claim_statuses) {
    cJSON *resource_claim_statuses = cJSON_AddArrayToObject(item, "resourceClaimStatuses");
    if(resource_claim_statuses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resource_claim_statusesListEntry;
    if (v1_pod_status->resource_claim_statuses) {
    list_ForEach(resource_claim_statusesListEntry, v1_pod_status->resource_claim_statuses) {
    cJSON *itemLocal = v1_pod_resource_claim_status_convertToJSON(resource_claim_statusesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resource_claim_statuses, itemLocal);
    }
    }
    }


    // v1_pod_status->resources
    if(v1_pod_status->resources) {
    cJSON *resources_local_JSON = v1_resource_requirements_convertToJSON(v1_pod_status->resources);
    if(resources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resources", resources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_pod_status->start_time
    if(v1_pod_status->start_time) {
    if(cJSON_AddStringToObject(item, "startTime", v1_pod_status->start_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_pod_status->volume_health
    if(v1_pod_status->volume_health) {
    cJSON *volume_health = cJSON_AddArrayToObject(item, "volumeHealth");
    if(volume_health == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volume_healthListEntry;
    if (v1_pod_status->volume_health) {
    list_ForEach(volume_healthListEntry, v1_pod_status->volume_health) {
    cJSON *itemLocal = v1_pod_volume_health_convertToJSON(volume_healthListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volume_health, itemLocal);
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

v1_pod_status_t *v1_pod_status_parseFromJSON(cJSON *v1_pod_statusJSON){

    v1_pod_status_t *v1_pod_status_local_var = NULL;

    // define the local map for v1_pod_status->allocated_resources
    list_t *allocated_resourcesList = NULL;

    // define the local list for v1_pod_status->conditions
    list_t *conditionsList = NULL;

    // define the local list for v1_pod_status->container_statuses
    list_t *container_statusesList = NULL;

    // define the local list for v1_pod_status->ephemeral_container_statuses
    list_t *ephemeral_container_statusesList = NULL;

    // define the local variable for v1_pod_status->extended_resource_claim_status
    v1_pod_extended_resource_claim_status_t *extended_resource_claim_status_local_nonprim = NULL;

    char *host_ip_local_str = NULL;

    // define the local list for v1_pod_status->host_ips
    list_t *host_ipsList = NULL;

    // define the local list for v1_pod_status->init_container_statuses
    list_t *init_container_statusesList = NULL;

    char *message_local_str = NULL;

    // define the local list for v1_pod_status->node_allocatable_resource_claim_statuses
    list_t *node_allocatable_resource_claim_statusesList = NULL;

    char *nominated_node_name_local_str = NULL;

    // define the local variable for v1_pod_status->observed_generation
    long *observed_generation_local_var = NULL;

    char *phase_local_str = NULL;

    char *pod_ip_local_str = NULL;

    // define the local list for v1_pod_status->pod_ips
    list_t *pod_ipsList = NULL;

    char *qos_class_local_str = NULL;

    char *reason_local_str = NULL;

    char *resize_local_str = NULL;

    // define the local list for v1_pod_status->resource_claim_statuses
    list_t *resource_claim_statusesList = NULL;

    // define the local variable for v1_pod_status->resources
    v1_resource_requirements_t *resources_local_nonprim = NULL;

    char *start_time_local_str = NULL;

    // define the local list for v1_pod_status->volume_health
    list_t *volume_healthList = NULL;

    // v1_pod_status->allocated_resources
    cJSON *allocated_resources = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "allocatedResources");
    if (cJSON_IsNull(allocated_resources)) {
        allocated_resources = NULL;
    }
    if (allocated_resources) { 
    cJSON *allocated_resources_local_map = NULL;
    if(!cJSON_IsObject(allocated_resources) && !cJSON_IsNull(allocated_resources))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(allocated_resources))
    {
        allocated_resourcesList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(allocated_resources_local_map, allocated_resources)
        {
            cJSON *localMapObject = allocated_resources_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(allocated_resourcesList , localMapKeyPair);
        }
    }
    }

    // v1_pod_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "conditions");
    if (cJSON_IsNull(conditions)) {
        conditions = NULL;
    }
    if (conditions) { 
    cJSON *conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_pod_condition_t *conditionsItem = v1_pod_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_pod_status->container_statuses
    cJSON *container_statuses = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "containerStatuses");
    if (cJSON_IsNull(container_statuses)) {
        container_statuses = NULL;
    }
    if (container_statuses) { 
    cJSON *container_statuses_local_nonprimitive = NULL;
    if(!cJSON_IsArray(container_statuses)){
        goto end; //nonprimitive container
    }

    container_statusesList = list_createList();

    cJSON_ArrayForEach(container_statuses_local_nonprimitive,container_statuses )
    {
        if(!cJSON_IsObject(container_statuses_local_nonprimitive)){
            goto end;
        }
        v1_container_status_t *container_statusesItem = v1_container_status_parseFromJSON(container_statuses_local_nonprimitive);

        list_addElement(container_statusesList, container_statusesItem);
    }
    }

    // v1_pod_status->ephemeral_container_statuses
    cJSON *ephemeral_container_statuses = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "ephemeralContainerStatuses");
    if (cJSON_IsNull(ephemeral_container_statuses)) {
        ephemeral_container_statuses = NULL;
    }
    if (ephemeral_container_statuses) { 
    cJSON *ephemeral_container_statuses_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ephemeral_container_statuses)){
        goto end; //nonprimitive container
    }

    ephemeral_container_statusesList = list_createList();

    cJSON_ArrayForEach(ephemeral_container_statuses_local_nonprimitive,ephemeral_container_statuses )
    {
        if(!cJSON_IsObject(ephemeral_container_statuses_local_nonprimitive)){
            goto end;
        }
        v1_container_status_t *ephemeral_container_statusesItem = v1_container_status_parseFromJSON(ephemeral_container_statuses_local_nonprimitive);

        list_addElement(ephemeral_container_statusesList, ephemeral_container_statusesItem);
    }
    }

    // v1_pod_status->extended_resource_claim_status
    cJSON *extended_resource_claim_status = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "extendedResourceClaimStatus");
    if (cJSON_IsNull(extended_resource_claim_status)) {
        extended_resource_claim_status = NULL;
    }
    if (extended_resource_claim_status) { 
    extended_resource_claim_status_local_nonprim = v1_pod_extended_resource_claim_status_parseFromJSON(extended_resource_claim_status); //nonprimitive
    }

    // v1_pod_status->host_ip
    cJSON *host_ip = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "hostIP");
    if (cJSON_IsNull(host_ip)) {
        host_ip = NULL;
    }
    if (host_ip) { 
    if(!cJSON_IsString(host_ip) && !cJSON_IsNull(host_ip))
    {
    goto end; //String
    }
    }

    // v1_pod_status->host_ips
    cJSON *host_ips = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "hostIPs");
    if (cJSON_IsNull(host_ips)) {
        host_ips = NULL;
    }
    if (host_ips) { 
    cJSON *host_ips_local_nonprimitive = NULL;
    if(!cJSON_IsArray(host_ips)){
        goto end; //nonprimitive container
    }

    host_ipsList = list_createList();

    cJSON_ArrayForEach(host_ips_local_nonprimitive,host_ips )
    {
        if(!cJSON_IsObject(host_ips_local_nonprimitive)){
            goto end;
        }
        v1_host_ip_t *host_ipsItem = v1_host_ip_parseFromJSON(host_ips_local_nonprimitive);

        list_addElement(host_ipsList, host_ipsItem);
    }
    }

    // v1_pod_status->init_container_statuses
    cJSON *init_container_statuses = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "initContainerStatuses");
    if (cJSON_IsNull(init_container_statuses)) {
        init_container_statuses = NULL;
    }
    if (init_container_statuses) { 
    cJSON *init_container_statuses_local_nonprimitive = NULL;
    if(!cJSON_IsArray(init_container_statuses)){
        goto end; //nonprimitive container
    }

    init_container_statusesList = list_createList();

    cJSON_ArrayForEach(init_container_statuses_local_nonprimitive,init_container_statuses )
    {
        if(!cJSON_IsObject(init_container_statuses_local_nonprimitive)){
            goto end;
        }
        v1_container_status_t *init_container_statusesItem = v1_container_status_parseFromJSON(init_container_statuses_local_nonprimitive);

        list_addElement(init_container_statusesList, init_container_statusesItem);
    }
    }

    // v1_pod_status->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // v1_pod_status->node_allocatable_resource_claim_statuses
    cJSON *node_allocatable_resource_claim_statuses = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "nodeAllocatableResourceClaimStatuses");
    if (cJSON_IsNull(node_allocatable_resource_claim_statuses)) {
        node_allocatable_resource_claim_statuses = NULL;
    }
    if (node_allocatable_resource_claim_statuses) { 
    cJSON *node_allocatable_resource_claim_statuses_local_nonprimitive = NULL;
    if(!cJSON_IsArray(node_allocatable_resource_claim_statuses)){
        goto end; //nonprimitive container
    }

    node_allocatable_resource_claim_statusesList = list_createList();

    cJSON_ArrayForEach(node_allocatable_resource_claim_statuses_local_nonprimitive,node_allocatable_resource_claim_statuses )
    {
        if(!cJSON_IsObject(node_allocatable_resource_claim_statuses_local_nonprimitive)){
            goto end;
        }
        v1_node_allocatable_resource_claim_status_t *node_allocatable_resource_claim_statusesItem = v1_node_allocatable_resource_claim_status_parseFromJSON(node_allocatable_resource_claim_statuses_local_nonprimitive);

        list_addElement(node_allocatable_resource_claim_statusesList, node_allocatable_resource_claim_statusesItem);
    }
    }

    // v1_pod_status->nominated_node_name
    cJSON *nominated_node_name = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "nominatedNodeName");
    if (cJSON_IsNull(nominated_node_name)) {
        nominated_node_name = NULL;
    }
    if (nominated_node_name) { 
    if(!cJSON_IsString(nominated_node_name) && !cJSON_IsNull(nominated_node_name))
    {
    goto end; //String
    }
    }

    // v1_pod_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "observedGeneration");
    if (cJSON_IsNull(observed_generation)) {
        observed_generation = NULL;
    }
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    observed_generation_local_var = malloc(sizeof(long));
    if(!observed_generation_local_var)
    {
        goto end;
    }
    *observed_generation_local_var = observed_generation->valuedouble;
    }

    // v1_pod_status->phase
    cJSON *phase = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "phase");
    if (cJSON_IsNull(phase)) {
        phase = NULL;
    }
    if (phase) { 
    if(!cJSON_IsString(phase) && !cJSON_IsNull(phase))
    {
    goto end; //String
    }
    }

    // v1_pod_status->pod_ip
    cJSON *pod_ip = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "podIP");
    if (cJSON_IsNull(pod_ip)) {
        pod_ip = NULL;
    }
    if (pod_ip) { 
    if(!cJSON_IsString(pod_ip) && !cJSON_IsNull(pod_ip))
    {
    goto end; //String
    }
    }

    // v1_pod_status->pod_ips
    cJSON *pod_ips = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "podIPs");
    if (cJSON_IsNull(pod_ips)) {
        pod_ips = NULL;
    }
    if (pod_ips) { 
    cJSON *pod_ips_local_nonprimitive = NULL;
    if(!cJSON_IsArray(pod_ips)){
        goto end; //nonprimitive container
    }

    pod_ipsList = list_createList();

    cJSON_ArrayForEach(pod_ips_local_nonprimitive,pod_ips )
    {
        if(!cJSON_IsObject(pod_ips_local_nonprimitive)){
            goto end;
        }
        v1_pod_ip_t *pod_ipsItem = v1_pod_ip_parseFromJSON(pod_ips_local_nonprimitive);

        list_addElement(pod_ipsList, pod_ipsItem);
    }
    }

    // v1_pod_status->qos_class
    cJSON *qos_class = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "qosClass");
    if (cJSON_IsNull(qos_class)) {
        qos_class = NULL;
    }
    if (qos_class) { 
    if(!cJSON_IsString(qos_class) && !cJSON_IsNull(qos_class))
    {
    goto end; //String
    }
    }

    // v1_pod_status->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // v1_pod_status->resize
    cJSON *resize = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "resize");
    if (cJSON_IsNull(resize)) {
        resize = NULL;
    }
    if (resize) { 
    if(!cJSON_IsString(resize) && !cJSON_IsNull(resize))
    {
    goto end; //String
    }
    }

    // v1_pod_status->resource_claim_statuses
    cJSON *resource_claim_statuses = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "resourceClaimStatuses");
    if (cJSON_IsNull(resource_claim_statuses)) {
        resource_claim_statuses = NULL;
    }
    if (resource_claim_statuses) { 
    cJSON *resource_claim_statuses_local_nonprimitive = NULL;
    if(!cJSON_IsArray(resource_claim_statuses)){
        goto end; //nonprimitive container
    }

    resource_claim_statusesList = list_createList();

    cJSON_ArrayForEach(resource_claim_statuses_local_nonprimitive,resource_claim_statuses )
    {
        if(!cJSON_IsObject(resource_claim_statuses_local_nonprimitive)){
            goto end;
        }
        v1_pod_resource_claim_status_t *resource_claim_statusesItem = v1_pod_resource_claim_status_parseFromJSON(resource_claim_statuses_local_nonprimitive);

        list_addElement(resource_claim_statusesList, resource_claim_statusesItem);
    }
    }

    // v1_pod_status->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "resources");
    if (cJSON_IsNull(resources)) {
        resources = NULL;
    }
    if (resources) { 
    resources_local_nonprim = v1_resource_requirements_parseFromJSON(resources); //nonprimitive
    }

    // v1_pod_status->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "startTime");
    if (cJSON_IsNull(start_time)) {
        start_time = NULL;
    }
    if (start_time) { 
    if(!cJSON_IsString(start_time) && !cJSON_IsNull(start_time))
    {
    goto end; //DateTime
    }
    }

    // v1_pod_status->volume_health
    cJSON *volume_health = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "volumeHealth");
    if (cJSON_IsNull(volume_health)) {
        volume_health = NULL;
    }
    if (volume_health) { 
    cJSON *volume_health_local_nonprimitive = NULL;
    if(!cJSON_IsArray(volume_health)){
        goto end; //nonprimitive container
    }

    volume_healthList = list_createList();

    cJSON_ArrayForEach(volume_health_local_nonprimitive,volume_health )
    {
        if(!cJSON_IsObject(volume_health_local_nonprimitive)){
            goto end;
        }
        v1_pod_volume_health_t *volume_healthItem = v1_pod_volume_health_parseFromJSON(volume_health_local_nonprimitive);

        list_addElement(volume_healthList, volume_healthItem);
    }
    }


    if (host_ip && !cJSON_IsNull(host_ip)) host_ip_local_str = strdup(host_ip->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (nominated_node_name && !cJSON_IsNull(nominated_node_name)) nominated_node_name_local_str = strdup(nominated_node_name->valuestring);
    if (phase && !cJSON_IsNull(phase)) phase_local_str = strdup(phase->valuestring);
    if (pod_ip && !cJSON_IsNull(pod_ip)) pod_ip_local_str = strdup(pod_ip->valuestring);
    if (qos_class && !cJSON_IsNull(qos_class)) qos_class_local_str = strdup(qos_class->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);
    if (resize && !cJSON_IsNull(resize)) resize_local_str = strdup(resize->valuestring);
    if (start_time && !cJSON_IsNull(start_time)) start_time_local_str = strdup(start_time->valuestring);

    v1_pod_status_local_var = v1_pod_status_create_internal (
        allocated_resources ? allocated_resourcesList : NULL,
        conditions ? conditionsList : NULL,
        container_statuses ? container_statusesList : NULL,
        ephemeral_container_statuses ? ephemeral_container_statusesList : NULL,
        extended_resource_claim_status ? extended_resource_claim_status_local_nonprim : NULL,
        host_ip_local_str,
        host_ips ? host_ipsList : NULL,
        init_container_statuses ? init_container_statusesList : NULL,
        message_local_str,
        node_allocatable_resource_claim_statuses ? node_allocatable_resource_claim_statusesList : NULL,
        nominated_node_name_local_str,
        observed_generation_local_var,
        phase_local_str,
        pod_ip_local_str,
        pod_ips ? pod_ipsList : NULL,
        qos_class_local_str,
        reason_local_str,
        resize_local_str,
        resource_claim_statuses ? resource_claim_statusesList : NULL,
        resources ? resources_local_nonprim : NULL,
        start_time_local_str,
        volume_health ? volume_healthList : NULL
        );

    if (!v1_pod_status_local_var) {
        goto end;
    }

    return v1_pod_status_local_var;
end:
    if (allocated_resourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allocated_resourcesList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(allocated_resourcesList);
        allocated_resourcesList = NULL;
    }
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_pod_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (container_statusesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, container_statusesList) {
            v1_container_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(container_statusesList);
        container_statusesList = NULL;
    }
    if (ephemeral_container_statusesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ephemeral_container_statusesList) {
            v1_container_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ephemeral_container_statusesList);
        ephemeral_container_statusesList = NULL;
    }
    if (extended_resource_claim_status_local_nonprim) {
        v1_pod_extended_resource_claim_status_free(extended_resource_claim_status_local_nonprim);
        extended_resource_claim_status_local_nonprim = NULL;
    }
    if (host_ip_local_str) {
        free(host_ip_local_str);
        host_ip_local_str = NULL;
    }
    if (host_ipsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, host_ipsList) {
            v1_host_ip_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(host_ipsList);
        host_ipsList = NULL;
    }
    if (init_container_statusesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, init_container_statusesList) {
            v1_container_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(init_container_statusesList);
        init_container_statusesList = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (node_allocatable_resource_claim_statusesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, node_allocatable_resource_claim_statusesList) {
            v1_node_allocatable_resource_claim_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(node_allocatable_resource_claim_statusesList);
        node_allocatable_resource_claim_statusesList = NULL;
    }
    if (nominated_node_name_local_str) {
        free(nominated_node_name_local_str);
        nominated_node_name_local_str = NULL;
    }
    if (observed_generation_local_var) {
        free(observed_generation_local_var);
        observed_generation_local_var = NULL;
    }
    if (phase_local_str) {
        free(phase_local_str);
        phase_local_str = NULL;
    }
    if (pod_ip_local_str) {
        free(pod_ip_local_str);
        pod_ip_local_str = NULL;
    }
    if (pod_ipsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pod_ipsList) {
            v1_pod_ip_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(pod_ipsList);
        pod_ipsList = NULL;
    }
    if (qos_class_local_str) {
        free(qos_class_local_str);
        qos_class_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    if (resize_local_str) {
        free(resize_local_str);
        resize_local_str = NULL;
    }
    if (resource_claim_statusesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resource_claim_statusesList) {
            v1_pod_resource_claim_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resource_claim_statusesList);
        resource_claim_statusesList = NULL;
    }
    if (resources_local_nonprim) {
        v1_resource_requirements_free(resources_local_nonprim);
        resources_local_nonprim = NULL;
    }
    if (start_time_local_str) {
        free(start_time_local_str);
        start_time_local_str = NULL;
    }
    if (volume_healthList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, volume_healthList) {
            v1_pod_volume_health_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(volume_healthList);
        volume_healthList = NULL;
    }
    return NULL;

}
