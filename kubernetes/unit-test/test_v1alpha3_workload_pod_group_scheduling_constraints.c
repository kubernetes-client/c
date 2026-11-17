#ifndef v1alpha3_workload_pod_group_scheduling_constraints_TEST
#define v1alpha3_workload_pod_group_scheduling_constraints_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_workload_pod_group_scheduling_constraints_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_workload_pod_group_scheduling_constraints.h"
v1alpha3_workload_pod_group_scheduling_constraints_t* instantiate_v1alpha3_workload_pod_group_scheduling_constraints(int include_optional);



v1alpha3_workload_pod_group_scheduling_constraints_t* instantiate_v1alpha3_workload_pod_group_scheduling_constraints(int include_optional) {
  v1alpha3_workload_pod_group_scheduling_constraints_t* v1alpha3_workload_pod_group_scheduling_constraints = NULL;
  if (include_optional) {
    v1alpha3_workload_pod_group_scheduling_constraints = v1alpha3_workload_pod_group_scheduling_constraints_create(
      list_createList()
    );
  } else {
    v1alpha3_workload_pod_group_scheduling_constraints = v1alpha3_workload_pod_group_scheduling_constraints_create(
      list_createList()
    );
  }

  return v1alpha3_workload_pod_group_scheduling_constraints;
}


#ifdef v1alpha3_workload_pod_group_scheduling_constraints_MAIN

void test_v1alpha3_workload_pod_group_scheduling_constraints(int include_optional) {
    v1alpha3_workload_pod_group_scheduling_constraints_t* v1alpha3_workload_pod_group_scheduling_constraints_1 = instantiate_v1alpha3_workload_pod_group_scheduling_constraints(include_optional);

	cJSON* jsonv1alpha3_workload_pod_group_scheduling_constraints_1 = v1alpha3_workload_pod_group_scheduling_constraints_convertToJSON(v1alpha3_workload_pod_group_scheduling_constraints_1);
	printf("v1alpha3_workload_pod_group_scheduling_constraints :\n%s\n", cJSON_Print(jsonv1alpha3_workload_pod_group_scheduling_constraints_1));
	v1alpha3_workload_pod_group_scheduling_constraints_t* v1alpha3_workload_pod_group_scheduling_constraints_2 = v1alpha3_workload_pod_group_scheduling_constraints_parseFromJSON(jsonv1alpha3_workload_pod_group_scheduling_constraints_1);
	cJSON* jsonv1alpha3_workload_pod_group_scheduling_constraints_2 = v1alpha3_workload_pod_group_scheduling_constraints_convertToJSON(v1alpha3_workload_pod_group_scheduling_constraints_2);
	printf("repeating v1alpha3_workload_pod_group_scheduling_constraints:\n%s\n", cJSON_Print(jsonv1alpha3_workload_pod_group_scheduling_constraints_2));
}

int main() {
  test_v1alpha3_workload_pod_group_scheduling_constraints(1);
  test_v1alpha3_workload_pod_group_scheduling_constraints(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_workload_pod_group_scheduling_constraints_MAIN
#endif // v1alpha3_workload_pod_group_scheduling_constraints_TEST
