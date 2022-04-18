# v1_stateful_set_persistent_volume_claim_retention_policy_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**when_deleted** | **char \*** | WhenDeleted specifies what happens to PVCs created from StatefulSet VolumeClaimTemplates when the StatefulSet is deleted. The default policy of &#x60;Retain&#x60; causes PVCs to not be affected by StatefulSet deletion. The &#x60;Delete&#x60; policy causes those PVCs to be deleted. | [optional] 
**when_scaled** | **char \*** | WhenScaled specifies what happens to PVCs created from StatefulSet VolumeClaimTemplates when the StatefulSet is scaled down. The default policy of &#x60;Retain&#x60; causes PVCs to not be affected by a scaledown. The &#x60;Delete&#x60; policy causes the associated PVCs for any excess pods above the replica count to be deleted. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


