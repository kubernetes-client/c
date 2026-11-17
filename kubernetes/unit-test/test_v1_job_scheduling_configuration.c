#ifndef v1_job_scheduling_configuration_TEST
#define v1_job_scheduling_configuration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_job_scheduling_configuration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_job_scheduling_configuration.h"
v1_job_scheduling_configuration_t* instantiate_v1_job_scheduling_configuration(int include_optional);

#include "test_v1alpha3_workload_pod_group_disruption_mode.c"
#include "test_v1alpha3_workload_pod_group_scheduling_constraints.c"
#include "test_v1alpha3_workload_pod_group_scheduling_policy.c"


v1_job_scheduling_configuration_t* instantiate_v1_job_scheduling_configuration(int include_optional) {
  v1_job_scheduling_configuration_t* v1_job_scheduling_configuration = NULL;
  if (include_optional) {
    v1_job_scheduling_configuration = v1_job_scheduling_configuration_create(
       // false, not to have infinite recursion
      instantiate_v1alpha3_workload_pod_group_disruption_mode(0),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_v1alpha3_workload_pod_group_scheduling_constraints(0),
       // false, not to have infinite recursion
      instantiate_v1alpha3_workload_pod_group_scheduling_policy(0)
    );
  } else {
    v1_job_scheduling_configuration = v1_job_scheduling_configuration_create(
      NULL,
      list_createList(),
      NULL,
      NULL
    );
  }

  return v1_job_scheduling_configuration;
}


#ifdef v1_job_scheduling_configuration_MAIN

void test_v1_job_scheduling_configuration(int include_optional) {
    v1_job_scheduling_configuration_t* v1_job_scheduling_configuration_1 = instantiate_v1_job_scheduling_configuration(include_optional);

	cJSON* jsonv1_job_scheduling_configuration_1 = v1_job_scheduling_configuration_convertToJSON(v1_job_scheduling_configuration_1);
	printf("v1_job_scheduling_configuration :\n%s\n", cJSON_Print(jsonv1_job_scheduling_configuration_1));
	v1_job_scheduling_configuration_t* v1_job_scheduling_configuration_2 = v1_job_scheduling_configuration_parseFromJSON(jsonv1_job_scheduling_configuration_1);
	cJSON* jsonv1_job_scheduling_configuration_2 = v1_job_scheduling_configuration_convertToJSON(v1_job_scheduling_configuration_2);
	printf("repeating v1_job_scheduling_configuration:\n%s\n", cJSON_Print(jsonv1_job_scheduling_configuration_2));
}

int main() {
  test_v1_job_scheduling_configuration(1);
  test_v1_job_scheduling_configuration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_job_scheduling_configuration_MAIN
#endif // v1_job_scheduling_configuration_TEST
