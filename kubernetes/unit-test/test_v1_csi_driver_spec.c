#ifndef v1_csi_driver_spec_TEST
#define v1_csi_driver_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_csi_driver_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_csi_driver_spec.h"
v1_csi_driver_spec_t* instantiate_v1_csi_driver_spec(int include_optional);



v1_csi_driver_spec_t* instantiate_v1_csi_driver_spec(int include_optional) {
  v1_csi_driver_spec_t* v1_csi_driver_spec = NULL;
  if (include_optional) {
    v1_csi_driver_spec = v1_csi_driver_spec_create(
      1,
      "0",
      1,
      1,
      1,
      list_createList(),
      list_createList()
    );
  } else {
    v1_csi_driver_spec = v1_csi_driver_spec_create(
      1,
      "0",
      1,
      1,
      1,
      list_createList(),
      list_createList()
    );
  }

  return v1_csi_driver_spec;
}


#ifdef v1_csi_driver_spec_MAIN

void test_v1_csi_driver_spec(int include_optional) {
    v1_csi_driver_spec_t* v1_csi_driver_spec_1 = instantiate_v1_csi_driver_spec(include_optional);

	cJSON* jsonv1_csi_driver_spec_1 = v1_csi_driver_spec_convertToJSON(v1_csi_driver_spec_1);
	printf("v1_csi_driver_spec :\n%s\n", cJSON_Print(jsonv1_csi_driver_spec_1));
	v1_csi_driver_spec_t* v1_csi_driver_spec_2 = v1_csi_driver_spec_parseFromJSON(jsonv1_csi_driver_spec_1);
	cJSON* jsonv1_csi_driver_spec_2 = v1_csi_driver_spec_convertToJSON(v1_csi_driver_spec_2);
	printf("repeating v1_csi_driver_spec:\n%s\n", cJSON_Print(jsonv1_csi_driver_spec_2));
}

int main() {
  test_v1_csi_driver_spec(1);
  test_v1_csi_driver_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_csi_driver_spec_MAIN
#endif // v1_csi_driver_spec_TEST
