#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_user_subject.h"



static v1_user_subject_t *v1_user_subject_create_internal(
    char *name
    ) {
    v1_user_subject_t *v1_user_subject_local_var = malloc(sizeof(v1_user_subject_t));
    if (!v1_user_subject_local_var) {
        return NULL;
    }
    v1_user_subject_local_var->name = name;

    v1_user_subject_local_var->_library_owned = 1;
    return v1_user_subject_local_var;
}

__attribute__((deprecated)) v1_user_subject_t *v1_user_subject_create(
    char *name
    ) {
    return v1_user_subject_create_internal (
        name
        );
}

void v1_user_subject_free(v1_user_subject_t *v1_user_subject) {
    if(NULL == v1_user_subject){
        return ;
    }
    if(v1_user_subject->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_user_subject_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_user_subject->name) {
        free(v1_user_subject->name);
        v1_user_subject->name = NULL;
    }
    free(v1_user_subject);
}

cJSON *v1_user_subject_convertToJSON(v1_user_subject_t *v1_user_subject) {
    cJSON *item = cJSON_CreateObject();

    // v1_user_subject->name
    if (!v1_user_subject->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_user_subject->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_user_subject_t *v1_user_subject_parseFromJSON(cJSON *v1_user_subjectJSON){

    v1_user_subject_t *v1_user_subject_local_var = NULL;

    // v1_user_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_user_subjectJSON, "name");
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


    v1_user_subject_local_var = v1_user_subject_create_internal (
        strdup(name->valuestring)
        );

    return v1_user_subject_local_var;
end:
    return NULL;

}
