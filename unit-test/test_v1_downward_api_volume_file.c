#ifndef v1_downward_api_volume_file_TEST
#define v1_downward_api_volume_file_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_downward_api_volume_file_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_downward_api_volume_file.h"
v1_downward_api_volume_file_t* instantiate_v1_downward_api_volume_file(int include_optional);

#include "test_v1_object_field_selector.c"
#include "test_v1_resource_field_selector.c"


v1_downward_api_volume_file_t* instantiate_v1_downward_api_volume_file(int include_optional) {
  v1_downward_api_volume_file_t* v1_downward_api_volume_file = NULL;
  if (include_optional) {
    v1_downward_api_volume_file = v1_downward_api_volume_file_create(
       // false, not to have infinite recursion
      instantiate_v1_object_field_selector(0),
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_v1_resource_field_selector(0)
    );
  } else {
    v1_downward_api_volume_file = v1_downward_api_volume_file_create(
      NULL,
      56,
      "0",
      NULL
    );
  }

  return v1_downward_api_volume_file;
}


#ifdef v1_downward_api_volume_file_MAIN

void test_v1_downward_api_volume_file(int include_optional) {
    v1_downward_api_volume_file_t* v1_downward_api_volume_file_1 = instantiate_v1_downward_api_volume_file(include_optional);

	cJSON* jsonv1_downward_api_volume_file_1 = v1_downward_api_volume_file_convertToJSON(v1_downward_api_volume_file_1);
	printf("v1_downward_api_volume_file :\n%s\n", cJSON_Print(jsonv1_downward_api_volume_file_1));
	v1_downward_api_volume_file_t* v1_downward_api_volume_file_2 = v1_downward_api_volume_file_parseFromJSON(jsonv1_downward_api_volume_file_1);
	cJSON* jsonv1_downward_api_volume_file_2 = v1_downward_api_volume_file_convertToJSON(v1_downward_api_volume_file_2);
	printf("repeating v1_downward_api_volume_file:\n%s\n", cJSON_Print(jsonv1_downward_api_volume_file_2));
}

int main() {
  test_v1_downward_api_volume_file(1);
  test_v1_downward_api_volume_file(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_downward_api_volume_file_MAIN
#endif // v1_downward_api_volume_file_TEST
