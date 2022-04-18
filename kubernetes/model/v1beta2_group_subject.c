#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_group_subject.h"



v1beta2_group_subject_t *v1beta2_group_subject_create(
    char *name
    ) {
    v1beta2_group_subject_t *v1beta2_group_subject_local_var = malloc(sizeof(v1beta2_group_subject_t));
    if (!v1beta2_group_subject_local_var) {
        return NULL;
    }
    v1beta2_group_subject_local_var->name = name;

    return v1beta2_group_subject_local_var;
}


void v1beta2_group_subject_free(v1beta2_group_subject_t *v1beta2_group_subject) {
    if(NULL == v1beta2_group_subject){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_group_subject->name) {
        free(v1beta2_group_subject->name);
        v1beta2_group_subject->name = NULL;
    }
    free(v1beta2_group_subject);
}

cJSON *v1beta2_group_subject_convertToJSON(v1beta2_group_subject_t *v1beta2_group_subject) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_group_subject->name
    if (!v1beta2_group_subject->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1beta2_group_subject->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta2_group_subject_t *v1beta2_group_subject_parseFromJSON(cJSON *v1beta2_group_subjectJSON){

    v1beta2_group_subject_t *v1beta2_group_subject_local_var = NULL;

    // v1beta2_group_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta2_group_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1beta2_group_subject_local_var = v1beta2_group_subject_create (
        strdup(name->valuestring)
        );

    return v1beta2_group_subject_local_var;
end:
    return NULL;

}
