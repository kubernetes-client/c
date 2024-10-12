#ifndef v1beta1_volume_attributes_class_TEST
#define v1beta1_volume_attributes_class_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_volume_attributes_class_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_volume_attributes_class.h"
v1beta1_volume_attributes_class_t* instantiate_v1beta1_volume_attributes_class(int include_optional);

#include "test_v1_object_meta.c"


v1beta1_volume_attributes_class_t* instantiate_v1beta1_volume_attributes_class(int include_optional) {
  v1beta1_volume_attributes_class_t* v1beta1_volume_attributes_class = NULL;
  if (include_optional) {
    v1beta1_volume_attributes_class = v1beta1_volume_attributes_class_create(
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
      list_createList()
    );
  } else {
    v1beta1_volume_attributes_class = v1beta1_volume_attributes_class_create(
      "0",
      "0",
      "0",
      NULL,
      list_createList()
    );
  }

  return v1beta1_volume_attributes_class;
}


#ifdef v1beta1_volume_attributes_class_MAIN

void test_v1beta1_volume_attributes_class(int include_optional) {
    v1beta1_volume_attributes_class_t* v1beta1_volume_attributes_class_1 = instantiate_v1beta1_volume_attributes_class(include_optional);

	cJSON* jsonv1beta1_volume_attributes_class_1 = v1beta1_volume_attributes_class_convertToJSON(v1beta1_volume_attributes_class_1);
	printf("v1beta1_volume_attributes_class :\n%s\n", cJSON_Print(jsonv1beta1_volume_attributes_class_1));
	v1beta1_volume_attributes_class_t* v1beta1_volume_attributes_class_2 = v1beta1_volume_attributes_class_parseFromJSON(jsonv1beta1_volume_attributes_class_1);
	cJSON* jsonv1beta1_volume_attributes_class_2 = v1beta1_volume_attributes_class_convertToJSON(v1beta1_volume_attributes_class_2);
	printf("repeating v1beta1_volume_attributes_class:\n%s\n", cJSON_Print(jsonv1beta1_volume_attributes_class_2));
}

int main() {
  test_v1beta1_volume_attributes_class(1);
  test_v1beta1_volume_attributes_class(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_volume_attributes_class_MAIN
#endif // v1beta1_volume_attributes_class_TEST
