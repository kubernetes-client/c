# v1_endpoint_hints_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**for_nodes** | [**list_t**](v1_for_node.md) \* | forNodes indicates the node(s) this endpoint should be consumed by when using topology aware routing. May contain a maximum of 8 entries. This is an Alpha feature and is only used when the PreferSameTrafficDistribution feature gate is enabled. | [optional] 
**for_zones** | [**list_t**](v1_for_zone.md) \* | forZones indicates the zone(s) this endpoint should be consumed by when using topology aware routing. May contain a maximum of 8 entries. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


