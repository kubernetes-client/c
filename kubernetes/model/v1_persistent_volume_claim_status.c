#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_claim_status.h"



v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_create(
    list_t *access_modes,
    list_t* capacity,
    list_t *conditions,
    char *phase
    ) {
    v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_local_var = malloc(sizeof(v1_persistent_volume_claim_status_t));
    if (!v1_persistent_volume_claim_status_local_var) {
        return NULL;
    }
    v1_persistent_volume_claim_status_local_var->access_modes = access_modes;
    v1_persistent_volume_claim_status_local_var->capacity = capacity;
    v1_persistent_volume_claim_status_local_var->conditions = conditions;
    v1_persistent_volume_claim_status_local_var->phase = phase;

    return v1_persistent_volume_claim_status_local_var;
}


void v1_persistent_volume_claim_status_free(v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status) {
    if(NULL == v1_persistent_volume_claim_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_persistent_volume_claim_status->access_modes) {
        list_ForEach(listEntry, v1_persistent_volume_claim_status->access_modes) {
            free(listEntry->data);
        }
        list_free(v1_persistent_volume_claim_status->access_modes);
        v1_persistent_volume_claim_status->access_modes = NULL;
    }
    if (v1_persistent_volume_claim_status->capacity) {
        list_ForEach(listEntry, v1_persistent_volume_claim_status->capacity) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_persistent_volume_claim_status->capacity);
        v1_persistent_volume_claim_status->capacity = NULL;
    }
    if (v1_persistent_volume_claim_status->conditions) {
        list_ForEach(listEntry, v1_persistent_volume_claim_status->conditions) {
            v1_persistent_volume_claim_condition_free(listEntry->data);
        }
        list_free(v1_persistent_volume_claim_status->conditions);
        v1_persistent_volume_claim_status->conditions = NULL;
    }
    if (v1_persistent_volume_claim_status->phase) {
        free(v1_persistent_volume_claim_status->phase);
        v1_persistent_volume_claim_status->phase = NULL;
    }
    free(v1_persistent_volume_claim_status);
}

cJSON *v1_persistent_volume_claim_status_convertToJSON(v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_persistent_volume_claim_status->access_modes
    if(v1_persistent_volume_claim_status->access_modes) { 
    cJSON *access_modes = cJSON_AddArrayToObject(item, "accessModes");
    if(access_modes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *access_modesListEntry;
    list_ForEach(access_modesListEntry, v1_persistent_volume_claim_status->access_modes) {
    if(cJSON_AddStringToObject(access_modes, "", (char*)access_modesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_persistent_volume_claim_status->capacity
    if(v1_persistent_volume_claim_status->capacity) { 
    cJSON *capacity = cJSON_AddObjectToObject(item, "capacity");
    if(capacity == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = capacity;
    listEntry_t *capacityListEntry;
    if (v1_persistent_volume_claim_status->capacity) {
    list_ForEach(capacityListEntry, v1_persistent_volume_claim_status->capacity) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)capacityListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_persistent_volume_claim_status->conditions
    if(v1_persistent_volume_claim_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_persistent_volume_claim_status->conditions) {
    list_ForEach(conditionsListEntry, v1_persistent_volume_claim_status->conditions) {
    cJSON *itemLocal = v1_persistent_volume_claim_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


    // v1_persistent_volume_claim_status->phase
    if(v1_persistent_volume_claim_status->phase) { 
    if(cJSON_AddStringToObject(item, "phase", v1_persistent_volume_claim_status->phase) == NULL) {
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

v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_parseFromJSON(cJSON *v1_persistent_volume_claim_statusJSON){

    v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_local_var = NULL;

    // v1_persistent_volume_claim_status->access_modes
    cJSON *access_modes = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "accessModes");
    list_t *access_modesList;
    if (access_modes) { 
    cJSON *access_modes_local;
    if(!cJSON_IsArray(access_modes)) {
        goto end;//primitive container
    }
    access_modesList = list_create();

    cJSON_ArrayForEach(access_modes_local, access_modes)
    {
        if(!cJSON_IsString(access_modes_local))
        {
            goto end;
        }
        list_addElement(access_modesList , strdup(access_modes_local->valuestring));
    }
    }

    // v1_persistent_volume_claim_status->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "capacity");
    list_t *capacityList;
    if (capacity) { 
    cJSON *capacity_local_map;
    if(!cJSON_IsObject(capacity)) {
        goto end;//primitive map container
    }
    capacityList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(capacity_local_map, capacity)
    {
		cJSON *localMapObject = capacity_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(capacityList , localMapKeyPair);
    }
    }

    // v1_persistent_volume_claim_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "conditions");
    list_t *conditionsList;
    if (conditions) { 
    cJSON *conditions_local_nonprimitive;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_create();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_persistent_volume_claim_condition_t *conditionsItem = v1_persistent_volume_claim_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_persistent_volume_claim_status->phase
    cJSON *phase = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "phase");
    if (phase) { 
    if(!cJSON_IsString(phase))
    {
    goto end; //String
    }
    }


    v1_persistent_volume_claim_status_local_var = v1_persistent_volume_claim_status_create (
        access_modes ? access_modesList : NULL,
        capacity ? capacityList : NULL,
        conditions ? conditionsList : NULL,
        phase ? strdup(phase->valuestring) : NULL
        );

    return v1_persistent_volume_claim_status_local_var;
end:
    return NULL;

}
