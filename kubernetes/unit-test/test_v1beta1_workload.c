#ifndef v1beta1_workload_TEST
#define v1beta1_workload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_workload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_workload.h"
v1beta1_workload_t* instantiate_v1beta1_workload(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1beta1_workload_spec.c"


v1beta1_workload_t* instantiate_v1beta1_workload(int include_optional) {
  v1beta1_workload_t* v1beta1_workload = NULL;
  if (include_optional) {
    v1beta1_workload = v1beta1_workload_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1beta1_workload_spec(0)
    );
  } else {
    v1beta1_workload = v1beta1_workload_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1beta1_workload;
}


#ifdef v1beta1_workload_MAIN

void test_v1beta1_workload(int include_optional) {
    v1beta1_workload_t* v1beta1_workload_1 = instantiate_v1beta1_workload(include_optional);

	cJSON* jsonv1beta1_workload_1 = v1beta1_workload_convertToJSON(v1beta1_workload_1);
	printf("v1beta1_workload :\n%s\n", cJSON_Print(jsonv1beta1_workload_1));
	v1beta1_workload_t* v1beta1_workload_2 = v1beta1_workload_parseFromJSON(jsonv1beta1_workload_1);
	cJSON* jsonv1beta1_workload_2 = v1beta1_workload_convertToJSON(v1beta1_workload_2);
	printf("repeating v1beta1_workload:\n%s\n", cJSON_Print(jsonv1beta1_workload_2));
}

int main() {
  test_v1beta1_workload(1);
  test_v1beta1_workload(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_workload_MAIN
#endif // v1beta1_workload_TEST
