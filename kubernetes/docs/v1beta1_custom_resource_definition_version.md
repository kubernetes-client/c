# v1beta1_custom_resource_definition_version_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**additional_printer_columns** | [**list_t**](v1beta1_custom_resource_column_definition.md) \* | additionalPrinterColumns specifies additional columns returned in Table output. See https://kubernetes.io/docs/reference/using-api/api-concepts/#receiving-resources-as-tables for details. Top-level and per-version columns are mutually exclusive. Per-version columns must not all be set to identical values (top-level columns should be used instead). If no top-level or per-version columns are specified, a single column displaying the age of the custom resource is used. | [optional] 
**name** | **char \*** | name is the version name, e.g. “v1”, “v2beta1”, etc. The custom resources are served under this version at &#x60;/apis/&lt;group&gt;/&lt;version&gt;/...&#x60; if &#x60;served&#x60; is true. | 
**schema** | [**v1beta1_custom_resource_validation_t**](v1beta1_custom_resource_validation.md) \* |  | [optional] 
**served** | **int** | served is a flag enabling/disabling this version from being served via REST APIs | 
**storage** | **int** | storage indicates this version should be used when persisting custom resources to storage. There must be exactly one version with storage&#x3D;true. | 
**subresources** | [**v1beta1_custom_resource_subresources_t**](v1beta1_custom_resource_subresources.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


