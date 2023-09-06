#ifndef v1beta1_param_kind_TEST
#define v1beta1_param_kind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_param_kind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_param_kind.h"
v1beta1_param_kind_t* instantiate_v1beta1_param_kind(int include_optional);



v1beta1_param_kind_t* instantiate_v1beta1_param_kind(int include_optional) {
  v1beta1_param_kind_t* v1beta1_param_kind = NULL;
  if (include_optional) {
    v1beta1_param_kind = v1beta1_param_kind_create(
      "0",
      "0"
    );
  } else {
    v1beta1_param_kind = v1beta1_param_kind_create(
      "0",
      "0"
    );
  }

  return v1beta1_param_kind;
}


#ifdef v1beta1_param_kind_MAIN

void test_v1beta1_param_kind(int include_optional) {
    v1beta1_param_kind_t* v1beta1_param_kind_1 = instantiate_v1beta1_param_kind(include_optional);

	cJSON* jsonv1beta1_param_kind_1 = v1beta1_param_kind_convertToJSON(v1beta1_param_kind_1);
	printf("v1beta1_param_kind :\n%s\n", cJSON_Print(jsonv1beta1_param_kind_1));
	v1beta1_param_kind_t* v1beta1_param_kind_2 = v1beta1_param_kind_parseFromJSON(jsonv1beta1_param_kind_1);
	cJSON* jsonv1beta1_param_kind_2 = v1beta1_param_kind_convertToJSON(v1beta1_param_kind_2);
	printf("repeating v1beta1_param_kind:\n%s\n", cJSON_Print(jsonv1beta1_param_kind_2));
}

int main() {
  test_v1beta1_param_kind(1);
  test_v1beta1_param_kind(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_param_kind_MAIN
#endif // v1beta1_param_kind_TEST
