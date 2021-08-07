#ifndef v1_label_selector_requirement_TEST
#define v1_label_selector_requirement_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_label_selector_requirement_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_label_selector_requirement.h"
v1_label_selector_requirement_t* instantiate_v1_label_selector_requirement(int include_optional);



v1_label_selector_requirement_t* instantiate_v1_label_selector_requirement(int include_optional) {
  v1_label_selector_requirement_t* v1_label_selector_requirement = NULL;
  if (include_optional) {
    v1_label_selector_requirement = v1_label_selector_requirement_create(
      "0",
      "0",
      list_create()
    );
  } else {
    v1_label_selector_requirement = v1_label_selector_requirement_create(
      "0",
      "0",
      list_create()
    );
  }

  return v1_label_selector_requirement;
}


#ifdef v1_label_selector_requirement_MAIN

void test_v1_label_selector_requirement(int include_optional) {
    v1_label_selector_requirement_t* v1_label_selector_requirement_1 = instantiate_v1_label_selector_requirement(include_optional);

	cJSON* jsonv1_label_selector_requirement_1 = v1_label_selector_requirement_convertToJSON(v1_label_selector_requirement_1);
	printf("v1_label_selector_requirement :\n%s\n", cJSON_Print(jsonv1_label_selector_requirement_1));
	v1_label_selector_requirement_t* v1_label_selector_requirement_2 = v1_label_selector_requirement_parseFromJSON(jsonv1_label_selector_requirement_1);
	cJSON* jsonv1_label_selector_requirement_2 = v1_label_selector_requirement_convertToJSON(v1_label_selector_requirement_2);
	printf("repeating v1_label_selector_requirement:\n%s\n", cJSON_Print(jsonv1_label_selector_requirement_2));
}

int main() {
  test_v1_label_selector_requirement(1);
  test_v1_label_selector_requirement(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_label_selector_requirement_MAIN
#endif // v1_label_selector_requirement_TEST
