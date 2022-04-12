# v1_limit_range_item_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_default** | **list_t*** | Default resource requirement limit value by resource name if resource limit is omitted. | [optional] 
**default_request** | **list_t*** | DefaultRequest is the default resource requirement request value by resource name if resource request is omitted. | [optional] 
**max** | **list_t*** | Max usage constraints on this kind by resource name. | [optional] 
**max_limit_request_ratio** | **list_t*** | MaxLimitRequestRatio if specified, the named resource must have a request and limit that are both non-zero where limit divided by request is less than or equal to the enumerated value; this represents the max burst for the named resource. | [optional] 
**min** | **list_t*** | Min usage constraints on this kind by resource name. | [optional] 
**type** | **kubernetes_v1_limit_range_item_TYPE_e** | Type of resource that this limit applies to.  Possible enum values:  - &#x60;\&quot;Container\&quot;&#x60; Limit that applies to all containers in a namespace  - &#x60;\&quot;PersistentVolumeClaim\&quot;&#x60; Limit that applies to all persistent volume claims in a namespace  - &#x60;\&quot;Pod\&quot;&#x60; Limit that applies to all pods in a namespace | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


