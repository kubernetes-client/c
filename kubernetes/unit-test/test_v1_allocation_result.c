#ifndef v1_allocation_result_TEST
#define v1_allocation_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_allocation_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_allocation_result.h"
v1_allocation_result_t* instantiate_v1_allocation_result(int include_optional);

#include "test_v1_device_allocation_result.c"
#include "test_v1_node_selector.c"


v1_allocation_result_t* instantiate_v1_allocation_result(int include_optional) {
  v1_allocation_result_t* v1_allocation_result = NULL;
  if (include_optional) {
    v1_allocation_result = v1_allocation_result_create(
      "2013-10-20T19:20:30+01:00",
       // false, not to have infinite recursion
      instantiate_v1_device_allocation_result(0),
       // false, not to have infinite recursion
      instantiate_v1_node_selector(0)
    );
  } else {
    v1_allocation_result = v1_allocation_result_create(
      "2013-10-20T19:20:30+01:00",
      NULL,
      NULL
    );
  }

  return v1_allocation_result;
}


#ifdef v1_allocation_result_MAIN

void test_v1_allocation_result(int include_optional) {
    v1_allocation_result_t* v1_allocation_result_1 = instantiate_v1_allocation_result(include_optional);

	cJSON* jsonv1_allocation_result_1 = v1_allocation_result_convertToJSON(v1_allocation_result_1);
	printf("v1_allocation_result :\n%s\n", cJSON_Print(jsonv1_allocation_result_1));
	v1_allocation_result_t* v1_allocation_result_2 = v1_allocation_result_parseFromJSON(jsonv1_allocation_result_1);
	cJSON* jsonv1_allocation_result_2 = v1_allocation_result_convertToJSON(v1_allocation_result_2);
	printf("repeating v1_allocation_result:\n%s\n", cJSON_Print(jsonv1_allocation_result_2));
}

int main() {
  test_v1_allocation_result(1);
  test_v1_allocation_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_allocation_result_MAIN
#endif // v1_allocation_result_TEST
