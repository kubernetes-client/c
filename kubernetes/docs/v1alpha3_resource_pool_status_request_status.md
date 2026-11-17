# v1alpha3_resource_pool_status_request_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**conditions** | [**list_t**](v1_condition.md) \* | Conditions provide information about the state of the request. A condition with type&#x3D;Complete or type&#x3D;Failed will always be set when the status is populated.  Known condition types: - \&quot;Complete\&quot;: True when the request has been processed successfully - \&quot;Failed\&quot;: True when the request could not be processed | [optional] 
**pool_count** | **int** | PoolCount is the total number of pools that matched the filter criteria, regardless of truncation. This helps users understand how many pools exist even when the response is truncated. A value of 0 means no pools matched the filter criteria. | 
**pools** | [**list_t**](v1alpha3_pool_status.md) \* | Pools contains the first &#x60;spec.limit&#x60; matching pools, sorted by driver then pool name. If &#x60;len(pools) &lt; poolCount&#x60;, the list was truncated. When omitted, no pools matched the request filters. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


