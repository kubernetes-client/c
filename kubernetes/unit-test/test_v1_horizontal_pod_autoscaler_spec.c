#ifndef v1_horizontal_pod_autoscaler_spec_TEST
#define v1_horizontal_pod_autoscaler_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_horizontal_pod_autoscaler_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_horizontal_pod_autoscaler_spec.h"
v1_horizontal_pod_autoscaler_spec_t* instantiate_v1_horizontal_pod_autoscaler_spec(int include_optional);

#include "test_v1_cross_version_object_reference.c"


v1_horizontal_pod_autoscaler_spec_t* instantiate_v1_horizontal_pod_autoscaler_spec(int include_optional) {
  v1_horizontal_pod_autoscaler_spec_t* v1_horizontal_pod_autoscaler_spec = NULL;
  if (include_optional) {
    v1_horizontal_pod_autoscaler_spec = v1_horizontal_pod_autoscaler_spec_create(
      56,
      56,
       // false, not to have infinite recursion
      instantiate_v1_cross_version_object_reference(0),
      56
    );
  } else {
    v1_horizontal_pod_autoscaler_spec = v1_horizontal_pod_autoscaler_spec_create(
      56,
      56,
      NULL,
      56
    );
  }

  return v1_horizontal_pod_autoscaler_spec;
}


#ifdef v1_horizontal_pod_autoscaler_spec_MAIN

void test_v1_horizontal_pod_autoscaler_spec(int include_optional) {
    v1_horizontal_pod_autoscaler_spec_t* v1_horizontal_pod_autoscaler_spec_1 = instantiate_v1_horizontal_pod_autoscaler_spec(include_optional);

	cJSON* jsonv1_horizontal_pod_autoscaler_spec_1 = v1_horizontal_pod_autoscaler_spec_convertToJSON(v1_horizontal_pod_autoscaler_spec_1);
	printf("v1_horizontal_pod_autoscaler_spec :\n%s\n", cJSON_Print(jsonv1_horizontal_pod_autoscaler_spec_1));
	v1_horizontal_pod_autoscaler_spec_t* v1_horizontal_pod_autoscaler_spec_2 = v1_horizontal_pod_autoscaler_spec_parseFromJSON(jsonv1_horizontal_pod_autoscaler_spec_1);
	cJSON* jsonv1_horizontal_pod_autoscaler_spec_2 = v1_horizontal_pod_autoscaler_spec_convertToJSON(v1_horizontal_pod_autoscaler_spec_2);
	printf("repeating v1_horizontal_pod_autoscaler_spec:\n%s\n", cJSON_Print(jsonv1_horizontal_pod_autoscaler_spec_2));
}

int main() {
  test_v1_horizontal_pod_autoscaler_spec(1);
  test_v1_horizontal_pod_autoscaler_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_horizontal_pod_autoscaler_spec_MAIN
#endif // v1_horizontal_pod_autoscaler_spec_TEST
