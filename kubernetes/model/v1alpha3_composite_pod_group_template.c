#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_composite_pod_group_template.h"



static v1alpha3_composite_pod_group_template_t *v1alpha3_composite_pod_group_template_create_internal(
    list_t *composite_pod_group_templates,
    v1alpha3_composite_disruption_mode_t *disruption_mode,
    char *name,
    list_t *pod_group_templates,
    char *preemption_policy,
    int *priority,
    char *priority_class_name,
    v1alpha3_composite_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1alpha3_composite_pod_group_scheduling_policy_t *scheduling_policy
    ) {
    v1alpha3_composite_pod_group_template_t *v1alpha3_composite_pod_group_template_local_var = malloc(sizeof(v1alpha3_composite_pod_group_template_t));
    if (!v1alpha3_composite_pod_group_template_local_var) {
        return NULL;
    }
    memset(v1alpha3_composite_pod_group_template_local_var, 0, sizeof(v1alpha3_composite_pod_group_template_t));
    v1alpha3_composite_pod_group_template_local_var->_library_owned = 1;
    v1alpha3_composite_pod_group_template_local_var->composite_pod_group_templates = composite_pod_group_templates;
    v1alpha3_composite_pod_group_template_local_var->disruption_mode = disruption_mode;
    v1alpha3_composite_pod_group_template_local_var->name = name;
    v1alpha3_composite_pod_group_template_local_var->pod_group_templates = pod_group_templates;
    v1alpha3_composite_pod_group_template_local_var->preemption_policy = preemption_policy;
    v1alpha3_composite_pod_group_template_local_var->priority = priority;
    v1alpha3_composite_pod_group_template_local_var->priority_class_name = priority_class_name;
    v1alpha3_composite_pod_group_template_local_var->scheduling_constraints = scheduling_constraints;
    v1alpha3_composite_pod_group_template_local_var->scheduling_policy = scheduling_policy;
    return v1alpha3_composite_pod_group_template_local_var;
}

__attribute__((deprecated)) v1alpha3_composite_pod_group_template_t *v1alpha3_composite_pod_group_template_create(
    list_t *composite_pod_group_templates,
    v1alpha3_composite_disruption_mode_t *disruption_mode,
    char *name,
    list_t *pod_group_templates,
    char *preemption_policy,
    int *priority,
    char *priority_class_name,
    v1alpha3_composite_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1alpha3_composite_pod_group_scheduling_policy_t *scheduling_policy
    ) {
    int *priority_copy = NULL;
    if (priority) {
        priority_copy = malloc(sizeof(int));
        if (priority_copy) *priority_copy = *priority;
    }
    v1alpha3_composite_pod_group_template_t *result = v1alpha3_composite_pod_group_template_create_internal (
        composite_pod_group_templates,
        disruption_mode,
        name,
        pod_group_templates,
        preemption_policy,
        priority_copy,
        priority_class_name,
        scheduling_constraints,
        scheduling_policy
        );
    if (!result) {
        free(priority_copy);
    }
    return result;
}

void v1alpha3_composite_pod_group_template_free(v1alpha3_composite_pod_group_template_t *v1alpha3_composite_pod_group_template) {
    if(NULL == v1alpha3_composite_pod_group_template){
        return ;
    }
    if(v1alpha3_composite_pod_group_template->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_composite_pod_group_template_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_composite_pod_group_template->composite_pod_group_templates) {
        list_ForEach(listEntry, v1alpha3_composite_pod_group_template->composite_pod_group_templates) {
            v1alpha3_composite_pod_group_template_free(listEntry->data);
        }
        list_freeList(v1alpha3_composite_pod_group_template->composite_pod_group_templates);
        v1alpha3_composite_pod_group_template->composite_pod_group_templates = NULL;
    }
    if (v1alpha3_composite_pod_group_template->disruption_mode) {
        v1alpha3_composite_disruption_mode_free(v1alpha3_composite_pod_group_template->disruption_mode);
        v1alpha3_composite_pod_group_template->disruption_mode = NULL;
    }
    if (v1alpha3_composite_pod_group_template->name) {
        free(v1alpha3_composite_pod_group_template->name);
        v1alpha3_composite_pod_group_template->name = NULL;
    }
    if (v1alpha3_composite_pod_group_template->pod_group_templates) {
        list_ForEach(listEntry, v1alpha3_composite_pod_group_template->pod_group_templates) {
            v1alpha3_pod_group_template_free(listEntry->data);
        }
        list_freeList(v1alpha3_composite_pod_group_template->pod_group_templates);
        v1alpha3_composite_pod_group_template->pod_group_templates = NULL;
    }
    if (v1alpha3_composite_pod_group_template->preemption_policy) {
        free(v1alpha3_composite_pod_group_template->preemption_policy);
        v1alpha3_composite_pod_group_template->preemption_policy = NULL;
    }
    if (v1alpha3_composite_pod_group_template->priority) {
        free(v1alpha3_composite_pod_group_template->priority);
        v1alpha3_composite_pod_group_template->priority = NULL;
    }
    if (v1alpha3_composite_pod_group_template->priority_class_name) {
        free(v1alpha3_composite_pod_group_template->priority_class_name);
        v1alpha3_composite_pod_group_template->priority_class_name = NULL;
    }
    if (v1alpha3_composite_pod_group_template->scheduling_constraints) {
        v1alpha3_composite_pod_group_scheduling_constraints_free(v1alpha3_composite_pod_group_template->scheduling_constraints);
        v1alpha3_composite_pod_group_template->scheduling_constraints = NULL;
    }
    if (v1alpha3_composite_pod_group_template->scheduling_policy) {
        v1alpha3_composite_pod_group_scheduling_policy_free(v1alpha3_composite_pod_group_template->scheduling_policy);
        v1alpha3_composite_pod_group_template->scheduling_policy = NULL;
    }
    free(v1alpha3_composite_pod_group_template);
}

cJSON *v1alpha3_composite_pod_group_template_convertToJSON(v1alpha3_composite_pod_group_template_t *v1alpha3_composite_pod_group_template) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_composite_pod_group_template->composite_pod_group_templates
    if(v1alpha3_composite_pod_group_template->composite_pod_group_templates) {
    cJSON *composite_pod_group_templates = cJSON_AddArrayToObject(item, "compositePodGroupTemplates");
    if(composite_pod_group_templates == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *composite_pod_group_templatesListEntry;
    if (v1alpha3_composite_pod_group_template->composite_pod_group_templates) {
    list_ForEach(composite_pod_group_templatesListEntry, v1alpha3_composite_pod_group_template->composite_pod_group_templates) {
    cJSON *itemLocal = v1alpha3_composite_pod_group_template_convertToJSON(composite_pod_group_templatesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(composite_pod_group_templates, itemLocal);
    }
    }
    }


    // v1alpha3_composite_pod_group_template->disruption_mode
    if(v1alpha3_composite_pod_group_template->disruption_mode) {
    cJSON *disruption_mode_local_JSON = v1alpha3_composite_disruption_mode_convertToJSON(v1alpha3_composite_pod_group_template->disruption_mode);
    if(disruption_mode_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "disruptionMode", disruption_mode_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_composite_pod_group_template->name
    if (!v1alpha3_composite_pod_group_template->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha3_composite_pod_group_template->name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_composite_pod_group_template->pod_group_templates
    if(v1alpha3_composite_pod_group_template->pod_group_templates) {
    cJSON *pod_group_templates = cJSON_AddArrayToObject(item, "podGroupTemplates");
    if(pod_group_templates == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pod_group_templatesListEntry;
    if (v1alpha3_composite_pod_group_template->pod_group_templates) {
    list_ForEach(pod_group_templatesListEntry, v1alpha3_composite_pod_group_template->pod_group_templates) {
    cJSON *itemLocal = v1alpha3_pod_group_template_convertToJSON(pod_group_templatesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(pod_group_templates, itemLocal);
    }
    }
    }


    // v1alpha3_composite_pod_group_template->preemption_policy
    if(v1alpha3_composite_pod_group_template->preemption_policy) {
    if(cJSON_AddStringToObject(item, "preemptionPolicy", v1alpha3_composite_pod_group_template->preemption_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_composite_pod_group_template->priority
    if(v1alpha3_composite_pod_group_template->priority) {
    if(cJSON_AddNumberToObject(item, "priority", *v1alpha3_composite_pod_group_template->priority) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_composite_pod_group_template->priority_class_name
    if(v1alpha3_composite_pod_group_template->priority_class_name) {
    if(cJSON_AddStringToObject(item, "priorityClassName", v1alpha3_composite_pod_group_template->priority_class_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_composite_pod_group_template->scheduling_constraints
    if(v1alpha3_composite_pod_group_template->scheduling_constraints) {
    cJSON *scheduling_constraints_local_JSON = v1alpha3_composite_pod_group_scheduling_constraints_convertToJSON(v1alpha3_composite_pod_group_template->scheduling_constraints);
    if(scheduling_constraints_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schedulingConstraints", scheduling_constraints_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_composite_pod_group_template->scheduling_policy
    if (!v1alpha3_composite_pod_group_template->scheduling_policy) {
        goto fail;
    }
    cJSON *scheduling_policy_local_JSON = v1alpha3_composite_pod_group_scheduling_policy_convertToJSON(v1alpha3_composite_pod_group_template->scheduling_policy);
    if(scheduling_policy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schedulingPolicy", scheduling_policy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_composite_pod_group_template_t *v1alpha3_composite_pod_group_template_parseFromJSON(cJSON *v1alpha3_composite_pod_group_templateJSON){

    v1alpha3_composite_pod_group_template_t *v1alpha3_composite_pod_group_template_local_var = NULL;

    // define the local list for v1alpha3_composite_pod_group_template->composite_pod_group_templates
    list_t *composite_pod_group_templatesList = NULL;

    // define the local variable for v1alpha3_composite_pod_group_template->disruption_mode
    v1alpha3_composite_disruption_mode_t *disruption_mode_local_nonprim = NULL;

    char *name_local_str = NULL;

    // define the local list for v1alpha3_composite_pod_group_template->pod_group_templates
    list_t *pod_group_templatesList = NULL;

    char *preemption_policy_local_str = NULL;

    // define the local variable for v1alpha3_composite_pod_group_template->priority
    int *priority_local_var = NULL;

    char *priority_class_name_local_str = NULL;

    // define the local variable for v1alpha3_composite_pod_group_template->scheduling_constraints
    v1alpha3_composite_pod_group_scheduling_constraints_t *scheduling_constraints_local_nonprim = NULL;

    // define the local variable for v1alpha3_composite_pod_group_template->scheduling_policy
    v1alpha3_composite_pod_group_scheduling_policy_t *scheduling_policy_local_nonprim = NULL;

    // v1alpha3_composite_pod_group_template->composite_pod_group_templates
    cJSON *composite_pod_group_templates = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_templateJSON, "compositePodGroupTemplates");
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
        v1alpha3_composite_pod_group_template_t *composite_pod_group_templatesItem = v1alpha3_composite_pod_group_template_parseFromJSON(composite_pod_group_templates_local_nonprimitive);

        list_addElement(composite_pod_group_templatesList, composite_pod_group_templatesItem);
    }
    }

    // v1alpha3_composite_pod_group_template->disruption_mode
    cJSON *disruption_mode = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_templateJSON, "disruptionMode");
    if (cJSON_IsNull(disruption_mode)) {
        disruption_mode = NULL;
    }
    if (disruption_mode) { 
    disruption_mode_local_nonprim = v1alpha3_composite_disruption_mode_parseFromJSON(disruption_mode); //nonprimitive
    }

    // v1alpha3_composite_pod_group_template->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_templateJSON, "name");
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

    // v1alpha3_composite_pod_group_template->pod_group_templates
    cJSON *pod_group_templates = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_templateJSON, "podGroupTemplates");
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
        v1alpha3_pod_group_template_t *pod_group_templatesItem = v1alpha3_pod_group_template_parseFromJSON(pod_group_templates_local_nonprimitive);

        list_addElement(pod_group_templatesList, pod_group_templatesItem);
    }
    }

    // v1alpha3_composite_pod_group_template->preemption_policy
    cJSON *preemption_policy = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_templateJSON, "preemptionPolicy");
    if (cJSON_IsNull(preemption_policy)) {
        preemption_policy = NULL;
    }
    if (preemption_policy) { 
    if(!cJSON_IsString(preemption_policy) && !cJSON_IsNull(preemption_policy))
    {
    goto end; //String
    }
    }

    // v1alpha3_composite_pod_group_template->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_templateJSON, "priority");
    if (cJSON_IsNull(priority)) {
        priority = NULL;
    }
    if (priority) { 
    if(!cJSON_IsNumber(priority))
    {
    goto end; //Numeric
    }
    priority_local_var = malloc(sizeof(int));
    if(!priority_local_var)
    {
        goto end;
    }
    *priority_local_var = priority->valuedouble;
    }

    // v1alpha3_composite_pod_group_template->priority_class_name
    cJSON *priority_class_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_templateJSON, "priorityClassName");
    if (cJSON_IsNull(priority_class_name)) {
        priority_class_name = NULL;
    }
    if (priority_class_name) { 
    if(!cJSON_IsString(priority_class_name) && !cJSON_IsNull(priority_class_name))
    {
    goto end; //String
    }
    }

    // v1alpha3_composite_pod_group_template->scheduling_constraints
    cJSON *scheduling_constraints = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_templateJSON, "schedulingConstraints");
    if (cJSON_IsNull(scheduling_constraints)) {
        scheduling_constraints = NULL;
    }
    if (scheduling_constraints) { 
    scheduling_constraints_local_nonprim = v1alpha3_composite_pod_group_scheduling_constraints_parseFromJSON(scheduling_constraints); //nonprimitive
    }

    // v1alpha3_composite_pod_group_template->scheduling_policy
    cJSON *scheduling_policy = cJSON_GetObjectItemCaseSensitive(v1alpha3_composite_pod_group_templateJSON, "schedulingPolicy");
    if (cJSON_IsNull(scheduling_policy)) {
        scheduling_policy = NULL;
    }
    if (!scheduling_policy) {
        goto end;
    }

    
    scheduling_policy_local_nonprim = v1alpha3_composite_pod_group_scheduling_policy_parseFromJSON(scheduling_policy); //nonprimitive


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (preemption_policy && !cJSON_IsNull(preemption_policy)) preemption_policy_local_str = strdup(preemption_policy->valuestring);
    if (priority_class_name && !cJSON_IsNull(priority_class_name)) priority_class_name_local_str = strdup(priority_class_name->valuestring);

    v1alpha3_composite_pod_group_template_local_var = v1alpha3_composite_pod_group_template_create_internal (
        composite_pod_group_templates ? composite_pod_group_templatesList : NULL,
        disruption_mode ? disruption_mode_local_nonprim : NULL,
        name_local_str,
        pod_group_templates ? pod_group_templatesList : NULL,
        preemption_policy_local_str,
        priority_local_var,
        priority_class_name_local_str,
        scheduling_constraints ? scheduling_constraints_local_nonprim : NULL,
        scheduling_policy_local_nonprim
        );

    if (!v1alpha3_composite_pod_group_template_local_var) {
        goto end;
    }

    return v1alpha3_composite_pod_group_template_local_var;
end:
    if (composite_pod_group_templatesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, composite_pod_group_templatesList) {
            v1alpha3_composite_pod_group_template_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(composite_pod_group_templatesList);
        composite_pod_group_templatesList = NULL;
    }
    if (disruption_mode_local_nonprim) {
        v1alpha3_composite_disruption_mode_free(disruption_mode_local_nonprim);
        disruption_mode_local_nonprim = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (pod_group_templatesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pod_group_templatesList) {
            v1alpha3_pod_group_template_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(pod_group_templatesList);
        pod_group_templatesList = NULL;
    }
    if (preemption_policy_local_str) {
        free(preemption_policy_local_str);
        preemption_policy_local_str = NULL;
    }
    if (priority_local_var) {
        free(priority_local_var);
        priority_local_var = NULL;
    }
    if (priority_class_name_local_str) {
        free(priority_class_name_local_str);
        priority_class_name_local_str = NULL;
    }
    if (scheduling_constraints_local_nonprim) {
        v1alpha3_composite_pod_group_scheduling_constraints_free(scheduling_constraints_local_nonprim);
        scheduling_constraints_local_nonprim = NULL;
    }
    if (scheduling_policy_local_nonprim) {
        v1alpha3_composite_pod_group_scheduling_policy_free(scheduling_policy_local_nonprim);
        scheduling_policy_local_nonprim = NULL;
    }
    return NULL;

}
