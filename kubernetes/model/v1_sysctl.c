#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_sysctl.h"



static v1_sysctl_t *v1_sysctl_create_internal(
    char *name,
    char *value
    ) {
    v1_sysctl_t *v1_sysctl_local_var = malloc(sizeof(v1_sysctl_t));
    if (!v1_sysctl_local_var) {
        return NULL;
    }
    v1_sysctl_local_var->name = name;
    v1_sysctl_local_var->value = value;

    v1_sysctl_local_var->_library_owned = 1;
    return v1_sysctl_local_var;
}

__attribute__((deprecated)) v1_sysctl_t *v1_sysctl_create(
    char *name,
    char *value
    ) {
    return v1_sysctl_create_internal (
        name,
        value
        );
}

void v1_sysctl_free(v1_sysctl_t *v1_sysctl) {
    if(NULL == v1_sysctl){
        return ;
    }
    if(v1_sysctl->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_sysctl_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_sysctl->name) {
        free(v1_sysctl->name);
        v1_sysctl->name = NULL;
    }
    if (v1_sysctl->value) {
        free(v1_sysctl->value);
        v1_sysctl->value = NULL;
    }
    free(v1_sysctl);
}

cJSON *v1_sysctl_convertToJSON(v1_sysctl_t *v1_sysctl) {
    cJSON *item = cJSON_CreateObject();

    // v1_sysctl->name
    if (!v1_sysctl->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_sysctl->name) == NULL) {
    goto fail; //String
    }


    // v1_sysctl->value
    if (!v1_sysctl->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", v1_sysctl->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_sysctl_t *v1_sysctl_parseFromJSON(cJSON *v1_sysctlJSON){

    v1_sysctl_t *v1_sysctl_local_var = NULL;

    // v1_sysctl->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_sysctlJSON, "name");
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

    // v1_sysctl->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_sysctlJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    v1_sysctl_local_var = v1_sysctl_create_internal (
        strdup(name->valuestring),
        strdup(value->valuestring)
        );

    return v1_sysctl_local_var;
end:
    return NULL;

}
