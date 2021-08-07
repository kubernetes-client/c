#ifndef v1_config_map_TEST
#define v1_config_map_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_config_map_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_config_map.h"
v1_config_map_t* instantiate_v1_config_map(int include_optional);

#include "test_v1_object_meta.c"


v1_config_map_t* instantiate_v1_config_map(int include_optional) {
  v1_config_map_t* v1_config_map = NULL;
  if (include_optional) {
    v1_config_map = v1_config_map_create(
      "0",
      list_create(),
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0)
    );
  } else {
    v1_config_map = v1_config_map_create(
      "0",
      list_create(),
      list_create(),
      "0",
      NULL
    );
  }

  return v1_config_map;
}


#ifdef v1_config_map_MAIN

void test_v1_config_map(int include_optional) {
    v1_config_map_t* v1_config_map_1 = instantiate_v1_config_map(include_optional);

	cJSON* jsonv1_config_map_1 = v1_config_map_convertToJSON(v1_config_map_1);
	printf("v1_config_map :\n%s\n", cJSON_Print(jsonv1_config_map_1));
	v1_config_map_t* v1_config_map_2 = v1_config_map_parseFromJSON(jsonv1_config_map_1);
	cJSON* jsonv1_config_map_2 = v1_config_map_convertToJSON(v1_config_map_2);
	printf("repeating v1_config_map:\n%s\n", cJSON_Print(jsonv1_config_map_2));
}

int main() {
  test_v1_config_map(1);
  test_v1_config_map(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_config_map_MAIN
#endif // v1_config_map_TEST
