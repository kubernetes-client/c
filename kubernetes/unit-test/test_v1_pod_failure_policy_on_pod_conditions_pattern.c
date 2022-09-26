#ifndef v1_pod_failure_policy_on_pod_conditions_pattern_TEST
#define v1_pod_failure_policy_on_pod_conditions_pattern_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_pod_failure_policy_on_pod_conditions_pattern_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_pod_failure_policy_on_pod_conditions_pattern.h"
v1_pod_failure_policy_on_pod_conditions_pattern_t* instantiate_v1_pod_failure_policy_on_pod_conditions_pattern(int include_optional);



v1_pod_failure_policy_on_pod_conditions_pattern_t* instantiate_v1_pod_failure_policy_on_pod_conditions_pattern(int include_optional) {
  v1_pod_failure_policy_on_pod_conditions_pattern_t* v1_pod_failure_policy_on_pod_conditions_pattern = NULL;
  if (include_optional) {
    v1_pod_failure_policy_on_pod_conditions_pattern = v1_pod_failure_policy_on_pod_conditions_pattern_create(
      "0",
      "0"
    );
  } else {
    v1_pod_failure_policy_on_pod_conditions_pattern = v1_pod_failure_policy_on_pod_conditions_pattern_create(
      "0",
      "0"
    );
  }

  return v1_pod_failure_policy_on_pod_conditions_pattern;
}


#ifdef v1_pod_failure_policy_on_pod_conditions_pattern_MAIN

void test_v1_pod_failure_policy_on_pod_conditions_pattern(int include_optional) {
    v1_pod_failure_policy_on_pod_conditions_pattern_t* v1_pod_failure_policy_on_pod_conditions_pattern_1 = instantiate_v1_pod_failure_policy_on_pod_conditions_pattern(include_optional);

	cJSON* jsonv1_pod_failure_policy_on_pod_conditions_pattern_1 = v1_pod_failure_policy_on_pod_conditions_pattern_convertToJSON(v1_pod_failure_policy_on_pod_conditions_pattern_1);
	printf("v1_pod_failure_policy_on_pod_conditions_pattern :\n%s\n", cJSON_Print(jsonv1_pod_failure_policy_on_pod_conditions_pattern_1));
	v1_pod_failure_policy_on_pod_conditions_pattern_t* v1_pod_failure_policy_on_pod_conditions_pattern_2 = v1_pod_failure_policy_on_pod_conditions_pattern_parseFromJSON(jsonv1_pod_failure_policy_on_pod_conditions_pattern_1);
	cJSON* jsonv1_pod_failure_policy_on_pod_conditions_pattern_2 = v1_pod_failure_policy_on_pod_conditions_pattern_convertToJSON(v1_pod_failure_policy_on_pod_conditions_pattern_2);
	printf("repeating v1_pod_failure_policy_on_pod_conditions_pattern:\n%s\n", cJSON_Print(jsonv1_pod_failure_policy_on_pod_conditions_pattern_2));
}

int main() {
  test_v1_pod_failure_policy_on_pod_conditions_pattern(1);
  test_v1_pod_failure_policy_on_pod_conditions_pattern(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_pod_failure_policy_on_pod_conditions_pattern_MAIN
#endif // v1_pod_failure_policy_on_pod_conditions_pattern_TEST
