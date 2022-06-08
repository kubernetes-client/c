#ifndef v1_endpoint_slice_TEST
#define v1_endpoint_slice_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_endpoint_slice_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_endpoint_slice.h"
v1_endpoint_slice_t* instantiate_v1_endpoint_slice(int include_optional);

#include "test_v1_object_meta.c"


v1_endpoint_slice_t* instantiate_v1_endpoint_slice(int include_optional) {
  v1_endpoint_slice_t* v1_endpoint_slice = NULL;
  if (include_optional) {
    v1_endpoint_slice = v1_endpoint_slice_create(
      "0",
      "0",
      list_createList(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
      list_createList()
    );
  } else {
    v1_endpoint_slice = v1_endpoint_slice_create(
      "0",
      "0",
      list_createList(),
      "0",
      NULL,
      list_createList()
    );
  }

  return v1_endpoint_slice;
}


#ifdef v1_endpoint_slice_MAIN

void test_v1_endpoint_slice(int include_optional) {
    v1_endpoint_slice_t* v1_endpoint_slice_1 = instantiate_v1_endpoint_slice(include_optional);

	cJSON* jsonv1_endpoint_slice_1 = v1_endpoint_slice_convertToJSON(v1_endpoint_slice_1);
	printf("v1_endpoint_slice :\n%s\n", cJSON_Print(jsonv1_endpoint_slice_1));
	v1_endpoint_slice_t* v1_endpoint_slice_2 = v1_endpoint_slice_parseFromJSON(jsonv1_endpoint_slice_1);
	cJSON* jsonv1_endpoint_slice_2 = v1_endpoint_slice_convertToJSON(v1_endpoint_slice_2);
	printf("repeating v1_endpoint_slice:\n%s\n", cJSON_Print(jsonv1_endpoint_slice_2));
}

int main() {
  test_v1_endpoint_slice(1);
  test_v1_endpoint_slice(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_endpoint_slice_MAIN
#endif // v1_endpoint_slice_TEST
