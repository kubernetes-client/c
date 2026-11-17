#ifndef v1beta1_composite_pod_group_scheduling_policy_TEST
#define v1beta1_composite_pod_group_scheduling_policy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_composite_pod_group_scheduling_policy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_composite_pod_group_scheduling_policy.h"
v1beta1_composite_pod_group_scheduling_policy_t* instantiate_v1beta1_composite_pod_group_scheduling_policy(int include_optional);

#include "test_v1beta1_composite_gang_scheduling_policy.c"


v1beta1_composite_pod_group_scheduling_policy_t* instantiate_v1beta1_composite_pod_group_scheduling_policy(int include_optional) {
  v1beta1_composite_pod_group_scheduling_policy_t* v1beta1_composite_pod_group_scheduling_policy = NULL;
  if (include_optional) {
    v1beta1_composite_pod_group_scheduling_policy = v1beta1_composite_pod_group_scheduling_policy_create(
      0,
       // false, not to have infinite recursion
      instantiate_v1beta1_composite_gang_scheduling_policy(0)
    );
  } else {
    v1beta1_composite_pod_group_scheduling_policy = v1beta1_composite_pod_group_scheduling_policy_create(
      0,
      NULL
    );
  }

  return v1beta1_composite_pod_group_scheduling_policy;
}


#ifdef v1beta1_composite_pod_group_scheduling_policy_MAIN

void test_v1beta1_composite_pod_group_scheduling_policy(int include_optional) {
    v1beta1_composite_pod_group_scheduling_policy_t* v1beta1_composite_pod_group_scheduling_policy_1 = instantiate_v1beta1_composite_pod_group_scheduling_policy(include_optional);

	cJSON* jsonv1beta1_composite_pod_group_scheduling_policy_1 = v1beta1_composite_pod_group_scheduling_policy_convertToJSON(v1beta1_composite_pod_group_scheduling_policy_1);
	printf("v1beta1_composite_pod_group_scheduling_policy :\n%s\n", cJSON_Print(jsonv1beta1_composite_pod_group_scheduling_policy_1));
	v1beta1_composite_pod_group_scheduling_policy_t* v1beta1_composite_pod_group_scheduling_policy_2 = v1beta1_composite_pod_group_scheduling_policy_parseFromJSON(jsonv1beta1_composite_pod_group_scheduling_policy_1);
	cJSON* jsonv1beta1_composite_pod_group_scheduling_policy_2 = v1beta1_composite_pod_group_scheduling_policy_convertToJSON(v1beta1_composite_pod_group_scheduling_policy_2);
	printf("repeating v1beta1_composite_pod_group_scheduling_policy:\n%s\n", cJSON_Print(jsonv1beta1_composite_pod_group_scheduling_policy_2));
}

int main() {
  test_v1beta1_composite_pod_group_scheduling_policy(1);
  test_v1beta1_composite_pod_group_scheduling_policy(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_composite_pod_group_scheduling_policy_MAIN
#endif // v1beta1_composite_pod_group_scheduling_policy_TEST
