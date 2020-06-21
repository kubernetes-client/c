#ifndef v1_config_map_node_config_source_TEST
#define v1_config_map_node_config_source_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_config_map_node_config_source_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_config_map_node_config_source.h"
v1_config_map_node_config_source_t* instantiate_v1_config_map_node_config_source(int include_optional);



v1_config_map_node_config_source_t* instantiate_v1_config_map_node_config_source(int include_optional) {
  v1_config_map_node_config_source_t* v1_config_map_node_config_source = NULL;
  if (include_optional) {
    v1_config_map_node_config_source = v1_config_map_node_config_source_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    v1_config_map_node_config_source = v1_config_map_node_config_source_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return v1_config_map_node_config_source;
}


#ifdef v1_config_map_node_config_source_MAIN

void test_v1_config_map_node_config_source(int include_optional) {
    v1_config_map_node_config_source_t* v1_config_map_node_config_source_1 = instantiate_v1_config_map_node_config_source(include_optional);

	cJSON* jsonv1_config_map_node_config_source_1 = v1_config_map_node_config_source_convertToJSON(v1_config_map_node_config_source_1);
	printf("v1_config_map_node_config_source :\n%s\n", cJSON_Print(jsonv1_config_map_node_config_source_1));
	v1_config_map_node_config_source_t* v1_config_map_node_config_source_2 = v1_config_map_node_config_source_parseFromJSON(jsonv1_config_map_node_config_source_1);
	cJSON* jsonv1_config_map_node_config_source_2 = v1_config_map_node_config_source_convertToJSON(v1_config_map_node_config_source_2);
	printf("repeating v1_config_map_node_config_source:\n%s\n", cJSON_Print(jsonv1_config_map_node_config_source_2));
}

int main() {
  test_v1_config_map_node_config_source(1);
  test_v1_config_map_node_config_source(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_config_map_node_config_source_MAIN
#endif // v1_config_map_node_config_source_TEST
