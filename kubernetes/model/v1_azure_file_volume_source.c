#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_azure_file_volume_source.h"



v1_azure_file_volume_source_t *v1_azure_file_volume_source_create(
    int read_only,
    char *secret_name,
    char *share_name
    ) {
    v1_azure_file_volume_source_t *v1_azure_file_volume_source_local_var = malloc(sizeof(v1_azure_file_volume_source_t));
    if (!v1_azure_file_volume_source_local_var) {
        return NULL;
    }
    v1_azure_file_volume_source_local_var->read_only = read_only;
    v1_azure_file_volume_source_local_var->secret_name = secret_name;
    v1_azure_file_volume_source_local_var->share_name = share_name;

    return v1_azure_file_volume_source_local_var;
}


void v1_azure_file_volume_source_free(v1_azure_file_volume_source_t *v1_azure_file_volume_source) {
    if(NULL == v1_azure_file_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_azure_file_volume_source->secret_name) {
        free(v1_azure_file_volume_source->secret_name);
        v1_azure_file_volume_source->secret_name = NULL;
    }
    if (v1_azure_file_volume_source->share_name) {
        free(v1_azure_file_volume_source->share_name);
        v1_azure_file_volume_source->share_name = NULL;
    }
    free(v1_azure_file_volume_source);
}

cJSON *v1_azure_file_volume_source_convertToJSON(v1_azure_file_volume_source_t *v1_azure_file_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_azure_file_volume_source->read_only
    if(v1_azure_file_volume_source->read_only) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_azure_file_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_azure_file_volume_source->secret_name
    if (!v1_azure_file_volume_source->secret_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "secretName", v1_azure_file_volume_source->secret_name) == NULL) {
    goto fail; //String
    }


    // v1_azure_file_volume_source->share_name
    if (!v1_azure_file_volume_source->share_name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "shareName", v1_azure_file_volume_source->share_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_azure_file_volume_source_t *v1_azure_file_volume_source_parseFromJSON(cJSON *v1_azure_file_volume_sourceJSON){

    v1_azure_file_volume_source_t *v1_azure_file_volume_source_local_var = NULL;

    // v1_azure_file_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_azure_file_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_azure_file_volume_source->secret_name
    cJSON *secret_name = cJSON_GetObjectItemCaseSensitive(v1_azure_file_volume_sourceJSON, "secretName");
    if (!secret_name) {
        goto end;
    }

    
    if(!cJSON_IsString(secret_name))
    {
    goto end; //String
    }

    // v1_azure_file_volume_source->share_name
    cJSON *share_name = cJSON_GetObjectItemCaseSensitive(v1_azure_file_volume_sourceJSON, "shareName");
    if (!share_name) {
        goto end;
    }

    
    if(!cJSON_IsString(share_name))
    {
    goto end; //String
    }


    v1_azure_file_volume_source_local_var = v1_azure_file_volume_source_create (
        read_only ? read_only->valueint : 0,
        strdup(secret_name->valuestring),
        strdup(share_name->valuestring)
        );

    return v1_azure_file_volume_source_local_var;
end:
    return NULL;

}
