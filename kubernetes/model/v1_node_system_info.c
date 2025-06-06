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
    v1_node_swap_status_t *swap,
    char *system_uuid
    ) {
    v1_node_system_info_t *v1_node_system_info_local_var = malloc(sizeof(v1_node_system_info_t));
    if (!v1_node_system_info_local_var) {
        return NULL;
    }
    v1_node_system_info_local_var->architecture = architecture;
    v1_node_system_info_local_var->boot_id = boot_id;
    v1_node_system_info_local_var->container_runtime_version = container_runtime_version;
    v1_node_system_info_local_var->kernel_version = kernel_version;
    v1_node_system_info_local_var->kube_proxy_version = kube_proxy_version;
    v1_node_system_info_local_var->kubelet_version = kubelet_version;
    v1_node_system_info_local_var->machine_id = machine_id;
    v1_node_system_info_local_var->operating_system = operating_system;
    v1_node_system_info_local_var->os_image = os_image;
    v1_node_system_info_local_var->swap = swap;
    v1_node_system_info_local_var->system_uuid = system_uuid;

    v1_node_system_info_local_var->_library_owned = 1;
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
    v1_node_swap_status_t *swap,
    char *system_uuid
    ) {
    return v1_node_system_info_create_internal (
        architecture,
        boot_id,
        container_runtime_version,
        kernel_version,
        kube_proxy_version,
        kubelet_version,
        machine_id,
        operating_system,
        os_image,
        swap,
        system_uuid
        );
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

    // define the local variable for v1_node_system_info->swap
    v1_node_swap_status_t *swap_local_nonprim = NULL;

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


    v1_node_system_info_local_var = v1_node_system_info_create_internal (
        strdup(architecture->valuestring),
        strdup(boot_id->valuestring),
        strdup(container_runtime_version->valuestring),
        strdup(kernel_version->valuestring),
        strdup(kube_proxy_version->valuestring),
        strdup(kubelet_version->valuestring),
        strdup(machine_id->valuestring),
        strdup(operating_system->valuestring),
        strdup(os_image->valuestring),
        swap ? swap_local_nonprim : NULL,
        strdup(system_uuid->valuestring)
        );

    return v1_node_system_info_local_var;
end:
    if (swap_local_nonprim) {
        v1_node_swap_status_free(swap_local_nonprim);
        swap_local_nonprim = NULL;
    }
    return NULL;

}
