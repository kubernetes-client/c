#ifndef v2beta1_metric_status_TEST
#define v2beta1_metric_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2beta1_metric_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2beta1_metric_status.h"
v2beta1_metric_status_t* instantiate_v2beta1_metric_status(int include_optional);

#include "test_v2beta1_external_metric_status.c"
#include "test_v2beta1_object_metric_status.c"
#include "test_v2beta1_pods_metric_status.c"
#include "test_v2beta1_resource_metric_status.c"


v2beta1_metric_status_t* instantiate_v2beta1_metric_status(int include_optional) {
  v2beta1_metric_status_t* v2beta1_metric_status = NULL;
  if (include_optional) {
    v2beta1_metric_status = v2beta1_metric_status_create(
       // false, not to have infinite recursion
      instantiate_v2beta1_external_metric_status(0),
       // false, not to have infinite recursion
      instantiate_v2beta1_object_metric_status(0),
       // false, not to have infinite recursion
      instantiate_v2beta1_pods_metric_status(0),
       // false, not to have infinite recursion
      instantiate_v2beta1_resource_metric_status(0),
      "0"
    );
  } else {
    v2beta1_metric_status = v2beta1_metric_status_create(
      NULL,
      NULL,
      NULL,
      NULL,
      "0"
    );
  }

  return v2beta1_metric_status;
}


#ifdef v2beta1_metric_status_MAIN

void test_v2beta1_metric_status(int include_optional) {
    v2beta1_metric_status_t* v2beta1_metric_status_1 = instantiate_v2beta1_metric_status(include_optional);

	cJSON* jsonv2beta1_metric_status_1 = v2beta1_metric_status_convertToJSON(v2beta1_metric_status_1);
	printf("v2beta1_metric_status :\n%s\n", cJSON_Print(jsonv2beta1_metric_status_1));
	v2beta1_metric_status_t* v2beta1_metric_status_2 = v2beta1_metric_status_parseFromJSON(jsonv2beta1_metric_status_1);
	cJSON* jsonv2beta1_metric_status_2 = v2beta1_metric_status_convertToJSON(v2beta1_metric_status_2);
	printf("repeating v2beta1_metric_status:\n%s\n", cJSON_Print(jsonv2beta1_metric_status_2));
}

int main() {
  test_v2beta1_metric_status(1);
  test_v2beta1_metric_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2beta1_metric_status_MAIN
#endif // v2beta1_metric_status_TEST
