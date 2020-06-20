#ifndef v1_custom_resource_definition_TEST
#define v1_custom_resource_definition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_custom_resource_definition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_custom_resource_definition.h"
v1_custom_resource_definition_t* instantiate_v1_custom_resource_definition(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_custom_resource_definition_spec.c"
#include "test_v1_custom_resource_definition_status.c"


v1_custom_resource_definition_t* instantiate_v1_custom_resource_definition(int include_optional) {
  v1_custom_resource_definition_t* v1_custom_resource_definition = NULL;
  if (include_optional) {
    v1_custom_resource_definition = v1_custom_resource_definition_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_custom_resource_definition_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_custom_resource_definition_status(0)
    );
  } else {
    v1_custom_resource_definition = v1_custom_resource_definition_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_custom_resource_definition;
}


#ifdef v1_custom_resource_definition_MAIN

void test_v1_custom_resource_definition(int include_optional) {
    v1_custom_resource_definition_t* v1_custom_resource_definition_1 = instantiate_v1_custom_resource_definition(include_optional);

	cJSON* jsonv1_custom_resource_definition_1 = v1_custom_resource_definition_convertToJSON(v1_custom_resource_definition_1);
	printf("v1_custom_resource_definition :\n%s\n", cJSON_Print(jsonv1_custom_resource_definition_1));
	v1_custom_resource_definition_t* v1_custom_resource_definition_2 = v1_custom_resource_definition_parseFromJSON(jsonv1_custom_resource_definition_1);
	cJSON* jsonv1_custom_resource_definition_2 = v1_custom_resource_definition_convertToJSON(v1_custom_resource_definition_2);
	printf("repeating v1_custom_resource_definition:\n%s\n", cJSON_Print(jsonv1_custom_resource_definition_2));
}

int main() {
  test_v1_custom_resource_definition(1);
  test_v1_custom_resource_definition(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_custom_resource_definition_MAIN
#endif // v1_custom_resource_definition_TEST
