#ifndef v1alpha1_priority_level_configuration_status_TEST
#define v1alpha1_priority_level_configuration_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_priority_level_configuration_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_priority_level_configuration_status.h"
v1alpha1_priority_level_configuration_status_t* instantiate_v1alpha1_priority_level_configuration_status(int include_optional);



v1alpha1_priority_level_configuration_status_t* instantiate_v1alpha1_priority_level_configuration_status(int include_optional) {
  v1alpha1_priority_level_configuration_status_t* v1alpha1_priority_level_configuration_status = NULL;
  if (include_optional) {
    v1alpha1_priority_level_configuration_status = v1alpha1_priority_level_configuration_status_create(
      list_create()
    );
  } else {
    v1alpha1_priority_level_configuration_status = v1alpha1_priority_level_configuration_status_create(
      list_create()
    );
  }

  return v1alpha1_priority_level_configuration_status;
}


#ifdef v1alpha1_priority_level_configuration_status_MAIN

void test_v1alpha1_priority_level_configuration_status(int include_optional) {
    v1alpha1_priority_level_configuration_status_t* v1alpha1_priority_level_configuration_status_1 = instantiate_v1alpha1_priority_level_configuration_status(include_optional);

	cJSON* jsonv1alpha1_priority_level_configuration_status_1 = v1alpha1_priority_level_configuration_status_convertToJSON(v1alpha1_priority_level_configuration_status_1);
	printf("v1alpha1_priority_level_configuration_status :\n%s\n", cJSON_Print(jsonv1alpha1_priority_level_configuration_status_1));
	v1alpha1_priority_level_configuration_status_t* v1alpha1_priority_level_configuration_status_2 = v1alpha1_priority_level_configuration_status_parseFromJSON(jsonv1alpha1_priority_level_configuration_status_1);
	cJSON* jsonv1alpha1_priority_level_configuration_status_2 = v1alpha1_priority_level_configuration_status_convertToJSON(v1alpha1_priority_level_configuration_status_2);
	printf("repeating v1alpha1_priority_level_configuration_status:\n%s\n", cJSON_Print(jsonv1alpha1_priority_level_configuration_status_2));
}

int main() {
  test_v1alpha1_priority_level_configuration_status(1);
  test_v1alpha1_priority_level_configuration_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_priority_level_configuration_status_MAIN
#endif // v1alpha1_priority_level_configuration_status_TEST
