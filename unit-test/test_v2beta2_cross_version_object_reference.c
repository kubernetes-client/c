#ifndef v2beta2_cross_version_object_reference_TEST
#define v2beta2_cross_version_object_reference_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2beta2_cross_version_object_reference_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2beta2_cross_version_object_reference.h"
v2beta2_cross_version_object_reference_t* instantiate_v2beta2_cross_version_object_reference(int include_optional);



v2beta2_cross_version_object_reference_t* instantiate_v2beta2_cross_version_object_reference(int include_optional) {
  v2beta2_cross_version_object_reference_t* v2beta2_cross_version_object_reference = NULL;
  if (include_optional) {
    v2beta2_cross_version_object_reference = v2beta2_cross_version_object_reference_create(
      "0",
      "0",
      "0"
    );
  } else {
    v2beta2_cross_version_object_reference = v2beta2_cross_version_object_reference_create(
      "0",
      "0",
      "0"
    );
  }

  return v2beta2_cross_version_object_reference;
}


#ifdef v2beta2_cross_version_object_reference_MAIN

void test_v2beta2_cross_version_object_reference(int include_optional) {
    v2beta2_cross_version_object_reference_t* v2beta2_cross_version_object_reference_1 = instantiate_v2beta2_cross_version_object_reference(include_optional);

	cJSON* jsonv2beta2_cross_version_object_reference_1 = v2beta2_cross_version_object_reference_convertToJSON(v2beta2_cross_version_object_reference_1);
	printf("v2beta2_cross_version_object_reference :\n%s\n", cJSON_Print(jsonv2beta2_cross_version_object_reference_1));
	v2beta2_cross_version_object_reference_t* v2beta2_cross_version_object_reference_2 = v2beta2_cross_version_object_reference_parseFromJSON(jsonv2beta2_cross_version_object_reference_1);
	cJSON* jsonv2beta2_cross_version_object_reference_2 = v2beta2_cross_version_object_reference_convertToJSON(v2beta2_cross_version_object_reference_2);
	printf("repeating v2beta2_cross_version_object_reference:\n%s\n", cJSON_Print(jsonv2beta2_cross_version_object_reference_2));
}

int main() {
  test_v2beta2_cross_version_object_reference(1);
  test_v2beta2_cross_version_object_reference(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2beta2_cross_version_object_reference_MAIN
#endif // v2beta2_cross_version_object_reference_TEST
