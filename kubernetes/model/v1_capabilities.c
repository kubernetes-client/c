#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_capabilities.h"



v1_capabilities_t *v1_capabilities_create(
    list_t *add,
    list_t *drop
    ) {
    v1_capabilities_t *v1_capabilities_local_var = malloc(sizeof(v1_capabilities_t));
    if (!v1_capabilities_local_var) {
        return NULL;
    }
    v1_capabilities_local_var->add = add;
    v1_capabilities_local_var->drop = drop;

    return v1_capabilities_local_var;
}


void v1_capabilities_free(v1_capabilities_t *v1_capabilities) {
    if(NULL == v1_capabilities){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_capabilities->add) {
        list_ForEach(listEntry, v1_capabilities->add) {
            free(listEntry->data);
        }
        list_free(v1_capabilities->add);
        v1_capabilities->add = NULL;
    }
    if (v1_capabilities->drop) {
        list_ForEach(listEntry, v1_capabilities->drop) {
            free(listEntry->data);
        }
        list_free(v1_capabilities->drop);
        v1_capabilities->drop = NULL;
    }
    free(v1_capabilities);
}

cJSON *v1_capabilities_convertToJSON(v1_capabilities_t *v1_capabilities) {
    cJSON *item = cJSON_CreateObject();

    // v1_capabilities->add
    if(v1_capabilities->add) { 
    cJSON *add = cJSON_AddArrayToObject(item, "add");
    if(add == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *addListEntry;
    list_ForEach(addListEntry, v1_capabilities->add) {
    if(cJSON_AddStringToObject(add, "", (char*)addListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_capabilities->drop
    if(v1_capabilities->drop) { 
    cJSON *drop = cJSON_AddArrayToObject(item, "drop");
    if(drop == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dropListEntry;
    list_ForEach(dropListEntry, v1_capabilities->drop) {
    if(cJSON_AddStringToObject(drop, "", (char*)dropListEntry->data) == NULL)
    {
        goto fail;
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

v1_capabilities_t *v1_capabilities_parseFromJSON(cJSON *v1_capabilitiesJSON){

    v1_capabilities_t *v1_capabilities_local_var = NULL;

    // v1_capabilities->add
    cJSON *add = cJSON_GetObjectItemCaseSensitive(v1_capabilitiesJSON, "add");
    list_t *addList;
    if (add) { 
    cJSON *add_local;
    if(!cJSON_IsArray(add)) {
        goto end;//primitive container
    }
    addList = list_create();

    cJSON_ArrayForEach(add_local, add)
    {
        if(!cJSON_IsString(add_local))
        {
            goto end;
        }
        list_addElement(addList , strdup(add_local->valuestring));
    }
    }

    // v1_capabilities->drop
    cJSON *drop = cJSON_GetObjectItemCaseSensitive(v1_capabilitiesJSON, "drop");
    list_t *dropList;
    if (drop) { 
    cJSON *drop_local;
    if(!cJSON_IsArray(drop)) {
        goto end;//primitive container
    }
    dropList = list_create();

    cJSON_ArrayForEach(drop_local, drop)
    {
        if(!cJSON_IsString(drop_local))
        {
            goto end;
        }
        list_addElement(dropList , strdup(drop_local->valuestring));
    }
    }


    v1_capabilities_local_var = v1_capabilities_create (
        add ? addList : NULL,
        drop ? dropList : NULL
        );

    return v1_capabilities_local_var;
end:
    return NULL;

}
