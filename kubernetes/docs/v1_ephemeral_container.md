# v1_ephemeral_container_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**args** | **list_t \*** | Arguments to the entrypoint. The docker image&#39;s CMD is used if this is not provided. Variable references $(VAR_NAME) are expanded using the container&#39;s environment. If a variable cannot be resolved, the reference in the input string will be unchanged. The $(VAR_NAME) syntax can be escaped with a double $$, ie: $$(VAR_NAME). Escaped references will never be expanded, regardless of whether the variable exists or not. Cannot be updated. More info: https://kubernetes.io/docs/tasks/inject-data-application/define-command-argument-container/#running-a-command-in-a-shell | [optional] 
**command** | **list_t \*** | Entrypoint array. Not executed within a shell. The docker image&#39;s ENTRYPOINT is used if this is not provided. Variable references $(VAR_NAME) are expanded using the container&#39;s environment. If a variable cannot be resolved, the reference in the input string will be unchanged. The $(VAR_NAME) syntax can be escaped with a double $$, ie: $$(VAR_NAME). Escaped references will never be expanded, regardless of whether the variable exists or not. Cannot be updated. More info: https://kubernetes.io/docs/tasks/inject-data-application/define-command-argument-container/#running-a-command-in-a-shell | [optional] 
**env** | [**list_t**](v1_env_var.md) \* | List of environment variables to set in the container. Cannot be updated. | [optional] 
**env_from** | [**list_t**](v1_env_from_source.md) \* | List of sources to populate environment variables in the container. The keys defined within a source must be a C_IDENTIFIER. All invalid keys will be reported as an event when the container is starting. When a key exists in multiple sources, the value associated with the last source will take precedence. Values defined by an Env with a duplicate key will take precedence. Cannot be updated. | [optional] 
**image** | **char \*** | Docker image name. More info: https://kubernetes.io/docs/concepts/containers/images | [optional] 
**image_pull_policy** | **char \*** | Image pull policy. One of Always, Never, IfNotPresent. Defaults to Always if :latest tag is specified, or IfNotPresent otherwise. Cannot be updated. More info: https://kubernetes.io/docs/concepts/containers/images#updating-images | [optional] 
**lifecycle** | [**v1_lifecycle_t**](v1_lifecycle.md) \* |  | [optional] 
**liveness_probe** | [**v1_probe_t**](v1_probe.md) \* |  | [optional] 
**name** | **char \*** | Name of the ephemeral container specified as a DNS_LABEL. This name must be unique among all containers, init containers and ephemeral containers. | 
**ports** | [**list_t**](v1_container_port.md) \* | Ports are not allowed for ephemeral containers. | [optional] 
**readiness_probe** | [**v1_probe_t**](v1_probe.md) \* |  | [optional] 
**resources** | [**v1_resource_requirements_t**](v1_resource_requirements.md) \* |  | [optional] 
**security_context** | [**v1_security_context_t**](v1_security_context.md) \* |  | [optional] 
**startup_probe** | [**v1_probe_t**](v1_probe.md) \* |  | [optional] 
**_stdin** | **int** | Whether this container should allocate a buffer for stdin in the container runtime. If this is not set, reads from stdin in the container will always result in EOF. Default is false. | [optional] 
**stdin_once** | **int** | Whether the container runtime should close the stdin channel after it has been opened by a single attach. When stdin is true the stdin stream will remain open across multiple attach sessions. If stdinOnce is set to true, stdin is opened on container start, is empty until the first client attaches to stdin, and then remains open and accepts data until the client disconnects, at which time stdin is closed and remains closed until the container is restarted. If this flag is false, a container processes that reads from stdin will never receive an EOF. Default is false | [optional] 
**target_container_name** | **char \*** | If set, the name of the container from PodSpec that this ephemeral container targets. The ephemeral container will be run in the namespaces (IPC, PID, etc) of this container. If not set then the ephemeral container is run in whatever namespaces are shared for the pod. Note that the container runtime must support this feature. | [optional] 
**termination_message_path** | **char \*** | Optional: Path at which the file to which the container&#39;s termination message will be written is mounted into the container&#39;s filesystem. Message written is intended to be brief final status, such as an assertion failure message. Will be truncated by the node if greater than 4096 bytes. The total message length across all containers will be limited to 12kb. Defaults to /dev/termination-log. Cannot be updated. | [optional] 
**termination_message_policy** | **char \*** | Indicate how the termination message should be populated. File will use the contents of terminationMessagePath to populate the container status message on both success and failure. FallbackToLogsOnError will use the last chunk of container log output if the termination message file is empty and the container exited with an error. The log output is limited to 2048 bytes or 80 lines, whichever is smaller. Defaults to File. Cannot be updated. | [optional] 
**tty** | **int** | Whether this container should allocate a TTY for itself, also requires &#39;stdin&#39; to be true. Default is false. | [optional] 
**volume_devices** | [**list_t**](v1_volume_device.md) \* | volumeDevices is the list of block devices to be used by the container. This is a beta feature. | [optional] 
**volume_mounts** | [**list_t**](v1_volume_mount.md) \* | Pod volumes to mount into the container&#39;s filesystem. Cannot be updated. | [optional] 
**working_dir** | **char \*** | Container&#39;s working directory. If not specified, the container runtime&#39;s default will be used, which might be configured in the container image. Cannot be updated. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


