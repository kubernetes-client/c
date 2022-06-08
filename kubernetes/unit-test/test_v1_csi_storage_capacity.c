#ifndef v1_csi_storage_capacity_TEST
#define v1_csi_storage_capacity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_csi_storage_capacity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_csi_storage_capacity.h"
v1_csi_storage_capacity_t* instantiate_v1_csi_storage_capacity(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_label_selector.c"


v1_csi_storage_capacity_t* instantiate_v1_csi_storage_capacity(int include_optional) {
  v1_csi_storage_capacity_t* v1_csi_storage_capacity = NULL;
  if (include_optional) {
    v1_csi_storage_capacity = v1_csi_storage_capacity_create(
      "0",
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
      "0"
    );
  } else {
    v1_csi_storage_capacity = v1_csi_storage_capacity_create(
      "0",
      "0",
      "0",
      "0",
      NULL,
      NULL,
      "0"
    );
  }

  return v1_csi_storage_capacity;
}


#ifdef v1_csi_storage_capacity_MAIN

void test_v1_csi_storage_capacity(int include_optional) {
    v1_csi_storage_capacity_t* v1_csi_storage_capacity_1 = instantiate_v1_csi_storage_capacity(include_optional);

	cJSON* jsonv1_csi_storage_capacity_1 = v1_csi_storage_capacity_convertToJSON(v1_csi_storage_capacity_1);
	printf("v1_csi_storage_capacity :\n%s\n", cJSON_Print(jsonv1_csi_storage_capacity_1));
	v1_csi_storage_capacity_t* v1_csi_storage_capacity_2 = v1_csi_storage_capacity_parseFromJSON(jsonv1_csi_storage_capacity_1);
	cJSON* jsonv1_csi_storage_capacity_2 = v1_csi_storage_capacity_convertToJSON(v1_csi_storage_capacity_2);
	printf("repeating v1_csi_storage_capacity:\n%s\n", cJSON_Print(jsonv1_csi_storage_capacity_2));
}

int main() {
  test_v1_csi_storage_capacity(1);
  test_v1_csi_storage_capacity(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_csi_storage_capacity_MAIN
#endif // v1_csi_storage_capacity_TEST
