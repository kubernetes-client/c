#ifndef v1_custom_resource_definition_version_TEST
#define v1_custom_resource_definition_version_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_custom_resource_definition_version_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_custom_resource_definition_version.h"
v1_custom_resource_definition_version_t* instantiate_v1_custom_resource_definition_version(int include_optional);

#include "test_v1_custom_resource_validation.c"
#include "test_v1_custom_resource_subresources.c"


v1_custom_resource_definition_version_t* instantiate_v1_custom_resource_definition_version(int include_optional) {
  v1_custom_resource_definition_version_t* v1_custom_resource_definition_version = NULL;
  if (include_optional) {
    v1_custom_resource_definition_version = v1_custom_resource_definition_version_create(
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_custom_resource_validation(0),
      1,
      1,
       // false, not to have infinite recursion
      instantiate_v1_custom_resource_subresources(0)
    );
  } else {
    v1_custom_resource_definition_version = v1_custom_resource_definition_version_create(
      list_create(),
      "0",
      NULL,
      1,
      1,
      NULL
    );
  }

  return v1_custom_resource_definition_version;
}


#ifdef v1_custom_resource_definition_version_MAIN

void test_v1_custom_resource_definition_version(int include_optional) {
    v1_custom_resource_definition_version_t* v1_custom_resource_definition_version_1 = instantiate_v1_custom_resource_definition_version(include_optional);

	cJSON* jsonv1_custom_resource_definition_version_1 = v1_custom_resource_definition_version_convertToJSON(v1_custom_resource_definition_version_1);
	printf("v1_custom_resource_definition_version :\n%s\n", cJSON_Print(jsonv1_custom_resource_definition_version_1));
	v1_custom_resource_definition_version_t* v1_custom_resource_definition_version_2 = v1_custom_resource_definition_version_parseFromJSON(jsonv1_custom_resource_definition_version_1);
	cJSON* jsonv1_custom_resource_definition_version_2 = v1_custom_resource_definition_version_convertToJSON(v1_custom_resource_definition_version_2);
	printf("repeating v1_custom_resource_definition_version:\n%s\n", cJSON_Print(jsonv1_custom_resource_definition_version_2));
}

int main() {
  test_v1_custom_resource_definition_version(1);
  test_v1_custom_resource_definition_version(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_custom_resource_definition_version_MAIN
#endif // v1_custom_resource_definition_version_TEST
