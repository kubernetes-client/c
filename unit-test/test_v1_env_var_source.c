#ifndef v1_env_var_source_TEST
#define v1_env_var_source_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_env_var_source_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_env_var_source.h"
v1_env_var_source_t* instantiate_v1_env_var_source(int include_optional);

#include "test_v1_config_map_key_selector.c"
#include "test_v1_object_field_selector.c"
#include "test_v1_resource_field_selector.c"
#include "test_v1_secret_key_selector.c"


v1_env_var_source_t* instantiate_v1_env_var_source(int include_optional) {
  v1_env_var_source_t* v1_env_var_source = NULL;
  if (include_optional) {
    v1_env_var_source = v1_env_var_source_create(
       // false, not to have infinite recursion
      instantiate_v1_config_map_key_selector(0),
       // false, not to have infinite recursion
      instantiate_v1_object_field_selector(0),
       // false, not to have infinite recursion
      instantiate_v1_resource_field_selector(0),
       // false, not to have infinite recursion
      instantiate_v1_secret_key_selector(0)
    );
  } else {
    v1_env_var_source = v1_env_var_source_create(
      NULL,
      NULL,
      NULL,
      NULL
    );
  }

  return v1_env_var_source;
}


#ifdef v1_env_var_source_MAIN

void test_v1_env_var_source(int include_optional) {
    v1_env_var_source_t* v1_env_var_source_1 = instantiate_v1_env_var_source(include_optional);

	cJSON* jsonv1_env_var_source_1 = v1_env_var_source_convertToJSON(v1_env_var_source_1);
	printf("v1_env_var_source :\n%s\n", cJSON_Print(jsonv1_env_var_source_1));
	v1_env_var_source_t* v1_env_var_source_2 = v1_env_var_source_parseFromJSON(jsonv1_env_var_source_1);
	cJSON* jsonv1_env_var_source_2 = v1_env_var_source_convertToJSON(v1_env_var_source_2);
	printf("repeating v1_env_var_source:\n%s\n", cJSON_Print(jsonv1_env_var_source_2));
}

int main() {
  test_v1_env_var_source(1);
  test_v1_env_var_source(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_env_var_source_MAIN
#endif // v1_env_var_source_TEST
