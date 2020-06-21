#ifndef v1_limit_range_item_TEST
#define v1_limit_range_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_limit_range_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_limit_range_item.h"
v1_limit_range_item_t* instantiate_v1_limit_range_item(int include_optional);



v1_limit_range_item_t* instantiate_v1_limit_range_item(int include_optional) {
  v1_limit_range_item_t* v1_limit_range_item = NULL;
  if (include_optional) {
    v1_limit_range_item = v1_limit_range_item_create(
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      "0"
    );
  } else {
    v1_limit_range_item = v1_limit_range_item_create(
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      list_create(),
      "0"
    );
  }

  return v1_limit_range_item;
}


#ifdef v1_limit_range_item_MAIN

void test_v1_limit_range_item(int include_optional) {
    v1_limit_range_item_t* v1_limit_range_item_1 = instantiate_v1_limit_range_item(include_optional);

	cJSON* jsonv1_limit_range_item_1 = v1_limit_range_item_convertToJSON(v1_limit_range_item_1);
	printf("v1_limit_range_item :\n%s\n", cJSON_Print(jsonv1_limit_range_item_1));
	v1_limit_range_item_t* v1_limit_range_item_2 = v1_limit_range_item_parseFromJSON(jsonv1_limit_range_item_1);
	cJSON* jsonv1_limit_range_item_2 = v1_limit_range_item_convertToJSON(v1_limit_range_item_2);
	printf("repeating v1_limit_range_item:\n%s\n", cJSON_Print(jsonv1_limit_range_item_2));
}

int main() {
  test_v1_limit_range_item(1);
  test_v1_limit_range_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_limit_range_item_MAIN
#endif // v1_limit_range_item_TEST
