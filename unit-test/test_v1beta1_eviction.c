#ifndef v1beta1_eviction_TEST
#define v1beta1_eviction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_eviction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_eviction.h"
v1beta1_eviction_t* instantiate_v1beta1_eviction(int include_optional);

#include "test_v1_delete_options.c"
#include "test_v1_object_meta.c"


v1beta1_eviction_t* instantiate_v1beta1_eviction(int include_optional) {
  v1beta1_eviction_t* v1beta1_eviction = NULL;
  if (include_optional) {
    v1beta1_eviction = v1beta1_eviction_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1_delete_options(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0)
    );
  } else {
    v1beta1_eviction = v1beta1_eviction_create(
      "0",
      NULL,
      "0",
      NULL
    );
  }

  return v1beta1_eviction;
}


#ifdef v1beta1_eviction_MAIN

void test_v1beta1_eviction(int include_optional) {
    v1beta1_eviction_t* v1beta1_eviction_1 = instantiate_v1beta1_eviction(include_optional);

	cJSON* jsonv1beta1_eviction_1 = v1beta1_eviction_convertToJSON(v1beta1_eviction_1);
	printf("v1beta1_eviction :\n%s\n", cJSON_Print(jsonv1beta1_eviction_1));
	v1beta1_eviction_t* v1beta1_eviction_2 = v1beta1_eviction_parseFromJSON(jsonv1beta1_eviction_1);
	cJSON* jsonv1beta1_eviction_2 = v1beta1_eviction_convertToJSON(v1beta1_eviction_2);
	printf("repeating v1beta1_eviction:\n%s\n", cJSON_Print(jsonv1beta1_eviction_2));
}

int main() {
  test_v1beta1_eviction(1);
  test_v1beta1_eviction(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_eviction_MAIN
#endif // v1beta1_eviction_TEST
