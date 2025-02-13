#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_flocker_volume_source.h"



static v1_flocker_volume_source_t *v1_flocker_volume_source_create_internal(
    char *dataset_name,
    char *dataset_uuid
    ) {
    v1_flocker_volume_source_t *v1_flocker_volume_source_local_var = malloc(sizeof(v1_flocker_volume_source_t));
    if (!v1_flocker_volume_source_local_var) {
        return NULL;
    }
    v1_flocker_volume_source_local_var->dataset_name = dataset_name;
    v1_flocker_volume_source_local_var->dataset_uuid = dataset_uuid;

    v1_flocker_volume_source_local_var->_library_owned = 1;
    return v1_flocker_volume_source_local_var;
}

__attribute__((deprecated)) v1_flocker_volume_source_t *v1_flocker_volume_source_create(
    char *dataset_name,
    char *dataset_uuid
    ) {
    return v1_flocker_volume_source_create_internal (
        dataset_name,
        dataset_uuid
        );
}

void v1_flocker_volume_source_free(v1_flocker_volume_source_t *v1_flocker_volume_source) {
    if(NULL == v1_flocker_volume_source){
        return ;
    }
    if(v1_flocker_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_flocker_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_flocker_volume_source->dataset_name) {
        free(v1_flocker_volume_source->dataset_name);
        v1_flocker_volume_source->dataset_name = NULL;
    }
    if (v1_flocker_volume_source->dataset_uuid) {
        free(v1_flocker_volume_source->dataset_uuid);
        v1_flocker_volume_source->dataset_uuid = NULL;
    }
    free(v1_flocker_volume_source);
}

cJSON *v1_flocker_volume_source_convertToJSON(v1_flocker_volume_source_t *v1_flocker_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_flocker_volume_source->dataset_name
    if(v1_flocker_volume_source->dataset_name) {
    if(cJSON_AddStringToObject(item, "datasetName", v1_flocker_volume_source->dataset_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_flocker_volume_source->dataset_uuid
    if(v1_flocker_volume_source->dataset_uuid) {
    if(cJSON_AddStringToObject(item, "datasetUUID", v1_flocker_volume_source->dataset_uuid) == NULL) {
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

v1_flocker_volume_source_t *v1_flocker_volume_source_parseFromJSON(cJSON *v1_flocker_volume_sourceJSON){

    v1_flocker_volume_source_t *v1_flocker_volume_source_local_var = NULL;

    // v1_flocker_volume_source->dataset_name
    cJSON *dataset_name = cJSON_GetObjectItemCaseSensitive(v1_flocker_volume_sourceJSON, "datasetName");
    if (cJSON_IsNull(dataset_name)) {
        dataset_name = NULL;
    }
    if (dataset_name) { 
    if(!cJSON_IsString(dataset_name) && !cJSON_IsNull(dataset_name))
    {
    goto end; //String
    }
    }

    // v1_flocker_volume_source->dataset_uuid
    cJSON *dataset_uuid = cJSON_GetObjectItemCaseSensitive(v1_flocker_volume_sourceJSON, "datasetUUID");
    if (cJSON_IsNull(dataset_uuid)) {
        dataset_uuid = NULL;
    }
    if (dataset_uuid) { 
    if(!cJSON_IsString(dataset_uuid) && !cJSON_IsNull(dataset_uuid))
    {
    goto end; //String
    }
    }


    v1_flocker_volume_source_local_var = v1_flocker_volume_source_create_internal (
        dataset_name && !cJSON_IsNull(dataset_name) ? strdup(dataset_name->valuestring) : NULL,
        dataset_uuid && !cJSON_IsNull(dataset_uuid) ? strdup(dataset_uuid->valuestring) : NULL
        );

    return v1_flocker_volume_source_local_var;
end:
    return NULL;

}
