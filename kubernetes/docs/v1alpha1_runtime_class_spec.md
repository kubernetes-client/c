# v1alpha1_runtime_class_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**overhead** | [**v1alpha1_overhead_t**](v1alpha1_overhead.md) \* |  | [optional] 
**runtime_handler** | **char \*** | RuntimeHandler specifies the underlying runtime and configuration that the CRI implementation will use to handle pods of this class. The possible values are specific to the node &amp; CRI configuration.  It is assumed that all handlers are available on every node, and handlers of the same name are equivalent on every node. For example, a handler called \&quot;runc\&quot; might specify that the runc OCI runtime (using native Linux containers) will be used to run the containers in a pod. The RuntimeHandler must conform to the DNS Label (RFC 1123) requirements and is immutable. | 
**scheduling** | [**v1alpha1_scheduling_t**](v1alpha1_scheduling.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


