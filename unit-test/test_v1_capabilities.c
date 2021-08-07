#ifndef v1_capabilities_TEST
#define v1_capabilities_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_capabilities_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_capabilities.h"
v1_capabilities_t* instantiate_v1_capabilities(int include_optional);



v1_capabilities_t* instantiate_v1_capabilities(int include_optional) {
  v1_capabilities_t* v1_capabilities = NULL;
  if (include_optional) {
    v1_capabilities = v1_capabilities_create(
      list_create(),
      list_create()
    );
  } else {
    v1_capabilities = v1_capabilities_create(
      list_create(),
      list_create()
    );
  }

  return v1_capabilities;
}


#ifdef v1_capabilities_MAIN

void test_v1_capabilities(int include_optional) {
    v1_capabilities_t* v1_capabilities_1 = instantiate_v1_capabilities(include_optional);

	cJSON* jsonv1_capabilities_1 = v1_capabilities_convertToJSON(v1_capabilities_1);
	printf("v1_capabilities :\n%s\n", cJSON_Print(jsonv1_capabilities_1));
	v1_capabilities_t* v1_capabilities_2 = v1_capabilities_parseFromJSON(jsonv1_capabilities_1);
	cJSON* jsonv1_capabilities_2 = v1_capabilities_convertToJSON(v1_capabilities_2);
	printf("repeating v1_capabilities:\n%s\n", cJSON_Print(jsonv1_capabilities_2));
}

int main() {
  test_v1_capabilities(1);
  test_v1_capabilities(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_capabilities_MAIN
#endif // v1_capabilities_TEST
