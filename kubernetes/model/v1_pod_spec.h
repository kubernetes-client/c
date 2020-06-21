/*
 * v1_pod_spec.h
 *
 * PodSpec is a description of a pod.
 */

#ifndef _v1_pod_spec_H_
#define _v1_pod_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_spec_t v1_pod_spec_t;

#include "v1_affinity.h"
#include "v1_container.h"
#include "v1_ephemeral_container.h"
#include "v1_host_alias.h"
#include "v1_local_object_reference.h"
#include "v1_pod_dns_config.h"
#include "v1_pod_readiness_gate.h"
#include "v1_pod_security_context.h"
#include "v1_toleration.h"
#include "v1_topology_spread_constraint.h"
#include "v1_volume.h"



typedef struct v1_pod_spec_t {
    long active_deadline_seconds; //numeric
    struct v1_affinity_t *affinity; //model
    int automount_service_account_token; //boolean
    list_t *containers; //nonprimitive container
    struct v1_pod_dns_config_t *dns_config; //model
    char *dns_policy; // string
    int enable_service_links; //boolean
    list_t *ephemeral_containers; //nonprimitive container
    list_t *host_aliases; //nonprimitive container
    int host_ipc; //boolean
    int host_network; //boolean
    int host_pid; //boolean
    char *hostname; // string
    list_t *image_pull_secrets; //nonprimitive container
    list_t *init_containers; //nonprimitive container
    char *node_name; // string
    list_t* node_selector; //map
    list_t* overhead; //map
    char *preemption_policy; // string
    int priority; //numeric
    char *priority_class_name; // string
    list_t *readiness_gates; //nonprimitive container
    char *restart_policy; // string
    char *runtime_class_name; // string
    char *scheduler_name; // string
    struct v1_pod_security_context_t *security_context; //model
    char *service_account; // string
    char *service_account_name; // string
    int share_process_namespace; //boolean
    char *subdomain; // string
    long termination_grace_period_seconds; //numeric
    list_t *tolerations; //nonprimitive container
    list_t *topology_spread_constraints; //nonprimitive container
    list_t *volumes; //nonprimitive container

} v1_pod_spec_t;

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
);

void v1_pod_spec_free(v1_pod_spec_t *v1_pod_spec);

v1_pod_spec_t *v1_pod_spec_parseFromJSON(cJSON *v1_pod_specJSON);

cJSON *v1_pod_spec_convertToJSON(v1_pod_spec_t *v1_pod_spec);

#endif /* _v1_pod_spec_H_ */

