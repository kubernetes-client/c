#ifndef v1alpha1_runtime_class_spec_TEST
#define v1alpha1_runtime_class_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_runtime_class_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_runtime_class_spec.h"
v1alpha1_runtime_class_spec_t* instantiate_v1alpha1_runtime_class_spec(int include_optional);

#include "test_v1alpha1_overhead.c"
#include "test_v1alpha1_scheduling.c"


v1alpha1_runtime_class_spec_t* instantiate_v1alpha1_runtime_class_spec(int include_optional) {
  v1alpha1_runtime_class_spec_t* v1alpha1_runtime_class_spec = NULL;
  if (include_optional) {
    v1alpha1_runtime_class_spec = v1alpha1_runtime_class_spec_create(
       // false, not to have infinite recursion
      instantiate_v1alpha1_overhead(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1alpha1_scheduling(0)
    );
  } else {
    v1alpha1_runtime_class_spec = v1alpha1_runtime_class_spec_create(
      NULL,
      "0",
      NULL
    );
  }

  return v1alpha1_runtime_class_spec;
}


#ifdef v1alpha1_runtime_class_spec_MAIN

void test_v1alpha1_runtime_class_spec(int include_optional) {
    v1alpha1_runtime_class_spec_t* v1alpha1_runtime_class_spec_1 = instantiate_v1alpha1_runtime_class_spec(include_optional);

	cJSON* jsonv1alpha1_runtime_class_spec_1 = v1alpha1_runtime_class_spec_convertToJSON(v1alpha1_runtime_class_spec_1);
	printf("v1alpha1_runtime_class_spec :\n%s\n", cJSON_Print(jsonv1alpha1_runtime_class_spec_1));
	v1alpha1_runtime_class_spec_t* v1alpha1_runtime_class_spec_2 = v1alpha1_runtime_class_spec_parseFromJSON(jsonv1alpha1_runtime_class_spec_1);
	cJSON* jsonv1alpha1_runtime_class_spec_2 = v1alpha1_runtime_class_spec_convertToJSON(v1alpha1_runtime_class_spec_2);
	printf("repeating v1alpha1_runtime_class_spec:\n%s\n", cJSON_Print(jsonv1alpha1_runtime_class_spec_2));
}

int main() {
  test_v1alpha1_runtime_class_spec(1);
  test_v1alpha1_runtime_class_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_runtime_class_spec_MAIN
#endif // v1alpha1_runtime_class_spec_TEST
