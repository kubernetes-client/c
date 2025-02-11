#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_group_version_for_discovery.h"



static v1_group_version_for_discovery_t *v1_group_version_for_discovery_create_internal(
    char *group_version,
    char *version
    ) {
    v1_group_version_for_discovery_t *v1_group_version_for_discovery_local_var = malloc(sizeof(v1_group_version_for_discovery_t));
    if (!v1_group_version_for_discovery_local_var) {
        return NULL;
    }
    v1_group_version_for_discovery_local_var->group_version = group_version;
    v1_group_version_for_discovery_local_var->version = version;

    v1_group_version_for_discovery_local_var->_library_owned = 1;
    return v1_group_version_for_discovery_local_var;
}

__attribute__((deprecated)) v1_group_version_for_discovery_t *v1_group_version_for_discovery_create(
    char *group_version,
    char *version
    ) {
    return v1_group_version_for_discovery_create_internal (
        group_version,
        version
        );
}

void v1_group_version_for_discovery_free(v1_group_version_for_discovery_t *v1_group_version_for_discovery) {
    if(NULL == v1_group_version_for_discovery){
        return ;
    }
    if(v1_group_version_for_discovery->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_group_version_for_discovery_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_group_version_for_discovery->group_version) {
        free(v1_group_version_for_discovery->group_version);
        v1_group_version_for_discovery->group_version = NULL;
    }
    if (v1_group_version_for_discovery->version) {
        free(v1_group_version_for_discovery->version);
        v1_group_version_for_discovery->version = NULL;
    }
    free(v1_group_version_for_discovery);
}

cJSON *v1_group_version_for_discovery_convertToJSON(v1_group_version_for_discovery_t *v1_group_version_for_discovery) {
    cJSON *item = cJSON_CreateObject();

    // v1_group_version_for_discovery->group_version
    if (!v1_group_version_for_discovery->group_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "groupVersion", v1_group_version_for_discovery->group_version) == NULL) {
    goto fail; //String
    }


    // v1_group_version_for_discovery->version
    if (!v1_group_version_for_discovery->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", v1_group_version_for_discovery->version) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_group_version_for_discovery_t *v1_group_version_for_discovery_parseFromJSON(cJSON *v1_group_version_for_discoveryJSON){

    v1_group_version_for_discovery_t *v1_group_version_for_discovery_local_var = NULL;

    // v1_group_version_for_discovery->group_version
    cJSON *group_version = cJSON_GetObjectItemCaseSensitive(v1_group_version_for_discoveryJSON, "groupVersion");
    if (cJSON_IsNull(group_version)) {
        group_version = NULL;
    }
    if (!group_version) {
        goto end;
    }

    
    if(!cJSON_IsString(group_version))
    {
    goto end; //String
    }

    // v1_group_version_for_discovery->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1_group_version_for_discoveryJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (!version) {
        goto end;
    }

    
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }


    v1_group_version_for_discovery_local_var = v1_group_version_for_discovery_create_internal (
        strdup(group_version->valuestring),
        strdup(version->valuestring)
        );

    return v1_group_version_for_discovery_local_var;
end:
    return NULL;

}
