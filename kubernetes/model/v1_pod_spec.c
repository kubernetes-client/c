#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_spec.h"



v1_pod_spec_t *v1_pod_spec_create(
    long active_deadline_seconds,
    v1_affinity_t *affinity,
    int automount_service_account_token,
    list_t *containers,
    v1_pod_dns_config_t *dns_config,
    char *dns_policy,
    int enable_service_links,
    list_t *ephemeral_containers,
    list_t *host_aliases,
    int host_ipc,
    int host_network,
    int host_pid,
    char *hostname,
    list_t *image_pull_secrets,
    list_t *init_containers,
    char *node_name,
    list_t* node_selector,
    list_t* overhead,
    char *preemption_policy,
    int priority,
    char *priority_class_name,
    list_t *readiness_gates,
    char *restart_policy,
    char *runtime_class_name,
    char *scheduler_name,
    v1_pod_security_context_t *security_context,
    char *service_account,
    char *service_account_name,
    int share_process_namespace,
    char *subdomain,
    long termination_grace_period_seconds,
    list_t *tolerations,
    list_t *topology_spread_constraints,
    list_t *volumes
    ) {
    v1_pod_spec_t *v1_pod_spec_local_var = malloc(sizeof(v1_pod_spec_t));
    if (!v1_pod_spec_local_var) {
        return NULL;
    }
    v1_pod_spec_local_var->active_deadline_seconds = active_deadline_seconds;
    v1_pod_spec_local_var->affinity = affinity;
    v1_pod_spec_local_var->automount_service_account_token = automount_service_account_token;
    v1_pod_spec_local_var->containers = containers;
    v1_pod_spec_local_var->dns_config = dns_config;
    v1_pod_spec_local_var->dns_policy = dns_policy;
    v1_pod_spec_local_var->enable_service_links = enable_service_links;
    v1_pod_spec_local_var->ephemeral_containers = ephemeral_containers;
    v1_pod_spec_local_var->host_aliases = host_aliases;
    v1_pod_spec_local_var->host_ipc = host_ipc;
    v1_pod_spec_local_var->host_network = host_network;
    v1_pod_spec_local_var->host_pid = host_pid;
    v1_pod_spec_local_var->hostname = hostname;
    v1_pod_spec_local_var->image_pull_secrets = image_pull_secrets;
    v1_pod_spec_local_var->init_containers = init_containers;
    v1_pod_spec_local_var->node_name = node_name;
    v1_pod_spec_local_var->node_selector = node_selector;
    v1_pod_spec_local_var->overhead = overhead;
    v1_pod_spec_local_var->preemption_policy = preemption_policy;
    v1_pod_spec_local_var->priority = priority;
    v1_pod_spec_local_var->priority_class_name = priority_class_name;
    v1_pod_spec_local_var->readiness_gates = readiness_gates;
    v1_pod_spec_local_var->restart_policy = restart_policy;
    v1_pod_spec_local_var->runtime_class_name = runtime_class_name;
    v1_pod_spec_local_var->scheduler_name = scheduler_name;
    v1_pod_spec_local_var->security_context = security_context;
    v1_pod_spec_local_var->service_account = service_account;
    v1_pod_spec_local_var->service_account_name = service_account_name;
    v1_pod_spec_local_var->share_process_namespace = share_process_namespace;
    v1_pod_spec_local_var->subdomain = subdomain;
    v1_pod_spec_local_var->termination_grace_period_seconds = termination_grace_period_seconds;
    v1_pod_spec_local_var->tolerations = tolerations;
    v1_pod_spec_local_var->topology_spread_constraints = topology_spread_constraints;
    v1_pod_spec_local_var->volumes = volumes;

    return v1_pod_spec_local_var;
}


void v1_pod_spec_free(v1_pod_spec_t *v1_pod_spec) {
    if(NULL == v1_pod_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_spec->affinity) {
        v1_affinity_free(v1_pod_spec->affinity);
        v1_pod_spec->affinity = NULL;
    }
    if (v1_pod_spec->containers) {
        list_ForEach(listEntry, v1_pod_spec->containers) {
            v1_container_free(listEntry->data);
        }
        list_free(v1_pod_spec->containers);
        v1_pod_spec->containers = NULL;
    }
    if (v1_pod_spec->dns_config) {
        v1_pod_dns_config_free(v1_pod_spec->dns_config);
        v1_pod_spec->dns_config = NULL;
    }
    if (v1_pod_spec->dns_policy) {
        free(v1_pod_spec->dns_policy);
        v1_pod_spec->dns_policy = NULL;
    }
    if (v1_pod_spec->ephemeral_containers) {
        list_ForEach(listEntry, v1_pod_spec->ephemeral_containers) {
            v1_ephemeral_container_free(listEntry->data);
        }
        list_free(v1_pod_spec->ephemeral_containers);
        v1_pod_spec->ephemeral_containers = NULL;
    }
    if (v1_pod_spec->host_aliases) {
        list_ForEach(listEntry, v1_pod_spec->host_aliases) {
            v1_host_alias_free(listEntry->data);
        }
        list_free(v1_pod_spec->host_aliases);
        v1_pod_spec->host_aliases = NULL;
    }
    if (v1_pod_spec->hostname) {
        free(v1_pod_spec->hostname);
        v1_pod_spec->hostname = NULL;
    }
    if (v1_pod_spec->image_pull_secrets) {
        list_ForEach(listEntry, v1_pod_spec->image_pull_secrets) {
            v1_local_object_reference_free(listEntry->data);
        }
        list_free(v1_pod_spec->image_pull_secrets);
        v1_pod_spec->image_pull_secrets = NULL;
    }
    if (v1_pod_spec->init_containers) {
        list_ForEach(listEntry, v1_pod_spec->init_containers) {
            v1_container_free(listEntry->data);
        }
        list_free(v1_pod_spec->init_containers);
        v1_pod_spec->init_containers = NULL;
    }
    if (v1_pod_spec->node_name) {
        free(v1_pod_spec->node_name);
        v1_pod_spec->node_name = NULL;
    }
    if (v1_pod_spec->node_selector) {
        list_ForEach(listEntry, v1_pod_spec->node_selector) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_pod_spec->node_selector);
        v1_pod_spec->node_selector = NULL;
    }
    if (v1_pod_spec->overhead) {
        list_ForEach(listEntry, v1_pod_spec->overhead) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_pod_spec->overhead);
        v1_pod_spec->overhead = NULL;
    }
    if (v1_pod_spec->preemption_policy) {
        free(v1_pod_spec->preemption_policy);
        v1_pod_spec->preemption_policy = NULL;
    }
    if (v1_pod_spec->priority_class_name) {
        free(v1_pod_spec->priority_class_name);
        v1_pod_spec->priority_class_name = NULL;
    }
    if (v1_pod_spec->readiness_gates) {
        list_ForEach(listEntry, v1_pod_spec->readiness_gates) {
            v1_pod_readiness_gate_free(listEntry->data);
        }
        list_free(v1_pod_spec->readiness_gates);
        v1_pod_spec->readiness_gates = NULL;
    }
    if (v1_pod_spec->restart_policy) {
        free(v1_pod_spec->restart_policy);
        v1_pod_spec->restart_policy = NULL;
    }
    if (v1_pod_spec->runtime_class_name) {
        free(v1_pod_spec->runtime_class_name);
        v1_pod_spec->runtime_class_name = NULL;
    }
    if (v1_pod_spec->scheduler_name) {
        free(v1_pod_spec->scheduler_name);
        v1_pod_spec->scheduler_name = NULL;
    }
    if (v1_pod_spec->security_context) {
        v1_pod_security_context_free(v1_pod_spec->security_context);
        v1_pod_spec->security_context = NULL;
    }
    if (v1_pod_spec->service_account) {
        free(v1_pod_spec->service_account);
        v1_pod_spec->service_account = NULL;
    }
    if (v1_pod_spec->service_account_name) {
        free(v1_pod_spec->service_account_name);
        v1_pod_spec->service_account_name = NULL;
    }
    if (v1_pod_spec->subdomain) {
        free(v1_pod_spec->subdomain);
        v1_pod_spec->subdomain = NULL;
    }
    if (v1_pod_spec->tolerations) {
        list_ForEach(listEntry, v1_pod_spec->tolerations) {
            v1_toleration_free(listEntry->data);
        }
        list_free(v1_pod_spec->tolerations);
        v1_pod_spec->tolerations = NULL;
    }
    if (v1_pod_spec->topology_spread_constraints) {
        list_ForEach(listEntry, v1_pod_spec->topology_spread_constraints) {
            v1_topology_spread_constraint_free(listEntry->data);
        }
        list_free(v1_pod_spec->topology_spread_constraints);
        v1_pod_spec->topology_spread_constraints = NULL;
    }
    if (v1_pod_spec->volumes) {
        list_ForEach(listEntry, v1_pod_spec->volumes) {
            v1_volume_free(listEntry->data);
        }
        list_free(v1_pod_spec->volumes);
        v1_pod_spec->volumes = NULL;
    }
    free(v1_pod_spec);
}

cJSON *v1_pod_spec_convertToJSON(v1_pod_spec_t *v1_pod_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_spec->active_deadline_seconds
    if(v1_pod_spec->active_deadline_seconds) { 
    if(cJSON_AddNumberToObject(item, "activeDeadlineSeconds", v1_pod_spec->active_deadline_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_pod_spec->affinity
    if(v1_pod_spec->affinity) { 
    cJSON *affinity_local_JSON = v1_affinity_convertToJSON(v1_pod_spec->affinity);
    if(affinity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "affinity", affinity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_pod_spec->automount_service_account_token
    if(v1_pod_spec->automount_service_account_token) { 
    if(cJSON_AddBoolToObject(item, "automountServiceAccountToken", v1_pod_spec->automount_service_account_token) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_pod_spec->containers
    if (!v1_pod_spec->containers) {
        goto fail;
    }
    
    cJSON *containers = cJSON_AddArrayToObject(item, "containers");
    if(containers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *containersListEntry;
    if (v1_pod_spec->containers) {
    list_ForEach(containersListEntry, v1_pod_spec->containers) {
    cJSON *itemLocal = v1_container_convertToJSON(containersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(containers, itemLocal);
    }
    }


    // v1_pod_spec->dns_config
    if(v1_pod_spec->dns_config) { 
    cJSON *dns_config_local_JSON = v1_pod_dns_config_convertToJSON(v1_pod_spec->dns_config);
    if(dns_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "dnsConfig", dns_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_pod_spec->dns_policy
    if(v1_pod_spec->dns_policy) { 
    if(cJSON_AddStringToObject(item, "dnsPolicy", v1_pod_spec->dns_policy) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->enable_service_links
    if(v1_pod_spec->enable_service_links) { 
    if(cJSON_AddBoolToObject(item, "enableServiceLinks", v1_pod_spec->enable_service_links) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_pod_spec->ephemeral_containers
    if(v1_pod_spec->ephemeral_containers) { 
    cJSON *ephemeral_containers = cJSON_AddArrayToObject(item, "ephemeralContainers");
    if(ephemeral_containers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ephemeral_containersListEntry;
    if (v1_pod_spec->ephemeral_containers) {
    list_ForEach(ephemeral_containersListEntry, v1_pod_spec->ephemeral_containers) {
    cJSON *itemLocal = v1_ephemeral_container_convertToJSON(ephemeral_containersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ephemeral_containers, itemLocal);
    }
    }
     } 


    // v1_pod_spec->host_aliases
    if(v1_pod_spec->host_aliases) { 
    cJSON *host_aliases = cJSON_AddArrayToObject(item, "hostAliases");
    if(host_aliases == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *host_aliasesListEntry;
    if (v1_pod_spec->host_aliases) {
    list_ForEach(host_aliasesListEntry, v1_pod_spec->host_aliases) {
    cJSON *itemLocal = v1_host_alias_convertToJSON(host_aliasesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(host_aliases, itemLocal);
    }
    }
     } 


    // v1_pod_spec->host_ipc
    if(v1_pod_spec->host_ipc) { 
    if(cJSON_AddBoolToObject(item, "hostIPC", v1_pod_spec->host_ipc) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_pod_spec->host_network
    if(v1_pod_spec->host_network) { 
    if(cJSON_AddBoolToObject(item, "hostNetwork", v1_pod_spec->host_network) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_pod_spec->host_pid
    if(v1_pod_spec->host_pid) { 
    if(cJSON_AddBoolToObject(item, "hostPID", v1_pod_spec->host_pid) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_pod_spec->hostname
    if(v1_pod_spec->hostname) { 
    if(cJSON_AddStringToObject(item, "hostname", v1_pod_spec->hostname) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->image_pull_secrets
    if(v1_pod_spec->image_pull_secrets) { 
    cJSON *image_pull_secrets = cJSON_AddArrayToObject(item, "imagePullSecrets");
    if(image_pull_secrets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *image_pull_secretsListEntry;
    if (v1_pod_spec->image_pull_secrets) {
    list_ForEach(image_pull_secretsListEntry, v1_pod_spec->image_pull_secrets) {
    cJSON *itemLocal = v1_local_object_reference_convertToJSON(image_pull_secretsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(image_pull_secrets, itemLocal);
    }
    }
     } 


    // v1_pod_spec->init_containers
    if(v1_pod_spec->init_containers) { 
    cJSON *init_containers = cJSON_AddArrayToObject(item, "initContainers");
    if(init_containers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *init_containersListEntry;
    if (v1_pod_spec->init_containers) {
    list_ForEach(init_containersListEntry, v1_pod_spec->init_containers) {
    cJSON *itemLocal = v1_container_convertToJSON(init_containersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(init_containers, itemLocal);
    }
    }
     } 


    // v1_pod_spec->node_name
    if(v1_pod_spec->node_name) { 
    if(cJSON_AddStringToObject(item, "nodeName", v1_pod_spec->node_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->node_selector
    if(v1_pod_spec->node_selector) { 
    cJSON *node_selector = cJSON_AddObjectToObject(item, "nodeSelector");
    if(node_selector == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = node_selector;
    listEntry_t *node_selectorListEntry;
    if (v1_pod_spec->node_selector) {
    list_ForEach(node_selectorListEntry, v1_pod_spec->node_selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)node_selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_pod_spec->overhead
    if(v1_pod_spec->overhead) { 
    cJSON *overhead = cJSON_AddObjectToObject(item, "overhead");
    if(overhead == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = overhead;
    listEntry_t *overheadListEntry;
    if (v1_pod_spec->overhead) {
    list_ForEach(overheadListEntry, v1_pod_spec->overhead) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)overheadListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_pod_spec->preemption_policy
    if(v1_pod_spec->preemption_policy) { 
    if(cJSON_AddStringToObject(item, "preemptionPolicy", v1_pod_spec->preemption_policy) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->priority
    if(v1_pod_spec->priority) { 
    if(cJSON_AddNumberToObject(item, "priority", v1_pod_spec->priority) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_pod_spec->priority_class_name
    if(v1_pod_spec->priority_class_name) { 
    if(cJSON_AddStringToObject(item, "priorityClassName", v1_pod_spec->priority_class_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->readiness_gates
    if(v1_pod_spec->readiness_gates) { 
    cJSON *readiness_gates = cJSON_AddArrayToObject(item, "readinessGates");
    if(readiness_gates == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *readiness_gatesListEntry;
    if (v1_pod_spec->readiness_gates) {
    list_ForEach(readiness_gatesListEntry, v1_pod_spec->readiness_gates) {
    cJSON *itemLocal = v1_pod_readiness_gate_convertToJSON(readiness_gatesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(readiness_gates, itemLocal);
    }
    }
     } 


    // v1_pod_spec->restart_policy
    if(v1_pod_spec->restart_policy) { 
    if(cJSON_AddStringToObject(item, "restartPolicy", v1_pod_spec->restart_policy) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->runtime_class_name
    if(v1_pod_spec->runtime_class_name) { 
    if(cJSON_AddStringToObject(item, "runtimeClassName", v1_pod_spec->runtime_class_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->scheduler_name
    if(v1_pod_spec->scheduler_name) { 
    if(cJSON_AddStringToObject(item, "schedulerName", v1_pod_spec->scheduler_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->security_context
    if(v1_pod_spec->security_context) { 
    cJSON *security_context_local_JSON = v1_pod_security_context_convertToJSON(v1_pod_spec->security_context);
    if(security_context_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "securityContext", security_context_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_pod_spec->service_account
    if(v1_pod_spec->service_account) { 
    if(cJSON_AddStringToObject(item, "serviceAccount", v1_pod_spec->service_account) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->service_account_name
    if(v1_pod_spec->service_account_name) { 
    if(cJSON_AddStringToObject(item, "serviceAccountName", v1_pod_spec->service_account_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->share_process_namespace
    if(v1_pod_spec->share_process_namespace) { 
    if(cJSON_AddBoolToObject(item, "shareProcessNamespace", v1_pod_spec->share_process_namespace) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_pod_spec->subdomain
    if(v1_pod_spec->subdomain) { 
    if(cJSON_AddStringToObject(item, "subdomain", v1_pod_spec->subdomain) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod_spec->termination_grace_period_seconds
    if(v1_pod_spec->termination_grace_period_seconds) { 
    if(cJSON_AddNumberToObject(item, "terminationGracePeriodSeconds", v1_pod_spec->termination_grace_period_seconds) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_pod_spec->tolerations
    if(v1_pod_spec->tolerations) { 
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1_pod_spec->tolerations) {
    list_ForEach(tolerationsListEntry, v1_pod_spec->tolerations) {
    cJSON *itemLocal = v1_toleration_convertToJSON(tolerationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tolerations, itemLocal);
    }
    }
     } 


    // v1_pod_spec->topology_spread_constraints
    if(v1_pod_spec->topology_spread_constraints) { 
    cJSON *topology_spread_constraints = cJSON_AddArrayToObject(item, "topologySpreadConstraints");
    if(topology_spread_constraints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *topology_spread_constraintsListEntry;
    if (v1_pod_spec->topology_spread_constraints) {
    list_ForEach(topology_spread_constraintsListEntry, v1_pod_spec->topology_spread_constraints) {
    cJSON *itemLocal = v1_topology_spread_constraint_convertToJSON(topology_spread_constraintsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(topology_spread_constraints, itemLocal);
    }
    }
     } 


    // v1_pod_spec->volumes
    if(v1_pod_spec->volumes) { 
    cJSON *volumes = cJSON_AddArrayToObject(item, "volumes");
    if(volumes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumesListEntry;
    if (v1_pod_spec->volumes) {
    list_ForEach(volumesListEntry, v1_pod_spec->volumes) {
    cJSON *itemLocal = v1_volume_convertToJSON(volumesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumes, itemLocal);
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

v1_pod_spec_t *v1_pod_spec_parseFromJSON(cJSON *v1_pod_specJSON){

    v1_pod_spec_t *v1_pod_spec_local_var = NULL;

    // v1_pod_spec->active_deadline_seconds
    cJSON *active_deadline_seconds = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "activeDeadlineSeconds");
    if (active_deadline_seconds) { 
    if(!cJSON_IsNumber(active_deadline_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_spec->affinity
    cJSON *affinity = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "affinity");
    v1_affinity_t *affinity_local_nonprim = NULL;
    if (affinity) { 
    affinity_local_nonprim = v1_affinity_parseFromJSON(affinity); //nonprimitive
    }

    // v1_pod_spec->automount_service_account_token
    cJSON *automount_service_account_token = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "automountServiceAccountToken");
    if (automount_service_account_token) { 
    if(!cJSON_IsBool(automount_service_account_token))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->containers
    cJSON *containers = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "containers");
    if (!containers) {
        goto end;
    }

    list_t *containersList;
    
    cJSON *containers_local_nonprimitive;
    if(!cJSON_IsArray(containers)){
        goto end; //nonprimitive container
    }

    containersList = list_create();

    cJSON_ArrayForEach(containers_local_nonprimitive,containers )
    {
        if(!cJSON_IsObject(containers_local_nonprimitive)){
            goto end;
        }
        v1_container_t *containersItem = v1_container_parseFromJSON(containers_local_nonprimitive);

        list_addElement(containersList, containersItem);
    }

    // v1_pod_spec->dns_config
    cJSON *dns_config = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "dnsConfig");
    v1_pod_dns_config_t *dns_config_local_nonprim = NULL;
    if (dns_config) { 
    dns_config_local_nonprim = v1_pod_dns_config_parseFromJSON(dns_config); //nonprimitive
    }

    // v1_pod_spec->dns_policy
    cJSON *dns_policy = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "dnsPolicy");
    if (dns_policy) { 
    if(!cJSON_IsString(dns_policy))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->enable_service_links
    cJSON *enable_service_links = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "enableServiceLinks");
    if (enable_service_links) { 
    if(!cJSON_IsBool(enable_service_links))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->ephemeral_containers
    cJSON *ephemeral_containers = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "ephemeralContainers");
    list_t *ephemeral_containersList;
    if (ephemeral_containers) { 
    cJSON *ephemeral_containers_local_nonprimitive;
    if(!cJSON_IsArray(ephemeral_containers)){
        goto end; //nonprimitive container
    }

    ephemeral_containersList = list_create();

    cJSON_ArrayForEach(ephemeral_containers_local_nonprimitive,ephemeral_containers )
    {
        if(!cJSON_IsObject(ephemeral_containers_local_nonprimitive)){
            goto end;
        }
        v1_ephemeral_container_t *ephemeral_containersItem = v1_ephemeral_container_parseFromJSON(ephemeral_containers_local_nonprimitive);

        list_addElement(ephemeral_containersList, ephemeral_containersItem);
    }
    }

    // v1_pod_spec->host_aliases
    cJSON *host_aliases = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "hostAliases");
    list_t *host_aliasesList;
    if (host_aliases) { 
    cJSON *host_aliases_local_nonprimitive;
    if(!cJSON_IsArray(host_aliases)){
        goto end; //nonprimitive container
    }

    host_aliasesList = list_create();

    cJSON_ArrayForEach(host_aliases_local_nonprimitive,host_aliases )
    {
        if(!cJSON_IsObject(host_aliases_local_nonprimitive)){
            goto end;
        }
        v1_host_alias_t *host_aliasesItem = v1_host_alias_parseFromJSON(host_aliases_local_nonprimitive);

        list_addElement(host_aliasesList, host_aliasesItem);
    }
    }

    // v1_pod_spec->host_ipc
    cJSON *host_ipc = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "hostIPC");
    if (host_ipc) { 
    if(!cJSON_IsBool(host_ipc))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->host_network
    cJSON *host_network = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "hostNetwork");
    if (host_network) { 
    if(!cJSON_IsBool(host_network))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->host_pid
    cJSON *host_pid = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "hostPID");
    if (host_pid) { 
    if(!cJSON_IsBool(host_pid))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "hostname");
    if (hostname) { 
    if(!cJSON_IsString(hostname))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->image_pull_secrets
    cJSON *image_pull_secrets = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "imagePullSecrets");
    list_t *image_pull_secretsList;
    if (image_pull_secrets) { 
    cJSON *image_pull_secrets_local_nonprimitive;
    if(!cJSON_IsArray(image_pull_secrets)){
        goto end; //nonprimitive container
    }

    image_pull_secretsList = list_create();

    cJSON_ArrayForEach(image_pull_secrets_local_nonprimitive,image_pull_secrets )
    {
        if(!cJSON_IsObject(image_pull_secrets_local_nonprimitive)){
            goto end;
        }
        v1_local_object_reference_t *image_pull_secretsItem = v1_local_object_reference_parseFromJSON(image_pull_secrets_local_nonprimitive);

        list_addElement(image_pull_secretsList, image_pull_secretsItem);
    }
    }

    // v1_pod_spec->init_containers
    cJSON *init_containers = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "initContainers");
    list_t *init_containersList;
    if (init_containers) { 
    cJSON *init_containers_local_nonprimitive;
    if(!cJSON_IsArray(init_containers)){
        goto end; //nonprimitive container
    }

    init_containersList = list_create();

    cJSON_ArrayForEach(init_containers_local_nonprimitive,init_containers )
    {
        if(!cJSON_IsObject(init_containers_local_nonprimitive)){
            goto end;
        }
        v1_container_t *init_containersItem = v1_container_parseFromJSON(init_containers_local_nonprimitive);

        list_addElement(init_containersList, init_containersItem);
    }
    }

    // v1_pod_spec->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "nodeName");
    if (node_name) { 
    if(!cJSON_IsString(node_name))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->node_selector
    cJSON *node_selector = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "nodeSelector");
    list_t *node_selectorList;
    if (node_selector) { 
    cJSON *node_selector_local_map;
    if(!cJSON_IsObject(node_selector)) {
        goto end;//primitive map container
    }
    node_selectorList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(node_selector_local_map, node_selector)
    {
		cJSON *localMapObject = node_selector_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(node_selectorList , localMapKeyPair);
    }
    }

    // v1_pod_spec->overhead
    cJSON *overhead = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "overhead");
    list_t *overheadList;
    if (overhead) { 
    cJSON *overhead_local_map;
    if(!cJSON_IsObject(overhead)) {
        goto end;//primitive map container
    }
    overheadList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(overhead_local_map, overhead)
    {
		cJSON *localMapObject = overhead_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(overheadList , localMapKeyPair);
    }
    }

    // v1_pod_spec->preemption_policy
    cJSON *preemption_policy = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "preemptionPolicy");
    if (preemption_policy) { 
    if(!cJSON_IsString(preemption_policy))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "priority");
    if (priority) { 
    if(!cJSON_IsNumber(priority))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_spec->priority_class_name
    cJSON *priority_class_name = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "priorityClassName");
    if (priority_class_name) { 
    if(!cJSON_IsString(priority_class_name))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->readiness_gates
    cJSON *readiness_gates = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "readinessGates");
    list_t *readiness_gatesList;
    if (readiness_gates) { 
    cJSON *readiness_gates_local_nonprimitive;
    if(!cJSON_IsArray(readiness_gates)){
        goto end; //nonprimitive container
    }

    readiness_gatesList = list_create();

    cJSON_ArrayForEach(readiness_gates_local_nonprimitive,readiness_gates )
    {
        if(!cJSON_IsObject(readiness_gates_local_nonprimitive)){
            goto end;
        }
        v1_pod_readiness_gate_t *readiness_gatesItem = v1_pod_readiness_gate_parseFromJSON(readiness_gates_local_nonprimitive);

        list_addElement(readiness_gatesList, readiness_gatesItem);
    }
    }

    // v1_pod_spec->restart_policy
    cJSON *restart_policy = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "restartPolicy");
    if (restart_policy) { 
    if(!cJSON_IsString(restart_policy))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->runtime_class_name
    cJSON *runtime_class_name = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "runtimeClassName");
    if (runtime_class_name) { 
    if(!cJSON_IsString(runtime_class_name))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->scheduler_name
    cJSON *scheduler_name = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "schedulerName");
    if (scheduler_name) { 
    if(!cJSON_IsString(scheduler_name))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->security_context
    cJSON *security_context = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "securityContext");
    v1_pod_security_context_t *security_context_local_nonprim = NULL;
    if (security_context) { 
    security_context_local_nonprim = v1_pod_security_context_parseFromJSON(security_context); //nonprimitive
    }

    // v1_pod_spec->service_account
    cJSON *service_account = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "serviceAccount");
    if (service_account) { 
    if(!cJSON_IsString(service_account))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->service_account_name
    cJSON *service_account_name = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "serviceAccountName");
    if (service_account_name) { 
    if(!cJSON_IsString(service_account_name))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->share_process_namespace
    cJSON *share_process_namespace = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "shareProcessNamespace");
    if (share_process_namespace) { 
    if(!cJSON_IsBool(share_process_namespace))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->subdomain
    cJSON *subdomain = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "subdomain");
    if (subdomain) { 
    if(!cJSON_IsString(subdomain))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->termination_grace_period_seconds
    cJSON *termination_grace_period_seconds = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "terminationGracePeriodSeconds");
    if (termination_grace_period_seconds) { 
    if(!cJSON_IsNumber(termination_grace_period_seconds))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_spec->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "tolerations");
    list_t *tolerationsList;
    if (tolerations) { 
    cJSON *tolerations_local_nonprimitive;
    if(!cJSON_IsArray(tolerations)){
        goto end; //nonprimitive container
    }

    tolerationsList = list_create();

    cJSON_ArrayForEach(tolerations_local_nonprimitive,tolerations )
    {
        if(!cJSON_IsObject(tolerations_local_nonprimitive)){
            goto end;
        }
        v1_toleration_t *tolerationsItem = v1_toleration_parseFromJSON(tolerations_local_nonprimitive);

        list_addElement(tolerationsList, tolerationsItem);
    }
    }

    // v1_pod_spec->topology_spread_constraints
    cJSON *topology_spread_constraints = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "topologySpreadConstraints");
    list_t *topology_spread_constraintsList;
    if (topology_spread_constraints) { 
    cJSON *topology_spread_constraints_local_nonprimitive;
    if(!cJSON_IsArray(topology_spread_constraints)){
        goto end; //nonprimitive container
    }

    topology_spread_constraintsList = list_create();

    cJSON_ArrayForEach(topology_spread_constraints_local_nonprimitive,topology_spread_constraints )
    {
        if(!cJSON_IsObject(topology_spread_constraints_local_nonprimitive)){
            goto end;
        }
        v1_topology_spread_constraint_t *topology_spread_constraintsItem = v1_topology_spread_constraint_parseFromJSON(topology_spread_constraints_local_nonprimitive);

        list_addElement(topology_spread_constraintsList, topology_spread_constraintsItem);
    }
    }

    // v1_pod_spec->volumes
    cJSON *volumes = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "volumes");
    list_t *volumesList;
    if (volumes) { 
    cJSON *volumes_local_nonprimitive;
    if(!cJSON_IsArray(volumes)){
        goto end; //nonprimitive container
    }

    volumesList = list_create();

    cJSON_ArrayForEach(volumes_local_nonprimitive,volumes )
    {
        if(!cJSON_IsObject(volumes_local_nonprimitive)){
            goto end;
        }
        v1_volume_t *volumesItem = v1_volume_parseFromJSON(volumes_local_nonprimitive);

        list_addElement(volumesList, volumesItem);
    }
    }


    v1_pod_spec_local_var = v1_pod_spec_create (
        active_deadline_seconds ? active_deadline_seconds->valuedouble : 0,
        affinity ? affinity_local_nonprim : NULL,
        automount_service_account_token ? automount_service_account_token->valueint : 0,
        containersList,
        dns_config ? dns_config_local_nonprim : NULL,
        dns_policy ? strdup(dns_policy->valuestring) : NULL,
        enable_service_links ? enable_service_links->valueint : 0,
        ephemeral_containers ? ephemeral_containersList : NULL,
        host_aliases ? host_aliasesList : NULL,
        host_ipc ? host_ipc->valueint : 0,
        host_network ? host_network->valueint : 0,
        host_pid ? host_pid->valueint : 0,
        hostname ? strdup(hostname->valuestring) : NULL,
        image_pull_secrets ? image_pull_secretsList : NULL,
        init_containers ? init_containersList : NULL,
        node_name ? strdup(node_name->valuestring) : NULL,
        node_selector ? node_selectorList : NULL,
        overhead ? overheadList : NULL,
        preemption_policy ? strdup(preemption_policy->valuestring) : NULL,
        priority ? priority->valuedouble : 0,
        priority_class_name ? strdup(priority_class_name->valuestring) : NULL,
        readiness_gates ? readiness_gatesList : NULL,
        restart_policy ? strdup(restart_policy->valuestring) : NULL,
        runtime_class_name ? strdup(runtime_class_name->valuestring) : NULL,
        scheduler_name ? strdup(scheduler_name->valuestring) : NULL,
        security_context ? security_context_local_nonprim : NULL,
        service_account ? strdup(service_account->valuestring) : NULL,
        service_account_name ? strdup(service_account_name->valuestring) : NULL,
        share_process_namespace ? share_process_namespace->valueint : 0,
        subdomain ? strdup(subdomain->valuestring) : NULL,
        termination_grace_period_seconds ? termination_grace_period_seconds->valuedouble : 0,
        tolerations ? tolerationsList : NULL,
        topology_spread_constraints ? topology_spread_constraintsList : NULL,
        volumes ? volumesList : NULL
        );

    return v1_pod_spec_local_var;
end:
    if (affinity_local_nonprim) {
        v1_affinity_free(affinity_local_nonprim);
        affinity_local_nonprim = NULL;
    }
    if (dns_config_local_nonprim) {
        v1_pod_dns_config_free(dns_config_local_nonprim);
        dns_config_local_nonprim = NULL;
    }
    if (security_context_local_nonprim) {
        v1_pod_security_context_free(security_context_local_nonprim);
        security_context_local_nonprim = NULL;
    }
    return NULL;

}
