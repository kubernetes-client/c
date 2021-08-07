#ifndef v1_volume_node_resources_TEST
#define v1_volume_node_resources_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_volume_node_resources_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_volume_node_resources.h"
v1_volume_node_resources_t* instantiate_v1_volume_node_resources(int include_optional);



v1_volume_node_resources_t* instantiate_v1_volume_node_resources(int include_optional) {
  v1_volume_node_resources_t* v1_volume_node_resources = NULL;
  if (include_optional) {
    v1_volume_node_resources = v1_volume_node_resources_create(
      56
    );
  } else {
    v1_volume_node_resources = v1_volume_node_resources_create(
      56
    );
  }

  return v1_volume_node_resources;
}


#ifdef v1_volume_node_resources_MAIN

void test_v1_volume_node_resources(int include_optional) {
    v1_volume_node_resources_t* v1_volume_node_resources_1 = instantiate_v1_volume_node_resources(include_optional);

	cJSON* jsonv1_volume_node_resources_1 = v1_volume_node_resources_convertToJSON(v1_volume_node_resources_1);
	printf("v1_volume_node_resources :\n%s\n", cJSON_Print(jsonv1_volume_node_resources_1));
	v1_volume_node_resources_t* v1_volume_node_resources_2 = v1_volume_node_resources_parseFromJSON(jsonv1_volume_node_resources_1);
	cJSON* jsonv1_volume_node_resources_2 = v1_volume_node_resources_convertToJSON(v1_volume_node_resources_2);
	printf("repeating v1_volume_node_resources:\n%s\n", cJSON_Print(jsonv1_volume_node_resources_2));
}

int main() {
  test_v1_volume_node_resources(1);
  test_v1_volume_node_resources(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_volume_node_resources_MAIN
#endif // v1_volume_node_resources_TEST
