# v1beta1_event_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**action** | **char \*** | What action was taken/failed regarding to the regarding object. | [optional] 
**api_version** | **char \*** | APIVersion defines the versioned schema of this representation of an object. Servers should convert recognized schemas to the latest internal value, and may reject unrecognized values. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#resources | [optional] 
**deprecated_count** | **int** | Deprecated field assuring backward compatibility with core.v1 Event type | [optional] 
**deprecated_first_timestamp** | **char \*** | Deprecated field assuring backward compatibility with core.v1 Event type | [optional] 
**deprecated_last_timestamp** | **char \*** | Deprecated field assuring backward compatibility with core.v1 Event type | [optional] 
**deprecated_source** | [**v1_event_source_t**](v1_event_source.md) \* |  | [optional] 
**event_time** | **char \*** | Required. Time when this Event was first observed. | 
**kind** | **char \*** | Kind is a string value representing the REST resource this object represents. Servers may infer this from the endpoint the client submits requests to. Cannot be updated. In CamelCase. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#types-kinds | [optional] 
**metadata** | [**v1_object_meta_t**](v1_object_meta.md) \* |  | [optional] 
**note** | **char \*** | Optional. A human-readable description of the status of this operation. Maximal length of the note is 1kB, but libraries should be prepared to handle values up to 64kB. | [optional] 
**reason** | **char \*** | Why the action was taken. | [optional] 
**regarding** | [**v1_object_reference_t**](v1_object_reference.md) \* |  | [optional] 
**related** | [**v1_object_reference_t**](v1_object_reference.md) \* |  | [optional] 
**reporting_controller** | **char \*** | Name of the controller that emitted this Event, e.g. &#x60;kubernetes.io/kubelet&#x60;. | [optional] 
**reporting_instance** | **char \*** | ID of the controller instance, e.g. &#x60;kubelet-xyzf&#x60;. | [optional] 
**series** | [**v1beta1_event_series_t**](v1beta1_event_series.md) \* |  | [optional] 
**type** | **char \*** | Type of this event (Normal, Warning), new types could be added in the future. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


