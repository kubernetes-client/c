#ifndef v2_api_resource_discovery_TEST
#define v2_api_resource_discovery_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2_api_resource_discovery_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2_api_resource_discovery.h"
v2_api_resource_discovery_t* instantiate_v2_api_resource_discovery(int include_optional);

#include "test_v1_group_version_kind.c"


v2_api_resource_discovery_t* instantiate_v2_api_resource_discovery(int include_optional) {
  v2_api_resource_discovery_t* v2_api_resource_discovery = NULL;
  if (include_optional) {
    v2_api_resource_discovery = v2_api_resource_discovery_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1_group_version_kind(0),
      "0",
      "0",
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList()
    );
  } else {
    v2_api_resource_discovery = v2_api_resource_discovery_create(
      "0",
      NULL,
      "0",
      "0",
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList()
    );
  }

  return v2_api_resource_discovery;
}


#ifdef v2_api_resource_discovery_MAIN

void test_v2_api_resource_discovery(int include_optional) {
    v2_api_resource_discovery_t* v2_api_resource_discovery_1 = instantiate_v2_api_resource_discovery(include_optional);

	cJSON* jsonv2_api_resource_discovery_1 = v2_api_resource_discovery_convertToJSON(v2_api_resource_discovery_1);
	printf("v2_api_resource_discovery :\n%s\n", cJSON_Print(jsonv2_api_resource_discovery_1));
	v2_api_resource_discovery_t* v2_api_resource_discovery_2 = v2_api_resource_discovery_parseFromJSON(jsonv2_api_resource_discovery_1);
	cJSON* jsonv2_api_resource_discovery_2 = v2_api_resource_discovery_convertToJSON(v2_api_resource_discovery_2);
	printf("repeating v2_api_resource_discovery:\n%s\n", cJSON_Print(jsonv2_api_resource_discovery_2));
}

int main() {
  test_v2_api_resource_discovery(1);
  test_v2_api_resource_discovery(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2_api_resource_discovery_MAIN
#endif // v2_api_resource_discovery_TEST
