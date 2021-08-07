#ifndef v1_resource_requirements_TEST
#define v1_resource_requirements_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_resource_requirements_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_resource_requirements.h"
v1_resource_requirements_t* instantiate_v1_resource_requirements(int include_optional);



v1_resource_requirements_t* instantiate_v1_resource_requirements(int include_optional) {
  v1_resource_requirements_t* v1_resource_requirements = NULL;
  if (include_optional) {
    v1_resource_requirements = v1_resource_requirements_create(
      list_create(),
      list_create()
    );
  } else {
    v1_resource_requirements = v1_resource_requirements_create(
      list_create(),
      list_create()
    );
  }

  return v1_resource_requirements;
}


#ifdef v1_resource_requirements_MAIN

void test_v1_resource_requirements(int include_optional) {
    v1_resource_requirements_t* v1_resource_requirements_1 = instantiate_v1_resource_requirements(include_optional);

	cJSON* jsonv1_resource_requirements_1 = v1_resource_requirements_convertToJSON(v1_resource_requirements_1);
	printf("v1_resource_requirements :\n%s\n", cJSON_Print(jsonv1_resource_requirements_1));
	v1_resource_requirements_t* v1_resource_requirements_2 = v1_resource_requirements_parseFromJSON(jsonv1_resource_requirements_1);
	cJSON* jsonv1_resource_requirements_2 = v1_resource_requirements_convertToJSON(v1_resource_requirements_2);
	printf("repeating v1_resource_requirements:\n%s\n", cJSON_Print(jsonv1_resource_requirements_2));
}

int main() {
  test_v1_resource_requirements(1);
  test_v1_resource_requirements(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_resource_requirements_MAIN
#endif // v1_resource_requirements_TEST
