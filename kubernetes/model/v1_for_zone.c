#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_for_zone.h"



static v1_for_zone_t *v1_for_zone_create_internal(
    char *name
    ) {
    v1_for_zone_t *v1_for_zone_local_var = malloc(sizeof(v1_for_zone_t));
    if (!v1_for_zone_local_var) {
        return NULL;
    }
    v1_for_zone_local_var->name = name;

    v1_for_zone_local_var->_library_owned = 1;
    return v1_for_zone_local_var;
}

__attribute__((deprecated)) v1_for_zone_t *v1_for_zone_create(
    char *name
    ) {
    return v1_for_zone_create_internal (
        name
        );
}

void v1_for_zone_free(v1_for_zone_t *v1_for_zone) {
    if(NULL == v1_for_zone){
        return ;
    }
    if(v1_for_zone->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_for_zone_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_for_zone->name) {
        free(v1_for_zone->name);
        v1_for_zone->name = NULL;
    }
    free(v1_for_zone);
}

cJSON *v1_for_zone_convertToJSON(v1_for_zone_t *v1_for_zone) {
    cJSON *item = cJSON_CreateObject();

    // v1_for_zone->name
    if (!v1_for_zone->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_for_zone->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_for_zone_t *v1_for_zone_parseFromJSON(cJSON *v1_for_zoneJSON){

    v1_for_zone_t *v1_for_zone_local_var = NULL;

    // v1_for_zone->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_for_zoneJSON, "name");
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


    v1_for_zone_local_var = v1_for_zone_create_internal (
        strdup(name->valuestring)
        );

    return v1_for_zone_local_var;
end:
    return NULL;

}
