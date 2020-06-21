#ifndef v1beta1_overhead_TEST
#define v1beta1_overhead_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_overhead_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_overhead.h"
v1beta1_overhead_t* instantiate_v1beta1_overhead(int include_optional);



v1beta1_overhead_t* instantiate_v1beta1_overhead(int include_optional) {
  v1beta1_overhead_t* v1beta1_overhead = NULL;
  if (include_optional) {
    v1beta1_overhead = v1beta1_overhead_create(
      list_create()
    );
  } else {
    v1beta1_overhead = v1beta1_overhead_create(
      list_create()
    );
  }

  return v1beta1_overhead;
}


#ifdef v1beta1_overhead_MAIN

void test_v1beta1_overhead(int include_optional) {
    v1beta1_overhead_t* v1beta1_overhead_1 = instantiate_v1beta1_overhead(include_optional);

	cJSON* jsonv1beta1_overhead_1 = v1beta1_overhead_convertToJSON(v1beta1_overhead_1);
	printf("v1beta1_overhead :\n%s\n", cJSON_Print(jsonv1beta1_overhead_1));
	v1beta1_overhead_t* v1beta1_overhead_2 = v1beta1_overhead_parseFromJSON(jsonv1beta1_overhead_1);
	cJSON* jsonv1beta1_overhead_2 = v1beta1_overhead_convertToJSON(v1beta1_overhead_2);
	printf("repeating v1beta1_overhead:\n%s\n", cJSON_Print(jsonv1beta1_overhead_2));
}

int main() {
  test_v1beta1_overhead(1);
  test_v1beta1_overhead(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_overhead_MAIN
#endif // v1beta1_overhead_TEST
