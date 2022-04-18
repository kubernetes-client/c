/*
 * v1_service_spec.h
 *
 * ServiceSpec describes the attributes that a user creates on a service.
 */

#ifndef _v1_service_spec_H_
#define _v1_service_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_service_spec_t v1_service_spec_t;

#include "v1_service_port.h"
#include "v1_session_affinity_config.h"

// Enum EXTERNALTRAFFICPOLICY for v1_service_spec

typedef enum  { kubernetes_v1_service_spec_EXTERNALTRAFFICPOLICY_NULL = 0, kubernetes_v1_service_spec_EXTERNALTRAFFICPOLICY_Cluster, kubernetes_v1_service_spec_EXTERNALTRAFFICPOLICY_Local } kubernetes_v1_service_spec_EXTERNALTRAFFICPOLICY_e;

char* v1_service_spec_external_traffic_policy_ToString(kubernetes_v1_service_spec_EXTERNALTRAFFICPOLICY_e external_traffic_policy);

kubernetes_v1_service_spec_EXTERNALTRAFFICPOLICY_e v1_service_spec_external_traffic_policy_FromString(char* external_traffic_policy);

// Enum SESSIONAFFINITY for v1_service_spec

typedef enum  { kubernetes_v1_service_spec_SESSIONAFFINITY_NULL = 0, kubernetes_v1_service_spec_SESSIONAFFINITY_ClientIP, kubernetes_v1_service_spec_SESSIONAFFINITY_None } kubernetes_v1_service_spec_SESSIONAFFINITY_e;

char* v1_service_spec_session_affinity_ToString(kubernetes_v1_service_spec_SESSIONAFFINITY_e session_affinity);

kubernetes_v1_service_spec_SESSIONAFFINITY_e v1_service_spec_session_affinity_FromString(char* session_affinity);

// Enum TYPE for v1_service_spec

typedef enum  { kubernetes_v1_service_spec_TYPE_NULL = 0, kubernetes_v1_service_spec_TYPE_ClusterIP, kubernetes_v1_service_spec_TYPE_ExternalName, kubernetes_v1_service_spec_TYPE_LoadBalancer, kubernetes_v1_service_spec_TYPE_NodePort } kubernetes_v1_service_spec_TYPE_e;

char* v1_service_spec_type_ToString(kubernetes_v1_service_spec_TYPE_e type);

kubernetes_v1_service_spec_TYPE_e v1_service_spec_type_FromString(char* type);



typedef struct v1_service_spec_t {
    int allocate_load_balancer_node_ports; //boolean
    char *cluster_ip; // string
    list_t *cluster_ips; //primitive container
    list_t *external_ips; //primitive container
    char *external_name; // string
    kubernetes_v1_service_spec_EXTERNALTRAFFICPOLICY_e external_traffic_policy; //enum
    int health_check_node_port; //numeric
    char *internal_traffic_policy; // string
    list_t *ip_families; //primitive container
    char *ip_family_policy; // string
    char *load_balancer_class; // string
    char *load_balancer_ip; // string
    list_t *load_balancer_source_ranges; //primitive container
    list_t *ports; //nonprimitive container
    int publish_not_ready_addresses; //boolean
    list_t* selector; //map
    kubernetes_v1_service_spec_SESSIONAFFINITY_e session_affinity; //enum
    struct v1_session_affinity_config_t *session_affinity_config; //model
    kubernetes_v1_service_spec_TYPE_e type; //enum

} v1_service_spec_t;

v1_service_spec_t *v1_service_spec_create(
    int allocate_load_balancer_node_ports,
    char *cluster_ip,
    list_t *cluster_ips,
    list_t *external_ips,
    char *external_name,
    kubernetes_v1_service_spec_EXTERNALTRAFFICPOLICY_e external_traffic_policy,
    int health_check_node_port,
    char *internal_traffic_policy,
    list_t *ip_families,
    char *ip_family_policy,
    char *load_balancer_class,
    char *load_balancer_ip,
    list_t *load_balancer_source_ranges,
    list_t *ports,
    int publish_not_ready_addresses,
    list_t* selector,
    kubernetes_v1_service_spec_SESSIONAFFINITY_e session_affinity,
    v1_session_affinity_config_t *session_affinity_config,
    kubernetes_v1_service_spec_TYPE_e type
);

void v1_service_spec_free(v1_service_spec_t *v1_service_spec);

v1_service_spec_t *v1_service_spec_parseFromJSON(cJSON *v1_service_specJSON);

cJSON *v1_service_spec_convertToJSON(v1_service_spec_t *v1_service_spec);

#endif /* _v1_service_spec_H_ */

