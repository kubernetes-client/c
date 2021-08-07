#ifndef v1_api_resource_TEST
#define v1_api_resource_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_api_resource_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_api_resource.h"
v1_api_resource_t* instantiate_v1_api_resource(int include_optional);



v1_api_resource_t* instantiate_v1_api_resource(int include_optional) {
  v1_api_resource_t* v1_api_resource = NULL;
  if (include_optional) {
    v1_api_resource = v1_api_resource_create(
      list_create(),
      "0",
      "0",
      "0",
      1,
      list_create(),
      "0",
      "0",
      list_create(),
      "0"
    );
  } else {
    v1_api_resource = v1_api_resource_create(
      list_create(),
      "0",
      "0",
      "0",
      1,
      list_create(),
      "0",
      "0",
      list_create(),
      "0"
    );
  }

  return v1_api_resource;
}


#ifdef v1_api_resource_MAIN

void test_v1_api_resource(int include_optional) {
    v1_api_resource_t* v1_api_resource_1 = instantiate_v1_api_resource(include_optional);

	cJSON* jsonv1_api_resource_1 = v1_api_resource_convertToJSON(v1_api_resource_1);
	printf("v1_api_resource :\n%s\n", cJSON_Print(jsonv1_api_resource_1));
	v1_api_resource_t* v1_api_resource_2 = v1_api_resource_parseFromJSON(jsonv1_api_resource_1);
	cJSON* jsonv1_api_resource_2 = v1_api_resource_convertToJSON(v1_api_resource_2);
	printf("repeating v1_api_resource:\n%s\n", cJSON_Print(jsonv1_api_resource_2));
}

int main() {
  test_v1_api_resource(1);
  test_v1_api_resource(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_api_resource_MAIN
#endif // v1_api_resource_TEST
