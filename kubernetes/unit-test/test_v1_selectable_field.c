#ifndef v1_selectable_field_TEST
#define v1_selectable_field_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_selectable_field_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_selectable_field.h"
v1_selectable_field_t* instantiate_v1_selectable_field(int include_optional);



v1_selectable_field_t* instantiate_v1_selectable_field(int include_optional) {
  v1_selectable_field_t* v1_selectable_field = NULL;
  if (include_optional) {
    v1_selectable_field = v1_selectable_field_create(
      "0"
    );
  } else {
    v1_selectable_field = v1_selectable_field_create(
      "0"
    );
  }

  return v1_selectable_field;
}


#ifdef v1_selectable_field_MAIN

void test_v1_selectable_field(int include_optional) {
    v1_selectable_field_t* v1_selectable_field_1 = instantiate_v1_selectable_field(include_optional);

	cJSON* jsonv1_selectable_field_1 = v1_selectable_field_convertToJSON(v1_selectable_field_1);
	printf("v1_selectable_field :\n%s\n", cJSON_Print(jsonv1_selectable_field_1));
	v1_selectable_field_t* v1_selectable_field_2 = v1_selectable_field_parseFromJSON(jsonv1_selectable_field_1);
	cJSON* jsonv1_selectable_field_2 = v1_selectable_field_convertToJSON(v1_selectable_field_2);
	printf("repeating v1_selectable_field:\n%s\n", cJSON_Print(jsonv1_selectable_field_2));
}

int main() {
  test_v1_selectable_field(1);
  test_v1_selectable_field(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_selectable_field_MAIN
#endif // v1_selectable_field_TEST
