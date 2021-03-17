# v1beta1_storage_class_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**allow_volume_expansion** | **int** | AllowVolumeExpansion shows whether the storage class allow volume expand | [optional] 
**allowed_topologies** | [**list_t**](v1_topology_selector_term.md) \* | Restrict the node topologies where volumes can be dynamically provisioned. Each volume plugin defines its own supported topology specifications. An empty TopologySelectorTerm list means there is no topology restriction. This field is only honored by servers that enable the VolumeScheduling feature. | [optional] 
**api_version** | **char \*** | APIVersion defines the versioned schema of this representation of an object. Servers should convert recognized schemas to the latest internal value, and may reject unrecognized values. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#resources | [optional] 
**kind** | **char \*** | Kind is a string value representing the REST resource this object represents. Servers may infer this from the endpoint the client submits requests to. Cannot be updated. In CamelCase. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#types-kinds | [optional] 
**metadata** | [**v1_object_meta_t**](v1_object_meta.md) \* |  | [optional] 
**mount_options** | **list_t \*** | Dynamically provisioned PersistentVolumes of this storage class are created with these mountOptions, e.g. [\&quot;ro\&quot;, \&quot;soft\&quot;]. Not validated - mount of the PVs will simply fail if one is invalid. | [optional] 
**parameters** | **list_t*** | Parameters holds the parameters for the provisioner that should create volumes of this storage class. | [optional] 
**provisioner** | **char \*** | Provisioner indicates the type of the provisioner. | 
**reclaim_policy** | **char \*** | Dynamically provisioned PersistentVolumes of this storage class are created with this reclaimPolicy. Defaults to Delete. | [optional] 
**volume_binding_mode** | **char \*** | VolumeBindingMode indicates how PersistentVolumeClaims should be provisioned and bound.  When unset, VolumeBindingImmediate is used. This field is only honored by servers that enable the VolumeScheduling feature. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


