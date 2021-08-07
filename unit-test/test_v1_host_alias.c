#ifndef v1_host_alias_TEST
#define v1_host_alias_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_host_alias_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_host_alias.h"
v1_host_alias_t* instantiate_v1_host_alias(int include_optional);



v1_host_alias_t* instantiate_v1_host_alias(int include_optional) {
  v1_host_alias_t* v1_host_alias = NULL;
  if (include_optional) {
    v1_host_alias = v1_host_alias_create(
      list_create(),
      "0"
    );
  } else {
    v1_host_alias = v1_host_alias_create(
      list_create(),
      "0"
    );
  }

  return v1_host_alias;
}


#ifdef v1_host_alias_MAIN

void test_v1_host_alias(int include_optional) {
    v1_host_alias_t* v1_host_alias_1 = instantiate_v1_host_alias(include_optional);

	cJSON* jsonv1_host_alias_1 = v1_host_alias_convertToJSON(v1_host_alias_1);
	printf("v1_host_alias :\n%s\n", cJSON_Print(jsonv1_host_alias_1));
	v1_host_alias_t* v1_host_alias_2 = v1_host_alias_parseFromJSON(jsonv1_host_alias_1);
	cJSON* jsonv1_host_alias_2 = v1_host_alias_convertToJSON(v1_host_alias_2);
	printf("repeating v1_host_alias:\n%s\n", cJSON_Print(jsonv1_host_alias_2));
}

int main() {
  test_v1_host_alias(1);
  test_v1_host_alias(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_host_alias_MAIN
#endif // v1_host_alias_TEST
