#ifndef v1_label_selector_attributes_TEST
#define v1_label_selector_attributes_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_label_selector_attributes_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_label_selector_attributes.h"
v1_label_selector_attributes_t* instantiate_v1_label_selector_attributes(int include_optional);



v1_label_selector_attributes_t* instantiate_v1_label_selector_attributes(int include_optional) {
  v1_label_selector_attributes_t* v1_label_selector_attributes = NULL;
  if (include_optional) {
    v1_label_selector_attributes = v1_label_selector_attributes_create(
      "0",
      list_createList()
    );
  } else {
    v1_label_selector_attributes = v1_label_selector_attributes_create(
      "0",
      list_createList()
    );
  }

  return v1_label_selector_attributes;
}


#ifdef v1_label_selector_attributes_MAIN

void test_v1_label_selector_attributes(int include_optional) {
    v1_label_selector_attributes_t* v1_label_selector_attributes_1 = instantiate_v1_label_selector_attributes(include_optional);

	cJSON* jsonv1_label_selector_attributes_1 = v1_label_selector_attributes_convertToJSON(v1_label_selector_attributes_1);
	printf("v1_label_selector_attributes :\n%s\n", cJSON_Print(jsonv1_label_selector_attributes_1));
	v1_label_selector_attributes_t* v1_label_selector_attributes_2 = v1_label_selector_attributes_parseFromJSON(jsonv1_label_selector_attributes_1);
	cJSON* jsonv1_label_selector_attributes_2 = v1_label_selector_attributes_convertToJSON(v1_label_selector_attributes_2);
	printf("repeating v1_label_selector_attributes:\n%s\n", cJSON_Print(jsonv1_label_selector_attributes_2));
}

int main() {
  test_v1_label_selector_attributes(1);
  test_v1_label_selector_attributes(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_label_selector_attributes_MAIN
#endif // v1_label_selector_attributes_TEST
