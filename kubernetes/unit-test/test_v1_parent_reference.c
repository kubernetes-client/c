#ifndef v1_parent_reference_TEST
#define v1_parent_reference_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_parent_reference_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_parent_reference.h"
v1_parent_reference_t* instantiate_v1_parent_reference(int include_optional);



v1_parent_reference_t* instantiate_v1_parent_reference(int include_optional) {
  v1_parent_reference_t* v1_parent_reference = NULL;
  if (include_optional) {
    v1_parent_reference = v1_parent_reference_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    v1_parent_reference = v1_parent_reference_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return v1_parent_reference;
}


#ifdef v1_parent_reference_MAIN

void test_v1_parent_reference(int include_optional) {
    v1_parent_reference_t* v1_parent_reference_1 = instantiate_v1_parent_reference(include_optional);

	cJSON* jsonv1_parent_reference_1 = v1_parent_reference_convertToJSON(v1_parent_reference_1);
	printf("v1_parent_reference :\n%s\n", cJSON_Print(jsonv1_parent_reference_1));
	v1_parent_reference_t* v1_parent_reference_2 = v1_parent_reference_parseFromJSON(jsonv1_parent_reference_1);
	cJSON* jsonv1_parent_reference_2 = v1_parent_reference_convertToJSON(v1_parent_reference_2);
	printf("repeating v1_parent_reference:\n%s\n", cJSON_Print(jsonv1_parent_reference_2));
}

int main() {
  test_v1_parent_reference(1);
  test_v1_parent_reference(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_parent_reference_MAIN
#endif // v1_parent_reference_TEST
