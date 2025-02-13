#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_os.h"



static v1_pod_os_t *v1_pod_os_create_internal(
    char *name
    ) {
    v1_pod_os_t *v1_pod_os_local_var = malloc(sizeof(v1_pod_os_t));
    if (!v1_pod_os_local_var) {
        return NULL;
    }
    v1_pod_os_local_var->name = name;

    v1_pod_os_local_var->_library_owned = 1;
    return v1_pod_os_local_var;
}

__attribute__((deprecated)) v1_pod_os_t *v1_pod_os_create(
    char *name
    ) {
    return v1_pod_os_create_internal (
        name
        );
}

void v1_pod_os_free(v1_pod_os_t *v1_pod_os) {
    if(NULL == v1_pod_os){
        return ;
    }
    if(v1_pod_os->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_os_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_os->name) {
        free(v1_pod_os->name);
        v1_pod_os->name = NULL;
    }
    free(v1_pod_os);
}

cJSON *v1_pod_os_convertToJSON(v1_pod_os_t *v1_pod_os) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_os->name
    if (!v1_pod_os->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_pod_os->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_os_t *v1_pod_os_parseFromJSON(cJSON *v1_pod_osJSON){

    v1_pod_os_t *v1_pod_os_local_var = NULL;

    // v1_pod_os->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_pod_osJSON, "name");
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


    v1_pod_os_local_var = v1_pod_os_create_internal (
        strdup(name->valuestring)
        );

    return v1_pod_os_local_var;
end:
    return NULL;

}
