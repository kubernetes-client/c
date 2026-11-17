#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_requester.h"



static v1alpha1_requester_t *v1alpha1_requester_create_internal(
    char *intent,
    char *name
    ) {
    v1alpha1_requester_t *v1alpha1_requester_local_var = malloc(sizeof(v1alpha1_requester_t));
    if (!v1alpha1_requester_local_var) {
        return NULL;
    }
    memset(v1alpha1_requester_local_var, 0, sizeof(v1alpha1_requester_t));
    v1alpha1_requester_local_var->_library_owned = 1;
    v1alpha1_requester_local_var->intent = intent;
    v1alpha1_requester_local_var->name = name;
    return v1alpha1_requester_local_var;
}

__attribute__((deprecated)) v1alpha1_requester_t *v1alpha1_requester_create(
    char *intent,
    char *name
    ) {
    v1alpha1_requester_t *result = v1alpha1_requester_create_internal (
        intent,
        name
        );
    if (!result) {
    }
    return result;
}

void v1alpha1_requester_free(v1alpha1_requester_t *v1alpha1_requester) {
    if(NULL == v1alpha1_requester){
        return ;
    }
    if(v1alpha1_requester->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha1_requester_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_requester->intent) {
        free(v1alpha1_requester->intent);
        v1alpha1_requester->intent = NULL;
    }
    if (v1alpha1_requester->name) {
        free(v1alpha1_requester->name);
        v1alpha1_requester->name = NULL;
    }
    free(v1alpha1_requester);
}

cJSON *v1alpha1_requester_convertToJSON(v1alpha1_requester_t *v1alpha1_requester) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_requester->intent
    if (!v1alpha1_requester->intent) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "intent", v1alpha1_requester->intent) == NULL) {
    goto fail; //String
    }


    // v1alpha1_requester->name
    if (!v1alpha1_requester->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha1_requester->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_requester_t *v1alpha1_requester_parseFromJSON(cJSON *v1alpha1_requesterJSON){

    v1alpha1_requester_t *v1alpha1_requester_local_var = NULL;

    char *intent_local_str = NULL;

    char *name_local_str = NULL;

    // v1alpha1_requester->intent
    cJSON *intent = cJSON_GetObjectItemCaseSensitive(v1alpha1_requesterJSON, "intent");
    if (cJSON_IsNull(intent)) {
        intent = NULL;
    }
    if (!intent) {
        goto end;
    }

    
    if(!cJSON_IsString(intent))
    {
    goto end; //String
    }

    // v1alpha1_requester->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_requesterJSON, "name");
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


    if (intent && !cJSON_IsNull(intent)) intent_local_str = strdup(intent->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    v1alpha1_requester_local_var = v1alpha1_requester_create_internal (
        intent_local_str,
        name_local_str
        );

    if (!v1alpha1_requester_local_var) {
        goto end;
    }

    return v1alpha1_requester_local_var;
end:
    if (intent_local_str) {
        free(intent_local_str);
        intent_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
