# v1_custom_resource_definition_version_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**additional_printer_columns** | [**list_t**](v1_custom_resource_column_definition.md) \* | additionalPrinterColumns specifies additional columns returned in Table output. See https://kubernetes.io/docs/reference/using-api/api-concepts/#receiving-resources-as-tables for details. If no columns are specified, a single column displaying the age of the custom resource is used. | [optional] 
**deprecated** | **int** | deprecated indicates this version of the custom resource API is deprecated. When set to true, API requests to this version receive a warning header in the server response. Defaults to false. | [optional] 
**deprecation_warning** | **char \*** | deprecationWarning overrides the default warning returned to API clients. May only be set when &#x60;deprecated&#x60; is true. The default warning indicates this version is deprecated and recommends use of the newest served version of equal or greater stability, if one exists. | [optional] 
**name** | **char \*** | name is the version name, e.g. “v1”, “v2beta1”, etc. The custom resources are served under this version at &#x60;/apis/&lt;group&gt;/&lt;version&gt;/...&#x60; if &#x60;served&#x60; is true. | 
**schema** | [**v1_custom_resource_validation_t**](v1_custom_resource_validation.md) \* |  | [optional] 
**selectable_fields** | [**list_t**](v1_selectable_field.md) \* | selectableFields specifies paths to fields that may be used as field selectors. A maximum of 8 selectable fields are allowed. See https://kubernetes.io/docs/concepts/overview/working-with-objects/field-selectors | [optional] 
**served** | **int** | served is a flag enabling/disabling this version from being served via REST APIs | 
**storage** | **int** | storage indicates this version should be used when persisting custom resources to storage. There must be exactly one version with storage&#x3D;true. | 
**subresources** | [**v1_custom_resource_subresources_t**](v1_custom_resource_subresources.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


