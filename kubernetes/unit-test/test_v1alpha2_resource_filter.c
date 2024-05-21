#ifndef v1alpha2_resource_filter_TEST
#define v1alpha2_resource_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha2_resource_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha2_resource_filter.h"
v1alpha2_resource_filter_t* instantiate_v1alpha2_resource_filter(int include_optional);

#include "test_v1alpha2_named_resources_filter.c"


v1alpha2_resource_filter_t* instantiate_v1alpha2_resource_filter(int include_optional) {
  v1alpha2_resource_filter_t* v1alpha2_resource_filter = NULL;
  if (include_optional) {
    v1alpha2_resource_filter = v1alpha2_resource_filter_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1alpha2_named_resources_filter(0)
    );
  } else {
    v1alpha2_resource_filter = v1alpha2_resource_filter_create(
      "0",
      NULL
    );
  }

  return v1alpha2_resource_filter;
}


#ifdef v1alpha2_resource_filter_MAIN

void test_v1alpha2_resource_filter(int include_optional) {
    v1alpha2_resource_filter_t* v1alpha2_resource_filter_1 = instantiate_v1alpha2_resource_filter(include_optional);

	cJSON* jsonv1alpha2_resource_filter_1 = v1alpha2_resource_filter_convertToJSON(v1alpha2_resource_filter_1);
	printf("v1alpha2_resource_filter :\n%s\n", cJSON_Print(jsonv1alpha2_resource_filter_1));
	v1alpha2_resource_filter_t* v1alpha2_resource_filter_2 = v1alpha2_resource_filter_parseFromJSON(jsonv1alpha2_resource_filter_1);
	cJSON* jsonv1alpha2_resource_filter_2 = v1alpha2_resource_filter_convertToJSON(v1alpha2_resource_filter_2);
	printf("repeating v1alpha2_resource_filter:\n%s\n", cJSON_Print(jsonv1alpha2_resource_filter_2));
}

int main() {
  test_v1alpha2_resource_filter(1);
  test_v1alpha2_resource_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha2_resource_filter_MAIN
#endif // v1alpha2_resource_filter_TEST
