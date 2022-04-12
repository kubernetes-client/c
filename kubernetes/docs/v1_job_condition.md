# v1_job_condition_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**last_probe_time** | **char \*** | Last time the condition was checked. | [optional] 
**last_transition_time** | **char \*** | Last time the condition transit from one status to another. | [optional] 
**message** | **char \*** | Human readable message indicating details about last transition. | [optional] 
**reason** | **char \*** | (brief) reason for the condition&#39;s last transition. | [optional] 
**status** | **char \*** | Status of the condition, one of True, False, Unknown. | 
**type** | **kubernetes_v1_job_condition_TYPE_e** | Type of job condition, Complete or Failed.  Possible enum values:  - &#x60;\&quot;Complete\&quot;&#x60; means the job has completed its execution.  - &#x60;\&quot;Failed\&quot;&#x60; means the job has failed its execution.  - &#x60;\&quot;Suspended\&quot;&#x60; means the job has been suspended. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


