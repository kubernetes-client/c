#ifndef v1alpha1_group_version_resource_TEST
#define v1alpha1_group_version_resource_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_group_version_resource_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_group_version_resource.h"
v1alpha1_group_version_resource_t* instantiate_v1alpha1_group_version_resource(int include_optional);



v1alpha1_group_version_resource_t* instantiate_v1alpha1_group_version_resource(int include_optional) {
  v1alpha1_group_version_resource_t* v1alpha1_group_version_resource = NULL;
  if (include_optional) {
    v1alpha1_group_version_resource = v1alpha1_group_version_resource_create(
      "0",
      "0",
      "0"
    );
  } else {
    v1alpha1_group_version_resource = v1alpha1_group_version_resource_create(
      "0",
      "0",
      "0"
    );
  }

  return v1alpha1_group_version_resource;
}


#ifdef v1alpha1_group_version_resource_MAIN

void test_v1alpha1_group_version_resource(int include_optional) {
    v1alpha1_group_version_resource_t* v1alpha1_group_version_resource_1 = instantiate_v1alpha1_group_version_resource(include_optional);

	cJSON* jsonv1alpha1_group_version_resource_1 = v1alpha1_group_version_resource_convertToJSON(v1alpha1_group_version_resource_1);
	printf("v1alpha1_group_version_resource :\n%s\n", cJSON_Print(jsonv1alpha1_group_version_resource_1));
	v1alpha1_group_version_resource_t* v1alpha1_group_version_resource_2 = v1alpha1_group_version_resource_parseFromJSON(jsonv1alpha1_group_version_resource_1);
	cJSON* jsonv1alpha1_group_version_resource_2 = v1alpha1_group_version_resource_convertToJSON(v1alpha1_group_version_resource_2);
	printf("repeating v1alpha1_group_version_resource:\n%s\n", cJSON_Print(jsonv1alpha1_group_version_resource_2));
}

int main() {
  test_v1alpha1_group_version_resource(1);
  test_v1alpha1_group_version_resource(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_group_version_resource_MAIN
#endif // v1alpha1_group_version_resource_TEST
