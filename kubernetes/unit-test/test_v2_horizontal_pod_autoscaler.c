#ifndef v2_horizontal_pod_autoscaler_TEST
#define v2_horizontal_pod_autoscaler_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2_horizontal_pod_autoscaler_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2_horizontal_pod_autoscaler.h"
v2_horizontal_pod_autoscaler_t* instantiate_v2_horizontal_pod_autoscaler(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v2_horizontal_pod_autoscaler_spec.c"
#include "test_v2_horizontal_pod_autoscaler_status.c"


v2_horizontal_pod_autoscaler_t* instantiate_v2_horizontal_pod_autoscaler(int include_optional) {
  v2_horizontal_pod_autoscaler_t* v2_horizontal_pod_autoscaler = NULL;
  if (include_optional) {
    v2_horizontal_pod_autoscaler = v2_horizontal_pod_autoscaler_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v2_horizontal_pod_autoscaler_spec(0),
       // false, not to have infinite recursion
      instantiate_v2_horizontal_pod_autoscaler_status(0)
    );
  } else {
    v2_horizontal_pod_autoscaler = v2_horizontal_pod_autoscaler_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v2_horizontal_pod_autoscaler;
}


#ifdef v2_horizontal_pod_autoscaler_MAIN

void test_v2_horizontal_pod_autoscaler(int include_optional) {
    v2_horizontal_pod_autoscaler_t* v2_horizontal_pod_autoscaler_1 = instantiate_v2_horizontal_pod_autoscaler(include_optional);

	cJSON* jsonv2_horizontal_pod_autoscaler_1 = v2_horizontal_pod_autoscaler_convertToJSON(v2_horizontal_pod_autoscaler_1);
	printf("v2_horizontal_pod_autoscaler :\n%s\n", cJSON_Print(jsonv2_horizontal_pod_autoscaler_1));
	v2_horizontal_pod_autoscaler_t* v2_horizontal_pod_autoscaler_2 = v2_horizontal_pod_autoscaler_parseFromJSON(jsonv2_horizontal_pod_autoscaler_1);
	cJSON* jsonv2_horizontal_pod_autoscaler_2 = v2_horizontal_pod_autoscaler_convertToJSON(v2_horizontal_pod_autoscaler_2);
	printf("repeating v2_horizontal_pod_autoscaler:\n%s\n", cJSON_Print(jsonv2_horizontal_pod_autoscaler_2));
}

int main() {
  test_v2_horizontal_pod_autoscaler(1);
  test_v2_horizontal_pod_autoscaler(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2_horizontal_pod_autoscaler_MAIN
#endif // v2_horizontal_pod_autoscaler_TEST
