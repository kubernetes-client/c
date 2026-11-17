#ifndef v1alpha3_workload_TEST
#define v1alpha3_workload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_workload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_workload.h"
v1alpha3_workload_t* instantiate_v1alpha3_workload(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha3_workload_spec.c"


v1alpha3_workload_t* instantiate_v1alpha3_workload(int include_optional) {
  v1alpha3_workload_t* v1alpha3_workload = NULL;
  if (include_optional) {
    v1alpha3_workload = v1alpha3_workload_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha3_workload_spec(0)
    );
  } else {
    v1alpha3_workload = v1alpha3_workload_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1alpha3_workload;
}


#ifdef v1alpha3_workload_MAIN

void test_v1alpha3_workload(int include_optional) {
    v1alpha3_workload_t* v1alpha3_workload_1 = instantiate_v1alpha3_workload(include_optional);

	cJSON* jsonv1alpha3_workload_1 = v1alpha3_workload_convertToJSON(v1alpha3_workload_1);
	printf("v1alpha3_workload :\n%s\n", cJSON_Print(jsonv1alpha3_workload_1));
	v1alpha3_workload_t* v1alpha3_workload_2 = v1alpha3_workload_parseFromJSON(jsonv1alpha3_workload_1);
	cJSON* jsonv1alpha3_workload_2 = v1alpha3_workload_convertToJSON(v1alpha3_workload_2);
	printf("repeating v1alpha3_workload:\n%s\n", cJSON_Print(jsonv1alpha3_workload_2));
}

int main() {
  test_v1alpha3_workload(1);
  test_v1alpha3_workload(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_workload_MAIN
#endif // v1alpha3_workload_TEST
