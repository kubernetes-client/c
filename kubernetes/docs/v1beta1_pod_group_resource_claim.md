# v1beta1_pod_group_resource_claim_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** | name uniquely identifies this resource claim inside the PodGroup. This must be a DNS_LABEL. | 
**resource_claim_name** | **char \*** | resourceClaimName is the name of a ResourceClaim object in the same namespace as this PodGroup. The ResourceClaim will be reserved for the PodGroup instead of its individual pods.  Exactly one of ResourceClaimName and ResourceClaimTemplateName must be set. | [optional] 
**resource_claim_template_name** | **char \*** | resourceClaimTemplateName is the name of a ResourceClaimTemplate object in the same namespace as this PodGroup.  The template will be used to create a new ResourceClaim, which will be bound to this PodGroup. When this PodGroup is deleted, the ResourceClaim will also be deleted. The PodGroup name and resource name, along with a generated component, will be used to form a unique name for the ResourceClaim, which will be recorded in podgroup.status.resourceClaimStatuses.  This field is immutable and no changes will be made to the corresponding ResourceClaim by the control plane after creating the ResourceClaim.  Exactly one of ResourceClaimName and ResourceClaimTemplateName must be set. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


