#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_shareable_capacity_status.h"



static v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status_create_internal(
    char *available,
    char *consumed,
    char *name,
    char *total
    ) {
    v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status_local_var = malloc(sizeof(v1alpha3_shareable_capacity_status_t));
    if (!v1alpha3_shareable_capacity_status_local_var) {
        return NULL;
    }
    memset(v1alpha3_shareable_capacity_status_local_var, 0, sizeof(v1alpha3_shareable_capacity_status_t));
    v1alpha3_shareable_capacity_status_local_var->_library_owned = 1;
    v1alpha3_shareable_capacity_status_local_var->available = available;
    v1alpha3_shareable_capacity_status_local_var->consumed = consumed;
    v1alpha3_shareable_capacity_status_local_var->name = name;
    v1alpha3_shareable_capacity_status_local_var->total = total;
    return v1alpha3_shareable_capacity_status_local_var;
}

__attribute__((deprecated)) v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status_create(
    char *available,
    char *consumed,
    char *name,
    char *total
    ) {
    v1alpha3_shareable_capacity_status_t *result = v1alpha3_shareable_capacity_status_create_internal (
        available,
        consumed,
        name,
        total
        );
    if (!result) {
    }
    return result;
}

void v1alpha3_shareable_capacity_status_free(v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status) {
    if(NULL == v1alpha3_shareable_capacity_status){
        return ;
    }
    if(v1alpha3_shareable_capacity_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_shareable_capacity_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_shareable_capacity_status->available) {
        free(v1alpha3_shareable_capacity_status->available);
        v1alpha3_shareable_capacity_status->available = NULL;
    }
    if (v1alpha3_shareable_capacity_status->consumed) {
        free(v1alpha3_shareable_capacity_status->consumed);
        v1alpha3_shareable_capacity_status->consumed = NULL;
    }
    if (v1alpha3_shareable_capacity_status->name) {
        free(v1alpha3_shareable_capacity_status->name);
        v1alpha3_shareable_capacity_status->name = NULL;
    }
    if (v1alpha3_shareable_capacity_status->total) {
        free(v1alpha3_shareable_capacity_status->total);
        v1alpha3_shareable_capacity_status->total = NULL;
    }
    free(v1alpha3_shareable_capacity_status);
}

cJSON *v1alpha3_shareable_capacity_status_convertToJSON(v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_shareable_capacity_status->available
    if (!v1alpha3_shareable_capacity_status->available) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "available", v1alpha3_shareable_capacity_status->available) == NULL) {
    goto fail; //String
    }


    // v1alpha3_shareable_capacity_status->consumed
    if (!v1alpha3_shareable_capacity_status->consumed) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "consumed", v1alpha3_shareable_capacity_status->consumed) == NULL) {
    goto fail; //String
    }


    // v1alpha3_shareable_capacity_status->name
    if (!v1alpha3_shareable_capacity_status->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha3_shareable_capacity_status->name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_shareable_capacity_status->total
    if (!v1alpha3_shareable_capacity_status->total) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "total", v1alpha3_shareable_capacity_status->total) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status_parseFromJSON(cJSON *v1alpha3_shareable_capacity_statusJSON){

    v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status_local_var = NULL;

    char *available_local_str = NULL;

    char *consumed_local_str = NULL;

    char *name_local_str = NULL;

    char *total_local_str = NULL;

    // v1alpha3_shareable_capacity_status->available
    cJSON *available = cJSON_GetObjectItemCaseSensitive(v1alpha3_shareable_capacity_statusJSON, "available");
    if (cJSON_IsNull(available)) {
        available = NULL;
    }
    if (!available) {
        goto end;
    }

    
    if(!cJSON_IsString(available))
    {
    goto end; //String
    }

    // v1alpha3_shareable_capacity_status->consumed
    cJSON *consumed = cJSON_GetObjectItemCaseSensitive(v1alpha3_shareable_capacity_statusJSON, "consumed");
    if (cJSON_IsNull(consumed)) {
        consumed = NULL;
    }
    if (!consumed) {
        goto end;
    }

    
    if(!cJSON_IsString(consumed))
    {
    goto end; //String
    }

    // v1alpha3_shareable_capacity_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha3_shareable_capacity_statusJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha3_shareable_capacity_status->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(v1alpha3_shareable_capacity_statusJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (!total) {
        goto end;
    }

    
    if(!cJSON_IsString(total))
    {
    goto end; //String
    }


    if (available && !cJSON_IsNull(available)) available_local_str = strdup(available->valuestring);
    if (consumed && !cJSON_IsNull(consumed)) consumed_local_str = strdup(consumed->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (total && !cJSON_IsNull(total)) total_local_str = strdup(total->valuestring);

    v1alpha3_shareable_capacity_status_local_var = v1alpha3_shareable_capacity_status_create_internal (
        available_local_str,
        consumed_local_str,
        name_local_str,
        total_local_str
        );

    if (!v1alpha3_shareable_capacity_status_local_var) {
        goto end;
    }

    return v1alpha3_shareable_capacity_status_local_var;
end:
    if (available_local_str) {
        free(available_local_str);
        available_local_str = NULL;
    }
    if (consumed_local_str) {
        free(consumed_local_str);
        consumed_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (total_local_str) {
        free(total_local_str);
        total_local_str = NULL;
    }
    return NULL;

}
