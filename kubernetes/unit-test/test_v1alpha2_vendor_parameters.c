#ifndef v1alpha2_vendor_parameters_TEST
#define v1alpha2_vendor_parameters_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha2_vendor_parameters_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha2_vendor_parameters.h"
v1alpha2_vendor_parameters_t* instantiate_v1alpha2_vendor_parameters(int include_optional);



v1alpha2_vendor_parameters_t* instantiate_v1alpha2_vendor_parameters(int include_optional) {
  v1alpha2_vendor_parameters_t* v1alpha2_vendor_parameters = NULL;
  if (include_optional) {
    v1alpha2_vendor_parameters = v1alpha2_vendor_parameters_create(
      "0",
      0
    );
  } else {
    v1alpha2_vendor_parameters = v1alpha2_vendor_parameters_create(
      "0",
      0
    );
  }

  return v1alpha2_vendor_parameters;
}


#ifdef v1alpha2_vendor_parameters_MAIN

void test_v1alpha2_vendor_parameters(int include_optional) {
    v1alpha2_vendor_parameters_t* v1alpha2_vendor_parameters_1 = instantiate_v1alpha2_vendor_parameters(include_optional);

	cJSON* jsonv1alpha2_vendor_parameters_1 = v1alpha2_vendor_parameters_convertToJSON(v1alpha2_vendor_parameters_1);
	printf("v1alpha2_vendor_parameters :\n%s\n", cJSON_Print(jsonv1alpha2_vendor_parameters_1));
	v1alpha2_vendor_parameters_t* v1alpha2_vendor_parameters_2 = v1alpha2_vendor_parameters_parseFromJSON(jsonv1alpha2_vendor_parameters_1);
	cJSON* jsonv1alpha2_vendor_parameters_2 = v1alpha2_vendor_parameters_convertToJSON(v1alpha2_vendor_parameters_2);
	printf("repeating v1alpha2_vendor_parameters:\n%s\n", cJSON_Print(jsonv1alpha2_vendor_parameters_2));
}

int main() {
  test_v1alpha2_vendor_parameters(1);
  test_v1alpha2_vendor_parameters(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha2_vendor_parameters_MAIN
#endif // v1alpha2_vendor_parameters_TEST
