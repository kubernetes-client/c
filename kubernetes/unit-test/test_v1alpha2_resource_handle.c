#ifndef v1alpha2_resource_handle_TEST
#define v1alpha2_resource_handle_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha2_resource_handle_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha2_resource_handle.h"
v1alpha2_resource_handle_t* instantiate_v1alpha2_resource_handle(int include_optional);



v1alpha2_resource_handle_t* instantiate_v1alpha2_resource_handle(int include_optional) {
  v1alpha2_resource_handle_t* v1alpha2_resource_handle = NULL;
  if (include_optional) {
    v1alpha2_resource_handle = v1alpha2_resource_handle_create(
      "0",
      "0"
    );
  } else {
    v1alpha2_resource_handle = v1alpha2_resource_handle_create(
      "0",
      "0"
    );
  }

  return v1alpha2_resource_handle;
}


#ifdef v1alpha2_resource_handle_MAIN

void test_v1alpha2_resource_handle(int include_optional) {
    v1alpha2_resource_handle_t* v1alpha2_resource_handle_1 = instantiate_v1alpha2_resource_handle(include_optional);

	cJSON* jsonv1alpha2_resource_handle_1 = v1alpha2_resource_handle_convertToJSON(v1alpha2_resource_handle_1);
	printf("v1alpha2_resource_handle :\n%s\n", cJSON_Print(jsonv1alpha2_resource_handle_1));
	v1alpha2_resource_handle_t* v1alpha2_resource_handle_2 = v1alpha2_resource_handle_parseFromJSON(jsonv1alpha2_resource_handle_1);
	cJSON* jsonv1alpha2_resource_handle_2 = v1alpha2_resource_handle_convertToJSON(v1alpha2_resource_handle_2);
	printf("repeating v1alpha2_resource_handle:\n%s\n", cJSON_Print(jsonv1alpha2_resource_handle_2));
}

int main() {
  test_v1alpha2_resource_handle(1);
  test_v1alpha2_resource_handle(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha2_resource_handle_MAIN
#endif // v1alpha2_resource_handle_TEST
