#ifndef v1_group_resource_TEST
#define v1_group_resource_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_group_resource_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_group_resource.h"
v1_group_resource_t* instantiate_v1_group_resource(int include_optional);



v1_group_resource_t* instantiate_v1_group_resource(int include_optional) {
  v1_group_resource_t* v1_group_resource = NULL;
  if (include_optional) {
    v1_group_resource = v1_group_resource_create(
      "0",
      "0"
    );
  } else {
    v1_group_resource = v1_group_resource_create(
      "0",
      "0"
    );
  }

  return v1_group_resource;
}


#ifdef v1_group_resource_MAIN

void test_v1_group_resource(int include_optional) {
    v1_group_resource_t* v1_group_resource_1 = instantiate_v1_group_resource(include_optional);

	cJSON* jsonv1_group_resource_1 = v1_group_resource_convertToJSON(v1_group_resource_1);
	printf("v1_group_resource :\n%s\n", cJSON_Print(jsonv1_group_resource_1));
	v1_group_resource_t* v1_group_resource_2 = v1_group_resource_parseFromJSON(jsonv1_group_resource_1);
	cJSON* jsonv1_group_resource_2 = v1_group_resource_convertToJSON(v1_group_resource_2);
	printf("repeating v1_group_resource:\n%s\n", cJSON_Print(jsonv1_group_resource_2));
}

int main() {
  test_v1_group_resource(1);
  test_v1_group_resource(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_group_resource_MAIN
#endif // v1_group_resource_TEST
