#ifndef v1_group_version_for_discovery_TEST
#define v1_group_version_for_discovery_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_group_version_for_discovery_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_group_version_for_discovery.h"
v1_group_version_for_discovery_t* instantiate_v1_group_version_for_discovery(int include_optional);



v1_group_version_for_discovery_t* instantiate_v1_group_version_for_discovery(int include_optional) {
  v1_group_version_for_discovery_t* v1_group_version_for_discovery = NULL;
  if (include_optional) {
    v1_group_version_for_discovery = v1_group_version_for_discovery_create(
      "0",
      "0"
    );
  } else {
    v1_group_version_for_discovery = v1_group_version_for_discovery_create(
      "0",
      "0"
    );
  }

  return v1_group_version_for_discovery;
}


#ifdef v1_group_version_for_discovery_MAIN

void test_v1_group_version_for_discovery(int include_optional) {
    v1_group_version_for_discovery_t* v1_group_version_for_discovery_1 = instantiate_v1_group_version_for_discovery(include_optional);

	cJSON* jsonv1_group_version_for_discovery_1 = v1_group_version_for_discovery_convertToJSON(v1_group_version_for_discovery_1);
	printf("v1_group_version_for_discovery :\n%s\n", cJSON_Print(jsonv1_group_version_for_discovery_1));
	v1_group_version_for_discovery_t* v1_group_version_for_discovery_2 = v1_group_version_for_discovery_parseFromJSON(jsonv1_group_version_for_discovery_1);
	cJSON* jsonv1_group_version_for_discovery_2 = v1_group_version_for_discovery_convertToJSON(v1_group_version_for_discovery_2);
	printf("repeating v1_group_version_for_discovery:\n%s\n", cJSON_Print(jsonv1_group_version_for_discovery_2));
}

int main() {
  test_v1_group_version_for_discovery(1);
  test_v1_group_version_for_discovery(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_group_version_for_discovery_MAIN
#endif // v1_group_version_for_discovery_TEST
