# v1_load_balancer_ingress_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**hostname** | **char \*** | Hostname is set for load-balancer ingress points that are DNS based (typically AWS load-balancers) | [optional] 
**ip** | **char \*** | IP is set for load-balancer ingress points that are IP based (typically GCE or OpenStack load-balancers) | [optional] 
**ports** | [**list_t**](v1_port_status.md) \* | Ports is a list of records of service ports If used, every port defined in the service should have an entry in it | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


