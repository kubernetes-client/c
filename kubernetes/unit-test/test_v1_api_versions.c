#ifndef v1_api_versions_TEST
#define v1_api_versions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_api_versions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_api_versions.h"
v1_api_versions_t* instantiate_v1_api_versions(int include_optional);



v1_api_versions_t* instantiate_v1_api_versions(int include_optional) {
  v1_api_versions_t* v1_api_versions = NULL;
  if (include_optional) {
    v1_api_versions = v1_api_versions_create(
      "0",
      "0",
      list_create(),
      list_create()
    );
  } else {
    v1_api_versions = v1_api_versions_create(
      "0",
      "0",
      list_create(),
      list_create()
    );
  }

  return v1_api_versions;
}


#ifdef v1_api_versions_MAIN

void test_v1_api_versions(int include_optional) {
    v1_api_versions_t* v1_api_versions_1 = instantiate_v1_api_versions(include_optional);

	cJSON* jsonv1_api_versions_1 = v1_api_versions_convertToJSON(v1_api_versions_1);
	printf("v1_api_versions :\n%s\n", cJSON_Print(jsonv1_api_versions_1));
	v1_api_versions_t* v1_api_versions_2 = v1_api_versions_parseFromJSON(jsonv1_api_versions_1);
	cJSON* jsonv1_api_versions_2 = v1_api_versions_convertToJSON(v1_api_versions_2);
	printf("repeating v1_api_versions:\n%s\n", cJSON_Print(jsonv1_api_versions_2));
}

int main() {
  test_v1_api_versions(1);
  test_v1_api_versions(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_api_versions_MAIN
#endif // v1_api_versions_TEST
