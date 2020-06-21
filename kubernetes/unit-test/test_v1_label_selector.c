#ifndef v1_label_selector_TEST
#define v1_label_selector_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_label_selector_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_label_selector.h"
v1_label_selector_t* instantiate_v1_label_selector(int include_optional);



v1_label_selector_t* instantiate_v1_label_selector(int include_optional) {
  v1_label_selector_t* v1_label_selector = NULL;
  if (include_optional) {
    v1_label_selector = v1_label_selector_create(
      list_create(),
      list_create()
    );
  } else {
    v1_label_selector = v1_label_selector_create(
      list_create(),
      list_create()
    );
  }

  return v1_label_selector;
}


#ifdef v1_label_selector_MAIN

void test_v1_label_selector(int include_optional) {
    v1_label_selector_t* v1_label_selector_1 = instantiate_v1_label_selector(include_optional);

	cJSON* jsonv1_label_selector_1 = v1_label_selector_convertToJSON(v1_label_selector_1);
	printf("v1_label_selector :\n%s\n", cJSON_Print(jsonv1_label_selector_1));
	v1_label_selector_t* v1_label_selector_2 = v1_label_selector_parseFromJSON(jsonv1_label_selector_1);
	cJSON* jsonv1_label_selector_2 = v1_label_selector_convertToJSON(v1_label_selector_2);
	printf("repeating v1_label_selector:\n%s\n", cJSON_Print(jsonv1_label_selector_2));
}

int main() {
  test_v1_label_selector(1);
  test_v1_label_selector(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_label_selector_MAIN
#endif // v1_label_selector_TEST
