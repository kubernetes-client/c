#ifndef v1_csi_driver_TEST
#define v1_csi_driver_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_csi_driver_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_csi_driver.h"
v1_csi_driver_t* instantiate_v1_csi_driver(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_csi_driver_spec.c"


v1_csi_driver_t* instantiate_v1_csi_driver(int include_optional) {
  v1_csi_driver_t* v1_csi_driver = NULL;
  if (include_optional) {
    v1_csi_driver = v1_csi_driver_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_csi_driver_spec(0)
    );
  } else {
    v1_csi_driver = v1_csi_driver_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1_csi_driver;
}


#ifdef v1_csi_driver_MAIN

void test_v1_csi_driver(int include_optional) {
    v1_csi_driver_t* v1_csi_driver_1 = instantiate_v1_csi_driver(include_optional);

	cJSON* jsonv1_csi_driver_1 = v1_csi_driver_convertToJSON(v1_csi_driver_1);
	printf("v1_csi_driver :\n%s\n", cJSON_Print(jsonv1_csi_driver_1));
	v1_csi_driver_t* v1_csi_driver_2 = v1_csi_driver_parseFromJSON(jsonv1_csi_driver_1);
	cJSON* jsonv1_csi_driver_2 = v1_csi_driver_convertToJSON(v1_csi_driver_2);
	printf("repeating v1_csi_driver:\n%s\n", cJSON_Print(jsonv1_csi_driver_2));
}

int main() {
  test_v1_csi_driver(1);
  test_v1_csi_driver(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_csi_driver_MAIN
#endif // v1_csi_driver_TEST
