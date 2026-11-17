#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_system_info.h"



static v1_node_system_info_t *v1_node_system_info_create_internal(
    char *architecture,
    char *boot_id,
    char *container_runtime_version,
    char *kernel_version,
    char *kube_proxy_version,
    char *kubelet_version,
    char *machine_id,
    char *operating_system,
    char *os_image,
    int *running_in_user_namespace,
    v1_node_swap_status_t *swap,
    char *system_uuid
    ) {
    v1_node_system_info_t *v1_node_system_info_local_var = malloc(sizeof(v1_node_system_info_t));
    if (!v1_node_system_info_local_var) {
        return NULL;
    }
    memset(v1_node_system_info_local_var, 0, sizeof(v1_node_system_info_t));
    v1_node_system_info_local_var->_library_owned = 1;
    v1_node_system_info_local_var->architecture = architecture;
    v1_node_system_info_local_var->boot_id = boot_id;
    v1_node_system_info_local_var->container_runtime_version = container_runtime_version;
    v1_node_system_info_local_var->kernel_version = kernel_version;
    v1_node_system_info_local_var->kube_proxy_version = kube_proxy_version;
    v1_node_system_info_local_var->kubelet_version = kubelet_version;
    v1_node_system_info_local_var->machine_id = machine_id;
    v1_node_system_info_local_var->operating_system = operating_system;
    v1_node_system_info_local_var->os_image = os_image;
    v1_node_system_info_local_var->running_in_user_namespace = running_in_user_namespace;
    v1_node_system_info_local_var->swap = swap;
    v1_node_system_info_local_var->system_uuid = system_uuid;
    return v1_node_system_info_local_var;
}

__attribute__((deprecated)) v1_node_system_info_t *v1_node_system_info_create(
    char *architecture,
    char *boot_id,
    char *container_runtime_version,
    char *kernel_version,
    char *kube_proxy_version,
    char *kubelet_version,
    char *machine_id,
    char *operating_system,
    char *os_image,
    int *running_in_user_namespace,
    v1_node_swap_status_t *swap,
    char *system_uuid
    ) {
    int *running_in_user_namespace_copy = NULL;
    if (running_in_user_namespace) {
        running_in_user_namespace_copy = malloc(sizeof(int));
        if (running_in_user_namespace_copy) *running_in_user_namespace_copy = *running_in_user_namespace;
    }
    v1_node_system_info_t *result = v1_node_system_info_create_internal (
        architecture,
        boot_id,
        container_runtime_version,
        kernel_version,
        kube_proxy_version,
        kubelet_version,
        machine_id,
        operating_system,
        os_image,
        running_in_user_namespace_copy,
        swap,
        system_uuid
        );
    if (!result) {
        free(running_in_user_namespace_copy);
    }
    return result;
}

void v1_node_system_info_free(v1_node_system_info_t *v1_node_system_info) {
    if(NULL == v1_node_system_info){
        return ;
    }
    if(v1_node_system_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_system_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_system_info->architecture) {
        free(v1_node_system_info->architecture);
        v1_node_system_info->architecture = NULL;
    }
    if (v1_node_system_info->boot_id) {
        free(v1_node_system_info->boot_id);
        v1_node_system_info->boot_id = NULL;
    }
    if (v1_node_system_info->container_runtime_version) {
        free(v1_node_system_info->container_runtime_version);
        v1_node_system_info->container_runtime_version = NULL;
    }
    if (v1_node_system_info->kernel_version) {
        free(v1_node_system_info->kernel_version);
        v1_node_system_info->kernel_version = NULL;
    }
    if (v1_node_system_info->kube_proxy_version) {
        free(v1_node_system_info->kube_proxy_version);
        v1_node_system_info->kube_proxy_version = NULL;
    }
    if (v1_node_system_info->kubelet_version) {
        free(v1_node_system_info->kubelet_version);
        v1_node_system_info->kubelet_version = NULL;
    }
    if (v1_node_system_info->machine_id) {
        free(v1_node_system_info->machine_id);
        v1_node_system_info->machine_id = NULL;
    }
    if (v1_node_system_info->operating_system) {
        free(v1_node_system_info->operating_system);
        v1_node_system_info->operating_system = NULL;
    }
    if (v1_node_system_info->os_image) {
        free(v1_node_system_info->os_image);
        v1_node_system_info->os_image = NULL;
    }
    if (v1_node_system_info->running_in_user_namespace) {
        free(v1_node_system_info->running_in_user_namespace);
        v1_node_system_info->running_in_user_namespace = NULL;
    }
    if (v1_node_system_info->swap) {
        v1_node_swap_status_free(v1_node_system_info->swap);
        v1_node_system_info->swap = NULL;
    }
    if (v1_node_system_info->system_uuid) {
        free(v1_node_system_info->system_uuid);
        v1_node_system_info->system_uuid = NULL;
    }
    free(v1_node_system_info);
}

cJSON *v1_node_system_info_convertToJSON(v1_node_system_info_t *v1_node_system_info) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_system_info->architecture
    if (!v1_node_system_info->architecture) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "architecture", v1_node_system_info->architecture) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->boot_id
    if (!v1_node_system_info->boot_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bootID", v1_node_system_info->boot_id) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->container_runtime_version
    if (!v1_node_system_info->container_runtime_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "containerRuntimeVersion", v1_node_system_info->container_runtime_version) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->kernel_version
    if (!v1_node_system_info->kernel_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kernelVersion", v1_node_system_info->kernel_version) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->kube_proxy_version
    if (!v1_node_system_info->kube_proxy_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kubeProxyVersion", v1_node_system_info->kube_proxy_version) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->kubelet_version
    if (!v1_node_system_info->kubelet_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kubeletVersion", v1_node_system_info->kubelet_version) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->machine_id
    if (!v1_node_system_info->machine_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "machineID", v1_node_system_info->machine_id) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->operating_system
    if (!v1_node_system_info->operating_system) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "operatingSystem", v1_node_system_info->operating_system) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->os_image
    if (!v1_node_system_info->os_image) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "osImage", v1_node_system_info->os_image) == NULL) {
    goto fail; //String
    }


    // v1_node_system_info->running_in_user_namespace
    if(v1_node_system_info->running_in_user_namespace) {
    if(cJSON_AddBoolToObject(item, "runningInUserNamespace", *v1_node_system_info->running_in_user_namespace) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_node_system_info->swap
    if(v1_node_system_info->swap) {
    cJSON *swap_local_JSON = v1_node_swap_status_convertToJSON(v1_node_system_info->swap);
    if(swap_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "swap", swap_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_node_system_info->system_uuid
    if (!v1_node_system_info->system_uuid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "systemUUID", v1_node_system_info->system_uuid) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_node_system_info_t *v1_node_system_info_parseFromJSON(cJSON *v1_node_system_infoJSON){

    v1_node_system_info_t *v1_node_system_info_local_var = NULL;

    char *architecture_local_str = NULL;

    char *boot_id_local_str = NULL;

    char *container_runtime_version_local_str = NULL;

    char *kernel_version_local_str = NULL;

    char *kube_proxy_version_local_str = NULL;

    char *kubelet_version_local_str = NULL;

    char *machine_id_local_str = NULL;

    char *operating_system_local_str = NULL;

    char *os_image_local_str = NULL;

    // define the local variable for v1_node_system_info->running_in_user_namespace
    int *running_in_user_namespace_local_var = NULL;

    // define the local variable for v1_node_system_info->swap
    v1_node_swap_status_t *swap_local_nonprim = NULL;

    char *system_uuid_local_str = NULL;

    // v1_node_system_info->architecture
    cJSON *architecture = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "architecture");
    if (cJSON_IsNull(architecture)) {
        architecture = NULL;
    }
    if (!architecture) {
        goto end;
    }

    
    if(!cJSON_IsString(architecture))
    {
    goto end; //String
    }

    // v1_node_system_info->boot_id
    cJSON *boot_id = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "bootID");
    if (cJSON_IsNull(boot_id)) {
        boot_id = NULL;
    }
    if (!boot_id) {
        goto end;
    }

    
    if(!cJSON_IsString(boot_id))
    {
    goto end; //String
    }

    // v1_node_system_info->container_runtime_version
    cJSON *container_runtime_version = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "containerRuntimeVersion");
    if (cJSON_IsNull(container_runtime_version)) {
        container_runtime_version = NULL;
    }
    if (!container_runtime_version) {
        goto end;
    }

    
    if(!cJSON_IsString(container_runtime_version))
    {
    goto end; //String
    }

    // v1_node_system_info->kernel_version
    cJSON *kernel_version = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "kernelVersion");
    if (cJSON_IsNull(kernel_version)) {
        kernel_version = NULL;
    }
    if (!kernel_version) {
        goto end;
    }

    
    if(!cJSON_IsString(kernel_version))
    {
    goto end; //String
    }

    // v1_node_system_info->kube_proxy_version
    cJSON *kube_proxy_version = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "kubeProxyVersion");
    if (cJSON_IsNull(kube_proxy_version)) {
        kube_proxy_version = NULL;
    }
    if (!kube_proxy_version) {
        goto end;
    }

    
    if(!cJSON_IsString(kube_proxy_version))
    {
    goto end; //String
    }

    // v1_node_system_info->kubelet_version
    cJSON *kubelet_version = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "kubeletVersion");
    if (cJSON_IsNull(kubelet_version)) {
        kubelet_version = NULL;
    }
    if (!kubelet_version) {
        goto end;
    }

    
    if(!cJSON_IsString(kubelet_version))
    {
    goto end; //String
    }

    // v1_node_system_info->machine_id
    cJSON *machine_id = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "machineID");
    if (cJSON_IsNull(machine_id)) {
        machine_id = NULL;
    }
    if (!machine_id) {
        goto end;
    }

    
    if(!cJSON_IsString(machine_id))
    {
    goto end; //String
    }

    // v1_node_system_info->operating_system
    cJSON *operating_system = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "operatingSystem");
    if (cJSON_IsNull(operating_system)) {
        operating_system = NULL;
    }
    if (!operating_system) {
        goto end;
    }

    
    if(!cJSON_IsString(operating_system))
    {
    goto end; //String
    }

    // v1_node_system_info->os_image
    cJSON *os_image = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "osImage");
    if (cJSON_IsNull(os_image)) {
        os_image = NULL;
    }
    if (!os_image) {
        goto end;
    }

    
    if(!cJSON_IsString(os_image))
    {
    goto end; //String
    }

    // v1_node_system_info->running_in_user_namespace
    cJSON *running_in_user_namespace = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "runningInUserNamespace");
    if (cJSON_IsNull(running_in_user_namespace)) {
        running_in_user_namespace = NULL;
    }
    if (running_in_user_namespace) { 
    if(!cJSON_IsBool(running_in_user_namespace))
    {
    goto end; //Bool
    }
    running_in_user_namespace_local_var = malloc(sizeof(int));
    if(!running_in_user_namespace_local_var)
    {
        goto end;
    }
    *running_in_user_namespace_local_var = running_in_user_namespace->valueint;
    }

    // v1_node_system_info->swap
    cJSON *swap = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "swap");
    if (cJSON_IsNull(swap)) {
        swap = NULL;
    }
    if (swap) { 
    swap_local_nonprim = v1_node_swap_status_parseFromJSON(swap); //nonprimitive
    }

    // v1_node_system_info->system_uuid
    cJSON *system_uuid = cJSON_GetObjectItemCaseSensitive(v1_node_system_infoJSON, "systemUUID");
    if (cJSON_IsNull(system_uuid)) {
        system_uuid = NULL;
    }
    if (!system_uuid) {
        goto end;
    }

    
    if(!cJSON_IsString(system_uuid))
    {
    goto end; //String
    }


    if (architecture && !cJSON_IsNull(architecture)) architecture_local_str = strdup(architecture->valuestring);
    if (boot_id && !cJSON_IsNull(boot_id)) boot_id_local_str = strdup(boot_id->valuestring);
    if (container_runtime_version && !cJSON_IsNull(container_runtime_version)) container_runtime_version_local_str = strdup(container_runtime_version->valuestring);
    if (kernel_version && !cJSON_IsNull(kernel_version)) kernel_version_local_str = strdup(kernel_version->valuestring);
    if (kube_proxy_version && !cJSON_IsNull(kube_proxy_version)) kube_proxy_version_local_str = strdup(kube_proxy_version->valuestring);
    if (kubelet_version && !cJSON_IsNull(kubelet_version)) kubelet_version_local_str = strdup(kubelet_version->valuestring);
    if (machine_id && !cJSON_IsNull(machine_id)) machine_id_local_str = strdup(machine_id->valuestring);
    if (operating_system && !cJSON_IsNull(operating_system)) operating_system_local_str = strdup(operating_system->valuestring);
    if (os_image && !cJSON_IsNull(os_image)) os_image_local_str = strdup(os_image->valuestring);
    if (system_uuid && !cJSON_IsNull(system_uuid)) system_uuid_local_str = strdup(system_uuid->valuestring);

    v1_node_system_info_local_var = v1_node_system_info_create_internal (
        architecture_local_str,
        boot_id_local_str,
        container_runtime_version_local_str,
        kernel_version_local_str,
        kube_proxy_version_local_str,
        kubelet_version_local_str,
        machine_id_local_str,
        operating_system_local_str,
        os_image_local_str,
        running_in_user_namespace_local_var,
        swap ? swap_local_nonprim : NULL,
        system_uuid_local_str
        );

    if (!v1_node_system_info_local_var) {
        goto end;
    }

    return v1_node_system_info_local_var;
end:
    if (architecture_local_str) {
        free(architecture_local_str);
        architecture_local_str = NULL;
    }
    if (boot_id_local_str) {
        free(boot_id_local_str);
        boot_id_local_str = NULL;
    }
    if (container_runtime_version_local_str) {
        free(container_runtime_version_local_str);
        container_runtime_version_local_str = NULL;
    }
    if (kernel_version_local_str) {
        free(kernel_version_local_str);
        kernel_version_local_str = NULL;
    }
    if (kube_proxy_version_local_str) {
        free(kube_proxy_version_local_str);
        kube_proxy_version_local_str = NULL;
    }
    if (kubelet_version_local_str) {
        free(kubelet_version_local_str);
        kubelet_version_local_str = NULL;
    }
    if (machine_id_local_str) {
        free(machine_id_local_str);
        machine_id_local_str = NULL;
    }
    if (operating_system_local_str) {
        free(operating_system_local_str);
        operating_system_local_str = NULL;
    }
    if (os_image_local_str) {
        free(os_image_local_str);
        os_image_local_str = NULL;
    }
    if (running_in_user_namespace_local_var) {
        free(running_in_user_namespace_local_var);
        running_in_user_namespace_local_var = NULL;
    }
    if (swap_local_nonprim) {
        v1_node_swap_status_free(swap_local_nonprim);
        swap_local_nonprim = NULL;
    }
    if (system_uuid_local_str) {
        free(system_uuid_local_str);
        system_uuid_local_str = NULL;
    }
    return NULL;

}
