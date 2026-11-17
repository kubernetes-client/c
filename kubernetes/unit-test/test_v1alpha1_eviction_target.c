#ifndef v1alpha1_eviction_target_TEST
#define v1alpha1_eviction_target_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_eviction_target_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_eviction_target.h"
v1alpha1_eviction_target_t* instantiate_v1alpha1_eviction_target(int include_optional);

#include "test_v1alpha1_eviction_pod_reference.c"


v1alpha1_eviction_target_t* instantiate_v1alpha1_eviction_target(int include_optional) {
  v1alpha1_eviction_target_t* v1alpha1_eviction_target = NULL;
  if (include_optional) {
    v1alpha1_eviction_target = v1alpha1_eviction_target_create(
       // false, not to have infinite recursion
      instantiate_v1alpha1_eviction_pod_reference(0)
    );
  } else {
    v1alpha1_eviction_target = v1alpha1_eviction_target_create(
      NULL
    );
  }

  return v1alpha1_eviction_target;
}


#ifdef v1alpha1_eviction_target_MAIN

void test_v1alpha1_eviction_target(int include_optional) {
    v1alpha1_eviction_target_t* v1alpha1_eviction_target_1 = instantiate_v1alpha1_eviction_target(include_optional);

	cJSON* jsonv1alpha1_eviction_target_1 = v1alpha1_eviction_target_convertToJSON(v1alpha1_eviction_target_1);
	printf("v1alpha1_eviction_target :\n%s\n", cJSON_Print(jsonv1alpha1_eviction_target_1));
	v1alpha1_eviction_target_t* v1alpha1_eviction_target_2 = v1alpha1_eviction_target_parseFromJSON(jsonv1alpha1_eviction_target_1);
	cJSON* jsonv1alpha1_eviction_target_2 = v1alpha1_eviction_target_convertToJSON(v1alpha1_eviction_target_2);
	printf("repeating v1alpha1_eviction_target:\n%s\n", cJSON_Print(jsonv1alpha1_eviction_target_2));
}

int main() {
  test_v1alpha1_eviction_target(1);
  test_v1alpha1_eviction_target(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_eviction_target_MAIN
#endif // v1alpha1_eviction_target_TEST
