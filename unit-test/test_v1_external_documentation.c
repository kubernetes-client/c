#ifndef v1_external_documentation_TEST
#define v1_external_documentation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_external_documentation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_external_documentation.h"
v1_external_documentation_t* instantiate_v1_external_documentation(int include_optional);



v1_external_documentation_t* instantiate_v1_external_documentation(int include_optional) {
  v1_external_documentation_t* v1_external_documentation = NULL;
  if (include_optional) {
    v1_external_documentation = v1_external_documentation_create(
      "0",
      "0"
    );
  } else {
    v1_external_documentation = v1_external_documentation_create(
      "0",
      "0"
    );
  }

  return v1_external_documentation;
}


#ifdef v1_external_documentation_MAIN

void test_v1_external_documentation(int include_optional) {
    v1_external_documentation_t* v1_external_documentation_1 = instantiate_v1_external_documentation(include_optional);

	cJSON* jsonv1_external_documentation_1 = v1_external_documentation_convertToJSON(v1_external_documentation_1);
	printf("v1_external_documentation :\n%s\n", cJSON_Print(jsonv1_external_documentation_1));
	v1_external_documentation_t* v1_external_documentation_2 = v1_external_documentation_parseFromJSON(jsonv1_external_documentation_1);
	cJSON* jsonv1_external_documentation_2 = v1_external_documentation_convertToJSON(v1_external_documentation_2);
	printf("repeating v1_external_documentation:\n%s\n", cJSON_Print(jsonv1_external_documentation_2));
}

int main() {
  test_v1_external_documentation(1);
  test_v1_external_documentation(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_external_documentation_MAIN
#endif // v1_external_documentation_TEST
