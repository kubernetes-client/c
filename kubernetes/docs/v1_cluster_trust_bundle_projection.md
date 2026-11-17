# v1_cluster_trust_bundle_projection_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**label_selector** | [**v1_label_selector_t**](v1_label_selector.md) \* |  | [optional] 
**name** | **char \*** | Select a single ClusterTrustBundle by object name.  Mutually-exclusive with signerName and labelSelector. | [optional] 
**optional** | **int** | If true, don&#39;t block pod startup if the referenced ClusterTrustBundle(s) aren&#39;t available.  If using name, then the named ClusterTrustBundle is allowed not to exist.  If using signerName, then the combination of signerName and labelSelector is allowed to match zero ClusterTrustBundles. | [optional] 
**path** | **char \*** | Relative path from the volume root to write the bundle. | 
**signer_name** | **char \*** | Select all ClusterTrustBundles that match this signer name. Mutually-exclusive with name.  The contents of all selected ClusterTrustBundles will be unified and deduplicated. | [optional] 
**user** | **long** | user is Optional: The owner UID of the created file. If specified, the item-level user field takes precedence over defaultUser. (Alpha) This field requires the AtomicWriteVolumeUserFields feature gate to be enabled. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


