# v1_http_get_action_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**host** | **char \*** | Host name to connect to, defaults to the pod IP. You probably want to set \&quot;Host\&quot; in httpHeaders instead. | [optional] 
**http_headers** | [**list_t**](v1_http_header.md) \* | Custom headers to set in the request. HTTP allows repeated headers. | [optional] 
**path** | **char \*** | Path to access on the HTTP server. | [optional] 
**port** | **int_or_string_t \*** | IntOrString is a type that can hold an int32 or a string.  When used in JSON or YAML marshalling and unmarshalling, it produces or consumes the inner type.  This allows you to have, for example, a JSON field that can accept a name or number. | 
**scheme** | **char \*** | Scheme to use for connecting to the host. Defaults to HTTP.   | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


