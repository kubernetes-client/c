#ifndef v1beta1_capacity_requirements_TEST
#define v1beta1_capacity_requirements_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_capacity_requirements_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_capacity_requirements.h"
v1beta1_capacity_requirements_t* instantiate_v1beta1_capacity_requirements(int include_optional);



v1beta1_capacity_requirements_t* instantiate_v1beta1_capacity_requirements(int include_optional) {
  v1beta1_capacity_requirements_t* v1beta1_capacity_requirements = NULL;
  if (include_optional) {
    v1beta1_capacity_requirements = v1beta1_capacity_requirements_create(
      list_createList()
    );
  } else {
    v1beta1_capacity_requirements = v1beta1_capacity_requirements_create(
      list_createList()
    );
  }

  return v1beta1_capacity_requirements;
}


#ifdef v1beta1_capacity_requirements_MAIN

void test_v1beta1_capacity_requirements(int include_optional) {
    v1beta1_capacity_requirements_t* v1beta1_capacity_requirements_1 = instantiate_v1beta1_capacity_requirements(include_optional);

	cJSON* jsonv1beta1_capacity_requirements_1 = v1beta1_capacity_requirements_convertToJSON(v1beta1_capacity_requirements_1);
	printf("v1beta1_capacity_requirements :\n%s\n", cJSON_Print(jsonv1beta1_capacity_requirements_1));
	v1beta1_capacity_requirements_t* v1beta1_capacity_requirements_2 = v1beta1_capacity_requirements_parseFromJSON(jsonv1beta1_capacity_requirements_1);
	cJSON* jsonv1beta1_capacity_requirements_2 = v1beta1_capacity_requirements_convertToJSON(v1beta1_capacity_requirements_2);
	printf("repeating v1beta1_capacity_requirements:\n%s\n", cJSON_Print(jsonv1beta1_capacity_requirements_2));
}

int main() {
  test_v1beta1_capacity_requirements(1);
  test_v1beta1_capacity_requirements(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_capacity_requirements_MAIN
#endif // v1beta1_capacity_requirements_TEST
