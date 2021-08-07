#ifndef v1_env_var_TEST
#define v1_env_var_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_env_var_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_env_var.h"
v1_env_var_t* instantiate_v1_env_var(int include_optional);

#include "test_v1_env_var_source.c"


v1_env_var_t* instantiate_v1_env_var(int include_optional) {
  v1_env_var_t* v1_env_var = NULL;
  if (include_optional) {
    v1_env_var = v1_env_var_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_env_var_source(0)
    );
  } else {
    v1_env_var = v1_env_var_create(
      "0",
      "0",
      NULL
    );
  }

  return v1_env_var;
}


#ifdef v1_env_var_MAIN

void test_v1_env_var(int include_optional) {
    v1_env_var_t* v1_env_var_1 = instantiate_v1_env_var(include_optional);

	cJSON* jsonv1_env_var_1 = v1_env_var_convertToJSON(v1_env_var_1);
	printf("v1_env_var :\n%s\n", cJSON_Print(jsonv1_env_var_1));
	v1_env_var_t* v1_env_var_2 = v1_env_var_parseFromJSON(jsonv1_env_var_1);
	cJSON* jsonv1_env_var_2 = v1_env_var_convertToJSON(v1_env_var_2);
	printf("repeating v1_env_var:\n%s\n", cJSON_Print(jsonv1_env_var_2));
}

int main() {
  test_v1_env_var(1);
  test_v1_env_var(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_env_var_MAIN
#endif // v1_env_var_TEST
