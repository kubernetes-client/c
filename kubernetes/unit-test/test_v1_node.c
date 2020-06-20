#ifndef v1_node_TEST
#define v1_node_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_node_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_node.h"
v1_node_t* instantiate_v1_node(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_node_spec.c"
#include "test_v1_node_status.c"


v1_node_t* instantiate_v1_node(int include_optional) {
  v1_node_t* v1_node = NULL;
  if (include_optional) {
    v1_node = v1_node_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_node_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_node_status(0)
    );
  } else {
    v1_node = v1_node_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_node;
}


#ifdef v1_node_MAIN

void test_v1_node(int include_optional) {
    v1_node_t* v1_node_1 = instantiate_v1_node(include_optional);

	cJSON* jsonv1_node_1 = v1_node_convertToJSON(v1_node_1);
	printf("v1_node :\n%s\n", cJSON_Print(jsonv1_node_1));
	v1_node_t* v1_node_2 = v1_node_parseFromJSON(jsonv1_node_1);
	cJSON* jsonv1_node_2 = v1_node_convertToJSON(v1_node_2);
	printf("repeating v1_node:\n%s\n", cJSON_Print(jsonv1_node_2));
}

int main() {
  test_v1_node(1);
  test_v1_node(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_node_MAIN
#endif // v1_node_TEST
