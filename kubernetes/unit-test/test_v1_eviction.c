#ifndef v1_eviction_TEST
#define v1_eviction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_eviction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_eviction.h"
v1_eviction_t* instantiate_v1_eviction(int include_optional);

#include "test_v1_delete_options.c"
#include "test_v1_object_meta.c"


v1_eviction_t* instantiate_v1_eviction(int include_optional) {
  v1_eviction_t* v1_eviction = NULL;
  if (include_optional) {
    v1_eviction = v1_eviction_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1_delete_options(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0)
    );
  } else {
    v1_eviction = v1_eviction_create(
      "0",
      NULL,
      "0",
      NULL
    );
  }

  return v1_eviction;
}


#ifdef v1_eviction_MAIN

void test_v1_eviction(int include_optional) {
    v1_eviction_t* v1_eviction_1 = instantiate_v1_eviction(include_optional);

	cJSON* jsonv1_eviction_1 = v1_eviction_convertToJSON(v1_eviction_1);
	printf("v1_eviction :\n%s\n", cJSON_Print(jsonv1_eviction_1));
	v1_eviction_t* v1_eviction_2 = v1_eviction_parseFromJSON(jsonv1_eviction_1);
	cJSON* jsonv1_eviction_2 = v1_eviction_convertToJSON(v1_eviction_2);
	printf("repeating v1_eviction:\n%s\n", cJSON_Print(jsonv1_eviction_2));
}

int main() {
  test_v1_eviction(1);
  test_v1_eviction(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_eviction_MAIN
#endif // v1_eviction_TEST
