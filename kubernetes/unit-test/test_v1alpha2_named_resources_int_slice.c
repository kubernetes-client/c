#ifndef v1alpha2_named_resources_int_slice_TEST
#define v1alpha2_named_resources_int_slice_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha2_named_resources_int_slice_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha2_named_resources_int_slice.h"
v1alpha2_named_resources_int_slice_t* instantiate_v1alpha2_named_resources_int_slice(int include_optional);



v1alpha2_named_resources_int_slice_t* instantiate_v1alpha2_named_resources_int_slice(int include_optional) {
  v1alpha2_named_resources_int_slice_t* v1alpha2_named_resources_int_slice = NULL;
  if (include_optional) {
    v1alpha2_named_resources_int_slice = v1alpha2_named_resources_int_slice_create(
      list_createList()
    );
  } else {
    v1alpha2_named_resources_int_slice = v1alpha2_named_resources_int_slice_create(
      list_createList()
    );
  }

  return v1alpha2_named_resources_int_slice;
}


#ifdef v1alpha2_named_resources_int_slice_MAIN

void test_v1alpha2_named_resources_int_slice(int include_optional) {
    v1alpha2_named_resources_int_slice_t* v1alpha2_named_resources_int_slice_1 = instantiate_v1alpha2_named_resources_int_slice(include_optional);

	cJSON* jsonv1alpha2_named_resources_int_slice_1 = v1alpha2_named_resources_int_slice_convertToJSON(v1alpha2_named_resources_int_slice_1);
	printf("v1alpha2_named_resources_int_slice :\n%s\n", cJSON_Print(jsonv1alpha2_named_resources_int_slice_1));
	v1alpha2_named_resources_int_slice_t* v1alpha2_named_resources_int_slice_2 = v1alpha2_named_resources_int_slice_parseFromJSON(jsonv1alpha2_named_resources_int_slice_1);
	cJSON* jsonv1alpha2_named_resources_int_slice_2 = v1alpha2_named_resources_int_slice_convertToJSON(v1alpha2_named_resources_int_slice_2);
	printf("repeating v1alpha2_named_resources_int_slice:\n%s\n", cJSON_Print(jsonv1alpha2_named_resources_int_slice_2));
}

int main() {
  test_v1alpha2_named_resources_int_slice(1);
  test_v1alpha2_named_resources_int_slice(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha2_named_resources_int_slice_MAIN
#endif // v1alpha2_named_resources_int_slice_TEST
