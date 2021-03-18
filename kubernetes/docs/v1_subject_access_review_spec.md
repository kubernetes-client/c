# v1_subject_access_review_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**extra** | **list_t*** | Extra corresponds to the user.Info.GetExtra() method from the authenticator.  Since that is input to the authorizer it needs a reflection here. | [optional] 
**groups** | **list_t \*** | Groups is the groups you&#39;re testing for. | [optional] 
**non_resource_attributes** | [**v1_non_resource_attributes_t**](v1_non_resource_attributes.md) \* |  | [optional] 
**resource_attributes** | [**v1_resource_attributes_t**](v1_resource_attributes.md) \* |  | [optional] 
**uid** | **char \*** | UID information about the requesting user. | [optional] 
**user** | **char \*** | User is the user you&#39;re testing for. If you specify \&quot;User\&quot; but not \&quot;Groups\&quot;, then is it interpreted as \&quot;What if User were not a member of any groups | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


