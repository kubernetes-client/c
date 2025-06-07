#ifndef v1beta2_device_constraint_TEST
#define v1beta2_device_constraint_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_device_constraint_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_device_constraint.h"
v1beta2_device_constraint_t* instantiate_v1beta2_device_constraint(int include_optional);



v1beta2_device_constraint_t* instantiate_v1beta2_device_constraint(int include_optional) {
  v1beta2_device_constraint_t* v1beta2_device_constraint = NULL;
  if (include_optional) {
    v1beta2_device_constraint = v1beta2_device_constraint_create(
      "0",
      list_createList()
    );
  } else {
    v1beta2_device_constraint = v1beta2_device_constraint_create(
      "0",
      list_createList()
    );
  }

  return v1beta2_device_constraint;
}


#ifdef v1beta2_device_constraint_MAIN

void test_v1beta2_device_constraint(int include_optional) {
    v1beta2_device_constraint_t* v1beta2_device_constraint_1 = instantiate_v1beta2_device_constraint(include_optional);

	cJSON* jsonv1beta2_device_constraint_1 = v1beta2_device_constraint_convertToJSON(v1beta2_device_constraint_1);
	printf("v1beta2_device_constraint :\n%s\n", cJSON_Print(jsonv1beta2_device_constraint_1));
	v1beta2_device_constraint_t* v1beta2_device_constraint_2 = v1beta2_device_constraint_parseFromJSON(jsonv1beta2_device_constraint_1);
	cJSON* jsonv1beta2_device_constraint_2 = v1beta2_device_constraint_convertToJSON(v1beta2_device_constraint_2);
	printf("repeating v1beta2_device_constraint:\n%s\n", cJSON_Print(jsonv1beta2_device_constraint_2));
}

int main() {
  test_v1beta2_device_constraint(1);
  test_v1beta2_device_constraint(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_device_constraint_MAIN
#endif // v1beta2_device_constraint_TEST
