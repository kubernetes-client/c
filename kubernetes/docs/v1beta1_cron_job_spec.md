# v1beta1_cron_job_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**concurrency_policy** | **char \*** | Specifies how to treat concurrent executions of a Job. Valid values are: - \&quot;Allow\&quot; (default): allows CronJobs to run concurrently; - \&quot;Forbid\&quot;: forbids concurrent runs, skipping next run if previous run hasn&#39;t finished yet; - \&quot;Replace\&quot;: cancels currently running job and replaces it with a new one | [optional] 
**failed_jobs_history_limit** | **int** | The number of failed finished jobs to retain. This is a pointer to distinguish between explicit zero and not specified. Defaults to 1. | [optional] 
**job_template** | [**v1beta1_job_template_spec_t**](v1beta1_job_template_spec.md) \* |  | 
**schedule** | **char \*** | The schedule in Cron format, see https://en.wikipedia.org/wiki/Cron. | 
**starting_deadline_seconds** | **long** | Optional deadline in seconds for starting the job if it misses scheduled time for any reason.  Missed jobs executions will be counted as failed ones. | [optional] 
**successful_jobs_history_limit** | **int** | The number of successful finished jobs to retain. This is a pointer to distinguish between explicit zero and not specified. Defaults to 3. | [optional] 
**suspend** | **int** | This flag tells the controller to suspend subsequent executions, it does not apply to already started executions.  Defaults to false. | [optional] 
**time_zone** | **char \*** | The time zone for the given schedule, see https://en.wikipedia.org/wiki/List_of_tz_database_time_zones. If not specified, this will rely on the time zone of the kube-controller-manager process. ALPHA: This field is in alpha and must be enabled via the &#x60;CronJobTimeZone&#x60; feature gate. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


