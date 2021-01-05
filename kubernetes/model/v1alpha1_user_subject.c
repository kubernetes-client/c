#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_user_subject.h"



v1alpha1_user_subject_t *v1alpha1_user_subject_create(
    char *name
    ) {
    v1alpha1_user_subject_t *v1alpha1_user_subject_local_var = malloc(sizeof(v1alpha1_user_subject_t));
    if (!v1alpha1_user_subject_local_var) {
        return NULL;
    }
    v1alpha1_user_subject_local_var->name = name;

    return v1alpha1_user_subject_local_var;
}


void v1alpha1_user_subject_free(v1alpha1_user_subject_t *v1alpha1_user_subject) {
    if(NULL == v1alpha1_user_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_user_subject->name) {
        free(v1alpha1_user_subject->name);
        v1alpha1_user_subject->name = NULL;
    }
    free(v1alpha1_user_subject);
}

cJSON *v1alpha1_user_subject_convertToJSON(v1alpha1_user_subject_t *v1alpha1_user_subject) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_user_subject->name
    if (!v1alpha1_user_subject->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1alpha1_user_subject->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_user_subject_t *v1alpha1_user_subject_parseFromJSON(cJSON *v1alpha1_user_subjectJSON){

    v1alpha1_user_subject_t *v1alpha1_user_subject_local_var = NULL;

    // v1alpha1_user_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_user_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1alpha1_user_subject_local_var = v1alpha1_user_subject_create (
        strdup(name->valuestring)
        );

    return v1alpha1_user_subject_local_var;
end:
    return NULL;

}
