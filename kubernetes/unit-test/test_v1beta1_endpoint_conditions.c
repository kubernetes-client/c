#ifndef v1beta1_endpoint_conditions_TEST
#define v1beta1_endpoint_conditions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_endpoint_conditions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_endpoint_conditions.h"
v1beta1_endpoint_conditions_t* instantiate_v1beta1_endpoint_conditions(int include_optional);



v1beta1_endpoint_conditions_t* instantiate_v1beta1_endpoint_conditions(int include_optional) {
  v1beta1_endpoint_conditions_t* v1beta1_endpoint_conditions = NULL;
  if (include_optional) {
    v1beta1_endpoint_conditions = v1beta1_endpoint_conditions_create(
      1
    );
  } else {
    v1beta1_endpoint_conditions = v1beta1_endpoint_conditions_create(
      1
    );
  }

  return v1beta1_endpoint_conditions;
}


#ifdef v1beta1_endpoint_conditions_MAIN

void test_v1beta1_endpoint_conditions(int include_optional) {
    v1beta1_endpoint_conditions_t* v1beta1_endpoint_conditions_1 = instantiate_v1beta1_endpoint_conditions(include_optional);

	cJSON* jsonv1beta1_endpoint_conditions_1 = v1beta1_endpoint_conditions_convertToJSON(v1beta1_endpoint_conditions_1);
	printf("v1beta1_endpoint_conditions :\n%s\n", cJSON_Print(jsonv1beta1_endpoint_conditions_1));
	v1beta1_endpoint_conditions_t* v1beta1_endpoint_conditions_2 = v1beta1_endpoint_conditions_parseFromJSON(jsonv1beta1_endpoint_conditions_1);
	cJSON* jsonv1beta1_endpoint_conditions_2 = v1beta1_endpoint_conditions_convertToJSON(v1beta1_endpoint_conditions_2);
	printf("repeating v1beta1_endpoint_conditions:\n%s\n", cJSON_Print(jsonv1beta1_endpoint_conditions_2));
}

int main() {
  test_v1beta1_endpoint_conditions(1);
  test_v1beta1_endpoint_conditions(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_endpoint_conditions_MAIN
#endif // v1beta1_endpoint_conditions_TEST
