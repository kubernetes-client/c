# events_v1_event_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**action** | **char \*** | action is what action was taken/failed regarding to the regarding object. It is machine-readable. This field cannot be empty for new Events and it can have at most 128 characters. | [optional] 
**api_version** | **char \*** | APIVersion defines the versioned schema of this representation of an object. Servers should convert recognized schemas to the latest internal value, and may reject unrecognized values. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#resources | [optional] 
**deprecated_count** | **int** | deprecatedCount is the deprecated field assuring backward compatibility with core.v1 Event type. | [optional] 
**deprecated_first_timestamp** | **char \*** | deprecatedFirstTimestamp is the deprecated field assuring backward compatibility with core.v1 Event type. | [optional] 
**deprecated_last_timestamp** | **char \*** | deprecatedLastTimestamp is the deprecated field assuring backward compatibility with core.v1 Event type. | [optional] 
**deprecated_source** | [**v1_event_source_t**](v1_event_source.md) \* |  | [optional] 
**event_time** | **char \*** | eventTime is the time when this Event was first observed. It is required. | 
**kind** | **char \*** | Kind is a string value representing the REST resource this object represents. Servers may infer this from the endpoint the client submits requests to. Cannot be updated. In CamelCase. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#types-kinds | [optional] 
**metadata** | [**v1_object_meta_t**](v1_object_meta.md) \* |  | [optional] 
**note** | **char \*** | note is a human-readable description of the status of this operation. Maximal length of the note is 1kB, but libraries should be prepared to handle values up to 64kB. | [optional] 
**reason** | **char \*** | reason is why the action was taken. It is human-readable. This field cannot be empty for new Events and it can have at most 128 characters. | [optional] 
**regarding** | [**v1_object_reference_t**](v1_object_reference.md) \* |  | [optional] 
**related** | [**v1_object_reference_t**](v1_object_reference.md) \* |  | [optional] 
**reporting_controller** | **char \*** | reportingController is the name of the controller that emitted this Event, e.g. &#x60;kubernetes.io/kubelet&#x60;. This field cannot be empty for new Events. | [optional] 
**reporting_instance** | **char \*** | reportingInstance is the ID of the controller instance, e.g. &#x60;kubelet-xyzf&#x60;. This field cannot be empty for new Events and it can have at most 128 characters. | [optional] 
**series** | [**events_v1_event_series_t**](events_v1_event_series.md) \* |  | [optional] 
**type** | **char \*** | type is the type of this event (Normal, Warning), new types could be added in the future. It is machine-readable. This field cannot be empty for new Events. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


