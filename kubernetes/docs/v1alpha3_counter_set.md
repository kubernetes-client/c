# v1alpha3_counter_set_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**counters** | **list_t*** | Counters defines the counters that will be consumed by the device. The name of each counter must be unique in that set and must be a DNS label.  To ensure this uniqueness, capacities defined by the vendor must be listed without the driver name as domain prefix in their name. All others must be listed with their domain prefix.  The maximum number of counters is 32. | 
**name** | **char \*** | CounterSet is the name of the set from which the counters defined will be consumed. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


