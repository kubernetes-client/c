#ifndef v1_config_map_projection_TEST
#define v1_config_map_projection_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_config_map_projection_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_config_map_projection.h"
v1_config_map_projection_t* instantiate_v1_config_map_projection(int include_optional);



v1_config_map_projection_t* instantiate_v1_config_map_projection(int include_optional) {
  v1_config_map_projection_t* v1_config_map_projection = NULL;
  if (include_optional) {
    v1_config_map_projection = v1_config_map_projection_create(
      list_create(),
      "0",
      1
    );
  } else {
    v1_config_map_projection = v1_config_map_projection_create(
      list_create(),
      "0",
      1
    );
  }

  return v1_config_map_projection;
}


#ifdef v1_config_map_projection_MAIN

void test_v1_config_map_projection(int include_optional) {
    v1_config_map_projection_t* v1_config_map_projection_1 = instantiate_v1_config_map_projection(include_optional);

	cJSON* jsonv1_config_map_projection_1 = v1_config_map_projection_convertToJSON(v1_config_map_projection_1);
	printf("v1_config_map_projection :\n%s\n", cJSON_Print(jsonv1_config_map_projection_1));
	v1_config_map_projection_t* v1_config_map_projection_2 = v1_config_map_projection_parseFromJSON(jsonv1_config_map_projection_1);
	cJSON* jsonv1_config_map_projection_2 = v1_config_map_projection_convertToJSON(v1_config_map_projection_2);
	printf("repeating v1_config_map_projection:\n%s\n", cJSON_Print(jsonv1_config_map_projection_2));
}

int main() {
  test_v1_config_map_projection(1);
  test_v1_config_map_projection(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_config_map_projection_MAIN
#endif // v1_config_map_projection_TEST
