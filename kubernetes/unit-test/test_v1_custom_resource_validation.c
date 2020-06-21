#ifndef v1_custom_resource_validation_TEST
#define v1_custom_resource_validation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_custom_resource_validation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_custom_resource_validation.h"
v1_custom_resource_validation_t* instantiate_v1_custom_resource_validation(int include_optional);

#include "test_v1_json_schema_props.c"


v1_custom_resource_validation_t* instantiate_v1_custom_resource_validation(int include_optional) {
  v1_custom_resource_validation_t* v1_custom_resource_validation = NULL;
  if (include_optional) {
    v1_custom_resource_validation = v1_custom_resource_validation_create(
       // false, not to have infinite recursion
      instantiate_v1_json_schema_props(0)
    );
  } else {
    v1_custom_resource_validation = v1_custom_resource_validation_create(
      NULL
    );
  }

  return v1_custom_resource_validation;
}


#ifdef v1_custom_resource_validation_MAIN

void test_v1_custom_resource_validation(int include_optional) {
    v1_custom_resource_validation_t* v1_custom_resource_validation_1 = instantiate_v1_custom_resource_validation(include_optional);

	cJSON* jsonv1_custom_resource_validation_1 = v1_custom_resource_validation_convertToJSON(v1_custom_resource_validation_1);
	printf("v1_custom_resource_validation :\n%s\n", cJSON_Print(jsonv1_custom_resource_validation_1));
	v1_custom_resource_validation_t* v1_custom_resource_validation_2 = v1_custom_resource_validation_parseFromJSON(jsonv1_custom_resource_validation_1);
	cJSON* jsonv1_custom_resource_validation_2 = v1_custom_resource_validation_convertToJSON(v1_custom_resource_validation_2);
	printf("repeating v1_custom_resource_validation:\n%s\n", cJSON_Print(jsonv1_custom_resource_validation_2));
}

int main() {
  test_v1_custom_resource_validation(1);
  test_v1_custom_resource_validation(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_custom_resource_validation_MAIN
#endif // v1_custom_resource_validation_TEST
