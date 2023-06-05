# v1alpha2_resource_class_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**api_version** | **char \*** | APIVersion defines the versioned schema of this representation of an object. Servers should convert recognized schemas to the latest internal value, and may reject unrecognized values. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#resources | [optional] 
**driver_name** | **char \*** | DriverName defines the name of the dynamic resource driver that is used for allocation of a ResourceClaim that uses this class.  Resource drivers have a unique name in forward domain order (acme.example.com). | 
**kind** | **char \*** | Kind is a string value representing the REST resource this object represents. Servers may infer this from the endpoint the client submits requests to. Cannot be updated. In CamelCase. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#types-kinds | [optional] 
**metadata** | [**v1_object_meta_t**](v1_object_meta.md) \* |  | [optional] 
**parameters_ref** | [**v1alpha2_resource_class_parameters_reference_t**](v1alpha2_resource_class_parameters_reference.md) \* |  | [optional] 
**suitable_nodes** | [**v1_node_selector_t**](v1_node_selector.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


