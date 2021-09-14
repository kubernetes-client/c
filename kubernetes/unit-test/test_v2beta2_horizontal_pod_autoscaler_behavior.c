#ifndef v2beta2_horizontal_pod_autoscaler_behavior_TEST
#define v2beta2_horizontal_pod_autoscaler_behavior_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2beta2_horizontal_pod_autoscaler_behavior_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2beta2_horizontal_pod_autoscaler_behavior.h"
v2beta2_horizontal_pod_autoscaler_behavior_t* instantiate_v2beta2_horizontal_pod_autoscaler_behavior(int include_optional);

#include "test_v2beta2_hpa_scaling_rules.c"
#include "test_v2beta2_hpa_scaling_rules.c"


v2beta2_horizontal_pod_autoscaler_behavior_t* instantiate_v2beta2_horizontal_pod_autoscaler_behavior(int include_optional) {
  v2beta2_horizontal_pod_autoscaler_behavior_t* v2beta2_horizontal_pod_autoscaler_behavior = NULL;
  if (include_optional) {
    v2beta2_horizontal_pod_autoscaler_behavior = v2beta2_horizontal_pod_autoscaler_behavior_create(
       // false, not to have infinite recursion
      instantiate_v2beta2_hpa_scaling_rules(0),
       // false, not to have infinite recursion
      instantiate_v2beta2_hpa_scaling_rules(0)
    );
  } else {
    v2beta2_horizontal_pod_autoscaler_behavior = v2beta2_horizontal_pod_autoscaler_behavior_create(
      NULL,
      NULL
    );
  }

  return v2beta2_horizontal_pod_autoscaler_behavior;
}


#ifdef v2beta2_horizontal_pod_autoscaler_behavior_MAIN

void test_v2beta2_horizontal_pod_autoscaler_behavior(int include_optional) {
    v2beta2_horizontal_pod_autoscaler_behavior_t* v2beta2_horizontal_pod_autoscaler_behavior_1 = instantiate_v2beta2_horizontal_pod_autoscaler_behavior(include_optional);

	cJSON* jsonv2beta2_horizontal_pod_autoscaler_behavior_1 = v2beta2_horizontal_pod_autoscaler_behavior_convertToJSON(v2beta2_horizontal_pod_autoscaler_behavior_1);
	printf("v2beta2_horizontal_pod_autoscaler_behavior :\n%s\n", cJSON_Print(jsonv2beta2_horizontal_pod_autoscaler_behavior_1));
	v2beta2_horizontal_pod_autoscaler_behavior_t* v2beta2_horizontal_pod_autoscaler_behavior_2 = v2beta2_horizontal_pod_autoscaler_behavior_parseFromJSON(jsonv2beta2_horizontal_pod_autoscaler_behavior_1);
	cJSON* jsonv2beta2_horizontal_pod_autoscaler_behavior_2 = v2beta2_horizontal_pod_autoscaler_behavior_convertToJSON(v2beta2_horizontal_pod_autoscaler_behavior_2);
	printf("repeating v2beta2_horizontal_pod_autoscaler_behavior:\n%s\n", cJSON_Print(jsonv2beta2_horizontal_pod_autoscaler_behavior_2));
}

int main() {
  test_v2beta2_horizontal_pod_autoscaler_behavior(1);
  test_v2beta2_horizontal_pod_autoscaler_behavior(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2beta2_horizontal_pod_autoscaler_behavior_MAIN
#endif // v2beta2_horizontal_pod_autoscaler_behavior_TEST
