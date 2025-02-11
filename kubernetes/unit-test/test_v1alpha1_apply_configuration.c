#ifndef v1alpha1_apply_configuration_TEST
#define v1alpha1_apply_configuration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_apply_configuration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_apply_configuration.h"
v1alpha1_apply_configuration_t* instantiate_v1alpha1_apply_configuration(int include_optional);



v1alpha1_apply_configuration_t* instantiate_v1alpha1_apply_configuration(int include_optional) {
  v1alpha1_apply_configuration_t* v1alpha1_apply_configuration = NULL;
  if (include_optional) {
    v1alpha1_apply_configuration = v1alpha1_apply_configuration_create(
      "0"
    );
  } else {
    v1alpha1_apply_configuration = v1alpha1_apply_configuration_create(
      "0"
    );
  }

  return v1alpha1_apply_configuration;
}


#ifdef v1alpha1_apply_configuration_MAIN

void test_v1alpha1_apply_configuration(int include_optional) {
    v1alpha1_apply_configuration_t* v1alpha1_apply_configuration_1 = instantiate_v1alpha1_apply_configuration(include_optional);

	cJSON* jsonv1alpha1_apply_configuration_1 = v1alpha1_apply_configuration_convertToJSON(v1alpha1_apply_configuration_1);
	printf("v1alpha1_apply_configuration :\n%s\n", cJSON_Print(jsonv1alpha1_apply_configuration_1));
	v1alpha1_apply_configuration_t* v1alpha1_apply_configuration_2 = v1alpha1_apply_configuration_parseFromJSON(jsonv1alpha1_apply_configuration_1);
	cJSON* jsonv1alpha1_apply_configuration_2 = v1alpha1_apply_configuration_convertToJSON(v1alpha1_apply_configuration_2);
	printf("repeating v1alpha1_apply_configuration:\n%s\n", cJSON_Print(jsonv1alpha1_apply_configuration_2));
}

int main() {
  test_v1alpha1_apply_configuration(1);
  test_v1alpha1_apply_configuration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_apply_configuration_MAIN
#endif // v1alpha1_apply_configuration_TEST
