#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ephemeral_container.h"



v1_ephemeral_container_t *v1_ephemeral_container_create(
    list_t *args,
    list_t *command,
    list_t *env,
    list_t *env_from,
    char *image,
    char *image_pull_policy,
    v1_lifecycle_t *lifecycle,
    v1_probe_t *liveness_probe,
    char *name,
    list_t *ports,
    v1_probe_t *readiness_probe,
    v1_resource_requirements_t *resources,
    v1_security_context_t *security_context,
    v1_probe_t *startup_probe,
    int _stdin,
    int stdin_once,
    char *target_container_name,
    char *termination_message_path,
    char *termination_message_policy,
    int tty,
    list_t *volume_devices,
    list_t *volume_mounts,
    char *working_dir
    ) {
    v1_ephemeral_container_t *v1_ephemeral_container_local_var = malloc(sizeof(v1_ephemeral_container_t));
    if (!v1_ephemeral_container_local_var) {
        return NULL;
    }
    v1_ephemeral_container_local_var->args = args;
    v1_ephemeral_container_local_var->command = command;
    v1_ephemeral_container_local_var->env = env;
    v1_ephemeral_container_local_var->env_from = env_from;
    v1_ephemeral_container_local_var->image = image;
    v1_ephemeral_container_local_var->image_pull_policy = image_pull_policy;
    v1_ephemeral_container_local_var->lifecycle = lifecycle;
    v1_ephemeral_container_local_var->liveness_probe = liveness_probe;
    v1_ephemeral_container_local_var->name = name;
    v1_ephemeral_container_local_var->ports = ports;
    v1_ephemeral_container_local_var->readiness_probe = readiness_probe;
    v1_ephemeral_container_local_var->resources = resources;
    v1_ephemeral_container_local_var->security_context = security_context;
    v1_ephemeral_container_local_var->startup_probe = startup_probe;
    v1_ephemeral_container_local_var->_stdin = _stdin;
    v1_ephemeral_container_local_var->stdin_once = stdin_once;
    v1_ephemeral_container_local_var->target_container_name = target_container_name;
    v1_ephemeral_container_local_var->termination_message_path = termination_message_path;
    v1_ephemeral_container_local_var->termination_message_policy = termination_message_policy;
    v1_ephemeral_container_local_var->tty = tty;
    v1_ephemeral_container_local_var->volume_devices = volume_devices;
    v1_ephemeral_container_local_var->volume_mounts = volume_mounts;
    v1_ephemeral_container_local_var->working_dir = working_dir;

    return v1_ephemeral_container_local_var;
}


void v1_ephemeral_container_free(v1_ephemeral_container_t *v1_ephemeral_container) {
    if(NULL == v1_ephemeral_container){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ephemeral_container->args) {
        list_ForEach(listEntry, v1_ephemeral_container->args) {
            free(listEntry->data);
        }
        list_free(v1_ephemeral_container->args);
        v1_ephemeral_container->args = NULL;
    }
    if (v1_ephemeral_container->command) {
        list_ForEach(listEntry, v1_ephemeral_container->command) {
            free(listEntry->data);
        }
        list_free(v1_ephemeral_container->command);
        v1_ephemeral_container->command = NULL;
    }
    if (v1_ephemeral_container->env) {
        list_ForEach(listEntry, v1_ephemeral_container->env) {
            v1_env_var_free(listEntry->data);
        }
        list_free(v1_ephemeral_container->env);
        v1_ephemeral_container->env = NULL;
    }
    if (v1_ephemeral_container->env_from) {
        list_ForEach(listEntry, v1_ephemeral_container->env_from) {
            v1_env_from_source_free(listEntry->data);
        }
        list_free(v1_ephemeral_container->env_from);
        v1_ephemeral_container->env_from = NULL;
    }
    if (v1_ephemeral_container->image) {
        free(v1_ephemeral_container->image);
        v1_ephemeral_container->image = NULL;
    }
    if (v1_ephemeral_container->image_pull_policy) {
        free(v1_ephemeral_container->image_pull_policy);
        v1_ephemeral_container->image_pull_policy = NULL;
    }
    if (v1_ephemeral_container->lifecycle) {
        v1_lifecycle_free(v1_ephemeral_container->lifecycle);
        v1_ephemeral_container->lifecycle = NULL;
    }
    if (v1_ephemeral_container->liveness_probe) {
        v1_probe_free(v1_ephemeral_container->liveness_probe);
        v1_ephemeral_container->liveness_probe = NULL;
    }
    if (v1_ephemeral_container->name) {
        free(v1_ephemeral_container->name);
        v1_ephemeral_container->name = NULL;
    }
    if (v1_ephemeral_container->ports) {
        list_ForEach(listEntry, v1_ephemeral_container->ports) {
            v1_container_port_free(listEntry->data);
        }
        list_free(v1_ephemeral_container->ports);
        v1_ephemeral_container->ports = NULL;
    }
    if (v1_ephemeral_container->readiness_probe) {
        v1_probe_free(v1_ephemeral_container->readiness_probe);
        v1_ephemeral_container->readiness_probe = NULL;
    }
    if (v1_ephemeral_container->resources) {
        v1_resource_requirements_free(v1_ephemeral_container->resources);
        v1_ephemeral_container->resources = NULL;
    }
    if (v1_ephemeral_container->security_context) {
        v1_security_context_free(v1_ephemeral_container->security_context);
        v1_ephemeral_container->security_context = NULL;
    }
    if (v1_ephemeral_container->startup_probe) {
        v1_probe_free(v1_ephemeral_container->startup_probe);
        v1_ephemeral_container->startup_probe = NULL;
    }
    if (v1_ephemeral_container->target_container_name) {
        free(v1_ephemeral_container->target_container_name);
        v1_ephemeral_container->target_container_name = NULL;
    }
    if (v1_ephemeral_container->termination_message_path) {
        free(v1_ephemeral_container->termination_message_path);
        v1_ephemeral_container->termination_message_path = NULL;
    }
    if (v1_ephemeral_container->termination_message_policy) {
        free(v1_ephemeral_container->termination_message_policy);
        v1_ephemeral_container->termination_message_policy = NULL;
    }
    if (v1_ephemeral_container->volume_devices) {
        list_ForEach(listEntry, v1_ephemeral_container->volume_devices) {
            v1_volume_device_free(listEntry->data);
        }
        list_free(v1_ephemeral_container->volume_devices);
        v1_ephemeral_container->volume_devices = NULL;
    }
    if (v1_ephemeral_container->volume_mounts) {
        list_ForEach(listEntry, v1_ephemeral_container->volume_mounts) {
            v1_volume_mount_free(listEntry->data);
        }
        list_free(v1_ephemeral_container->volume_mounts);
        v1_ephemeral_container->volume_mounts = NULL;
    }
    if (v1_ephemeral_container->working_dir) {
        free(v1_ephemeral_container->working_dir);
        v1_ephemeral_container->working_dir = NULL;
    }
    free(v1_ephemeral_container);
}

cJSON *v1_ephemeral_container_convertToJSON(v1_ephemeral_container_t *v1_ephemeral_container) {
    cJSON *item = cJSON_CreateObject();

    // v1_ephemeral_container->args
    if(v1_ephemeral_container->args) { 
    cJSON *args = cJSON_AddArrayToObject(item, "args");
    if(args == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *argsListEntry;
    list_ForEach(argsListEntry, v1_ephemeral_container->args) {
    if(cJSON_AddStringToObject(args, "", (char*)argsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_ephemeral_container->command
    if(v1_ephemeral_container->command) { 
    cJSON *command = cJSON_AddArrayToObject(item, "command");
    if(command == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *commandListEntry;
    list_ForEach(commandListEntry, v1_ephemeral_container->command) {
    if(cJSON_AddStringToObject(command, "", (char*)commandListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


    // v1_ephemeral_container->env
    if(v1_ephemeral_container->env) { 
    cJSON *env = cJSON_AddArrayToObject(item, "env");
    if(env == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *envListEntry;
    if (v1_ephemeral_container->env) {
    list_ForEach(envListEntry, v1_ephemeral_container->env) {
    cJSON *itemLocal = v1_env_var_convertToJSON(envListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(env, itemLocal);
    }
    }
     } 


    // v1_ephemeral_container->env_from
    if(v1_ephemeral_container->env_from) { 
    cJSON *env_from = cJSON_AddArrayToObject(item, "envFrom");
    if(env_from == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *env_fromListEntry;
    if (v1_ephemeral_container->env_from) {
    list_ForEach(env_fromListEntry, v1_ephemeral_container->env_from) {
    cJSON *itemLocal = v1_env_from_source_convertToJSON(env_fromListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(env_from, itemLocal);
    }
    }
     } 


    // v1_ephemeral_container->image
    if(v1_ephemeral_container->image) { 
    if(cJSON_AddStringToObject(item, "image", v1_ephemeral_container->image) == NULL) {
    goto fail; //String
    }
     } 


    // v1_ephemeral_container->image_pull_policy
    if(v1_ephemeral_container->image_pull_policy) { 
    if(cJSON_AddStringToObject(item, "imagePullPolicy", v1_ephemeral_container->image_pull_policy) == NULL) {
    goto fail; //String
    }
     } 


    // v1_ephemeral_container->lifecycle
    if(v1_ephemeral_container->lifecycle) { 
    cJSON *lifecycle_local_JSON = v1_lifecycle_convertToJSON(v1_ephemeral_container->lifecycle);
    if(lifecycle_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "lifecycle", lifecycle_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_ephemeral_container->liveness_probe
    if(v1_ephemeral_container->liveness_probe) { 
    cJSON *liveness_probe_local_JSON = v1_probe_convertToJSON(v1_ephemeral_container->liveness_probe);
    if(liveness_probe_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "livenessProbe", liveness_probe_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_ephemeral_container->name
    if (!v1_ephemeral_container->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_ephemeral_container->name) == NULL) {
    goto fail; //String
    }


    // v1_ephemeral_container->ports
    if(v1_ephemeral_container->ports) { 
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1_ephemeral_container->ports) {
    list_ForEach(portsListEntry, v1_ephemeral_container->ports) {
    cJSON *itemLocal = v1_container_port_convertToJSON(portsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ports, itemLocal);
    }
    }
     } 


    // v1_ephemeral_container->readiness_probe
    if(v1_ephemeral_container->readiness_probe) { 
    cJSON *readiness_probe_local_JSON = v1_probe_convertToJSON(v1_ephemeral_container->readiness_probe);
    if(readiness_probe_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "readinessProbe", readiness_probe_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_ephemeral_container->resources
    if(v1_ephemeral_container->resources) { 
    cJSON *resources_local_JSON = v1_resource_requirements_convertToJSON(v1_ephemeral_container->resources);
    if(resources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resources", resources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_ephemeral_container->security_context
    if(v1_ephemeral_container->security_context) { 
    cJSON *security_context_local_JSON = v1_security_context_convertToJSON(v1_ephemeral_container->security_context);
    if(security_context_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "securityContext", security_context_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_ephemeral_container->startup_probe
    if(v1_ephemeral_container->startup_probe) { 
    cJSON *startup_probe_local_JSON = v1_probe_convertToJSON(v1_ephemeral_container->startup_probe);
    if(startup_probe_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "startupProbe", startup_probe_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_ephemeral_container->_stdin
    if(v1_ephemeral_container->_stdin) { 
    if(cJSON_AddBoolToObject(item, "stdin", v1_ephemeral_container->_stdin) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_ephemeral_container->stdin_once
    if(v1_ephemeral_container->stdin_once) { 
    if(cJSON_AddBoolToObject(item, "stdinOnce", v1_ephemeral_container->stdin_once) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_ephemeral_container->target_container_name
    if(v1_ephemeral_container->target_container_name) { 
    if(cJSON_AddStringToObject(item, "targetContainerName", v1_ephemeral_container->target_container_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_ephemeral_container->termination_message_path
    if(v1_ephemeral_container->termination_message_path) { 
    if(cJSON_AddStringToObject(item, "terminationMessagePath", v1_ephemeral_container->termination_message_path) == NULL) {
    goto fail; //String
    }
     } 


    // v1_ephemeral_container->termination_message_policy
    if(v1_ephemeral_container->termination_message_policy) { 
    if(cJSON_AddStringToObject(item, "terminationMessagePolicy", v1_ephemeral_container->termination_message_policy) == NULL) {
    goto fail; //String
    }
     } 


    // v1_ephemeral_container->tty
    if(v1_ephemeral_container->tty) { 
    if(cJSON_AddBoolToObject(item, "tty", v1_ephemeral_container->tty) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_ephemeral_container->volume_devices
    if(v1_ephemeral_container->volume_devices) { 
    cJSON *volume_devices = cJSON_AddArrayToObject(item, "volumeDevices");
    if(volume_devices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volume_devicesListEntry;
    if (v1_ephemeral_container->volume_devices) {
    list_ForEach(volume_devicesListEntry, v1_ephemeral_container->volume_devices) {
    cJSON *itemLocal = v1_volume_device_convertToJSON(volume_devicesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volume_devices, itemLocal);
    }
    }
     } 


    // v1_ephemeral_container->volume_mounts
    if(v1_ephemeral_container->volume_mounts) { 
    cJSON *volume_mounts = cJSON_AddArrayToObject(item, "volumeMounts");
    if(volume_mounts == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volume_mountsListEntry;
    if (v1_ephemeral_container->volume_mounts) {
    list_ForEach(volume_mountsListEntry, v1_ephemeral_container->volume_mounts) {
    cJSON *itemLocal = v1_volume_mount_convertToJSON(volume_mountsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volume_mounts, itemLocal);
    }
    }
     } 


    // v1_ephemeral_container->working_dir
    if(v1_ephemeral_container->working_dir) { 
    if(cJSON_AddStringToObject(item, "workingDir", v1_ephemeral_container->working_dir) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_ephemeral_container_t *v1_ephemeral_container_parseFromJSON(cJSON *v1_ephemeral_containerJSON){

    v1_ephemeral_container_t *v1_ephemeral_container_local_var = NULL;

    // v1_ephemeral_container->args
    cJSON *args = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "args");
    list_t *argsList;
    if (args) { 
    cJSON *args_local;
    if(!cJSON_IsArray(args)) {
        goto end;//primitive container
    }
    argsList = list_create();

    cJSON_ArrayForEach(args_local, args)
    {
        if(!cJSON_IsString(args_local))
        {
            goto end;
        }
        list_addElement(argsList , strdup(args_local->valuestring));
    }
    }

    // v1_ephemeral_container->command
    cJSON *command = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "command");
    list_t *commandList;
    if (command) { 
    cJSON *command_local;
    if(!cJSON_IsArray(command)) {
        goto end;//primitive container
    }
    commandList = list_create();

    cJSON_ArrayForEach(command_local, command)
    {
        if(!cJSON_IsString(command_local))
        {
            goto end;
        }
        list_addElement(commandList , strdup(command_local->valuestring));
    }
    }

    // v1_ephemeral_container->env
    cJSON *env = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "env");
    list_t *envList;
    if (env) { 
    cJSON *env_local_nonprimitive;
    if(!cJSON_IsArray(env)){
        goto end; //nonprimitive container
    }

    envList = list_create();

    cJSON_ArrayForEach(env_local_nonprimitive,env )
    {
        if(!cJSON_IsObject(env_local_nonprimitive)){
            goto end;
        }
        v1_env_var_t *envItem = v1_env_var_parseFromJSON(env_local_nonprimitive);

        list_addElement(envList, envItem);
    }
    }

    // v1_ephemeral_container->env_from
    cJSON *env_from = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "envFrom");
    list_t *env_fromList;
    if (env_from) { 
    cJSON *env_from_local_nonprimitive;
    if(!cJSON_IsArray(env_from)){
        goto end; //nonprimitive container
    }

    env_fromList = list_create();

    cJSON_ArrayForEach(env_from_local_nonprimitive,env_from )
    {
        if(!cJSON_IsObject(env_from_local_nonprimitive)){
            goto end;
        }
        v1_env_from_source_t *env_fromItem = v1_env_from_source_parseFromJSON(env_from_local_nonprimitive);

        list_addElement(env_fromList, env_fromItem);
    }
    }

    // v1_ephemeral_container->image
    cJSON *image = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "image");
    if (image) { 
    if(!cJSON_IsString(image))
    {
    goto end; //String
    }
    }

    // v1_ephemeral_container->image_pull_policy
    cJSON *image_pull_policy = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "imagePullPolicy");
    if (image_pull_policy) { 
    if(!cJSON_IsString(image_pull_policy))
    {
    goto end; //String
    }
    }

    // v1_ephemeral_container->lifecycle
    cJSON *lifecycle = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "lifecycle");
    v1_lifecycle_t *lifecycle_local_nonprim = NULL;
    if (lifecycle) { 
    lifecycle_local_nonprim = v1_lifecycle_parseFromJSON(lifecycle); //nonprimitive
    }

    // v1_ephemeral_container->liveness_probe
    cJSON *liveness_probe = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "livenessProbe");
    v1_probe_t *liveness_probe_local_nonprim = NULL;
    if (liveness_probe) { 
    liveness_probe_local_nonprim = v1_probe_parseFromJSON(liveness_probe); //nonprimitive
    }

    // v1_ephemeral_container->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_ephemeral_container->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "ports");
    list_t *portsList;
    if (ports) { 
    cJSON *ports_local_nonprimitive;
    if(!cJSON_IsArray(ports)){
        goto end; //nonprimitive container
    }

    portsList = list_create();

    cJSON_ArrayForEach(ports_local_nonprimitive,ports )
    {
        if(!cJSON_IsObject(ports_local_nonprimitive)){
            goto end;
        }
        v1_container_port_t *portsItem = v1_container_port_parseFromJSON(ports_local_nonprimitive);

        list_addElement(portsList, portsItem);
    }
    }

    // v1_ephemeral_container->readiness_probe
    cJSON *readiness_probe = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "readinessProbe");
    v1_probe_t *readiness_probe_local_nonprim = NULL;
    if (readiness_probe) { 
    readiness_probe_local_nonprim = v1_probe_parseFromJSON(readiness_probe); //nonprimitive
    }

    // v1_ephemeral_container->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "resources");
    v1_resource_requirements_t *resources_local_nonprim = NULL;
    if (resources) { 
    resources_local_nonprim = v1_resource_requirements_parseFromJSON(resources); //nonprimitive
    }

    // v1_ephemeral_container->security_context
    cJSON *security_context = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "securityContext");
    v1_security_context_t *security_context_local_nonprim = NULL;
    if (security_context) { 
    security_context_local_nonprim = v1_security_context_parseFromJSON(security_context); //nonprimitive
    }

    // v1_ephemeral_container->startup_probe
    cJSON *startup_probe = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "startupProbe");
    v1_probe_t *startup_probe_local_nonprim = NULL;
    if (startup_probe) { 
    startup_probe_local_nonprim = v1_probe_parseFromJSON(startup_probe); //nonprimitive
    }

    // v1_ephemeral_container->_stdin
    cJSON *_stdin = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "stdin");
    if (_stdin) { 
    if(!cJSON_IsBool(_stdin))
    {
    goto end; //Bool
    }
    }

    // v1_ephemeral_container->stdin_once
    cJSON *stdin_once = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "stdinOnce");
    if (stdin_once) { 
    if(!cJSON_IsBool(stdin_once))
    {
    goto end; //Bool
    }
    }

    // v1_ephemeral_container->target_container_name
    cJSON *target_container_name = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "targetContainerName");
    if (target_container_name) { 
    if(!cJSON_IsString(target_container_name))
    {
    goto end; //String
    }
    }

    // v1_ephemeral_container->termination_message_path
    cJSON *termination_message_path = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "terminationMessagePath");
    if (termination_message_path) { 
    if(!cJSON_IsString(termination_message_path))
    {
    goto end; //String
    }
    }

    // v1_ephemeral_container->termination_message_policy
    cJSON *termination_message_policy = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "terminationMessagePolicy");
    if (termination_message_policy) { 
    if(!cJSON_IsString(termination_message_policy))
    {
    goto end; //String
    }
    }

    // v1_ephemeral_container->tty
    cJSON *tty = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "tty");
    if (tty) { 
    if(!cJSON_IsBool(tty))
    {
    goto end; //Bool
    }
    }

    // v1_ephemeral_container->volume_devices
    cJSON *volume_devices = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "volumeDevices");
    list_t *volume_devicesList;
    if (volume_devices) { 
    cJSON *volume_devices_local_nonprimitive;
    if(!cJSON_IsArray(volume_devices)){
        goto end; //nonprimitive container
    }

    volume_devicesList = list_create();

    cJSON_ArrayForEach(volume_devices_local_nonprimitive,volume_devices )
    {
        if(!cJSON_IsObject(volume_devices_local_nonprimitive)){
            goto end;
        }
        v1_volume_device_t *volume_devicesItem = v1_volume_device_parseFromJSON(volume_devices_local_nonprimitive);

        list_addElement(volume_devicesList, volume_devicesItem);
    }
    }

    // v1_ephemeral_container->volume_mounts
    cJSON *volume_mounts = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "volumeMounts");
    list_t *volume_mountsList;
    if (volume_mounts) { 
    cJSON *volume_mounts_local_nonprimitive;
    if(!cJSON_IsArray(volume_mounts)){
        goto end; //nonprimitive container
    }

    volume_mountsList = list_create();

    cJSON_ArrayForEach(volume_mounts_local_nonprimitive,volume_mounts )
    {
        if(!cJSON_IsObject(volume_mounts_local_nonprimitive)){
            goto end;
        }
        v1_volume_mount_t *volume_mountsItem = v1_volume_mount_parseFromJSON(volume_mounts_local_nonprimitive);

        list_addElement(volume_mountsList, volume_mountsItem);
    }
    }

    // v1_ephemeral_container->working_dir
    cJSON *working_dir = cJSON_GetObjectItemCaseSensitive(v1_ephemeral_containerJSON, "workingDir");
    if (working_dir) { 
    if(!cJSON_IsString(working_dir))
    {
    goto end; //String
    }
    }


    v1_ephemeral_container_local_var = v1_ephemeral_container_create (
        args ? argsList : NULL,
        command ? commandList : NULL,
        env ? envList : NULL,
        env_from ? env_fromList : NULL,
        image ? strdup(image->valuestring) : NULL,
        image_pull_policy ? strdup(image_pull_policy->valuestring) : NULL,
        lifecycle ? lifecycle_local_nonprim : NULL,
        liveness_probe ? liveness_probe_local_nonprim : NULL,
        strdup(name->valuestring),
        ports ? portsList : NULL,
        readiness_probe ? readiness_probe_local_nonprim : NULL,
        resources ? resources_local_nonprim : NULL,
        security_context ? security_context_local_nonprim : NULL,
        startup_probe ? startup_probe_local_nonprim : NULL,
        _stdin ? _stdin->valueint : 0,
        stdin_once ? stdin_once->valueint : 0,
        target_container_name ? strdup(target_container_name->valuestring) : NULL,
        termination_message_path ? strdup(termination_message_path->valuestring) : NULL,
        termination_message_policy ? strdup(termination_message_policy->valuestring) : NULL,
        tty ? tty->valueint : 0,
        volume_devices ? volume_devicesList : NULL,
        volume_mounts ? volume_mountsList : NULL,
        working_dir ? strdup(working_dir->valuestring) : NULL
        );

    return v1_ephemeral_container_local_var;
end:
    if (lifecycle_local_nonprim) {
        v1_lifecycle_free(lifecycle_local_nonprim);
        lifecycle_local_nonprim = NULL;
    }
    if (liveness_probe_local_nonprim) {
        v1_probe_free(liveness_probe_local_nonprim);
        liveness_probe_local_nonprim = NULL;
    }
    if (readiness_probe_local_nonprim) {
        v1_probe_free(readiness_probe_local_nonprim);
        readiness_probe_local_nonprim = NULL;
    }
    if (resources_local_nonprim) {
        v1_resource_requirements_free(resources_local_nonprim);
        resources_local_nonprim = NULL;
    }
    if (security_context_local_nonprim) {
        v1_security_context_free(security_context_local_nonprim);
        security_context_local_nonprim = NULL;
    }
    if (startup_probe_local_nonprim) {
        v1_probe_free(startup_probe_local_nonprim);
        startup_probe_local_nonprim = NULL;
    }
    return NULL;

}
