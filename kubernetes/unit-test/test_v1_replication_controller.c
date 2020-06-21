#ifndef v1_replication_controller_TEST
#define v1_replication_controller_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_replication_controller_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_replication_controller.h"
v1_replication_controller_t* instantiate_v1_replication_controller(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_replication_controller_spec.c"
#include "test_v1_replication_controller_status.c"


v1_replication_controller_t* instantiate_v1_replication_controller(int include_optional) {
  v1_replication_controller_t* v1_replication_controller = NULL;
  if (include_optional) {
    v1_replication_controller = v1_replication_controller_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_replication_controller_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_replication_controller_status(0)
    );
  } else {
    v1_replication_controller = v1_replication_controller_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_replication_controller;
}


#ifdef v1_replication_controller_MAIN

void test_v1_replication_controller(int include_optional) {
    v1_replication_controller_t* v1_replication_controller_1 = instantiate_v1_replication_controller(include_optional);

	cJSON* jsonv1_replication_controller_1 = v1_replication_controller_convertToJSON(v1_replication_controller_1);
	printf("v1_replication_controller :\n%s\n", cJSON_Print(jsonv1_replication_controller_1));
	v1_replication_controller_t* v1_replication_controller_2 = v1_replication_controller_parseFromJSON(jsonv1_replication_controller_1);
	cJSON* jsonv1_replication_controller_2 = v1_replication_controller_convertToJSON(v1_replication_controller_2);
	printf("repeating v1_replication_controller:\n%s\n", cJSON_Print(jsonv1_replication_controller_2));
}

int main() {
  test_v1_replication_controller(1);
  test_v1_replication_controller(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_replication_controller_MAIN
#endif // v1_replication_controller_TEST
