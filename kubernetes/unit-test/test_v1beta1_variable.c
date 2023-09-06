#ifndef v1beta1_variable_TEST
#define v1beta1_variable_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_variable_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_variable.h"
v1beta1_variable_t* instantiate_v1beta1_variable(int include_optional);



v1beta1_variable_t* instantiate_v1beta1_variable(int include_optional) {
  v1beta1_variable_t* v1beta1_variable = NULL;
  if (include_optional) {
    v1beta1_variable = v1beta1_variable_create(
      "0",
      "0"
    );
  } else {
    v1beta1_variable = v1beta1_variable_create(
      "0",
      "0"
    );
  }

  return v1beta1_variable;
}


#ifdef v1beta1_variable_MAIN

void test_v1beta1_variable(int include_optional) {
    v1beta1_variable_t* v1beta1_variable_1 = instantiate_v1beta1_variable(include_optional);

	cJSON* jsonv1beta1_variable_1 = v1beta1_variable_convertToJSON(v1beta1_variable_1);
	printf("v1beta1_variable :\n%s\n", cJSON_Print(jsonv1beta1_variable_1));
	v1beta1_variable_t* v1beta1_variable_2 = v1beta1_variable_parseFromJSON(jsonv1beta1_variable_1);
	cJSON* jsonv1beta1_variable_2 = v1beta1_variable_convertToJSON(v1beta1_variable_2);
	printf("repeating v1beta1_variable:\n%s\n", cJSON_Print(jsonv1beta1_variable_2));
}

int main() {
  test_v1beta1_variable(1);
  test_v1beta1_variable(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_variable_MAIN
#endif // v1beta1_variable_TEST
