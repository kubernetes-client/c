#ifndef v2beta2_horizontal_pod_autoscaler_status_TEST
#define v2beta2_horizontal_pod_autoscaler_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2beta2_horizontal_pod_autoscaler_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2beta2_horizontal_pod_autoscaler_status.h"
v2beta2_horizontal_pod_autoscaler_status_t* instantiate_v2beta2_horizontal_pod_autoscaler_status(int include_optional);



v2beta2_horizontal_pod_autoscaler_status_t* instantiate_v2beta2_horizontal_pod_autoscaler_status(int include_optional) {
  v2beta2_horizontal_pod_autoscaler_status_t* v2beta2_horizontal_pod_autoscaler_status = NULL;
  if (include_optional) {
    v2beta2_horizontal_pod_autoscaler_status = v2beta2_horizontal_pod_autoscaler_status_create(
      list_create(),
      list_create(),
      56,
      56,
      "2013-10-20T19:20:30+01:00",
      56
    );
  } else {
    v2beta2_horizontal_pod_autoscaler_status = v2beta2_horizontal_pod_autoscaler_status_create(
      list_create(),
      list_create(),
      56,
      56,
      "2013-10-20T19:20:30+01:00",
      56
    );
  }

  return v2beta2_horizontal_pod_autoscaler_status;
}


#ifdef v2beta2_horizontal_pod_autoscaler_status_MAIN

void test_v2beta2_horizontal_pod_autoscaler_status(int include_optional) {
    v2beta2_horizontal_pod_autoscaler_status_t* v2beta2_horizontal_pod_autoscaler_status_1 = instantiate_v2beta2_horizontal_pod_autoscaler_status(include_optional);

	cJSON* jsonv2beta2_horizontal_pod_autoscaler_status_1 = v2beta2_horizontal_pod_autoscaler_status_convertToJSON(v2beta2_horizontal_pod_autoscaler_status_1);
	printf("v2beta2_horizontal_pod_autoscaler_status :\n%s\n", cJSON_Print(jsonv2beta2_horizontal_pod_autoscaler_status_1));
	v2beta2_horizontal_pod_autoscaler_status_t* v2beta2_horizontal_pod_autoscaler_status_2 = v2beta2_horizontal_pod_autoscaler_status_parseFromJSON(jsonv2beta2_horizontal_pod_autoscaler_status_1);
	cJSON* jsonv2beta2_horizontal_pod_autoscaler_status_2 = v2beta2_horizontal_pod_autoscaler_status_convertToJSON(v2beta2_horizontal_pod_autoscaler_status_2);
	printf("repeating v2beta2_horizontal_pod_autoscaler_status:\n%s\n", cJSON_Print(jsonv2beta2_horizontal_pod_autoscaler_status_2));
}

int main() {
  test_v2beta2_horizontal_pod_autoscaler_status(1);
  test_v2beta2_horizontal_pod_autoscaler_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2beta2_horizontal_pod_autoscaler_status_MAIN
#endif // v2beta2_horizontal_pod_autoscaler_status_TEST
