# v1_pod_resource_claim_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** | Name uniquely identifies this resource claim inside the pod. This must match the name of an entry in pod.spec.resourceClaims, which implies that the string must be a DNS_LABEL. | 
**resource_claim_name** | **char \*** | ResourceClaimName is the name of the ResourceClaim that was generated for the Pod in the namespace of the Pod. It this is unset, then generating a ResourceClaim was not necessary. The pod.spec.resourceClaims entry can be ignored in this case. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


