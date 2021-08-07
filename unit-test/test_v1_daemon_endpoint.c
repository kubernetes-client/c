#ifndef v1_daemon_endpoint_TEST
#define v1_daemon_endpoint_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_daemon_endpoint_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_daemon_endpoint.h"
v1_daemon_endpoint_t* instantiate_v1_daemon_endpoint(int include_optional);



v1_daemon_endpoint_t* instantiate_v1_daemon_endpoint(int include_optional) {
  v1_daemon_endpoint_t* v1_daemon_endpoint = NULL;
  if (include_optional) {
    v1_daemon_endpoint = v1_daemon_endpoint_create(
      56
    );
  } else {
    v1_daemon_endpoint = v1_daemon_endpoint_create(
      56
    );
  }

  return v1_daemon_endpoint;
}


#ifdef v1_daemon_endpoint_MAIN

void test_v1_daemon_endpoint(int include_optional) {
    v1_daemon_endpoint_t* v1_daemon_endpoint_1 = instantiate_v1_daemon_endpoint(include_optional);

	cJSON* jsonv1_daemon_endpoint_1 = v1_daemon_endpoint_convertToJSON(v1_daemon_endpoint_1);
	printf("v1_daemon_endpoint :\n%s\n", cJSON_Print(jsonv1_daemon_endpoint_1));
	v1_daemon_endpoint_t* v1_daemon_endpoint_2 = v1_daemon_endpoint_parseFromJSON(jsonv1_daemon_endpoint_1);
	cJSON* jsonv1_daemon_endpoint_2 = v1_daemon_endpoint_convertToJSON(v1_daemon_endpoint_2);
	printf("repeating v1_daemon_endpoint:\n%s\n", cJSON_Print(jsonv1_daemon_endpoint_2));
}

int main() {
  test_v1_daemon_endpoint(1);
  test_v1_daemon_endpoint(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_daemon_endpoint_MAIN
#endif // v1_daemon_endpoint_TEST
