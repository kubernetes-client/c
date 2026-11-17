#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_workload_reference.h"



static v1beta1_workload_reference_t *v1beta1_workload_reference_create_internal(
    char *template_name,
    char *workload_name
    ) {
    v1beta1_workload_reference_t *v1beta1_workload_reference_local_var = malloc(sizeof(v1beta1_workload_reference_t));
    if (!v1beta1_workload_reference_local_var) {
        return NULL;
    }
    memset(v1beta1_workload_reference_local_var, 0, sizeof(v1beta1_workload_reference_t));
    v1beta1_workload_reference_local_var->_library_owned = 1;
    v1beta1_workload_reference_local_var->template_name = template_name;
    v1beta1_workload_reference_local_var->workload_name = workload_name;
    return v1beta1_workload_reference_local_var;
}

__attribute__((deprecated)) v1beta1_workload_reference_t *v1beta1_workload_reference_create(
    char *template_name,
    char *workload_name
    ) {
    v1beta1_workload_reference_t *result = v1beta1_workload_reference_create_internal (
        template_name,
        workload_name
        );
    if (!result) {
    }
    return result;
}

void v1beta1_workload_reference_free(v1beta1_workload_reference_t *v1beta1_workload_reference) {
    if(NULL == v1beta1_workload_reference){
        return ;
    }
    if(v1beta1_workload_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_workload_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_workload_reference->template_name) {
        free(v1beta1_workload_reference->template_name);
        v1beta1_workload_reference->template_name = NULL;
    }
    if (v1beta1_workload_reference->workload_name) {
        free(v1beta1_workload_reference->workload_name);
        v1beta1_workload_reference->workload_name = NULL;
    }
    free(v1beta1_workload_reference);
}

cJSON *v1beta1_workload_reference_convertToJSON(v1beta1_workload_reference_t *v1beta1_workload_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_workload_reference->template_name
    if (!v1beta1_workload_reference->template_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "templateName", v1beta1_workload_reference->template_name) == NULL) {
    goto fail; //String
    }


    // v1beta1_workload_reference->workload_name
    if (!v1beta1_workload_reference->workload_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "workloadName", v1beta1_workload_reference->workload_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_workload_reference_t *v1beta1_workload_reference_parseFromJSON(cJSON *v1beta1_workload_referenceJSON){

    v1beta1_workload_reference_t *v1beta1_workload_reference_local_var = NULL;

    char *template_name_local_str = NULL;

    char *workload_name_local_str = NULL;

    // v1beta1_workload_reference->template_name
    cJSON *template_name = cJSON_GetObjectItemCaseSensitive(v1beta1_workload_referenceJSON, "templateName");
    if (cJSON_IsNull(template_name)) {
        template_name = NULL;
    }
    if (!template_name) {
        goto end;
    }

    
    if(!cJSON_IsString(template_name))
    {
    goto end; //String
    }

    // v1beta1_workload_reference->workload_name
    cJSON *workload_name = cJSON_GetObjectItemCaseSensitive(v1beta1_workload_referenceJSON, "workloadName");
    if (cJSON_IsNull(workload_name)) {
        workload_name = NULL;
    }
    if (!workload_name) {
        goto end;
    }

    
    if(!cJSON_IsString(workload_name))
    {
    goto end; //String
    }


    if (template_name && !cJSON_IsNull(template_name)) template_name_local_str = strdup(template_name->valuestring);
    if (workload_name && !cJSON_IsNull(workload_name)) workload_name_local_str = strdup(workload_name->valuestring);

    v1beta1_workload_reference_local_var = v1beta1_workload_reference_create_internal (
        template_name_local_str,
        workload_name_local_str
        );

    if (!v1beta1_workload_reference_local_var) {
        goto end;
    }

    return v1beta1_workload_reference_local_var;
end:
    if (template_name_local_str) {
        free(template_name_local_str);
        template_name_local_str = NULL;
    }
    if (workload_name_local_str) {
        free(workload_name_local_str);
        workload_name_local_str = NULL;
    }
    return NULL;

}
