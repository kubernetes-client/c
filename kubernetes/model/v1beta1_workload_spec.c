#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_workload_spec.h"



static v1beta1_workload_spec_t *v1beta1_workload_spec_create_internal(
    list_t *composite_pod_group_templates,
    v1beta1_typed_local_object_reference_t *controller_ref,
    list_t *pod_group_templates
    ) {
    v1beta1_workload_spec_t *v1beta1_workload_spec_local_var = malloc(sizeof(v1beta1_workload_spec_t));
    if (!v1beta1_workload_spec_local_var) {
        return NULL;
    }
    memset(v1beta1_workload_spec_local_var, 0, sizeof(v1beta1_workload_spec_t));
    v1beta1_workload_spec_local_var->_library_owned = 1;
    v1beta1_workload_spec_local_var->composite_pod_group_templates = composite_pod_group_templates;
    v1beta1_workload_spec_local_var->controller_ref = controller_ref;
    v1beta1_workload_spec_local_var->pod_group_templates = pod_group_templates;
    return v1beta1_workload_spec_local_var;
}

__attribute__((deprecated)) v1beta1_workload_spec_t *v1beta1_workload_spec_create(
    list_t *composite_pod_group_templates,
    v1beta1_typed_local_object_reference_t *controller_ref,
    list_t *pod_group_templates
    ) {
    v1beta1_workload_spec_t *result = v1beta1_workload_spec_create_internal (
        composite_pod_group_templates,
        controller_ref,
        pod_group_templates
        );
    if (!result) {
    }
    return result;
}

void v1beta1_workload_spec_free(v1beta1_workload_spec_t *v1beta1_workload_spec) {
    if(NULL == v1beta1_workload_spec){
        return ;
    }
    if(v1beta1_workload_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_workload_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_workload_spec->composite_pod_group_templates) {
        list_ForEach(listEntry, v1beta1_workload_spec->composite_pod_group_templates) {
            v1beta1_composite_pod_group_template_free(listEntry->data);
        }
        list_freeList(v1beta1_workload_spec->composite_pod_group_templates);
        v1beta1_workload_spec->composite_pod_group_templates = NULL;
    }
    if (v1beta1_workload_spec->controller_ref) {
        v1beta1_typed_local_object_reference_free(v1beta1_workload_spec->controller_ref);
        v1beta1_workload_spec->controller_ref = NULL;
    }
    if (v1beta1_workload_spec->pod_group_templates) {
        list_ForEach(listEntry, v1beta1_workload_spec->pod_group_templates) {
            v1beta1_pod_group_template_free(listEntry->data);
        }
        list_freeList(v1beta1_workload_spec->pod_group_templates);
        v1beta1_workload_spec->pod_group_templates = NULL;
    }
    free(v1beta1_workload_spec);
}

cJSON *v1beta1_workload_spec_convertToJSON(v1beta1_workload_spec_t *v1beta1_workload_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_workload_spec->composite_pod_group_templates
    if(v1beta1_workload_spec->composite_pod_group_templates) {
    cJSON *composite_pod_group_templates = cJSON_AddArrayToObject(item, "compositePodGroupTemplates");
    if(composite_pod_group_templates == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *composite_pod_group_templatesListEntry;
    if (v1beta1_workload_spec->composite_pod_group_templates) {
    list_ForEach(composite_pod_group_templatesListEntry, v1beta1_workload_spec->composite_pod_group_templates) {
    cJSON *itemLocal = v1beta1_composite_pod_group_template_convertToJSON(composite_pod_group_templatesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(composite_pod_group_templates, itemLocal);
    }
    }
    }


    // v1beta1_workload_spec->controller_ref
    if(v1beta1_workload_spec->controller_ref) {
    cJSON *controller_ref_local_JSON = v1beta1_typed_local_object_reference_convertToJSON(v1beta1_workload_spec->controller_ref);
    if(controller_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "controllerRef", controller_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_workload_spec->pod_group_templates
    if(v1beta1_workload_spec->pod_group_templates) {
    cJSON *pod_group_templates = cJSON_AddArrayToObject(item, "podGroupTemplates");
    if(pod_group_templates == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pod_group_templatesListEntry;
    if (v1beta1_workload_spec->pod_group_templates) {
    list_ForEach(pod_group_templatesListEntry, v1beta1_workload_spec->pod_group_templates) {
    cJSON *itemLocal = v1beta1_pod_group_template_convertToJSON(pod_group_templatesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(pod_group_templates, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_workload_spec_t *v1beta1_workload_spec_parseFromJSON(cJSON *v1beta1_workload_specJSON){

    v1beta1_workload_spec_t *v1beta1_workload_spec_local_var = NULL;

    // define the local list for v1beta1_workload_spec->composite_pod_group_templates
    list_t *composite_pod_group_templatesList = NULL;

    // define the local variable for v1beta1_workload_spec->controller_ref
    v1beta1_typed_local_object_reference_t *controller_ref_local_nonprim = NULL;

    // define the local list for v1beta1_workload_spec->pod_group_templates
    list_t *pod_group_templatesList = NULL;

    // v1beta1_workload_spec->composite_pod_group_templates
    cJSON *composite_pod_group_templates = cJSON_GetObjectItemCaseSensitive(v1beta1_workload_specJSON, "compositePodGroupTemplates");
    if (cJSON_IsNull(composite_pod_group_templates)) {
        composite_pod_group_templates = NULL;
    }
    if (composite_pod_group_templates) { 
    cJSON *composite_pod_group_templates_local_nonprimitive = NULL;
    if(!cJSON_IsArray(composite_pod_group_templates)){
        goto end; //nonprimitive container
    }

    composite_pod_group_templatesList = list_createList();

    cJSON_ArrayForEach(composite_pod_group_templates_local_nonprimitive,composite_pod_group_templates )
    {
        if(!cJSON_IsObject(composite_pod_group_templates_local_nonprimitive)){
            goto end;
        }
        v1beta1_composite_pod_group_template_t *composite_pod_group_templatesItem = v1beta1_composite_pod_group_template_parseFromJSON(composite_pod_group_templates_local_nonprimitive);

        list_addElement(composite_pod_group_templatesList, composite_pod_group_templatesItem);
    }
    }

    // v1beta1_workload_spec->controller_ref
    cJSON *controller_ref = cJSON_GetObjectItemCaseSensitive(v1beta1_workload_specJSON, "controllerRef");
    if (cJSON_IsNull(controller_ref)) {
        controller_ref = NULL;
    }
    if (controller_ref) { 
    controller_ref_local_nonprim = v1beta1_typed_local_object_reference_parseFromJSON(controller_ref); //nonprimitive
    }

    // v1beta1_workload_spec->pod_group_templates
    cJSON *pod_group_templates = cJSON_GetObjectItemCaseSensitive(v1beta1_workload_specJSON, "podGroupTemplates");
    if (cJSON_IsNull(pod_group_templates)) {
        pod_group_templates = NULL;
    }
    if (pod_group_templates) { 
    cJSON *pod_group_templates_local_nonprimitive = NULL;
    if(!cJSON_IsArray(pod_group_templates)){
        goto end; //nonprimitive container
    }

    pod_group_templatesList = list_createList();

    cJSON_ArrayForEach(pod_group_templates_local_nonprimitive,pod_group_templates )
    {
        if(!cJSON_IsObject(pod_group_templates_local_nonprimitive)){
            goto end;
        }
        v1beta1_pod_group_template_t *pod_group_templatesItem = v1beta1_pod_group_template_parseFromJSON(pod_group_templates_local_nonprimitive);

        list_addElement(pod_group_templatesList, pod_group_templatesItem);
    }
    }



    v1beta1_workload_spec_local_var = v1beta1_workload_spec_create_internal (
        composite_pod_group_templates ? composite_pod_group_templatesList : NULL,
        controller_ref ? controller_ref_local_nonprim : NULL,
        pod_group_templates ? pod_group_templatesList : NULL
        );

    if (!v1beta1_workload_spec_local_var) {
        goto end;
    }

    return v1beta1_workload_spec_local_var;
end:
    if (composite_pod_group_templatesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, composite_pod_group_templatesList) {
            v1beta1_composite_pod_group_template_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(composite_pod_group_templatesList);
        composite_pod_group_templatesList = NULL;
    }
    if (controller_ref_local_nonprim) {
        v1beta1_typed_local_object_reference_free(controller_ref_local_nonprim);
        controller_ref_local_nonprim = NULL;
    }
    if (pod_group_templatesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pod_group_templatesList) {
            v1beta1_pod_group_template_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(pod_group_templatesList);
        pod_group_templatesList = NULL;
    }
    return NULL;

}
