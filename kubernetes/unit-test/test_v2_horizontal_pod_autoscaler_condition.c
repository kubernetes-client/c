#ifndef v2_horizontal_pod_autoscaler_condition_TEST
#define v2_horizontal_pod_autoscaler_condition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2_horizontal_pod_autoscaler_condition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2_horizontal_pod_autoscaler_condition.h"
v2_horizontal_pod_autoscaler_condition_t* instantiate_v2_horizontal_pod_autoscaler_condition(int include_optional);



v2_horizontal_pod_autoscaler_condition_t* instantiate_v2_horizontal_pod_autoscaler_condition(int include_optional) {
  v2_horizontal_pod_autoscaler_condition_t* v2_horizontal_pod_autoscaler_condition = NULL;
  if (include_optional) {
    v2_horizontal_pod_autoscaler_condition = v2_horizontal_pod_autoscaler_condition_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    v2_horizontal_pod_autoscaler_condition = v2_horizontal_pod_autoscaler_condition_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return v2_horizontal_pod_autoscaler_condition;
}


#ifdef v2_horizontal_pod_autoscaler_condition_MAIN

void test_v2_horizontal_pod_autoscaler_condition(int include_optional) {
    v2_horizontal_pod_autoscaler_condition_t* v2_horizontal_pod_autoscaler_condition_1 = instantiate_v2_horizontal_pod_autoscaler_condition(include_optional);

	cJSON* jsonv2_horizontal_pod_autoscaler_condition_1 = v2_horizontal_pod_autoscaler_condition_convertToJSON(v2_horizontal_pod_autoscaler_condition_1);
	printf("v2_horizontal_pod_autoscaler_condition :\n%s\n", cJSON_Print(jsonv2_horizontal_pod_autoscaler_condition_1));
	v2_horizontal_pod_autoscaler_condition_t* v2_horizontal_pod_autoscaler_condition_2 = v2_horizontal_pod_autoscaler_condition_parseFromJSON(jsonv2_horizontal_pod_autoscaler_condition_1);
	cJSON* jsonv2_horizontal_pod_autoscaler_condition_2 = v2_horizontal_pod_autoscaler_condition_convertToJSON(v2_horizontal_pod_autoscaler_condition_2);
	printf("repeating v2_horizontal_pod_autoscaler_condition:\n%s\n", cJSON_Print(jsonv2_horizontal_pod_autoscaler_condition_2));
}

int main() {
  test_v2_horizontal_pod_autoscaler_condition(1);
  test_v2_horizontal_pod_autoscaler_condition(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2_horizontal_pod_autoscaler_condition_MAIN
#endif // v2_horizontal_pod_autoscaler_condition_TEST
