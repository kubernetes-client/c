#ifndef v1_node_config_status_TEST
#define v1_node_config_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_node_config_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_node_config_status.h"
v1_node_config_status_t* instantiate_v1_node_config_status(int include_optional);

#include "test_v1_node_config_source.c"
#include "test_v1_node_config_source.c"
#include "test_v1_node_config_source.c"


v1_node_config_status_t* instantiate_v1_node_config_status(int include_optional) {
  v1_node_config_status_t* v1_node_config_status = NULL;
  if (include_optional) {
    v1_node_config_status = v1_node_config_status_create(
       // false, not to have infinite recursion
      instantiate_v1_node_config_source(0),
       // false, not to have infinite recursion
      instantiate_v1_node_config_source(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_node_config_source(0)
    );
  } else {
    v1_node_config_status = v1_node_config_status_create(
      NULL,
      NULL,
      "0",
      NULL
    );
  }

  return v1_node_config_status;
}


#ifdef v1_node_config_status_MAIN

void test_v1_node_config_status(int include_optional) {
    v1_node_config_status_t* v1_node_config_status_1 = instantiate_v1_node_config_status(include_optional);

	cJSON* jsonv1_node_config_status_1 = v1_node_config_status_convertToJSON(v1_node_config_status_1);
	printf("v1_node_config_status :\n%s\n", cJSON_Print(jsonv1_node_config_status_1));
	v1_node_config_status_t* v1_node_config_status_2 = v1_node_config_status_parseFromJSON(jsonv1_node_config_status_1);
	cJSON* jsonv1_node_config_status_2 = v1_node_config_status_convertToJSON(v1_node_config_status_2);
	printf("repeating v1_node_config_status:\n%s\n", cJSON_Print(jsonv1_node_config_status_2));
}

int main() {
  test_v1_node_config_status(1);
  test_v1_node_config_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_node_config_status_MAIN
#endif // v1_node_config_status_TEST
