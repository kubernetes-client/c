#ifndef v1_api_group_TEST
#define v1_api_group_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_api_group_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_api_group.h"
v1_api_group_t* instantiate_v1_api_group(int include_optional);

#include "test_v1_group_version_for_discovery.c"


v1_api_group_t* instantiate_v1_api_group(int include_optional) {
  v1_api_group_t* v1_api_group = NULL;
  if (include_optional) {
    v1_api_group = v1_api_group_create(
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_group_version_for_discovery(0),
      list_create(),
      list_create()
    );
  } else {
    v1_api_group = v1_api_group_create(
      "0",
      "0",
      "0",
      NULL,
      list_create(),
      list_create()
    );
  }

  return v1_api_group;
}


#ifdef v1_api_group_MAIN

void test_v1_api_group(int include_optional) {
    v1_api_group_t* v1_api_group_1 = instantiate_v1_api_group(include_optional);

	cJSON* jsonv1_api_group_1 = v1_api_group_convertToJSON(v1_api_group_1);
	printf("v1_api_group :\n%s\n", cJSON_Print(jsonv1_api_group_1));
	v1_api_group_t* v1_api_group_2 = v1_api_group_parseFromJSON(jsonv1_api_group_1);
	cJSON* jsonv1_api_group_2 = v1_api_group_convertToJSON(v1_api_group_2);
	printf("repeating v1_api_group:\n%s\n", cJSON_Print(jsonv1_api_group_2));
}

int main() {
  test_v1_api_group(1);
  test_v1_api_group(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_api_group_MAIN
#endif // v1_api_group_TEST
