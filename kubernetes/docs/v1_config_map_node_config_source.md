# v1_config_map_node_config_source_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**kubelet_config_key** | **char \*** | KubeletConfigKey declares which key of the referenced ConfigMap corresponds to the KubeletConfiguration structure This field is required in all cases. | 
**name** | **char \*** | Name is the metadata.name of the referenced ConfigMap. This field is required in all cases. | 
**_namespace** | **char \*** | Namespace is the metadata.namespace of the referenced ConfigMap. This field is required in all cases. | 
**resource_version** | **char \*** | ResourceVersion is the metadata.ResourceVersion of the referenced ConfigMap. This field is forbidden in Node.Spec, and required in Node.Status. | [optional] 
**uid** | **char \*** | UID is the metadata.UID of the referenced ConfigMap. This field is forbidden in Node.Spec, and required in Node.Status. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


