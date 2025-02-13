#ifndef v1beta1_device_allocation_result_TEST
#define v1beta1_device_allocation_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_device_allocation_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_device_allocation_result.h"
v1beta1_device_allocation_result_t* instantiate_v1beta1_device_allocation_result(int include_optional);



v1beta1_device_allocation_result_t* instantiate_v1beta1_device_allocation_result(int include_optional) {
  v1beta1_device_allocation_result_t* v1beta1_device_allocation_result = NULL;
  if (include_optional) {
    v1beta1_device_allocation_result = v1beta1_device_allocation_result_create(
      list_createList(),
      list_createList()
    );
  } else {
    v1beta1_device_allocation_result = v1beta1_device_allocation_result_create(
      list_createList(),
      list_createList()
    );
  }

  return v1beta1_device_allocation_result;
}


#ifdef v1beta1_device_allocation_result_MAIN

void test_v1beta1_device_allocation_result(int include_optional) {
    v1beta1_device_allocation_result_t* v1beta1_device_allocation_result_1 = instantiate_v1beta1_device_allocation_result(include_optional);

	cJSON* jsonv1beta1_device_allocation_result_1 = v1beta1_device_allocation_result_convertToJSON(v1beta1_device_allocation_result_1);
	printf("v1beta1_device_allocation_result :\n%s\n", cJSON_Print(jsonv1beta1_device_allocation_result_1));
	v1beta1_device_allocation_result_t* v1beta1_device_allocation_result_2 = v1beta1_device_allocation_result_parseFromJSON(jsonv1beta1_device_allocation_result_1);
	cJSON* jsonv1beta1_device_allocation_result_2 = v1beta1_device_allocation_result_convertToJSON(v1beta1_device_allocation_result_2);
	printf("repeating v1beta1_device_allocation_result:\n%s\n", cJSON_Print(jsonv1beta1_device_allocation_result_2));
}

int main() {
  test_v1beta1_device_allocation_result(1);
  test_v1beta1_device_allocation_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_device_allocation_result_MAIN
#endif // v1beta1_device_allocation_result_TEST
