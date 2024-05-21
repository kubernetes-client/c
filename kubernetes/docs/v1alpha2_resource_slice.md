# v1alpha2_resource_slice_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**api_version** | **char \*** | APIVersion defines the versioned schema of this representation of an object. Servers should convert recognized schemas to the latest internal value, and may reject unrecognized values. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#resources | [optional] 
**driver_name** | **char \*** | DriverName identifies the DRA driver providing the capacity information. A field selector can be used to list only ResourceSlice objects with a certain driver name. | 
**kind** | **char \*** | Kind is a string value representing the REST resource this object represents. Servers may infer this from the endpoint the client submits requests to. Cannot be updated. In CamelCase. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#types-kinds | [optional] 
**metadata** | [**v1_object_meta_t**](v1_object_meta.md) \* |  | [optional] 
**named_resources** | [**v1alpha2_named_resources_resources_t**](v1alpha2_named_resources_resources.md) \* |  | [optional] 
**node_name** | **char \*** | NodeName identifies the node which provides the resources if they are local to a node.  A field selector can be used to list only ResourceSlice objects with a certain node name. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


