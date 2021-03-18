# v1alpha1_flow_schema_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**api_version** | **char \*** | APIVersion defines the versioned schema of this representation of an object. Servers should convert recognized schemas to the latest internal value, and may reject unrecognized values. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#resources | [optional] 
**kind** | **char \*** | Kind is a string value representing the REST resource this object represents. Servers may infer this from the endpoint the client submits requests to. Cannot be updated. In CamelCase. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#types-kinds | [optional] 
**metadata** | [**v1_object_meta_t**](v1_object_meta.md) \* |  | [optional] 
**spec** | [**v1alpha1_flow_schema_spec_t**](v1alpha1_flow_schema_spec.md) \* |  | [optional] 
**status** | [**v1alpha1_flow_schema_status_t**](v1alpha1_flow_schema_status.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


