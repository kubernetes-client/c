#ifndef v1alpha1_expression_warning_TEST
#define v1alpha1_expression_warning_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_expression_warning_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_expression_warning.h"
v1alpha1_expression_warning_t* instantiate_v1alpha1_expression_warning(int include_optional);



v1alpha1_expression_warning_t* instantiate_v1alpha1_expression_warning(int include_optional) {
  v1alpha1_expression_warning_t* v1alpha1_expression_warning = NULL;
  if (include_optional) {
    v1alpha1_expression_warning = v1alpha1_expression_warning_create(
      "0",
      "0"
    );
  } else {
    v1alpha1_expression_warning = v1alpha1_expression_warning_create(
      "0",
      "0"
    );
  }

  return v1alpha1_expression_warning;
}


#ifdef v1alpha1_expression_warning_MAIN

void test_v1alpha1_expression_warning(int include_optional) {
    v1alpha1_expression_warning_t* v1alpha1_expression_warning_1 = instantiate_v1alpha1_expression_warning(include_optional);

	cJSON* jsonv1alpha1_expression_warning_1 = v1alpha1_expression_warning_convertToJSON(v1alpha1_expression_warning_1);
	printf("v1alpha1_expression_warning :\n%s\n", cJSON_Print(jsonv1alpha1_expression_warning_1));
	v1alpha1_expression_warning_t* v1alpha1_expression_warning_2 = v1alpha1_expression_warning_parseFromJSON(jsonv1alpha1_expression_warning_1);
	cJSON* jsonv1alpha1_expression_warning_2 = v1alpha1_expression_warning_convertToJSON(v1alpha1_expression_warning_2);
	printf("repeating v1alpha1_expression_warning:\n%s\n", cJSON_Print(jsonv1alpha1_expression_warning_2));
}

int main() {
  test_v1alpha1_expression_warning(1);
  test_v1alpha1_expression_warning(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_expression_warning_MAIN
#endif // v1alpha1_expression_warning_TEST
