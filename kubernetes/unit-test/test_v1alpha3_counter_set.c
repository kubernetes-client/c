#ifndef v1alpha3_counter_set_TEST
#define v1alpha3_counter_set_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_counter_set_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_counter_set.h"
v1alpha3_counter_set_t* instantiate_v1alpha3_counter_set(int include_optional);



v1alpha3_counter_set_t* instantiate_v1alpha3_counter_set(int include_optional) {
  v1alpha3_counter_set_t* v1alpha3_counter_set = NULL;
  if (include_optional) {
    v1alpha3_counter_set = v1alpha3_counter_set_create(
      list_createList(),
      "0"
    );
  } else {
    v1alpha3_counter_set = v1alpha3_counter_set_create(
      list_createList(),
      "0"
    );
  }

  return v1alpha3_counter_set;
}


#ifdef v1alpha3_counter_set_MAIN

void test_v1alpha3_counter_set(int include_optional) {
    v1alpha3_counter_set_t* v1alpha3_counter_set_1 = instantiate_v1alpha3_counter_set(include_optional);

	cJSON* jsonv1alpha3_counter_set_1 = v1alpha3_counter_set_convertToJSON(v1alpha3_counter_set_1);
	printf("v1alpha3_counter_set :\n%s\n", cJSON_Print(jsonv1alpha3_counter_set_1));
	v1alpha3_counter_set_t* v1alpha3_counter_set_2 = v1alpha3_counter_set_parseFromJSON(jsonv1alpha3_counter_set_1);
	cJSON* jsonv1alpha3_counter_set_2 = v1alpha3_counter_set_convertToJSON(v1alpha3_counter_set_2);
	printf("repeating v1alpha3_counter_set:\n%s\n", cJSON_Print(jsonv1alpha3_counter_set_2));
}

int main() {
  test_v1alpha3_counter_set(1);
  test_v1alpha3_counter_set(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_counter_set_MAIN
#endif // v1alpha3_counter_set_TEST
