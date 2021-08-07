#ifndef v1_config_map_key_selector_TEST
#define v1_config_map_key_selector_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_config_map_key_selector_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_config_map_key_selector.h"
v1_config_map_key_selector_t* instantiate_v1_config_map_key_selector(int include_optional);



v1_config_map_key_selector_t* instantiate_v1_config_map_key_selector(int include_optional) {
  v1_config_map_key_selector_t* v1_config_map_key_selector = NULL;
  if (include_optional) {
    v1_config_map_key_selector = v1_config_map_key_selector_create(
      "0",
      "0",
      1
    );
  } else {
    v1_config_map_key_selector = v1_config_map_key_selector_create(
      "0",
      "0",
      1
    );
  }

  return v1_config_map_key_selector;
}


#ifdef v1_config_map_key_selector_MAIN

void test_v1_config_map_key_selector(int include_optional) {
    v1_config_map_key_selector_t* v1_config_map_key_selector_1 = instantiate_v1_config_map_key_selector(include_optional);

	cJSON* jsonv1_config_map_key_selector_1 = v1_config_map_key_selector_convertToJSON(v1_config_map_key_selector_1);
	printf("v1_config_map_key_selector :\n%s\n", cJSON_Print(jsonv1_config_map_key_selector_1));
	v1_config_map_key_selector_t* v1_config_map_key_selector_2 = v1_config_map_key_selector_parseFromJSON(jsonv1_config_map_key_selector_1);
	cJSON* jsonv1_config_map_key_selector_2 = v1_config_map_key_selector_convertToJSON(v1_config_map_key_selector_2);
	printf("repeating v1_config_map_key_selector:\n%s\n", cJSON_Print(jsonv1_config_map_key_selector_2));
}

int main() {
  test_v1_config_map_key_selector(1);
  test_v1_config_map_key_selector(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_config_map_key_selector_MAIN
#endif // v1_config_map_key_selector_TEST
