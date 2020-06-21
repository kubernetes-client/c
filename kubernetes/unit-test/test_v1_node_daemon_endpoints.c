#ifndef v1_node_daemon_endpoints_TEST
#define v1_node_daemon_endpoints_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_node_daemon_endpoints_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_node_daemon_endpoints.h"
v1_node_daemon_endpoints_t* instantiate_v1_node_daemon_endpoints(int include_optional);

#include "test_v1_daemon_endpoint.c"


v1_node_daemon_endpoints_t* instantiate_v1_node_daemon_endpoints(int include_optional) {
  v1_node_daemon_endpoints_t* v1_node_daemon_endpoints = NULL;
  if (include_optional) {
    v1_node_daemon_endpoints = v1_node_daemon_endpoints_create(
       // false, not to have infinite recursion
      instantiate_v1_daemon_endpoint(0)
    );
  } else {
    v1_node_daemon_endpoints = v1_node_daemon_endpoints_create(
      NULL
    );
  }

  return v1_node_daemon_endpoints;
}


#ifdef v1_node_daemon_endpoints_MAIN

void test_v1_node_daemon_endpoints(int include_optional) {
    v1_node_daemon_endpoints_t* v1_node_daemon_endpoints_1 = instantiate_v1_node_daemon_endpoints(include_optional);

	cJSON* jsonv1_node_daemon_endpoints_1 = v1_node_daemon_endpoints_convertToJSON(v1_node_daemon_endpoints_1);
	printf("v1_node_daemon_endpoints :\n%s\n", cJSON_Print(jsonv1_node_daemon_endpoints_1));
	v1_node_daemon_endpoints_t* v1_node_daemon_endpoints_2 = v1_node_daemon_endpoints_parseFromJSON(jsonv1_node_daemon_endpoints_1);
	cJSON* jsonv1_node_daemon_endpoints_2 = v1_node_daemon_endpoints_convertToJSON(v1_node_daemon_endpoints_2);
	printf("repeating v1_node_daemon_endpoints:\n%s\n", cJSON_Print(jsonv1_node_daemon_endpoints_2));
}

int main() {
  test_v1_node_daemon_endpoints(1);
  test_v1_node_daemon_endpoints(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_node_daemon_endpoints_MAIN
#endif // v1_node_daemon_endpoints_TEST
