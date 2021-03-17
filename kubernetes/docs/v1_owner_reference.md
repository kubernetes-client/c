# v1_owner_reference_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**api_version** | **char \*** | API version of the referent. | 
**block_owner_deletion** | **int** | If true, AND if the owner has the \&quot;foregroundDeletion\&quot; finalizer, then the owner cannot be deleted from the key-value store until this reference is removed. Defaults to false. To set this field, a user needs \&quot;delete\&quot; permission of the owner, otherwise 422 (Unprocessable Entity) will be returned. | [optional] 
**controller** | **int** | If true, this reference points to the managing controller. | [optional] 
**kind** | **char \*** | Kind of the referent. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#types-kinds | 
**name** | **char \*** | Name of the referent. More info: http://kubernetes.io/docs/user-guide/identifiers#names | 
**uid** | **char \*** | UID of the referent. More info: http://kubernetes.io/docs/user-guide/identifiers#uids | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


