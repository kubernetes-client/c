#ifndef v1_expression_warning_TEST
#define v1_expression_warning_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_expression_warning_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_expression_warning.h"
v1_expression_warning_t* instantiate_v1_expression_warning(int include_optional);



v1_expression_warning_t* instantiate_v1_expression_warning(int include_optional) {
  v1_expression_warning_t* v1_expression_warning = NULL;
  if (include_optional) {
    v1_expression_warning = v1_expression_warning_create(
      "0",
      "0"
    );
  } else {
    v1_expression_warning = v1_expression_warning_create(
      "0",
      "0"
    );
  }

  return v1_expression_warning;
}


#ifdef v1_expression_warning_MAIN

void test_v1_expression_warning(int include_optional) {
    v1_expression_warning_t* v1_expression_warning_1 = instantiate_v1_expression_warning(include_optional);

	cJSON* jsonv1_expression_warning_1 = v1_expression_warning_convertToJSON(v1_expression_warning_1);
	printf("v1_expression_warning :\n%s\n", cJSON_Print(jsonv1_expression_warning_1));
	v1_expression_warning_t* v1_expression_warning_2 = v1_expression_warning_parseFromJSON(jsonv1_expression_warning_1);
	cJSON* jsonv1_expression_warning_2 = v1_expression_warning_convertToJSON(v1_expression_warning_2);
	printf("repeating v1_expression_warning:\n%s\n", cJSON_Print(jsonv1_expression_warning_2));
}

int main() {
  test_v1_expression_warning(1);
  test_v1_expression_warning(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_expression_warning_MAIN
#endif // v1_expression_warning_TEST
