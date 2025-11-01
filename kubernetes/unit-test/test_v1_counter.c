#ifndef v1_counter_TEST
#define v1_counter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_counter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_counter.h"
v1_counter_t* instantiate_v1_counter(int include_optional);



v1_counter_t* instantiate_v1_counter(int include_optional) {
  v1_counter_t* v1_counter = NULL;
  if (include_optional) {
    v1_counter = v1_counter_create(
      "0"
    );
  } else {
    v1_counter = v1_counter_create(
      "0"
    );
  }

  return v1_counter;
}


#ifdef v1_counter_MAIN

void test_v1_counter(int include_optional) {
    v1_counter_t* v1_counter_1 = instantiate_v1_counter(include_optional);

	cJSON* jsonv1_counter_1 = v1_counter_convertToJSON(v1_counter_1);
	printf("v1_counter :\n%s\n", cJSON_Print(jsonv1_counter_1));
	v1_counter_t* v1_counter_2 = v1_counter_parseFromJSON(jsonv1_counter_1);
	cJSON* jsonv1_counter_2 = v1_counter_convertToJSON(v1_counter_2);
	printf("repeating v1_counter:\n%s\n", cJSON_Print(jsonv1_counter_2));
}

int main() {
  test_v1_counter(1);
  test_v1_counter(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_counter_MAIN
#endif // v1_counter_TEST
