#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ip_block.h"



static v1_ip_block_t *v1_ip_block_create_internal(
    char *cidr,
    list_t *except
    ) {
    v1_ip_block_t *v1_ip_block_local_var = malloc(sizeof(v1_ip_block_t));
    if (!v1_ip_block_local_var) {
        return NULL;
    }
    v1_ip_block_local_var->cidr = cidr;
    v1_ip_block_local_var->except = except;

    v1_ip_block_local_var->_library_owned = 1;
    return v1_ip_block_local_var;
}

__attribute__((deprecated)) v1_ip_block_t *v1_ip_block_create(
    char *cidr,
    list_t *except
    ) {
    return v1_ip_block_create_internal (
        cidr,
        except
        );
}

void v1_ip_block_free(v1_ip_block_t *v1_ip_block) {
    if(NULL == v1_ip_block){
        return ;
    }
    if(v1_ip_block->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ip_block_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ip_block->cidr) {
        free(v1_ip_block->cidr);
        v1_ip_block->cidr = NULL;
    }
    if (v1_ip_block->except) {
        list_ForEach(listEntry, v1_ip_block->except) {
            free(listEntry->data);
        }
        list_freeList(v1_ip_block->except);
        v1_ip_block->except = NULL;
    }
    free(v1_ip_block);
}

cJSON *v1_ip_block_convertToJSON(v1_ip_block_t *v1_ip_block) {
    cJSON *item = cJSON_CreateObject();

    // v1_ip_block->cidr
    if (!v1_ip_block->cidr) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "cidr", v1_ip_block->cidr) == NULL) {
    goto fail; //String
    }


    // v1_ip_block->except
    if(v1_ip_block->except) {
    cJSON *except = cJSON_AddArrayToObject(item, "except");
    if(except == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *exceptListEntry;
    list_ForEach(exceptListEntry, v1_ip_block->except) {
    if(cJSON_AddStringToObject(except, "", exceptListEntry->data) == NULL)
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

v1_ip_block_t *v1_ip_block_parseFromJSON(cJSON *v1_ip_blockJSON){

    v1_ip_block_t *v1_ip_block_local_var = NULL;

    // define the local list for v1_ip_block->except
    list_t *exceptList = NULL;

    // v1_ip_block->cidr
    cJSON *cidr = cJSON_GetObjectItemCaseSensitive(v1_ip_blockJSON, "cidr");
    if (cJSON_IsNull(cidr)) {
        cidr = NULL;
    }
    if (!cidr) {
        goto end;
    }

    
    if(!cJSON_IsString(cidr))
    {
    goto end; //String
    }

    // v1_ip_block->except
    cJSON *except = cJSON_GetObjectItemCaseSensitive(v1_ip_blockJSON, "except");
    if (cJSON_IsNull(except)) {
        except = NULL;
    }
    if (except) { 
    cJSON *except_local = NULL;
    if(!cJSON_IsArray(except)) {
        goto end;//primitive container
    }
    exceptList = list_createList();

    cJSON_ArrayForEach(except_local, except)
    {
        if(!cJSON_IsString(except_local))
        {
            goto end;
        }
        list_addElement(exceptList , strdup(except_local->valuestring));
    }
    }


    v1_ip_block_local_var = v1_ip_block_create_internal (
        strdup(cidr->valuestring),
        except ? exceptList : NULL
        );

    return v1_ip_block_local_var;
end:
    if (exceptList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, exceptList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(exceptList);
        exceptList = NULL;
    }
    return NULL;

}
