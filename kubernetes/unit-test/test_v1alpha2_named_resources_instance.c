#ifndef v1alpha2_named_resources_instance_TEST
#define v1alpha2_named_resources_instance_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha2_named_resources_instance_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha2_named_resources_instance.h"
v1alpha2_named_resources_instance_t* instantiate_v1alpha2_named_resources_instance(int include_optional);



v1alpha2_named_resources_instance_t* instantiate_v1alpha2_named_resources_instance(int include_optional) {
  v1alpha2_named_resources_instance_t* v1alpha2_named_resources_instance = NULL;
  if (include_optional) {
    v1alpha2_named_resources_instance = v1alpha2_named_resources_instance_create(
      list_createList(),
      "0"
    );
  } else {
    v1alpha2_named_resources_instance = v1alpha2_named_resources_instance_create(
      list_createList(),
      "0"
    );
  }

  return v1alpha2_named_resources_instance;
}


#ifdef v1alpha2_named_resources_instance_MAIN

void test_v1alpha2_named_resources_instance(int include_optional) {
    v1alpha2_named_resources_instance_t* v1alpha2_named_resources_instance_1 = instantiate_v1alpha2_named_resources_instance(include_optional);

	cJSON* jsonv1alpha2_named_resources_instance_1 = v1alpha2_named_resources_instance_convertToJSON(v1alpha2_named_resources_instance_1);
	printf("v1alpha2_named_resources_instance :\n%s\n", cJSON_Print(jsonv1alpha2_named_resources_instance_1));
	v1alpha2_named_resources_instance_t* v1alpha2_named_resources_instance_2 = v1alpha2_named_resources_instance_parseFromJSON(jsonv1alpha2_named_resources_instance_1);
	cJSON* jsonv1alpha2_named_resources_instance_2 = v1alpha2_named_resources_instance_convertToJSON(v1alpha2_named_resources_instance_2);
	printf("repeating v1alpha2_named_resources_instance:\n%s\n", cJSON_Print(jsonv1alpha2_named_resources_instance_2));
}

int main() {
  test_v1alpha2_named_resources_instance(1);
  test_v1alpha2_named_resources_instance(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha2_named_resources_instance_MAIN
#endif // v1alpha2_named_resources_instance_TEST
