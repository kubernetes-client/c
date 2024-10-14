#ifndef v1_resource_status_TEST
#define v1_resource_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_resource_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_resource_status.h"
v1_resource_status_t* instantiate_v1_resource_status(int include_optional);



v1_resource_status_t* instantiate_v1_resource_status(int include_optional) {
  v1_resource_status_t* v1_resource_status = NULL;
  if (include_optional) {
    v1_resource_status = v1_resource_status_create(
      "0",
      list_createList()
    );
  } else {
    v1_resource_status = v1_resource_status_create(
      "0",
      list_createList()
    );
  }

  return v1_resource_status;
}


#ifdef v1_resource_status_MAIN

void test_v1_resource_status(int include_optional) {
    v1_resource_status_t* v1_resource_status_1 = instantiate_v1_resource_status(include_optional);

	cJSON* jsonv1_resource_status_1 = v1_resource_status_convertToJSON(v1_resource_status_1);
	printf("v1_resource_status :\n%s\n", cJSON_Print(jsonv1_resource_status_1));
	v1_resource_status_t* v1_resource_status_2 = v1_resource_status_parseFromJSON(jsonv1_resource_status_1);
	cJSON* jsonv1_resource_status_2 = v1_resource_status_convertToJSON(v1_resource_status_2);
	printf("repeating v1_resource_status:\n%s\n", cJSON_Print(jsonv1_resource_status_2));
}

int main() {
  test_v1_resource_status(1);
  test_v1_resource_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_resource_status_MAIN
#endif // v1_resource_status_TEST
