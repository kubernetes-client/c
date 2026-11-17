# v1alpha3_partition_type_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**allocatable** | **int** | Allocatable is the number of additional devices of this partition type that could still be allocated given current shared-counter consumption. | 
**attribute** | **char \*** | Attribute is the fully qualified name of the device attribute whose value groups this entry. It is the PartitionTypeAttribute declared by the devices&#39; own slice, or the default named in the request when their slice declares none. | 
**total** | **int** | Total is the number of devices of this partition type in the pool. | 
**type** | **char \*** | Type is the partition type value (e.g. \&quot;Full\&quot; or \&quot;Half\&quot;). | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


