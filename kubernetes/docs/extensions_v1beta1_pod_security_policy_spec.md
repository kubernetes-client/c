# extensions_v1beta1_pod_security_policy_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**allow_privilege_escalation** | **int** | allowPrivilegeEscalation determines if a pod can request to allow privilege escalation. If unspecified, defaults to true. | [optional] 
**allowed_csi_drivers** | [**list_t**](extensions_v1beta1_allowed_csi_driver.md) \* | AllowedCSIDrivers is a whitelist of inline CSI drivers that must be explicitly set to be embedded within a pod spec. An empty value indicates that any CSI driver can be used for inline ephemeral volumes. | [optional] 
**allowed_capabilities** | **list_t \*** | allowedCapabilities is a list of capabilities that can be requested to add to the container. Capabilities in this field may be added at the pod author&#39;s discretion. You must not list a capability in both allowedCapabilities and requiredDropCapabilities. | [optional] 
**allowed_flex_volumes** | [**list_t**](extensions_v1beta1_allowed_flex_volume.md) \* | allowedFlexVolumes is a whitelist of allowed Flexvolumes.  Empty or nil indicates that all Flexvolumes may be used.  This parameter is effective only when the usage of the Flexvolumes is allowed in the \&quot;volumes\&quot; field. | [optional] 
**allowed_host_paths** | [**list_t**](extensions_v1beta1_allowed_host_path.md) \* | allowedHostPaths is a white list of allowed host paths. Empty indicates that all host paths may be used. | [optional] 
**allowed_proc_mount_types** | **list_t \*** | AllowedProcMountTypes is a whitelist of allowed ProcMountTypes. Empty or nil indicates that only the DefaultProcMountType may be used. This requires the ProcMountType feature flag to be enabled. | [optional] 
**allowed_unsafe_sysctls** | **list_t \*** | allowedUnsafeSysctls is a list of explicitly allowed unsafe sysctls, defaults to none. Each entry is either a plain sysctl name or ends in \&quot;*\&quot; in which case it is considered as a prefix of allowed sysctls. Single * means all unsafe sysctls are allowed. Kubelet has to whitelist all allowed unsafe sysctls explicitly to avoid rejection.  Examples: e.g. \&quot;foo/*\&quot; allows \&quot;foo/bar\&quot;, \&quot;foo/baz\&quot;, etc. e.g. \&quot;foo.*\&quot; allows \&quot;foo.bar\&quot;, \&quot;foo.baz\&quot;, etc. | [optional] 
**default_add_capabilities** | **list_t \*** | defaultAddCapabilities is the default set of capabilities that will be added to the container unless the pod spec specifically drops the capability.  You may not list a capability in both defaultAddCapabilities and requiredDropCapabilities. Capabilities added here are implicitly allowed, and need not be included in the allowedCapabilities list. | [optional] 
**default_allow_privilege_escalation** | **int** | defaultAllowPrivilegeEscalation controls the default setting for whether a process can gain more privileges than its parent process. | [optional] 
**forbidden_sysctls** | **list_t \*** | forbiddenSysctls is a list of explicitly forbidden sysctls, defaults to none. Each entry is either a plain sysctl name or ends in \&quot;*\&quot; in which case it is considered as a prefix of forbidden sysctls. Single * means all sysctls are forbidden.  Examples: e.g. \&quot;foo/*\&quot; forbids \&quot;foo/bar\&quot;, \&quot;foo/baz\&quot;, etc. e.g. \&quot;foo.*\&quot; forbids \&quot;foo.bar\&quot;, \&quot;foo.baz\&quot;, etc. | [optional] 
**fs_group** | [**extensions_v1beta1_fs_group_strategy_options_t**](extensions_v1beta1_fs_group_strategy_options.md) \* |  | 
**host_ipc** | **int** | hostIPC determines if the policy allows the use of HostIPC in the pod spec. | [optional] 
**host_network** | **int** | hostNetwork determines if the policy allows the use of HostNetwork in the pod spec. | [optional] 
**host_pid** | **int** | hostPID determines if the policy allows the use of HostPID in the pod spec. | [optional] 
**host_ports** | [**list_t**](extensions_v1beta1_host_port_range.md) \* | hostPorts determines which host port ranges are allowed to be exposed. | [optional] 
**privileged** | **int** | privileged determines if a pod can request to be run as privileged. | [optional] 
**read_only_root_filesystem** | **int** | readOnlyRootFilesystem when set to true will force containers to run with a read only root file system.  If the container specifically requests to run with a non-read only root file system the PSP should deny the pod. If set to false the container may run with a read only root file system if it wishes but it will not be forced to. | [optional] 
**required_drop_capabilities** | **list_t \*** | requiredDropCapabilities are the capabilities that will be dropped from the container.  These are required to be dropped and cannot be added. | [optional] 
**run_as_group** | [**extensions_v1beta1_run_as_group_strategy_options_t**](extensions_v1beta1_run_as_group_strategy_options.md) \* |  | [optional] 
**run_as_user** | [**extensions_v1beta1_run_as_user_strategy_options_t**](extensions_v1beta1_run_as_user_strategy_options.md) \* |  | 
**runtime_class** | [**extensions_v1beta1_runtime_class_strategy_options_t**](extensions_v1beta1_runtime_class_strategy_options.md) \* |  | [optional] 
**se_linux** | [**extensions_v1beta1_se_linux_strategy_options_t**](extensions_v1beta1_se_linux_strategy_options.md) \* |  | 
**supplemental_groups** | [**extensions_v1beta1_supplemental_groups_strategy_options_t**](extensions_v1beta1_supplemental_groups_strategy_options.md) \* |  | 
**volumes** | **list_t \*** | volumes is a white list of allowed volume plugins. Empty indicates that no volumes may be used. To allow all volumes you may use &#39;*&#39;. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


