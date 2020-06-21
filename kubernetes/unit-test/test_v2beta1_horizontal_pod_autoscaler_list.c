#ifndef v2beta1_horizontal_pod_autoscaler_list_TEST
#define v2beta1_horizontal_pod_autoscaler_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2beta1_horizontal_pod_autoscaler_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2beta1_horizontal_pod_autoscaler_list.h"
v2beta1_horizontal_pod_autoscaler_list_t* instantiate_v2beta1_horizontal_pod_autoscaler_list(int include_optional);

#include "test_v1_list_meta.c"


v2beta1_horizontal_pod_autoscaler_list_t* instantiate_v2beta1_horizontal_pod_autoscaler_list(int include_optional) {
  v2beta1_horizontal_pod_autoscaler_list_t* v2beta1_horizontal_pod_autoscaler_list = NULL;
  if (include_optional) {
    v2beta1_horizontal_pod_autoscaler_list = v2beta1_horizontal_pod_autoscaler_list_create(
      "0",
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_list_meta(0)
    );
  } else {
    v2beta1_horizontal_pod_autoscaler_list = v2beta1_horizontal_pod_autoscaler_list_create(
      "0",
      list_create(),
      "0",
      NULL
    );
  }

  return v2beta1_horizontal_pod_autoscaler_list;
}


#ifdef v2beta1_horizontal_pod_autoscaler_list_MAIN

void test_v2beta1_horizontal_pod_autoscaler_list(int include_optional) {
    v2beta1_horizontal_pod_autoscaler_list_t* v2beta1_horizontal_pod_autoscaler_list_1 = instantiate_v2beta1_horizontal_pod_autoscaler_list(include_optional);

	cJSON* jsonv2beta1_horizontal_pod_autoscaler_list_1 = v2beta1_horizontal_pod_autoscaler_list_convertToJSON(v2beta1_horizontal_pod_autoscaler_list_1);
	printf("v2beta1_horizontal_pod_autoscaler_list :\n%s\n", cJSON_Print(jsonv2beta1_horizontal_pod_autoscaler_list_1));
	v2beta1_horizontal_pod_autoscaler_list_t* v2beta1_horizontal_pod_autoscaler_list_2 = v2beta1_horizontal_pod_autoscaler_list_parseFromJSON(jsonv2beta1_horizontal_pod_autoscaler_list_1);
	cJSON* jsonv2beta1_horizontal_pod_autoscaler_list_2 = v2beta1_horizontal_pod_autoscaler_list_convertToJSON(v2beta1_horizontal_pod_autoscaler_list_2);
	printf("repeating v2beta1_horizontal_pod_autoscaler_list:\n%s\n", cJSON_Print(jsonv2beta1_horizontal_pod_autoscaler_list_2));
}

int main() {
  test_v2beta1_horizontal_pod_autoscaler_list(1);
  test_v2beta1_horizontal_pod_autoscaler_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2beta1_horizontal_pod_autoscaler_list_MAIN
#endif // v2beta1_horizontal_pod_autoscaler_list_TEST
