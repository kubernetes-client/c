#ifndef discovery_v1_endpoint_port_TEST
#define discovery_v1_endpoint_port_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define discovery_v1_endpoint_port_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/discovery_v1_endpoint_port.h"
discovery_v1_endpoint_port_t* instantiate_discovery_v1_endpoint_port(int include_optional);



discovery_v1_endpoint_port_t* instantiate_discovery_v1_endpoint_port(int include_optional) {
  discovery_v1_endpoint_port_t* discovery_v1_endpoint_port = NULL;
  if (include_optional) {
    discovery_v1_endpoint_port = discovery_v1_endpoint_port_create(
      "0",
      "0",
      56,
      "0"
    );
  } else {
    discovery_v1_endpoint_port = discovery_v1_endpoint_port_create(
      "0",
      "0",
      56,
      "0"
    );
  }

  return discovery_v1_endpoint_port;
}


#ifdef discovery_v1_endpoint_port_MAIN

void test_discovery_v1_endpoint_port(int include_optional) {
    discovery_v1_endpoint_port_t* discovery_v1_endpoint_port_1 = instantiate_discovery_v1_endpoint_port(include_optional);

	cJSON* jsondiscovery_v1_endpoint_port_1 = discovery_v1_endpoint_port_convertToJSON(discovery_v1_endpoint_port_1);
	printf("discovery_v1_endpoint_port :\n%s\n", cJSON_Print(jsondiscovery_v1_endpoint_port_1));
	discovery_v1_endpoint_port_t* discovery_v1_endpoint_port_2 = discovery_v1_endpoint_port_parseFromJSON(jsondiscovery_v1_endpoint_port_1);
	cJSON* jsondiscovery_v1_endpoint_port_2 = discovery_v1_endpoint_port_convertToJSON(discovery_v1_endpoint_port_2);
	printf("repeating discovery_v1_endpoint_port:\n%s\n", cJSON_Print(jsondiscovery_v1_endpoint_port_2));
}

int main() {
  test_discovery_v1_endpoint_port(1);
  test_discovery_v1_endpoint_port(0);

  printf("Hello world \n");
  return 0;
}

#endif // discovery_v1_endpoint_port_MAIN
#endif // discovery_v1_endpoint_port_TEST
