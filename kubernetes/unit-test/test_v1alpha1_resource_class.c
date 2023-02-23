#ifndef v1alpha1_resource_class_TEST
#define v1alpha1_resource_class_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_resource_class_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_resource_class.h"
v1alpha1_resource_class_t* instantiate_v1alpha1_resource_class(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha1_resource_class_parameters_reference.c"
#include "test_v1_node_selector.c"


v1alpha1_resource_class_t* instantiate_v1alpha1_resource_class(int include_optional) {
  v1alpha1_resource_class_t* v1alpha1_resource_class = NULL;
  if (include_optional) {
    v1alpha1_resource_class = v1alpha1_resource_class_create(
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_resource_class_parameters_reference(0),
       // false, not to have infinite recursion
      instantiate_v1_node_selector(0)
    );
  } else {
    v1alpha1_resource_class = v1alpha1_resource_class_create(
      "0",
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1alpha1_resource_class;
}


#ifdef v1alpha1_resource_class_MAIN

void test_v1alpha1_resource_class(int include_optional) {
    v1alpha1_resource_class_t* v1alpha1_resource_class_1 = instantiate_v1alpha1_resource_class(include_optional);

	cJSON* jsonv1alpha1_resource_class_1 = v1alpha1_resource_class_convertToJSON(v1alpha1_resource_class_1);
	printf("v1alpha1_resource_class :\n%s\n", cJSON_Print(jsonv1alpha1_resource_class_1));
	v1alpha1_resource_class_t* v1alpha1_resource_class_2 = v1alpha1_resource_class_parseFromJSON(jsonv1alpha1_resource_class_1);
	cJSON* jsonv1alpha1_resource_class_2 = v1alpha1_resource_class_convertToJSON(v1alpha1_resource_class_2);
	printf("repeating v1alpha1_resource_class:\n%s\n", cJSON_Print(jsonv1alpha1_resource_class_2));
}

int main() {
  test_v1alpha1_resource_class(1);
  test_v1alpha1_resource_class(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_resource_class_MAIN
#endif // v1alpha1_resource_class_TEST
