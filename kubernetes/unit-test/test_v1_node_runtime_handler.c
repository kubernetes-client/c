#ifndef v1_node_runtime_handler_TEST
#define v1_node_runtime_handler_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_node_runtime_handler_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_node_runtime_handler.h"
v1_node_runtime_handler_t* instantiate_v1_node_runtime_handler(int include_optional);

#include "test_v1_node_runtime_handler_features.c"


v1_node_runtime_handler_t* instantiate_v1_node_runtime_handler(int include_optional) {
  v1_node_runtime_handler_t* v1_node_runtime_handler = NULL;
  if (include_optional) {
    v1_node_runtime_handler = v1_node_runtime_handler_create(
       // false, not to have infinite recursion
      instantiate_v1_node_runtime_handler_features(0),
      "0"
    );
  } else {
    v1_node_runtime_handler = v1_node_runtime_handler_create(
      NULL,
      "0"
    );
  }

  return v1_node_runtime_handler;
}


#ifdef v1_node_runtime_handler_MAIN

void test_v1_node_runtime_handler(int include_optional) {
    v1_node_runtime_handler_t* v1_node_runtime_handler_1 = instantiate_v1_node_runtime_handler(include_optional);

	cJSON* jsonv1_node_runtime_handler_1 = v1_node_runtime_handler_convertToJSON(v1_node_runtime_handler_1);
	printf("v1_node_runtime_handler :\n%s\n", cJSON_Print(jsonv1_node_runtime_handler_1));
	v1_node_runtime_handler_t* v1_node_runtime_handler_2 = v1_node_runtime_handler_parseFromJSON(jsonv1_node_runtime_handler_1);
	cJSON* jsonv1_node_runtime_handler_2 = v1_node_runtime_handler_convertToJSON(v1_node_runtime_handler_2);
	printf("repeating v1_node_runtime_handler:\n%s\n", cJSON_Print(jsonv1_node_runtime_handler_2));
}

int main() {
  test_v1_node_runtime_handler(1);
  test_v1_node_runtime_handler(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_node_runtime_handler_MAIN
#endif // v1_node_runtime_handler_TEST
