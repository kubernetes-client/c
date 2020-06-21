#ifndef v1_custom_resource_definition_names_TEST
#define v1_custom_resource_definition_names_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_custom_resource_definition_names_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_custom_resource_definition_names.h"
v1_custom_resource_definition_names_t* instantiate_v1_custom_resource_definition_names(int include_optional);



v1_custom_resource_definition_names_t* instantiate_v1_custom_resource_definition_names(int include_optional) {
  v1_custom_resource_definition_names_t* v1_custom_resource_definition_names = NULL;
  if (include_optional) {
    v1_custom_resource_definition_names = v1_custom_resource_definition_names_create(
      list_create(),
      "0",
      "0",
      "0",
      list_create(),
      "0"
    );
  } else {
    v1_custom_resource_definition_names = v1_custom_resource_definition_names_create(
      list_create(),
      "0",
      "0",
      "0",
      list_create(),
      "0"
    );
  }

  return v1_custom_resource_definition_names;
}


#ifdef v1_custom_resource_definition_names_MAIN

void test_v1_custom_resource_definition_names(int include_optional) {
    v1_custom_resource_definition_names_t* v1_custom_resource_definition_names_1 = instantiate_v1_custom_resource_definition_names(include_optional);

	cJSON* jsonv1_custom_resource_definition_names_1 = v1_custom_resource_definition_names_convertToJSON(v1_custom_resource_definition_names_1);
	printf("v1_custom_resource_definition_names :\n%s\n", cJSON_Print(jsonv1_custom_resource_definition_names_1));
	v1_custom_resource_definition_names_t* v1_custom_resource_definition_names_2 = v1_custom_resource_definition_names_parseFromJSON(jsonv1_custom_resource_definition_names_1);
	cJSON* jsonv1_custom_resource_definition_names_2 = v1_custom_resource_definition_names_convertToJSON(v1_custom_resource_definition_names_2);
	printf("repeating v1_custom_resource_definition_names:\n%s\n", cJSON_Print(jsonv1_custom_resource_definition_names_2));
}

int main() {
  test_v1_custom_resource_definition_names(1);
  test_v1_custom_resource_definition_names(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_custom_resource_definition_names_MAIN
#endif // v1_custom_resource_definition_names_TEST
