#ifndef v2beta1_api_version_discovery_TEST
#define v2beta1_api_version_discovery_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2beta1_api_version_discovery_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2beta1_api_version_discovery.h"
v2beta1_api_version_discovery_t* instantiate_v2beta1_api_version_discovery(int include_optional);



v2beta1_api_version_discovery_t* instantiate_v2beta1_api_version_discovery(int include_optional) {
  v2beta1_api_version_discovery_t* v2beta1_api_version_discovery = NULL;
  if (include_optional) {
    v2beta1_api_version_discovery = v2beta1_api_version_discovery_create(
      "0",
      list_createList(),
      "0"
    );
  } else {
    v2beta1_api_version_discovery = v2beta1_api_version_discovery_create(
      "0",
      list_createList(),
      "0"
    );
  }

  return v2beta1_api_version_discovery;
}


#ifdef v2beta1_api_version_discovery_MAIN

void test_v2beta1_api_version_discovery(int include_optional) {
    v2beta1_api_version_discovery_t* v2beta1_api_version_discovery_1 = instantiate_v2beta1_api_version_discovery(include_optional);

	cJSON* jsonv2beta1_api_version_discovery_1 = v2beta1_api_version_discovery_convertToJSON(v2beta1_api_version_discovery_1);
	printf("v2beta1_api_version_discovery :\n%s\n", cJSON_Print(jsonv2beta1_api_version_discovery_1));
	v2beta1_api_version_discovery_t* v2beta1_api_version_discovery_2 = v2beta1_api_version_discovery_parseFromJSON(jsonv2beta1_api_version_discovery_1);
	cJSON* jsonv2beta1_api_version_discovery_2 = v2beta1_api_version_discovery_convertToJSON(v2beta1_api_version_discovery_2);
	printf("repeating v2beta1_api_version_discovery:\n%s\n", cJSON_Print(jsonv2beta1_api_version_discovery_2));
}

int main() {
  test_v2beta1_api_version_discovery(1);
  test_v2beta1_api_version_discovery(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2beta1_api_version_discovery_MAIN
#endif // v2beta1_api_version_discovery_TEST
