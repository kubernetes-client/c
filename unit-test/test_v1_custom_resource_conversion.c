#ifndef v1_custom_resource_conversion_TEST
#define v1_custom_resource_conversion_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_custom_resource_conversion_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_custom_resource_conversion.h"
v1_custom_resource_conversion_t* instantiate_v1_custom_resource_conversion(int include_optional);

#include "test_v1_webhook_conversion.c"


v1_custom_resource_conversion_t* instantiate_v1_custom_resource_conversion(int include_optional) {
  v1_custom_resource_conversion_t* v1_custom_resource_conversion = NULL;
  if (include_optional) {
    v1_custom_resource_conversion = v1_custom_resource_conversion_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1_webhook_conversion(0)
    );
  } else {
    v1_custom_resource_conversion = v1_custom_resource_conversion_create(
      "0",
      NULL
    );
  }

  return v1_custom_resource_conversion;
}


#ifdef v1_custom_resource_conversion_MAIN

void test_v1_custom_resource_conversion(int include_optional) {
    v1_custom_resource_conversion_t* v1_custom_resource_conversion_1 = instantiate_v1_custom_resource_conversion(include_optional);

	cJSON* jsonv1_custom_resource_conversion_1 = v1_custom_resource_conversion_convertToJSON(v1_custom_resource_conversion_1);
	printf("v1_custom_resource_conversion :\n%s\n", cJSON_Print(jsonv1_custom_resource_conversion_1));
	v1_custom_resource_conversion_t* v1_custom_resource_conversion_2 = v1_custom_resource_conversion_parseFromJSON(jsonv1_custom_resource_conversion_1);
	cJSON* jsonv1_custom_resource_conversion_2 = v1_custom_resource_conversion_convertToJSON(v1_custom_resource_conversion_2);
	printf("repeating v1_custom_resource_conversion:\n%s\n", cJSON_Print(jsonv1_custom_resource_conversion_2));
}

int main() {
  test_v1_custom_resource_conversion(1);
  test_v1_custom_resource_conversion(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_custom_resource_conversion_MAIN
#endif // v1_custom_resource_conversion_TEST
