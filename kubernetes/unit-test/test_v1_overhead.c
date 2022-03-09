#ifndef v1_overhead_TEST
#define v1_overhead_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_overhead_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_overhead.h"
v1_overhead_t* instantiate_v1_overhead(int include_optional);



v1_overhead_t* instantiate_v1_overhead(int include_optional) {
  v1_overhead_t* v1_overhead = NULL;
  if (include_optional) {
    v1_overhead = v1_overhead_create(
      list_createList()
    );
  } else {
    v1_overhead = v1_overhead_create(
      list_createList()
    );
  }

  return v1_overhead;
}


#ifdef v1_overhead_MAIN

void test_v1_overhead(int include_optional) {
    v1_overhead_t* v1_overhead_1 = instantiate_v1_overhead(include_optional);

	cJSON* jsonv1_overhead_1 = v1_overhead_convertToJSON(v1_overhead_1);
	printf("v1_overhead :\n%s\n", cJSON_Print(jsonv1_overhead_1));
	v1_overhead_t* v1_overhead_2 = v1_overhead_parseFromJSON(jsonv1_overhead_1);
	cJSON* jsonv1_overhead_2 = v1_overhead_convertToJSON(v1_overhead_2);
	printf("repeating v1_overhead:\n%s\n", cJSON_Print(jsonv1_overhead_2));
}

int main() {
  test_v1_overhead(1);
  test_v1_overhead(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_overhead_MAIN
#endif // v1_overhead_TEST
