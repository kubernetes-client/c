# v1_device_attribute_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_bool** | **int** | BoolValue is a true/false value. | [optional] 
**bools** | **list_t \*** | BoolValues is a non-empty list of true/false values. | [optional] 
**_int** | **long** | IntValue is a number. | [optional] 
**ints** | **list_t \*** | IntValues is a non-empty list of numbers.  This is an alpha field and requires enabling the DRAListTypeAttributes feature gate. | [optional] 
**string** | **char \*** | StringValue is a string. Must not be longer than 64 characters. | [optional] 
**strings** | **list_t \*** | StringValues is a non-empty list of strings. Each string must not be longer than 64 characters.  This is an alpha field and requires enabling the DRAListTypeAttributes feature gate. | [optional] 
**version** | **char \*** | VersionValue is a semantic version according to semver.org spec 2.0.0. Must not be longer than 64 characters. | [optional] 
**versions** | **list_t \*** | VersionValues is a non-empty list of semantic versions according to semver.org spec 2.0.0. Each version string must not be longer than 64 characters.  This is an alpha field and requires enabling the DRAListTypeAttributes feature gate. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


