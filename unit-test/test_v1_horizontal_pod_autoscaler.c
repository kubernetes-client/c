#ifndef v1_horizontal_pod_autoscaler_TEST
#define v1_horizontal_pod_autoscaler_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_horizontal_pod_autoscaler_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_horizontal_pod_autoscaler.h"
v1_horizontal_pod_autoscaler_t* instantiate_v1_horizontal_pod_autoscaler(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_horizontal_pod_autoscaler_spec.c"
#include "test_v1_horizontal_pod_autoscaler_status.c"


v1_horizontal_pod_autoscaler_t* instantiate_v1_horizontal_pod_autoscaler(int include_optional) {
  v1_horizontal_pod_autoscaler_t* v1_horizontal_pod_autoscaler = NULL;
  if (include_optional) {
    v1_horizontal_pod_autoscaler = v1_horizontal_pod_autoscaler_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_horizontal_pod_autoscaler_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_horizontal_pod_autoscaler_status(0)
    );
  } else {
    v1_horizontal_pod_autoscaler = v1_horizontal_pod_autoscaler_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_horizontal_pod_autoscaler;
}


#ifdef v1_horizontal_pod_autoscaler_MAIN

void test_v1_horizontal_pod_autoscaler(int include_optional) {
    v1_horizontal_pod_autoscaler_t* v1_horizontal_pod_autoscaler_1 = instantiate_v1_horizontal_pod_autoscaler(include_optional);

	cJSON* jsonv1_horizontal_pod_autoscaler_1 = v1_horizontal_pod_autoscaler_convertToJSON(v1_horizontal_pod_autoscaler_1);
	printf("v1_horizontal_pod_autoscaler :\n%s\n", cJSON_Print(jsonv1_horizontal_pod_autoscaler_1));
	v1_horizontal_pod_autoscaler_t* v1_horizontal_pod_autoscaler_2 = v1_horizontal_pod_autoscaler_parseFromJSON(jsonv1_horizontal_pod_autoscaler_1);
	cJSON* jsonv1_horizontal_pod_autoscaler_2 = v1_horizontal_pod_autoscaler_convertToJSON(v1_horizontal_pod_autoscaler_2);
	printf("repeating v1_horizontal_pod_autoscaler:\n%s\n", cJSON_Print(jsonv1_horizontal_pod_autoscaler_2));
}

int main() {
  test_v1_horizontal_pod_autoscaler(1);
  test_v1_horizontal_pod_autoscaler(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_horizontal_pod_autoscaler_MAIN
#endif // v1_horizontal_pod_autoscaler_TEST
