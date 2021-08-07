#ifndef v1_custom_resource_definition_status_TEST
#define v1_custom_resource_definition_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_custom_resource_definition_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_custom_resource_definition_status.h"
v1_custom_resource_definition_status_t* instantiate_v1_custom_resource_definition_status(int include_optional);

#include "test_v1_custom_resource_definition_names.c"


v1_custom_resource_definition_status_t* instantiate_v1_custom_resource_definition_status(int include_optional) {
  v1_custom_resource_definition_status_t* v1_custom_resource_definition_status = NULL;
  if (include_optional) {
    v1_custom_resource_definition_status = v1_custom_resource_definition_status_create(
       // false, not to have infinite recursion
      instantiate_v1_custom_resource_definition_names(0),
      list_create(),
      list_create()
    );
  } else {
    v1_custom_resource_definition_status = v1_custom_resource_definition_status_create(
      NULL,
      list_create(),
      list_create()
    );
  }

  return v1_custom_resource_definition_status;
}


#ifdef v1_custom_resource_definition_status_MAIN

void test_v1_custom_resource_definition_status(int include_optional) {
    v1_custom_resource_definition_status_t* v1_custom_resource_definition_status_1 = instantiate_v1_custom_resource_definition_status(include_optional);

	cJSON* jsonv1_custom_resource_definition_status_1 = v1_custom_resource_definition_status_convertToJSON(v1_custom_resource_definition_status_1);
	printf("v1_custom_resource_definition_status :\n%s\n", cJSON_Print(jsonv1_custom_resource_definition_status_1));
	v1_custom_resource_definition_status_t* v1_custom_resource_definition_status_2 = v1_custom_resource_definition_status_parseFromJSON(jsonv1_custom_resource_definition_status_1);
	cJSON* jsonv1_custom_resource_definition_status_2 = v1_custom_resource_definition_status_convertToJSON(v1_custom_resource_definition_status_2);
	printf("repeating v1_custom_resource_definition_status:\n%s\n", cJSON_Print(jsonv1_custom_resource_definition_status_2));
}

int main() {
  test_v1_custom_resource_definition_status(1);
  test_v1_custom_resource_definition_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_custom_resource_definition_status_MAIN
#endif // v1_custom_resource_definition_status_TEST
