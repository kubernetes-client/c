#ifndef v1alpha3_counter_TEST
#define v1alpha3_counter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_counter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_counter.h"
v1alpha3_counter_t* instantiate_v1alpha3_counter(int include_optional);



v1alpha3_counter_t* instantiate_v1alpha3_counter(int include_optional) {
  v1alpha3_counter_t* v1alpha3_counter = NULL;
  if (include_optional) {
    v1alpha3_counter = v1alpha3_counter_create(
      "0"
    );
  } else {
    v1alpha3_counter = v1alpha3_counter_create(
      "0"
    );
  }

  return v1alpha3_counter;
}


#ifdef v1alpha3_counter_MAIN

void test_v1alpha3_counter(int include_optional) {
    v1alpha3_counter_t* v1alpha3_counter_1 = instantiate_v1alpha3_counter(include_optional);

	cJSON* jsonv1alpha3_counter_1 = v1alpha3_counter_convertToJSON(v1alpha3_counter_1);
	printf("v1alpha3_counter :\n%s\n", cJSON_Print(jsonv1alpha3_counter_1));
	v1alpha3_counter_t* v1alpha3_counter_2 = v1alpha3_counter_parseFromJSON(jsonv1alpha3_counter_1);
	cJSON* jsonv1alpha3_counter_2 = v1alpha3_counter_convertToJSON(v1alpha3_counter_2);
	printf("repeating v1alpha3_counter:\n%s\n", cJSON_Print(jsonv1alpha3_counter_2));
}

int main() {
  test_v1alpha3_counter(1);
  test_v1alpha3_counter(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_counter_MAIN
#endif // v1alpha3_counter_TEST
