# v1alpha1_priority_level_configuration_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**limited** | [**v1alpha1_limited_priority_level_configuration_t**](v1alpha1_limited_priority_level_configuration.md) \* |  | [optional] 
**type** | **char \*** | &#x60;type&#x60; indicates whether this priority level is subject to limitation on request execution.  A value of &#x60;\&quot;Exempt\&quot;&#x60; means that requests of this priority level are not subject to a limit (and thus are never queued) and do not detract from the capacity made available to other priority levels.  A value of &#x60;\&quot;Limited\&quot;&#x60; means that (a) requests of this priority level _are_ subject to limits and (b) some of the server&#39;s limited capacity is made available exclusively to this priority level. Required. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


