# v1_stateful_set_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**min_ready_seconds** | **int** | Minimum number of seconds for which a newly created pod should be ready without any of its container crashing for it to be considered available. Defaults to 0 (pod will be considered available as soon as it is ready) | [optional] 
**ordinals** | [**v1_stateful_set_ordinals_t**](v1_stateful_set_ordinals.md) \* |  | [optional] 
**persistent_volume_claim_retention_policy** | [**v1_stateful_set_persistent_volume_claim_retention_policy_t**](v1_stateful_set_persistent_volume_claim_retention_policy.md) \* |  | [optional] 
**pod_management_policy** | **char \*** | podManagementPolicy controls how pods are created during initial scale up, when replacing pods on nodes, or when scaling down. The default policy is &#x60;OrderedReady&#x60;, where pods are created in increasing order (pod-0, then pod-1, etc) and the controller will wait until each pod is ready before continuing. When scaling down, the pods are removed in the opposite order. The alternative policy is &#x60;Parallel&#x60; which will create pods in parallel to match the desired scale without waiting, and on scale down will delete all pods at once. | [optional] 
**replicas** | **int** | replicas is the desired number of replicas of the given Template. These are replicas in the sense that they are instantiations of the same Template, but individual replicas also have a consistent identity. If unspecified, defaults to 1. | [optional] 
**revision_history_limit** | **int** | revisionHistoryLimit is the maximum number of revisions that will be maintained in the StatefulSet&#39;s revision history. The revision history consists of all revisions not represented by a currently applied StatefulSetSpec version. The default value is 10. | [optional] 
**selector** | [**v1_label_selector_t**](v1_label_selector.md) \* |  | 
**service_name** | **char \*** | serviceName is the name of the service that governs this StatefulSet. This service must exist before the StatefulSet, and is responsible for the network identity of the set. Pods get DNS/hostnames that follow the pattern: pod-specific-string.serviceName.default.svc.cluster.local where \&quot;pod-specific-string\&quot; is managed by the StatefulSet controller. | [optional] 
**_template** | [**v1_pod_template_spec_t**](v1_pod_template_spec.md) \* |  | 
**update_strategy** | [**v1_stateful_set_update_strategy_t**](v1_stateful_set_update_strategy.md) \* |  | [optional] 
**volume_claim_templates** | [**list_t**](v1_persistent_volume_claim.md) \* | volumeClaimTemplates is a list of claims that pods are allowed to reference. The StatefulSet controller is responsible for mapping network identities to claims in a way that maintains the identity of a pod. Every claim in this list must have at least one matching (by name) volumeMount in one container in the template. A claim in this list takes precedence over any volumes in the template, with the same name. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


