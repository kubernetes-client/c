#ifndef v1_component_status_TEST
#define v1_component_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_component_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_component_status.h"
v1_component_status_t* instantiate_v1_component_status(int include_optional);

#include "test_v1_object_meta.c"


v1_component_status_t* instantiate_v1_component_status(int include_optional) {
  v1_component_status_t* v1_component_status = NULL;
  if (include_optional) {
    v1_component_status = v1_component_status_create(
      "0",
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0)
    );
  } else {
    v1_component_status = v1_component_status_create(
      "0",
      list_create(),
      "0",
      NULL
    );
  }

  return v1_component_status;
}


#ifdef v1_component_status_MAIN

void test_v1_component_status(int include_optional) {
    v1_component_status_t* v1_component_status_1 = instantiate_v1_component_status(include_optional);

	cJSON* jsonv1_component_status_1 = v1_component_status_convertToJSON(v1_component_status_1);
	printf("v1_component_status :\n%s\n", cJSON_Print(jsonv1_component_status_1));
	v1_component_status_t* v1_component_status_2 = v1_component_status_parseFromJSON(jsonv1_component_status_1);
	cJSON* jsonv1_component_status_2 = v1_component_status_convertToJSON(v1_component_status_2);
	printf("repeating v1_component_status:\n%s\n", cJSON_Print(jsonv1_component_status_2));
}

int main() {
  test_v1_component_status(1);
  test_v1_component_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_component_status_MAIN
#endif // v1_component_status_TEST
