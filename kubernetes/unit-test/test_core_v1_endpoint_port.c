#ifndef core_v1_endpoint_port_TEST
#define core_v1_endpoint_port_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define core_v1_endpoint_port_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/core_v1_endpoint_port.h"
core_v1_endpoint_port_t* instantiate_core_v1_endpoint_port(int include_optional);



core_v1_endpoint_port_t* instantiate_core_v1_endpoint_port(int include_optional) {
  core_v1_endpoint_port_t* core_v1_endpoint_port = NULL;
  if (include_optional) {
    core_v1_endpoint_port = core_v1_endpoint_port_create(
      "0",
      "0",
      56,
      "0"
    );
  } else {
    core_v1_endpoint_port = core_v1_endpoint_port_create(
      "0",
      "0",
      56,
      "0"
    );
  }

  return core_v1_endpoint_port;
}


#ifdef core_v1_endpoint_port_MAIN

void test_core_v1_endpoint_port(int include_optional) {
    core_v1_endpoint_port_t* core_v1_endpoint_port_1 = instantiate_core_v1_endpoint_port(include_optional);

	cJSON* jsoncore_v1_endpoint_port_1 = core_v1_endpoint_port_convertToJSON(core_v1_endpoint_port_1);
	printf("core_v1_endpoint_port :\n%s\n", cJSON_Print(jsoncore_v1_endpoint_port_1));
	core_v1_endpoint_port_t* core_v1_endpoint_port_2 = core_v1_endpoint_port_parseFromJSON(jsoncore_v1_endpoint_port_1);
	cJSON* jsoncore_v1_endpoint_port_2 = core_v1_endpoint_port_convertToJSON(core_v1_endpoint_port_2);
	printf("repeating core_v1_endpoint_port:\n%s\n", cJSON_Print(jsoncore_v1_endpoint_port_2));
}

int main() {
  test_core_v1_endpoint_port(1);
  test_core_v1_endpoint_port(0);

  printf("Hello world \n");
  return 0;
}

#endif // core_v1_endpoint_port_MAIN
#endif // core_v1_endpoint_port_TEST
